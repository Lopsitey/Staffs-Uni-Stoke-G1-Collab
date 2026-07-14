#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "RemoveConstellationBloopWidget.generated.h"

USTRUCT(BlueprintType)
struct G1COLLABEDITOR_API FConstellationBloopEditResult
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Constellation Bloop")
	int32 MapsProcessed = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Constellation Bloop")
	int32 MapsChanged = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Constellation Bloop")
	int32 MapsFailed = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Constellation Bloop")
	int32 ActorsScanned = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Constellation Bloop")
	int32 TargetActors = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Constellation Bloop")
	int32 BloopComponentsFound = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Constellation Bloop")
	int32 ComponentsChanged = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Constellation Bloop")
	int32 ComponentsAlreadyInstant = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Constellation Bloop")
	int32 ComponentsMissingOutCurve = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Constellation Bloop")
	int32 TargetActorsWithoutBloop = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Constellation Bloop")
	bool bCancelled = false;

	UPROPERTY(BlueprintReadOnly, Category = "Constellation Bloop")
	FString ErrorMessage;

	void Append(const FConstellationBloopEditResult& Other);
	FString ToSummary(bool bIncludeMapCounts) const;
};

/** Deprecated after CellOutInstant was applied to the project levels. */
UCLASS(BlueprintType, meta = (DisplayName = "DEPRECATED - Remove Constellation Bloop", DeprecationMessage = "This one-use migration utility has already been applied and is retained only for reference."))
class G1COLLABEDITOR_API URemoveConstellationBloopWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Constellation Bloop", meta = (DeprecatedFunction, DeprecationMessage = "The constellation bloop migration has already been applied."))
	FConstellationBloopEditResult ApplyToCurrentLevel();

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Constellation Bloop", meta = (DeprecatedFunction, DeprecationMessage = "The constellation bloop migration has already been applied."))
	FConstellationBloopEditResult ApplyToAllProjectLevels();
};
