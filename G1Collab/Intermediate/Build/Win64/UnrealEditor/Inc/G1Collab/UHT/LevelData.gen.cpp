// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LevelData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLevelData() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
G1COLLAB_API UClass* Z_Construct_UClass_UMyClass();
G1COLLAB_API UClass* Z_Construct_UClass_UMyClass_NoRegister();
UPackage* Z_Construct_UPackage__Script_G1Collab();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UMyClass *****************************************************************
void UMyClass::StaticRegisterNativesUMyClass()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UMyClass;
UClass* UMyClass::GetPrivateStaticClass()
{
	using TClass = UMyClass;
	if (!Z_Registration_Info_UClass_UMyClass.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("MyClass"),
			Z_Registration_Info_UClass_UMyClass.InnerSingleton,
			StaticRegisterNativesUMyClass,
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
	return Z_Registration_Info_UClass_UMyClass.InnerSingleton;
}
UClass* Z_Construct_UClass_UMyClass_NoRegister()
{
	return UMyClass::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UMyClass_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "LevelData.h" },
		{ "ModuleRelativePath", "Public/LevelData.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyClass>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMyClass_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_G1Collab,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyClass_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyClass_Statics::ClassParams = {
	&UMyClass::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyClass_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyClass_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMyClass()
{
	if (!Z_Registration_Info_UClass_UMyClass.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyClass.OuterSingleton, Z_Construct_UClass_UMyClass_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyClass.OuterSingleton;
}
UMyClass::UMyClass(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMyClass);
UMyClass::~UMyClass() {}
// ********** End Class UMyClass *******************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_LevelData_h__Script_G1Collab_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMyClass, UMyClass::StaticClass, TEXT("UMyClass"), &Z_Registration_Info_UClass_UMyClass, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyClass), 521949547U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_LevelData_h__Script_G1Collab_3652866552(TEXT("/Script/G1Collab"),
	Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_LevelData_h__Script_G1Collab_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_LevelData_h__Script_G1Collab_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
