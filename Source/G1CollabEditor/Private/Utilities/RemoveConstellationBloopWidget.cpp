#if 0 // Deprecated one-use migration implementation retained for reference.

#include "Utilities/RemoveConstellationBloopWidget.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "Blueprint/WidgetTree.h"
#include "Components/ActorComponent.h"
#include "Components/Button.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextBlock.h"
#include "Curves/CurveFloat.h"
#include "Editor.h"
#include "Engine/StaticMesh.h"
#include "EngineUtils.h"
#include "LevelEditorSubsystem.h"
#include "Materials/MaterialInstance.h"
#include "Misc/MessageDialog.h"
#include "Misc/PackageName.h"
#include "Misc/ScopedSlowTask.h"
#include "Modules/ModuleManager.h"
#include "ScopedTransaction.h"
#include "UObject/Package.h"
#include "UObject/SavePackage.h"
#include "UObject/UnrealType.h"

#define LOCTEXT_NAMESPACE "RemoveConstellationBloopWidget"

DEFINE_LOG_CATEGORY_STATIC(LogRemoveConstellationBloop, Log, All);

namespace RemoveConstellationBloop
{
	constexpr TCHAR InstantCurvePackageName[] = TEXT("/Game/Blueprints/Data/Curves/CellOutInstant");
	constexpr TCHAR InstantCurveObjectPath[] = TEXT("/Game/Blueprints/Data/Curves/CellOutInstant.CellOutInstant");
	constexpr TCHAR OriginalOutCurveObjectPath[] = TEXT("/Game/Blueprints/Data/Curves/CellOutCurve.CellOutCurve");
	constexpr TCHAR BloopComponentClassPath[] = TEXT("/Game/Blueprints/Data/Components/Grid/BPC_BloopIn.BPC_BloopIn_C");
	constexpr TCHAR CavePaintingOnePath[] = TEXT("/Game/Imported_Assets/Meshes/Set_Dressing/Cave/CavePaintings/SM_CavePainting1.SM_CavePainting1");
	constexpr TCHAR CavePaintingTwoPath[] = TEXT("/Game/Imported_Assets/Meshes/Set_Dressing/Cave/CavePaintings/SM_CavePainting2.SM_CavePainting2");
	constexpr TCHAR ConstellationMaterialRoot[] = TEXT("/Game/Imported_Assets/Meshes/Set_Dressing/Sky/Constellation/");
	constexpr TCHAR ProjectLevelsRoot[] = TEXT("/Game/Levels");

	bool HasConstellationMaterial(UMaterialInterface* Material)
	{
		TSet<const UMaterialInterface*> VisitedMaterials;
		while (Material && !VisitedMaterials.Contains(Material))
		{
			VisitedMaterials.Add(Material);
			if (Material->GetPathName().StartsWith(ConstellationMaterialRoot, ESearchCase::IgnoreCase))
			{
				return true;
			}

			const UMaterialInstance* MaterialInstance = Cast<UMaterialInstance>(Material);
			Material = MaterialInstance ? MaterialInstance->Parent : nullptr;
		}

		return false;
	}

	bool IsTargetStaticMeshComponent(const UStaticMeshComponent* StaticMeshComponent)
	{
		if (!StaticMeshComponent)
		{
			return false;
		}

		if (const UStaticMesh* StaticMesh = StaticMeshComponent->GetStaticMesh())
		{
			const FString MeshPath = StaticMesh->GetPathName();
			if (MeshPath.Equals(CavePaintingOnePath, ESearchCase::IgnoreCase)
				|| MeshPath.Equals(CavePaintingTwoPath, ESearchCase::IgnoreCase)
				|| MeshPath.Contains(TEXT("/Constellation/"), ESearchCase::IgnoreCase)
				|| StaticMesh->GetName().Contains(TEXT("Constellation"), ESearchCase::IgnoreCase))
			{
				return true;
			}
		}

		for (int32 MaterialIndex = 0; MaterialIndex < StaticMeshComponent->GetNumMaterials(); ++MaterialIndex)
		{
			if (HasConstellationMaterial(StaticMeshComponent->GetMaterial(MaterialIndex)))
			{
				return true;
			}
		}

		return false;
	}

	bool IsConfiguredAsInstant(const UCurveFloat* Curve, const float EndTime)
	{
		if (!Curve)
		{
			return false;
		}

		const TArray<FRichCurveKey>& Keys = Curve->FloatCurve.GetConstRefOfKeys();
		if (Keys.Num() != 2)
		{
			return false;
		}

		return FMath::IsNearlyEqual(Keys[0].Time, 0.0f)
			&& FMath::IsNearlyZero(Keys[0].Value)
			&& Keys[0].InterpMode == RCIM_Constant
			&& FMath::IsNearlyEqual(Keys[1].Time, EndTime)
			&& FMath::IsNearlyZero(Keys[1].Value)
			&& Keys[1].InterpMode == RCIM_Constant
			&& Curve->FloatCurve.PreInfinityExtrap == RCCE_Constant
			&& Curve->FloatCurve.PostInfinityExtrap == RCCE_Constant;
	}

	void ConfigureInstantCurve(UCurveFloat* Curve, const float EndTime)
	{
		Curve->Modify();
		Curve->FloatCurve.Reset();
		Curve->FloatCurve.PreInfinityExtrap = RCCE_Constant;
		Curve->FloatCurve.PostInfinityExtrap = RCCE_Constant;

		const FKeyHandle StartKey = Curve->FloatCurve.AddKey(0.0f, 0.0f);
		const FKeyHandle EndKey = Curve->FloatCurve.AddKey(EndTime, 0.0f);
		Curve->FloatCurve.SetKeyInterpMode(StartKey, RCIM_Constant);
		Curve->FloatCurve.SetKeyInterpMode(EndKey, RCIM_Constant);
		Curve->MarkPackageDirty();
	}
}

void FConstellationBloopEditResult::Append(const FConstellationBloopEditResult& Other)
{
	MapsProcessed += Other.MapsProcessed;
	MapsChanged += Other.MapsChanged;
	MapsFailed += Other.MapsFailed;
	ActorsScanned += Other.ActorsScanned;
	TargetActors += Other.TargetActors;
	BloopComponentsFound += Other.BloopComponentsFound;
	ComponentsChanged += Other.ComponentsChanged;
	ComponentsAlreadyInstant += Other.ComponentsAlreadyInstant;
	ComponentsMissingOutCurve += Other.ComponentsMissingOutCurve;
	TargetActorsWithoutBloop += Other.TargetActorsWithoutBloop;
	bCancelled |= Other.bCancelled;

	if (!Other.ErrorMessage.IsEmpty())
	{
		if (!ErrorMessage.IsEmpty())
		{
			ErrorMessage += TEXT(" ");
		}
		ErrorMessage += Other.ErrorMessage;
	}
}

FString FConstellationBloopEditResult::ToSummary(const bool bIncludeMapCounts) const
{
	FString Summary;
	if (bIncludeMapCounts)
	{
		Summary = FString::Printf(
			TEXT("Maps: %d processed, %d changed, %d failed. "),
			MapsProcessed,
			MapsChanged,
			MapsFailed);
	}

	Summary += FString::Printf(
		TEXT("Actors: %d scanned, %d targets. Bloop components: %d found, %d changed, %d already instant."),
		ActorsScanned,
		TargetActors,
		BloopComponentsFound,
		ComponentsChanged,
		ComponentsAlreadyInstant);

	if (TargetActorsWithoutBloop > 0)
	{
		Summary += FString::Printf(TEXT(" %d target actor(s) had no BPC_BloopIn."), TargetActorsWithoutBloop);
	}

	if (ComponentsMissingOutCurve > 0)
	{
		Summary += FString::Printf(TEXT(" %d BPC_BloopIn component(s) had no OutCurve property."), ComponentsMissingOutCurve);
	}

	if (bCancelled)
	{
		Summary += TEXT(" Cancelled; completed maps were already saved.");
	}

	if (!ErrorMessage.IsEmpty())
	{
		Summary += TEXT(" Error: ");
		Summary += ErrorMessage;
	}

	return Summary;
}

UCurveFloat* URemoveConstellationBloopWidget::EnsureInstantOutCurve(const bool bSaveAsset, FString* OutError)
{
	using namespace RemoveConstellationBloop;

	if (OutError)
	{
		OutError->Reset();
	}

	float EndTime = 0.5f;
	if (const UCurveFloat* OriginalOutCurve = LoadObject<UCurveFloat>(nullptr, OriginalOutCurveObjectPath))
	{
		const TArray<FRichCurveKey>& OriginalKeys = OriginalOutCurve->FloatCurve.GetConstRefOfKeys();
		if (!OriginalKeys.IsEmpty())
		{
			EndTime = FMath::Max(OriginalKeys.Last().Time, KINDA_SMALL_NUMBER);
		}
	}

	UCurveFloat* Curve = LoadObject<UCurveFloat>(nullptr, InstantCurveObjectPath);
	bool bNewAsset = false;
	if (!Curve)
	{
		UPackage* Package = CreatePackage(InstantCurvePackageName);
		if (!Package)
		{
			if (OutError)
			{
				*OutError = TEXT("Could not create the CellOutInstant package.");
			}
			return nullptr;
		}

		Curve = NewObject<UCurveFloat>(
			Package,
			TEXT("CellOutInstant"),
			RF_Public | RF_Standalone | RF_Transactional);
		if (!Curve)
		{
			if (OutError)
			{
				*OutError = TEXT("Could not create CellOutInstant.");
			}
			return nullptr;
		}

		FAssetRegistryModule::AssetCreated(Curve);
		bNewAsset = true;
	}

	if (!IsConfiguredAsInstant(Curve, EndTime))
	{
		ConfigureInstantCurve(Curve, EndTime);
	}

	UPackage* Package = Curve->GetOutermost();
	if (bSaveAsset && (bNewAsset || Package->IsDirty()))
	{
		const FString Filename = FPackageName::LongPackageNameToFilename(
			InstantCurvePackageName,
			FPackageName::GetAssetPackageExtension());

		FSavePackageArgs SaveArgs;
		SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
		SaveArgs.SaveFlags = SAVE_NoError;
		if (!UPackage::SavePackage(Package, Curve, *Filename, SaveArgs))
		{
			if (OutError)
			{
				*OutError = FString::Printf(TEXT("Could not save %s."), *Filename);
			}
			return nullptr;
		}
	}

	return Curve;
}

FConstellationBloopEditResult URemoveConstellationBloopWidget::ApplyToWorld(UWorld* World, UCurveFloat* InstantCurve)
{
	using namespace RemoveConstellationBloop;

	FConstellationBloopEditResult Result;
	if (!World || !InstantCurve)
	{
		Result.ErrorMessage = TEXT("No editable world or instant curve was available.");
		return Result;
	}

	UClass* BloopComponentClass = LoadClass<UActorComponent>(nullptr, BloopComponentClassPath);
	if (!BloopComponentClass)
	{
		Result.ErrorMessage = FString::Printf(TEXT("Could not load %s."), BloopComponentClassPath);
		return Result;
	}

	FObjectPropertyBase* OutCurveProperty = FindFProperty<FObjectPropertyBase>(BloopComponentClass, TEXT("OutCurve"));

	for (TActorIterator<AActor> ActorIterator(World); ActorIterator; ++ActorIterator)
	{
		AActor* Actor = *ActorIterator;
		if (!IsValid(Actor) || Actor->HasAnyFlags(RF_Transient))
		{
			continue;
		}

		++Result.ActorsScanned;

		TInlineComponentArray<UStaticMeshComponent*> StaticMeshComponents(Actor);
		const bool bIsTargetActor = StaticMeshComponents.ContainsByPredicate(
			[](const UStaticMeshComponent* Component)
			{
				return IsTargetStaticMeshComponent(Component);
			});

		if (!bIsTargetActor)
		{
			continue;
		}

		++Result.TargetActors;
		bool bFoundBloopComponent = false;
		TInlineComponentArray<UActorComponent*> ActorComponents(Actor);
		for (UActorComponent* Component : ActorComponents)
		{
			if (!IsValid(Component) || !Component->IsA(BloopComponentClass))
			{
				continue;
			}

			bFoundBloopComponent = true;
			++Result.BloopComponentsFound;
			if (!OutCurveProperty)
			{
				++Result.ComponentsMissingOutCurve;
				continue;
			}

			if (OutCurveProperty->GetObjectPropertyValue_InContainer(Component) == InstantCurve)
			{
				++Result.ComponentsAlreadyInstant;
				continue;
			}

			Actor->Modify();
			Component->Modify();
			OutCurveProperty->SetObjectPropertyValue_InContainer(Component, InstantCurve);
			Component->MarkPackageDirty();
			Actor->MarkPackageDirty();
			++Result.ComponentsChanged;
		}

		if (!bFoundBloopComponent)
		{
			++Result.TargetActorsWithoutBloop;
		}
	}

	Result.MapsProcessed = 1;
	Result.MapsChanged = Result.ComponentsChanged > 0 ? 1 : 0;
	return Result;
}

FConstellationBloopEditResult URemoveConstellationBloopWidget::ApplyToCurrentLevel()
{
	FConstellationBloopEditResult Result;
	if (!GEditor || GEditor->PlayWorld)
	{
		Result.ErrorMessage = TEXT("Stop Play In Editor before changing level instances.");
		return Result;
	}

	UWorld* World = GEditor->GetEditorWorldContext().World();
	if (!World)
	{
		Result.ErrorMessage = TEXT("No editor world is open.");
		return Result;
	}

	FString CurveError;
	UCurveFloat* InstantCurve = EnsureInstantOutCurve(true, &CurveError);
	if (!InstantCurve)
	{
		Result.ErrorMessage = CurveError;
		return Result;
	}

	FScopedTransaction Transaction(LOCTEXT("ApplyInstantBloopCurrentLevel", "Remove constellation bloop from current level"));
	Result = ApplyToWorld(World, InstantCurve);
	if (Result.ComponentsChanged == 0)
	{
		Transaction.Cancel();
	}

	UE_LOG(LogRemoveConstellationBloop, Display, TEXT("%s"), *Result.ToSummary(false));
	return Result;
}

FConstellationBloopEditResult URemoveConstellationBloopWidget::ApplyToAllProjectLevels()
{
	using namespace RemoveConstellationBloop;

	FConstellationBloopEditResult Result;
	if (!GEditor || GEditor->PlayWorld)
	{
		Result.ErrorMessage = TEXT("Stop Play In Editor before changing project levels.");
		return Result;
	}

	const EAppReturnType::Type Confirmation = FMessageDialog::Open(
		EAppMsgType::YesNo,
		LOCTEXT(
			"ConfirmApplyAllProjectLevels",
			"This will load every map under /Game/Levels, update matching level instances, and save each changed map. The current map will be restored when the operation finishes.\n\nContinue?"),
		LOCTEXT("ConfirmApplyAllProjectLevelsTitle", "Remove Constellation Bloop"));
	if (Confirmation != EAppReturnType::Yes)
	{
		Result.bCancelled = true;
		return Result;
	}

	ULevelEditorSubsystem* LevelEditorSubsystem = GEditor->GetEditorSubsystem<ULevelEditorSubsystem>();
	UWorld* OriginalWorld = GEditor->GetEditorWorldContext().World();
	if (!LevelEditorSubsystem || !OriginalWorld)
	{
		Result.ErrorMessage = TEXT("The level editor subsystem or current editor world was unavailable.");
		return Result;
	}

	const FString OriginalMapPath = OriginalWorld->GetOutermost()->GetName();
	if (!OriginalMapPath.StartsWith(TEXT("/Game/")))
	{
		Result.ErrorMessage = TEXT("Save the current map into /Game before running the project-wide action.");
		return Result;
	}

	if (!LevelEditorSubsystem->SaveAllDirtyLevels())
	{
		Result.ErrorMessage = TEXT("The current dirty level could not be saved, so no maps were switched.");
		return Result;
	}

	FString CurveError;
	UCurveFloat* InstantCurve = EnsureInstantOutCurve(true, &CurveError);
	if (!InstantCurve)
	{
		Result.ErrorMessage = CurveError;
		return Result;
	}

	FARFilter MapFilter;
	MapFilter.PackagePaths.Add(FName(ProjectLevelsRoot));
	MapFilter.ClassPaths.Add(UWorld::StaticClass()->GetClassPathName());
	MapFilter.bRecursivePaths = true;
	MapFilter.bRecursiveClasses = true;

	TArray<FAssetData> MapAssets;
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
	AssetRegistryModule.Get().GetAssets(MapFilter, MapAssets);
	MapAssets.Sort(
		[](const FAssetData& Left, const FAssetData& Right)
		{
			return Left.PackageName.LexicalLess(Right.PackageName);
		});

	if (MapAssets.IsEmpty())
	{
		Result.ErrorMessage = TEXT("No maps were found under /Game/Levels.");
		return Result;
	}

	bool bLeaveCurrentMapOpen = false;
	FString CurrentMapPath = OriginalMapPath;
	FScopedSlowTask SlowTask(MapAssets.Num(), LOCTEXT("ApplyingInstantBloopAllMaps", "Removing constellation bloop from project levels"));
	SlowTask.MakeDialog(true);

	for (const FAssetData& MapAsset : MapAssets)
	{
		if (SlowTask.ShouldCancel())
		{
			Result.bCancelled = true;
			break;
		}

		const FString MapPath = MapAsset.PackageName.ToString();
		SlowTask.EnterProgressFrame(1.0f, FText::FromString(MapPath));
		if (!MapPath.Equals(CurrentMapPath, ESearchCase::CaseSensitive))
		{
			if (!LevelEditorSubsystem->LoadLevel(MapPath))
			{
				++Result.MapsFailed;
				UE_LOG(LogRemoveConstellationBloop, Error, TEXT("Could not load map %s."), *MapPath);
				continue;
			}
			CurrentMapPath = MapPath;
		}

		UWorld* World = GEditor->GetEditorWorldContext().World();
		FConstellationBloopEditResult MapResult = ApplyToWorld(World, InstantCurve);
		Result.Append(MapResult);

		if (MapResult.ComponentsChanged > 0 && !LevelEditorSubsystem->SaveAllDirtyLevels())
		{
			++Result.MapsFailed;
			Result.ErrorMessage = FString::Printf(
				TEXT("Saving %s failed. Processing stopped and that map was left open so no edits would be discarded."),
				*MapPath);
			bLeaveCurrentMapOpen = true;
			break;
		}
	}

	if (!bLeaveCurrentMapOpen && !CurrentMapPath.Equals(OriginalMapPath, ESearchCase::CaseSensitive))
	{
		if (!LevelEditorSubsystem->LoadLevel(OriginalMapPath))
		{
			++Result.MapsFailed;
			if (!Result.ErrorMessage.IsEmpty())
			{
				Result.ErrorMessage += TEXT(" ");
			}
			Result.ErrorMessage += FString::Printf(TEXT("Could not restore the original map %s."), *OriginalMapPath);
		}
	}

	UE_LOG(LogRemoveConstellationBloop, Display, TEXT("%s"), *Result.ToSummary(true));
	return Result;
}

void URemoveConstellationBloopWidget::NativeConstruct()
{
	Super::NativeConstruct();

	CurrentLevelButtonInstance = WidgetTree ? WidgetTree->FindWidget<UButton>(TEXT("ApplyCurrentLevelButton")) : nullptr;
	AllProjectLevelsButtonInstance = WidgetTree ? WidgetTree->FindWidget<UButton>(TEXT("ApplyAllProjectLevelsButton")) : nullptr;
	StatusTextInstance = WidgetTree ? WidgetTree->FindWidget<UTextBlock>(TEXT("StatusText")) : nullptr;

	if (CurrentLevelButtonInstance)
	{
		CurrentLevelButtonInstance->OnClicked.RemoveDynamic(this, &ThisClass::HandleApplyToCurrentLevel);
		CurrentLevelButtonInstance->OnClicked.AddDynamic(this, &ThisClass::HandleApplyToCurrentLevel);
	}

	if (AllProjectLevelsButtonInstance)
	{
		AllProjectLevelsButtonInstance->OnClicked.RemoveDynamic(this, &ThisClass::HandleApplyToAllProjectLevels);
		AllProjectLevelsButtonInstance->OnClicked.AddDynamic(this, &ThisClass::HandleApplyToAllProjectLevels);
	}
}

void URemoveConstellationBloopWidget::NativeDestruct()
{
	if (CurrentLevelButtonInstance)
	{
		CurrentLevelButtonInstance->OnClicked.RemoveDynamic(this, &ThisClass::HandleApplyToCurrentLevel);
	}

	if (AllProjectLevelsButtonInstance)
	{
		AllProjectLevelsButtonInstance->OnClicked.RemoveDynamic(this, &ThisClass::HandleApplyToAllProjectLevels);
	}

	Super::NativeDestruct();
}

void URemoveConstellationBloopWidget::HandleApplyToCurrentLevel()
{
	SetStatus(ApplyToCurrentLevel(), false);
}

void URemoveConstellationBloopWidget::HandleApplyToAllProjectLevels()
{
	SetStatus(ApplyToAllProjectLevels(), true);
}

void URemoveConstellationBloopWidget::SetStatus(const FConstellationBloopEditResult& Result, const bool bIncludeMapCounts)
{
	if (StatusTextInstance)
	{
		StatusTextInstance->SetText(FText::FromString(Result.ToSummary(bIncludeMapCounts)));
	}
}

#undef LOCTEXT_NAMESPACE

#endif

#include "Utilities/RemoveConstellationBloopWidget.h"

void FConstellationBloopEditResult::Append(const FConstellationBloopEditResult& Other)
{
	MapsProcessed += Other.MapsProcessed;
	MapsChanged += Other.MapsChanged;
	MapsFailed += Other.MapsFailed;
	ActorsScanned += Other.ActorsScanned;
	TargetActors += Other.TargetActors;
	BloopComponentsFound += Other.BloopComponentsFound;
	ComponentsChanged += Other.ComponentsChanged;
	ComponentsAlreadyInstant += Other.ComponentsAlreadyInstant;
	ComponentsMissingOutCurve += Other.ComponentsMissingOutCurve;
	TargetActorsWithoutBloop += Other.TargetActorsWithoutBloop;
	bCancelled |= Other.bCancelled;
}

FString FConstellationBloopEditResult::ToSummary(const bool bIncludeMapCounts) const
{
	(void)bIncludeMapCounts;
	return ErrorMessage;
}

FConstellationBloopEditResult URemoveConstellationBloopWidget::ApplyToCurrentLevel()
{
	FConstellationBloopEditResult Result;
	Result.ErrorMessage = TEXT("Deprecated: the constellation bloop migration has already been applied.");
	return Result;
}

FConstellationBloopEditResult URemoveConstellationBloopWidget::ApplyToAllProjectLevels()
{
	FConstellationBloopEditResult Result;
	Result.ErrorMessage = TEXT("Deprecated: the constellation bloop migration has already been applied.");
	return Result;
}
