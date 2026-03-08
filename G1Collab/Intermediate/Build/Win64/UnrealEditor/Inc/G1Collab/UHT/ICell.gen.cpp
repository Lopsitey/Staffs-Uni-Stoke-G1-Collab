// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Grid/ICell.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeICell() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
G1COLLAB_API UClass* Z_Construct_UClass_UICell();
G1COLLAB_API UClass* Z_Construct_UClass_UICell_NoRegister();
G1COLLAB_API UFunction* Z_Construct_UDelegateFunction_G1Collab_CellUpdateSig__DelegateSignature();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagQuery();
UPackage* Z_Construct_UPackage__Script_G1Collab();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FCellUpdateSig ********************************************************
struct Z_Construct_UDelegateFunction_G1Collab_CellUpdateSig__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Grid/ICell.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_G1Collab_CellUpdateSig__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_G1Collab, nullptr, "CellUpdateSig__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_G1Collab_CellUpdateSig__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_G1Collab_CellUpdateSig__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_G1Collab_CellUpdateSig__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_G1Collab_CellUpdateSig__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FCellUpdateSig_DelegateWrapper(const FMulticastScriptDelegate& CellUpdateSig)
{
	CellUpdateSig.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FCellUpdateSig **********************************************************

// ********** Begin Interface UICell Function AppendCellTags ***************************************
struct ICell_eventAppendCellTags_Parms
{
	FGameplayTagContainer inputTags;
};
void IICell::AppendCellTags(FGameplayTagContainer inputTags)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_AppendCellTags instead.");
}
static FName NAME_UICell_AppendCellTags = FName(TEXT("AppendCellTags"));
void IICell::Execute_AppendCellTags(UObject* O, FGameplayTagContainer inputTags)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UICell::StaticClass()));
	ICell_eventAppendCellTags_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UICell_AppendCellTags);
	if (Func)
	{
		Parms.inputTags=inputTags;
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IICell*)(O->GetNativeInterfaceAddress(UICell::StaticClass())))
	{
		I->AppendCellTags_Implementation(inputTags);
	}
}
struct Z_Construct_UFunction_UICell_AppendCellTags_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ICell" },
		{ "ModuleRelativePath", "Public/Grid/ICell.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_inputTags;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UICell_AppendCellTags_Statics::NewProp_inputTags = { "inputTags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ICell_eventAppendCellTags_Parms, inputTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(0, nullptr) }; // 2104890724
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UICell_AppendCellTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UICell_AppendCellTags_Statics::NewProp_inputTags,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UICell_AppendCellTags_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UICell_AppendCellTags_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UICell, nullptr, "AppendCellTags", Z_Construct_UFunction_UICell_AppendCellTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UICell_AppendCellTags_Statics::PropPointers), sizeof(ICell_eventAppendCellTags_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UICell_AppendCellTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_UICell_AppendCellTags_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ICell_eventAppendCellTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UICell_AppendCellTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UICell_AppendCellTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IICell::execAppendCellTags)
{
	P_GET_STRUCT(FGameplayTagContainer,Z_Param_inputTags);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AppendCellTags_Implementation(Z_Param_inputTags);
	P_NATIVE_END;
}
// ********** End Interface UICell Function AppendCellTags *****************************************

// ********** Begin Interface UICell Function GetTags **********************************************
struct ICell_eventGetTags_Parms
{
	FGameplayTagContainer ReturnValue;
};
FGameplayTagContainer IICell::GetTags()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetTags instead.");
	ICell_eventGetTags_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UICell_GetTags = FName(TEXT("GetTags"));
FGameplayTagContainer IICell::Execute_GetTags(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UICell::StaticClass()));
	ICell_eventGetTags_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UICell_GetTags);
	if (Func)
	{
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IICell*)(O->GetNativeInterfaceAddress(UICell::StaticClass())))
	{
		Parms.ReturnValue = I->GetTags_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UICell_GetTags_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ICell" },
		{ "ModuleRelativePath", "Public/Grid/ICell.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UICell_GetTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ICell_eventGetTags_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(0, nullptr) }; // 2104890724
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UICell_GetTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UICell_GetTags_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UICell_GetTags_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UICell_GetTags_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UICell, nullptr, "GetTags", Z_Construct_UFunction_UICell_GetTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UICell_GetTags_Statics::PropPointers), sizeof(ICell_eventGetTags_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UICell_GetTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_UICell_GetTags_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ICell_eventGetTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UICell_GetTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UICell_GetTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IICell::execGetTags)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameplayTagContainer*)Z_Param__Result=P_THIS->GetTags_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UICell Function GetTags ************************************************

// ********** Begin Interface UICell Function QueryTags ********************************************
struct ICell_eventQueryTags_Parms
{
	FGameplayTagQuery query;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	ICell_eventQueryTags_Parms()
		: ReturnValue(false)
	{
	}
};
bool IICell::QueryTags(FGameplayTagQuery query)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_QueryTags instead.");
	ICell_eventQueryTags_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UICell_QueryTags = FName(TEXT("QueryTags"));
bool IICell::Execute_QueryTags(UObject* O, FGameplayTagQuery query)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UICell::StaticClass()));
	ICell_eventQueryTags_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UICell_QueryTags);
	if (Func)
	{
		Parms.query=query;
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IICell*)(O->GetNativeInterfaceAddress(UICell::StaticClass())))
	{
		Parms.ReturnValue = I->QueryTags_Implementation(query);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UICell_QueryTags_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ICell" },
		{ "ModuleRelativePath", "Public/Grid/ICell.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_query;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UICell_QueryTags_Statics::NewProp_query = { "query", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ICell_eventQueryTags_Parms, query), Z_Construct_UScriptStruct_FGameplayTagQuery, METADATA_PARAMS(0, nullptr) }; // 899807351
void Z_Construct_UFunction_UICell_QueryTags_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ICell_eventQueryTags_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UICell_QueryTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ICell_eventQueryTags_Parms), &Z_Construct_UFunction_UICell_QueryTags_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UICell_QueryTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UICell_QueryTags_Statics::NewProp_query,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UICell_QueryTags_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UICell_QueryTags_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UICell_QueryTags_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UICell, nullptr, "QueryTags", Z_Construct_UFunction_UICell_QueryTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UICell_QueryTags_Statics::PropPointers), sizeof(ICell_eventQueryTags_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UICell_QueryTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_UICell_QueryTags_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ICell_eventQueryTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UICell_QueryTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UICell_QueryTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IICell::execQueryTags)
{
	P_GET_STRUCT(FGameplayTagQuery,Z_Param_query);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->QueryTags_Implementation(Z_Param_query);
	P_NATIVE_END;
}
// ********** End Interface UICell Function QueryTags **********************************************

// ********** Begin Interface UICell Function RemoveCellTags ***************************************
struct ICell_eventRemoveCellTags_Parms
{
	FGameplayTagContainer inputTags;
};
void IICell::RemoveCellTags(FGameplayTagContainer inputTags)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_RemoveCellTags instead.");
}
static FName NAME_UICell_RemoveCellTags = FName(TEXT("RemoveCellTags"));
void IICell::Execute_RemoveCellTags(UObject* O, FGameplayTagContainer inputTags)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UICell::StaticClass()));
	ICell_eventRemoveCellTags_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UICell_RemoveCellTags);
	if (Func)
	{
		Parms.inputTags=inputTags;
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IICell*)(O->GetNativeInterfaceAddress(UICell::StaticClass())))
	{
		I->RemoveCellTags_Implementation(inputTags);
	}
}
struct Z_Construct_UFunction_UICell_RemoveCellTags_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ICell" },
		{ "ModuleRelativePath", "Public/Grid/ICell.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_inputTags;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UICell_RemoveCellTags_Statics::NewProp_inputTags = { "inputTags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ICell_eventRemoveCellTags_Parms, inputTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(0, nullptr) }; // 2104890724
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UICell_RemoveCellTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UICell_RemoveCellTags_Statics::NewProp_inputTags,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UICell_RemoveCellTags_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UICell_RemoveCellTags_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UICell, nullptr, "RemoveCellTags", Z_Construct_UFunction_UICell_RemoveCellTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UICell_RemoveCellTags_Statics::PropPointers), sizeof(ICell_eventRemoveCellTags_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UICell_RemoveCellTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_UICell_RemoveCellTags_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ICell_eventRemoveCellTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UICell_RemoveCellTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UICell_RemoveCellTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IICell::execRemoveCellTags)
{
	P_GET_STRUCT(FGameplayTagContainer,Z_Param_inputTags);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RemoveCellTags_Implementation(Z_Param_inputTags);
	P_NATIVE_END;
}
// ********** End Interface UICell Function RemoveCellTags *****************************************

// ********** Begin Interface UICell ***************************************************************
void UICell::StaticRegisterNativesUICell()
{
	UClass* Class = UICell::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AppendCellTags", &IICell::execAppendCellTags },
		{ "GetTags", &IICell::execGetTags },
		{ "QueryTags", &IICell::execQueryTags },
		{ "RemoveCellTags", &IICell::execRemoveCellTags },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UICell;
UClass* UICell::GetPrivateStaticClass()
{
	using TClass = UICell;
	if (!Z_Registration_Info_UClass_UICell.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ICell"),
			Z_Registration_Info_UClass_UICell.InnerSingleton,
			StaticRegisterNativesUICell,
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
	return Z_Registration_Info_UClass_UICell.InnerSingleton;
}
UClass* Z_Construct_UClass_UICell_NoRegister()
{
	return UICell::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UICell_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Grid/ICell.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UICell_AppendCellTags, "AppendCellTags" }, // 2407303863
		{ &Z_Construct_UFunction_UICell_GetTags, "GetTags" }, // 1291715588
		{ &Z_Construct_UFunction_UICell_QueryTags, "QueryTags" }, // 3792840781
		{ &Z_Construct_UFunction_UICell_RemoveCellTags, "RemoveCellTags" }, // 1071993439
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IICell>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UICell_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_G1Collab,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UICell_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UICell_Statics::ClassParams = {
	&UICell::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UICell_Statics::Class_MetaDataParams), Z_Construct_UClass_UICell_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UICell()
{
	if (!Z_Registration_Info_UClass_UICell.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UICell.OuterSingleton, Z_Construct_UClass_UICell_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UICell.OuterSingleton;
}
UICell::UICell(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UICell);
// ********** End Interface UICell *****************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h__Script_G1Collab_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UICell, UICell::StaticClass, TEXT("UICell"), &Z_Registration_Info_UClass_UICell, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UICell), 2173439704U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h__Script_G1Collab_224097242(TEXT("/Script/G1Collab"),
	Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h__Script_G1Collab_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h__Script_G1Collab_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
