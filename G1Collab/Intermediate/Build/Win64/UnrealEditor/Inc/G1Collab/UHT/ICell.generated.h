// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Grid/ICell.h"

#ifdef G1COLLAB_ICell_generated_h
#error "ICell.generated.h already included, missing '#pragma once' in ICell.h"
#endif
#define G1COLLAB_ICell_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FGameplayTagContainer;
struct FGameplayTagQuery;

// ********** Begin Delegate FCellUpdateSig ********************************************************
#define FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h_11_DELEGATE \
G1COLLAB_API void FCellUpdateSig_DelegateWrapper(const FMulticastScriptDelegate& CellUpdateSig);


// ********** End Delegate FCellUpdateSig **********************************************************

// ********** Begin Interface UICell ***************************************************************
#define FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetTags); \
	DECLARE_FUNCTION(execRemoveCellTags); \
	DECLARE_FUNCTION(execAppendCellTags); \
	DECLARE_FUNCTION(execQueryTags);


#define FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h_16_CALLBACK_WRAPPERS
G1COLLAB_API UClass* Z_Construct_UClass_UICell_NoRegister();

#define FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	G1COLLAB_API UICell(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UICell(UICell&&) = delete; \
	UICell(const UICell&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(G1COLLAB_API, UICell); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UICell); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UICell) \
	virtual ~UICell() = default;


#define FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h_16_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUICell(); \
	friend struct Z_Construct_UClass_UICell_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend G1COLLAB_API UClass* Z_Construct_UClass_UICell_NoRegister(); \
public: \
	DECLARE_CLASS2(UICell, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/G1Collab"), Z_Construct_UClass_UICell_NoRegister) \
	DECLARE_SERIALIZER(UICell)


#define FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h_16_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h_16_GENERATED_UINTERFACE_BODY() \
	FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h_16_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h_16_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IICell() {} \
public: \
	typedef UICell UClassType; \
	typedef IICell ThisClass; \
	static void Execute_AppendCellTags(UObject* O, FGameplayTagContainer inputTags); \
	static FGameplayTagContainer Execute_GetTags(UObject* O); \
	static bool Execute_QueryTags(UObject* O, FGameplayTagQuery query); \
	static void Execute_RemoveCellTags(UObject* O, FGameplayTagContainer inputTags); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h_13_PROLOG
#define FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h_16_CALLBACK_WRAPPERS \
	FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h_16_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UICell;

// ********** End Interface UICell *****************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_G1Collab_Source_G1Collab_Public_Grid_ICell_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
