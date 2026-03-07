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

// ********** Begin Class UMyClass *****************************************************************
G1COLLAB_API UClass* Z_Construct_UClass_UMyClass_NoRegister();

#define FID_G1Collab_Source_G1Collab_Public_LevelData_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyClass(); \
	friend struct Z_Construct_UClass_UMyClass_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend G1COLLAB_API UClass* Z_Construct_UClass_UMyClass_NoRegister(); \
public: \
	DECLARE_CLASS2(UMyClass, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/G1Collab"), Z_Construct_UClass_UMyClass_NoRegister) \
	DECLARE_SERIALIZER(UMyClass)


#define FID_G1Collab_Source_G1Collab_Public_LevelData_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyClass(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UMyClass(UMyClass&&) = delete; \
	UMyClass(const UMyClass&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyClass); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyClass); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyClass) \
	NO_API virtual ~UMyClass();


#define FID_G1Collab_Source_G1Collab_Public_LevelData_h_12_PROLOG
#define FID_G1Collab_Source_G1Collab_Public_LevelData_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_G1Collab_Source_G1Collab_Public_LevelData_h_15_INCLASS_NO_PURE_DECLS \
	FID_G1Collab_Source_G1Collab_Public_LevelData_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UMyClass;

// ********** End Class UMyClass *******************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_G1Collab_Source_G1Collab_Public_LevelData_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
