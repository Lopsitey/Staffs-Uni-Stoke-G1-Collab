// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Grid/UGridVisualFactory.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeUGridVisualFactory() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
G1COLLAB_API UClass* Z_Construct_UClass_AUGridVisualFactory();
G1COLLAB_API UClass* Z_Construct_UClass_AUGridVisualFactory_NoRegister();
UPackage* Z_Construct_UPackage__Script_G1Collab();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AUGridVisualFactory ******************************************************
void AUGridVisualFactory::StaticRegisterNativesAUGridVisualFactory()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_AUGridVisualFactory;
UClass* AUGridVisualFactory::GetPrivateStaticClass()
{
	using TClass = AUGridVisualFactory;
	if (!Z_Registration_Info_UClass_AUGridVisualFactory.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("UGridVisualFactory"),
			Z_Registration_Info_UClass_AUGridVisualFactory.InnerSingleton,
			StaticRegisterNativesAUGridVisualFactory,
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
	return Z_Registration_Info_UClass_AUGridVisualFactory.InnerSingleton;
}
UClass* Z_Construct_UClass_AUGridVisualFactory_NoRegister()
{
	return AUGridVisualFactory::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AUGridVisualFactory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Grid/UGridVisualFactory.h" },
		{ "ModuleRelativePath", "Public/Grid/UGridVisualFactory.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUGridVisualFactory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AUGridVisualFactory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_G1Collab,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUGridVisualFactory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AUGridVisualFactory_Statics::ClassParams = {
	&AUGridVisualFactory::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUGridVisualFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_AUGridVisualFactory_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AUGridVisualFactory()
{
	if (!Z_Registration_Info_UClass_AUGridVisualFactory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AUGridVisualFactory.OuterSingleton, Z_Construct_UClass_AUGridVisualFactory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AUGridVisualFactory.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AUGridVisualFactory);
AUGridVisualFactory::~AUGridVisualFactory() {}
// ********** End Class AUGridVisualFactory ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_Grid_UGridVisualFactory_h__Script_G1Collab_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AUGridVisualFactory, AUGridVisualFactory::StaticClass, TEXT("AUGridVisualFactory"), &Z_Registration_Info_UClass_AUGridVisualFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUGridVisualFactory), 4140033670U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_Grid_UGridVisualFactory_h__Script_G1Collab_4125068624(TEXT("/Script/G1Collab"),
	Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_Grid_UGridVisualFactory_h__Script_G1Collab_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_Grid_UGridVisualFactory_h__Script_G1Collab_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
