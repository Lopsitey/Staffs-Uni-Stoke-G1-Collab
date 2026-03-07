// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "G1Collab/UGridDataFactory.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeUGridDataFactory() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
G1COLLAB_API UClass* Z_Construct_UClass_UCPPCell_NoRegister();
G1COLLAB_API UClass* Z_Construct_UClass_UUGridDataFactory();
G1COLLAB_API UClass* Z_Construct_UClass_UUGridDataFactory_NoRegister();
UPackage* Z_Construct_UPackage__Script_G1Collab();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UUGridDataFactory Function ConstructGrid *********************************
struct Z_Construct_UFunction_UUGridDataFactory_ConstructGrid_Statics
{
	struct UGridDataFactory_eventConstructGrid_Parms
	{
		UObject* Leveldata;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UGridDataFactory.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Leveldata;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGridDataFactory_ConstructGrid_Statics::NewProp_Leveldata = { "Leveldata", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGridDataFactory_eventConstructGrid_Parms, Leveldata), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGridDataFactory_ConstructGrid_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGridDataFactory_ConstructGrid_Statics::NewProp_Leveldata,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGridDataFactory_ConstructGrid_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGridDataFactory_ConstructGrid_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UUGridDataFactory, nullptr, "ConstructGrid", Z_Construct_UFunction_UUGridDataFactory_ConstructGrid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGridDataFactory_ConstructGrid_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGridDataFactory_ConstructGrid_Statics::UGridDataFactory_eventConstructGrid_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGridDataFactory_ConstructGrid_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGridDataFactory_ConstructGrid_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UUGridDataFactory_ConstructGrid_Statics::UGridDataFactory_eventConstructGrid_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGridDataFactory_ConstructGrid()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGridDataFactory_ConstructGrid_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGridDataFactory::execConstructGrid)
{
	P_GET_OBJECT(UObject,Z_Param_Leveldata);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ConstructGrid(Z_Param_Leveldata);
	P_NATIVE_END;
}
// ********** End Class UUGridDataFactory Function ConstructGrid ***********************************

// ********** Begin Class UUGridDataFactory Function RetrieveCellInformation ***********************
struct Z_Construct_UFunction_UUGridDataFactory_RetrieveCellInformation_Statics
{
	struct UGridDataFactory_eventRetrieveCellInformation_Parms
	{
		FVector2D key;
		UCPPCell* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UGridDataFactory.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_key;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UUGridDataFactory_RetrieveCellInformation_Statics::NewProp_key = { "key", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGridDataFactory_eventRetrieveCellInformation_Parms, key), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUGridDataFactory_RetrieveCellInformation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGridDataFactory_eventRetrieveCellInformation_Parms, ReturnValue), Z_Construct_UClass_UCPPCell_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUGridDataFactory_RetrieveCellInformation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGridDataFactory_RetrieveCellInformation_Statics::NewProp_key,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUGridDataFactory_RetrieveCellInformation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGridDataFactory_RetrieveCellInformation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUGridDataFactory_RetrieveCellInformation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UUGridDataFactory, nullptr, "RetrieveCellInformation", Z_Construct_UFunction_UUGridDataFactory_RetrieveCellInformation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUGridDataFactory_RetrieveCellInformation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUGridDataFactory_RetrieveCellInformation_Statics::UGridDataFactory_eventRetrieveCellInformation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUGridDataFactory_RetrieveCellInformation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUGridDataFactory_RetrieveCellInformation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UUGridDataFactory_RetrieveCellInformation_Statics::UGridDataFactory_eventRetrieveCellInformation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUGridDataFactory_RetrieveCellInformation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUGridDataFactory_RetrieveCellInformation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUGridDataFactory::execRetrieveCellInformation)
{
	P_GET_STRUCT(FVector2D,Z_Param_key);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UCPPCell**)Z_Param__Result=P_THIS->RetrieveCellInformation(Z_Param_key);
	P_NATIVE_END;
}
// ********** End Class UUGridDataFactory Function RetrieveCellInformation *************************

// ********** Begin Class UUGridDataFactory ********************************************************
void UUGridDataFactory::StaticRegisterNativesUUGridDataFactory()
{
	UClass* Class = UUGridDataFactory::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ConstructGrid", &UUGridDataFactory::execConstructGrid },
		{ "RetrieveCellInformation", &UUGridDataFactory::execRetrieveCellInformation },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UUGridDataFactory;
UClass* UUGridDataFactory::GetPrivateStaticClass()
{
	using TClass = UUGridDataFactory;
	if (!Z_Registration_Info_UClass_UUGridDataFactory.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("UGridDataFactory"),
			Z_Registration_Info_UClass_UUGridDataFactory.InnerSingleton,
			StaticRegisterNativesUUGridDataFactory,
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
	return Z_Registration_Info_UClass_UUGridDataFactory.InnerSingleton;
}
UClass* Z_Construct_UClass_UUGridDataFactory_NoRegister()
{
	return UUGridDataFactory::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UUGridDataFactory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "UGridDataFactory.h" },
		{ "ModuleRelativePath", "UGridDataFactory.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_cellInformation_MetaData[] = {
		{ "ModuleRelativePath", "UGridDataFactory.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_cellInformation_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_cellInformation_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_cellInformation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UUGridDataFactory_ConstructGrid, "ConstructGrid" }, // 3833136306
		{ &Z_Construct_UFunction_UUGridDataFactory_RetrieveCellInformation, "RetrieveCellInformation" }, // 2876821427
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUGridDataFactory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUGridDataFactory_Statics::NewProp_cellInformation_ValueProp = { "cellInformation", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UCPPCell_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUGridDataFactory_Statics::NewProp_cellInformation_Key_KeyProp = { "cellInformation_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UUGridDataFactory_Statics::NewProp_cellInformation = { "cellInformation", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUGridDataFactory, cellInformation), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_cellInformation_MetaData), NewProp_cellInformation_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUGridDataFactory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGridDataFactory_Statics::NewProp_cellInformation_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGridDataFactory_Statics::NewProp_cellInformation_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUGridDataFactory_Statics::NewProp_cellInformation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGridDataFactory_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UUGridDataFactory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_G1Collab,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUGridDataFactory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UUGridDataFactory_Statics::ClassParams = {
	&UUGridDataFactory::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UUGridDataFactory_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UUGridDataFactory_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUGridDataFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_UUGridDataFactory_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UUGridDataFactory()
{
	if (!Z_Registration_Info_UClass_UUGridDataFactory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUGridDataFactory.OuterSingleton, Z_Construct_UClass_UUGridDataFactory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UUGridDataFactory.OuterSingleton;
}
UUGridDataFactory::UUGridDataFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UUGridDataFactory);
UUGridDataFactory::~UUGridDataFactory() {}
// ********** End Class UUGridDataFactory **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_UGridDataFactory_h__Script_G1Collab_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UUGridDataFactory, UUGridDataFactory::StaticClass, TEXT("UUGridDataFactory"), &Z_Registration_Info_UClass_UUGridDataFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUGridDataFactory), 3037418062U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_UGridDataFactory_h__Script_G1Collab_1738179141(TEXT("/Script/G1Collab"),
	Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_UGridDataFactory_h__Script_G1Collab_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_UGridDataFactory_h__Script_G1Collab_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
