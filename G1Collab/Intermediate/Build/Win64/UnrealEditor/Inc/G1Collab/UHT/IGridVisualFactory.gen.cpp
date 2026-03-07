// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IGridVisualFactory.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeIGridVisualFactory() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
G1COLLAB_API UClass* Z_Construct_UClass_UIGridVisualFactory();
G1COLLAB_API UClass* Z_Construct_UClass_UIGridVisualFactory_NoRegister();
UPackage* Z_Construct_UPackage__Script_G1Collab();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UIGridVisualFactory Function ConstructVisualCells ********************
struct IGridVisualFactory_eventConstructVisualCells_Parms
{
	TMap<FVector2D,UObject*> gridData;
};
void IIGridVisualFactory::ConstructVisualCells(TMap<FVector2D,UObject*> const& gridData)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ConstructVisualCells instead.");
}
static FName NAME_UIGridVisualFactory_ConstructVisualCells = FName(TEXT("ConstructVisualCells"));
void IIGridVisualFactory::Execute_ConstructVisualCells(UObject* O, TMap<FVector2D,UObject*> const& gridData)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UIGridVisualFactory::StaticClass()));
	IGridVisualFactory_eventConstructVisualCells_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UIGridVisualFactory_ConstructVisualCells);
	if (Func)
	{
		Parms.gridData=gridData;
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IIGridVisualFactory*)(O->GetNativeInterfaceAddress(UIGridVisualFactory::StaticClass())))
	{
		I->ConstructVisualCells_Implementation(gridData);
	}
}
struct Z_Construct_UFunction_UIGridVisualFactory_ConstructVisualCells_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/IGridVisualFactory.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_gridData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_gridData_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_gridData_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_gridData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UIGridVisualFactory_ConstructVisualCells_Statics::NewProp_gridData_ValueProp = { "gridData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UIGridVisualFactory_ConstructVisualCells_Statics::NewProp_gridData_Key_KeyProp = { "gridData_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UIGridVisualFactory_ConstructVisualCells_Statics::NewProp_gridData = { "gridData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(IGridVisualFactory_eventConstructVisualCells_Parms, gridData), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_gridData_MetaData), NewProp_gridData_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UIGridVisualFactory_ConstructVisualCells_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UIGridVisualFactory_ConstructVisualCells_Statics::NewProp_gridData_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UIGridVisualFactory_ConstructVisualCells_Statics::NewProp_gridData_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UIGridVisualFactory_ConstructVisualCells_Statics::NewProp_gridData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UIGridVisualFactory_ConstructVisualCells_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UIGridVisualFactory_ConstructVisualCells_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UIGridVisualFactory, nullptr, "ConstructVisualCells", Z_Construct_UFunction_UIGridVisualFactory_ConstructVisualCells_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UIGridVisualFactory_ConstructVisualCells_Statics::PropPointers), sizeof(IGridVisualFactory_eventConstructVisualCells_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UIGridVisualFactory_ConstructVisualCells_Statics::Function_MetaDataParams), Z_Construct_UFunction_UIGridVisualFactory_ConstructVisualCells_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(IGridVisualFactory_eventConstructVisualCells_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UIGridVisualFactory_ConstructVisualCells()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UIGridVisualFactory_ConstructVisualCells_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IIGridVisualFactory::execConstructVisualCells)
{
	P_GET_TMAP_REF(FVector2D,UObject*,Z_Param_Out_gridData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ConstructVisualCells_Implementation(Z_Param_Out_gridData);
	P_NATIVE_END;
}
// ********** End Interface UIGridVisualFactory Function ConstructVisualCells **********************

// ********** Begin Interface UIGridVisualFactory Function UpdateVisualCell ************************
struct IGridVisualFactory_eventUpdateVisualCell_Parms
{
	FVector2D Cellpos;
};
void IIGridVisualFactory::UpdateVisualCell(FVector2D Cellpos)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_UpdateVisualCell instead.");
}
static FName NAME_UIGridVisualFactory_UpdateVisualCell = FName(TEXT("UpdateVisualCell"));
void IIGridVisualFactory::Execute_UpdateVisualCell(UObject* O, FVector2D Cellpos)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UIGridVisualFactory::StaticClass()));
	IGridVisualFactory_eventUpdateVisualCell_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UIGridVisualFactory_UpdateVisualCell);
	if (Func)
	{
		Parms.Cellpos=Cellpos;
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IIGridVisualFactory*)(O->GetNativeInterfaceAddress(UIGridVisualFactory::StaticClass())))
	{
		I->UpdateVisualCell_Implementation(Cellpos);
	}
}
struct Z_Construct_UFunction_UIGridVisualFactory_UpdateVisualCell_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/IGridVisualFactory.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Cellpos;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UIGridVisualFactory_UpdateVisualCell_Statics::NewProp_Cellpos = { "Cellpos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(IGridVisualFactory_eventUpdateVisualCell_Parms, Cellpos), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UIGridVisualFactory_UpdateVisualCell_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UIGridVisualFactory_UpdateVisualCell_Statics::NewProp_Cellpos,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UIGridVisualFactory_UpdateVisualCell_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UIGridVisualFactory_UpdateVisualCell_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UIGridVisualFactory, nullptr, "UpdateVisualCell", Z_Construct_UFunction_UIGridVisualFactory_UpdateVisualCell_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UIGridVisualFactory_UpdateVisualCell_Statics::PropPointers), sizeof(IGridVisualFactory_eventUpdateVisualCell_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C820C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UIGridVisualFactory_UpdateVisualCell_Statics::Function_MetaDataParams), Z_Construct_UFunction_UIGridVisualFactory_UpdateVisualCell_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(IGridVisualFactory_eventUpdateVisualCell_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UIGridVisualFactory_UpdateVisualCell()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UIGridVisualFactory_UpdateVisualCell_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IIGridVisualFactory::execUpdateVisualCell)
{
	P_GET_STRUCT(FVector2D,Z_Param_Cellpos);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateVisualCell_Implementation(Z_Param_Cellpos);
	P_NATIVE_END;
}
// ********** End Interface UIGridVisualFactory Function UpdateVisualCell **************************

// ********** Begin Interface UIGridVisualFactory **************************************************
void UIGridVisualFactory::StaticRegisterNativesUIGridVisualFactory()
{
	UClass* Class = UIGridVisualFactory::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ConstructVisualCells", &IIGridVisualFactory::execConstructVisualCells },
		{ "UpdateVisualCell", &IIGridVisualFactory::execUpdateVisualCell },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UIGridVisualFactory;
UClass* UIGridVisualFactory::GetPrivateStaticClass()
{
	using TClass = UIGridVisualFactory;
	if (!Z_Registration_Info_UClass_UIGridVisualFactory.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("IGridVisualFactory"),
			Z_Registration_Info_UClass_UIGridVisualFactory.InnerSingleton,
			StaticRegisterNativesUIGridVisualFactory,
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
	return Z_Registration_Info_UClass_UIGridVisualFactory.InnerSingleton;
}
UClass* Z_Construct_UClass_UIGridVisualFactory_NoRegister()
{
	return UIGridVisualFactory::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UIGridVisualFactory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/IGridVisualFactory.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UIGridVisualFactory_ConstructVisualCells, "ConstructVisualCells" }, // 1978912526
		{ &Z_Construct_UFunction_UIGridVisualFactory_UpdateVisualCell, "UpdateVisualCell" }, // 3997544073
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IIGridVisualFactory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UIGridVisualFactory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_G1Collab,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UIGridVisualFactory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UIGridVisualFactory_Statics::ClassParams = {
	&UIGridVisualFactory::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UIGridVisualFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_UIGridVisualFactory_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UIGridVisualFactory()
{
	if (!Z_Registration_Info_UClass_UIGridVisualFactory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UIGridVisualFactory.OuterSingleton, Z_Construct_UClass_UIGridVisualFactory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UIGridVisualFactory.OuterSingleton;
}
UIGridVisualFactory::UIGridVisualFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UIGridVisualFactory);
// ********** End Interface UIGridVisualFactory ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h__Script_G1Collab_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UIGridVisualFactory, UIGridVisualFactory::StaticClass, TEXT("UIGridVisualFactory"), &Z_Registration_Info_UClass_UIGridVisualFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UIGridVisualFactory), 3714125322U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h__Script_G1Collab_1037585410(TEXT("/Script/G1Collab"),
	Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h__Script_G1Collab_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h__Script_G1Collab_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
