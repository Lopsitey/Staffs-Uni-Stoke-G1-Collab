// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "IGridVisualFactory.h"

#ifdef G1COLLAB_IGridVisualFactory_generated_h
#error "IGridVisualFactory.generated.h already included, missing '#pragma once' in IGridVisualFactory.h"
#endif
#define G1COLLAB_IGridVisualFactory_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

 class UObject;

// ********** Begin Interface UIGridVisualFactory **************************************************
#define FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execConstructVisualCells); \
	DECLARE_FUNCTION(execUpdateVisualCell);


#define FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h_13_CALLBACK_WRAPPERS
G1COLLAB_API UClass* Z_Construct_UClass_UIGridVisualFactory_NoRegister();

#define FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	G1COLLAB_API UIGridVisualFactory(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UIGridVisualFactory(UIGridVisualFactory&&) = delete; \
	UIGridVisualFactory(const UIGridVisualFactory&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(G1COLLAB_API, UIGridVisualFactory); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UIGridVisualFactory); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UIGridVisualFactory) \
	virtual ~UIGridVisualFactory() = default;


#define FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUIGridVisualFactory(); \
	friend struct Z_Construct_UClass_UIGridVisualFactory_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend G1COLLAB_API UClass* Z_Construct_UClass_UIGridVisualFactory_NoRegister(); \
public: \
	DECLARE_CLASS2(UIGridVisualFactory, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/G1Collab"), Z_Construct_UClass_UIGridVisualFactory_NoRegister) \
	DECLARE_SERIALIZER(UIGridVisualFactory)


#define FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h_13_GENERATED_UINTERFACE_BODY() \
	FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IIGridVisualFactory() {} \
public: \
	typedef UIGridVisualFactory UClassType; \
	typedef IIGridVisualFactory ThisClass; \
	static void Execute_ConstructVisualCells(UObject* O, TMap<FVector2D,UObject*> const& gridData); \
	static void Execute_UpdateVisualCell(UObject* O, FVector2D Cellpos); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h_10_PROLOG
#define FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h_13_CALLBACK_WRAPPERS \
	FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UIGridVisualFactory;

// ********** End Interface UIGridVisualFactory ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_G1Collab_Source_G1Collab_Public_IGridVisualFactory_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
