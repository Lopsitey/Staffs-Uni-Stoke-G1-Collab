// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LevelData.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLevelData() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
G1COLLAB_API UClass* Z_Construct_UClass_ULevelDataAsset();
G1COLLAB_API UClass* Z_Construct_UClass_ULevelDataAsset_NoRegister();
G1COLLAB_API UScriptStruct* Z_Construct_UScriptStruct_FLevelCellData();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
UPackage* Z_Construct_UPackage__Script_G1Collab();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FLevelCellData ****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FLevelCellData;
class UScriptStruct* FLevelCellData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FLevelCellData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FLevelCellData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLevelCellData, (UObject*)Z_Construct_UPackage__Script_G1Collab(), TEXT("LevelCellData"));
	}
	return Z_Registration_Info_UScriptStruct_FLevelCellData.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FLevelCellData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/LevelData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_cellPosition_MetaData[] = {
		{ "Category", "LevelCellData" },
		{ "ModuleRelativePath", "Public/LevelData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_cellTags_MetaData[] = {
		{ "Category", "LevelCellData" },
		{ "ModuleRelativePath", "Public/LevelData.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_cellPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_cellTags;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLevelCellData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FLevelCellData_Statics::NewProp_cellPosition = { "cellPosition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLevelCellData, cellPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_cellPosition_MetaData), NewProp_cellPosition_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FLevelCellData_Statics::NewProp_cellTags = { "cellTags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLevelCellData, cellTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_cellTags_MetaData), NewProp_cellTags_MetaData) }; // 2104890724
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLevelCellData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLevelCellData_Statics::NewProp_cellPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLevelCellData_Statics::NewProp_cellTags,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLevelCellData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLevelCellData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_G1Collab,
	nullptr,
	&NewStructOps,
	"LevelCellData",
	Z_Construct_UScriptStruct_FLevelCellData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLevelCellData_Statics::PropPointers),
	sizeof(FLevelCellData),
	alignof(FLevelCellData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLevelCellData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FLevelCellData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FLevelCellData()
{
	if (!Z_Registration_Info_UScriptStruct_FLevelCellData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FLevelCellData.InnerSingleton, Z_Construct_UScriptStruct_FLevelCellData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FLevelCellData.InnerSingleton;
}
// ********** End ScriptStruct FLevelCellData ******************************************************

// ********** Begin Class ULevelDataAsset **********************************************************
void ULevelDataAsset::StaticRegisterNativesULevelDataAsset()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULevelDataAsset;
UClass* ULevelDataAsset::GetPrivateStaticClass()
{
	using TClass = ULevelDataAsset;
	if (!Z_Registration_Info_UClass_ULevelDataAsset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LevelDataAsset"),
			Z_Registration_Info_UClass_ULevelDataAsset.InnerSingleton,
			StaticRegisterNativesULevelDataAsset,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ULevelDataAsset.InnerSingleton;
}
UClass* Z_Construct_UClass_ULevelDataAsset_NoRegister()
{
	return ULevelDataAsset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULevelDataAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "LevelData.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/LevelData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_cellData_MetaData[] = {
		{ "Category", "LevelDataAsset" },
		{ "ModuleRelativePath", "Public/LevelData.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_cellData_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_cellData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULevelDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULevelDataAsset_Statics::NewProp_cellData_Inner = { "cellData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FLevelCellData, METADATA_PARAMS(0, nullptr) }; // 1738160662
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULevelDataAsset_Statics::NewProp_cellData = { "cellData", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULevelDataAsset, cellData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_cellData_MetaData), NewProp_cellData_MetaData) }; // 1738160662
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULevelDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULevelDataAsset_Statics::NewProp_cellData_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULevelDataAsset_Statics::NewProp_cellData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULevelDataAsset_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULevelDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_G1Collab,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULevelDataAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULevelDataAsset_Statics::ClassParams = {
	&ULevelDataAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ULevelDataAsset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ULevelDataAsset_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULevelDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_ULevelDataAsset_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULevelDataAsset()
{
	if (!Z_Registration_Info_UClass_ULevelDataAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULevelDataAsset.OuterSingleton, Z_Construct_UClass_ULevelDataAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULevelDataAsset.OuterSingleton;
}
ULevelDataAsset::ULevelDataAsset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULevelDataAsset);
ULevelDataAsset::~ULevelDataAsset() {}
// ********** End Class ULevelDataAsset ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_LevelData_h__Script_G1Collab_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FLevelCellData::StaticStruct, Z_Construct_UScriptStruct_FLevelCellData_Statics::NewStructOps, TEXT("LevelCellData"), &Z_Registration_Info_UScriptStruct_FLevelCellData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLevelCellData), 1738160662U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULevelDataAsset, ULevelDataAsset::StaticClass, TEXT("ULevelDataAsset"), &Z_Registration_Info_UClass_ULevelDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULevelDataAsset), 872893932U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_LevelData_h__Script_G1Collab_2841042451(TEXT("/Script/G1Collab"),
	Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_LevelData_h__Script_G1Collab_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_LevelData_h__Script_G1Collab_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_LevelData_h__Script_G1Collab_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_LevelData_h__Script_G1Collab_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
