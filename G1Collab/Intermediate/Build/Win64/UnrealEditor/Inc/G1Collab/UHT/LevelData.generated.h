// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LevelData.h"

#ifdef G1COLLAB_LevelData_generated_h
#error "LevelData.generated.h already included, missing '#pragma once' in LevelData.h"
#endif
#define G1COLLAB_LevelData_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FLevelCellData ****************************************************
#define FID_G1Collab_Source_G1Collab_Public_LevelData_h_13_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLevelCellData_Statics; \
	G1COLLAB_API static class UScriptStruct* StaticStruct();


struct FLevelCellData;
// ********** End ScriptStruct FLevelCellData ******************************************************

// ********** Begin Class ULevelDataAsset **********************************************************
G1COLLAB_API UClass* Z_Construct_UClass_ULevelDataAsset_NoRegister();

#define FID_G1Collab_Source_G1Collab_Public_LevelData_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULevelDataAsset(); \
	friend struct Z_Construct_UClass_ULevelDataAsset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend G1COLLAB_API UClass* Z_Construct_UClass_ULevelDataAsset_NoRegister(); \
public: \
	DECLARE_CLASS2(ULevelDataAsset, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/G1Collab"), Z_Construct_UClass_ULevelDataAsset_NoRegister) \
	DECLARE_SERIALIZER(ULevelDataAsset)


#define FID_G1Collab_Source_G1Collab_Public_LevelData_h_28_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULevelDataAsset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULevelDataAsset(ULevelDataAsset&&) = delete; \
	ULevelDataAsset(const ULevelDataAsset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULevelDataAsset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULevelDataAsset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULevelDataAsset) \
	NO_API virtual ~ULevelDataAsset();


#define FID_G1Collab_Source_G1Collab_Public_LevelData_h_25_PROLOG
#define FID_G1Collab_Source_G1Collab_Public_LevelData_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_G1Collab_Source_G1Collab_Public_LevelData_h_28_INCLASS_NO_PURE_DECLS \
	FID_G1Collab_Source_G1Collab_Public_LevelData_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULevelDataAsset;

// ********** End Class ULevelDataAsset ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_G1Collab_Source_G1Collab_Public_LevelData_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
