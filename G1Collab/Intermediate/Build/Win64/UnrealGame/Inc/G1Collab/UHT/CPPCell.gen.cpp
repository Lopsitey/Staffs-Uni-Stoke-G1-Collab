// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "G1Collab/CPPCell.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeCPPCell() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
G1COLLAB_API UClass* Z_Construct_UClass_UCPPCell();
G1COLLAB_API UClass* Z_Construct_UClass_UCPPCell_NoRegister();
G1COLLAB_API UClass* Z_Construct_UClass_UICell_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
UPackage* Z_Construct_UPackage__Script_G1Collab();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCPPCell *****************************************************************
void UCPPCell::StaticRegisterNativesUCPPCell()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCPPCell;
UClass* UCPPCell::GetPrivateStaticClass()
{
	using TClass = UCPPCell;
	if (!Z_Registration_Info_UClass_UCPPCell.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("CPPCell"),
			Z_Registration_Info_UClass_UCPPCell.InnerSingleton,
			StaticRegisterNativesUCPPCell,
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
	return Z_Registration_Info_UClass_UCPPCell.InnerSingleton;
}
UClass* Z_Construct_UClass_UCPPCell_NoRegister()
{
	return UCPPCell::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCPPCell_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "CPPCell.h" },
		{ "ModuleRelativePath", "CPPCell.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_cellTags_MetaData[] = {
		{ "Category", "CPPCell" },
		{ "ModuleRelativePath", "CPPCell.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_cellTags;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCPPCell>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCPPCell_Statics::NewProp_cellTags = { "cellTags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCPPCell, cellTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_cellTags_MetaData), NewProp_cellTags_MetaData) }; // 2104890724
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCPPCell_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCPPCell_Statics::NewProp_cellTags,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCPPCell_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCPPCell_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_G1Collab,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCPPCell_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UCPPCell_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UICell_NoRegister, (int32)VTABLE_OFFSET(UCPPCell, IICell), false },  // 3568048417
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCPPCell_Statics::ClassParams = {
	&UCPPCell::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCPPCell_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCPPCell_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCPPCell_Statics::Class_MetaDataParams), Z_Construct_UClass_UCPPCell_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCPPCell()
{
	if (!Z_Registration_Info_UClass_UCPPCell.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCPPCell.OuterSingleton, Z_Construct_UClass_UCPPCell_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCPPCell.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCPPCell);
UCPPCell::~UCPPCell() {}
// ********** End Class UCPPCell *******************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_CPPCell_h__Script_G1Collab_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCPPCell, UCPPCell::StaticClass, TEXT("UCPPCell"), &Z_Registration_Info_UClass_UCPPCell, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCPPCell), 4085541701U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_CPPCell_h__Script_G1Collab_1220516563(TEXT("/Script/G1Collab"),
	Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_CPPCell_h__Script_G1Collab_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_CPPCell_h__Script_G1Collab_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
