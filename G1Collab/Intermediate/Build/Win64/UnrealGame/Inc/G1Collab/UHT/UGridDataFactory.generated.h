// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UGridDataFactory.h"

#ifdef G1COLLAB_UGridDataFactory_generated_h
#error "UGridDataFactory.generated.h already included, missing '#pragma once' in UGridDataFactory.h"
#endif
#define G1COLLAB_UGridDataFactory_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UCPPCell;
class UObject;

// ********** Begin Class UUGridDataFactory ********************************************************
#define FID_G1Collab_Source_G1Collab_UGridDataFactory_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRetrieveCellInformation); \
	DECLARE_FUNCTION(execConstructGrid);


G1COLLAB_API UClass* Z_Construct_UClass_UUGridDataFactory_NoRegister();

#define FID_G1Collab_Source_G1Collab_UGridDataFactory_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUUGridDataFactory(); \
	friend struct Z_Construct_UClass_UUGridDataFactory_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend G1COLLAB_API UClass* Z_Construct_UClass_UUGridDataFactory_NoRegister(); \
public: \
	DECLARE_CLASS2(UUGridDataFactory, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/G1Collab"), Z_Construct_UClass_UUGridDataFactory_NoRegister) \
	DECLARE_SERIALIZER(UUGridDataFactory)


#define FID_G1Collab_Source_G1Collab_UGridDataFactory_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UUGridDataFactory(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UUGridDataFactory(UUGridDataFactory&&) = delete; \
	UUGridDataFactory(const UUGridDataFactory&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUGridDataFactory); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUGridDataFactory); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUGridDataFactory) \
	NO_API virtual ~UUGridDataFactory();


#define FID_G1Collab_Source_G1Collab_UGridDataFactory_h_13_PROLOG
#define FID_G1Collab_Source_G1Collab_UGridDataFactory_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_G1Collab_Source_G1Collab_UGridDataFactory_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_G1Collab_Source_G1Collab_UGridDataFactory_h_16_INCLASS_NO_PURE_DECLS \
	FID_G1Collab_Source_G1Collab_UGridDataFactory_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UUGridDataFactory;

// ********** End Class UUGridDataFactory **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_G1Collab_Source_G1Collab_UGridDataFactory_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
