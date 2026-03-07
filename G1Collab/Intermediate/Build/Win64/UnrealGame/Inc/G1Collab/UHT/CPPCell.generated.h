// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CPPCell.h"

#ifdef G1COLLAB_CPPCell_generated_h
#error "CPPCell.generated.h already included, missing '#pragma once' in CPPCell.h"
#endif
#define G1COLLAB_CPPCell_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UCPPCell *****************************************************************
G1COLLAB_API UClass* Z_Construct_UClass_UCPPCell_NoRegister();

#define FID_G1Collab_Source_G1Collab_CPPCell_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCPPCell(); \
	friend struct Z_Construct_UClass_UCPPCell_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend G1COLLAB_API UClass* Z_Construct_UClass_UCPPCell_NoRegister(); \
public: \
	DECLARE_CLASS2(UCPPCell, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/G1Collab"), Z_Construct_UClass_UCPPCell_NoRegister) \
	DECLARE_SERIALIZER(UCPPCell) \
	virtual UObject* _getUObject() const override { return const_cast<UCPPCell*>(this); }


#define FID_G1Collab_Source_G1Collab_CPPCell_h_17_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCPPCell(UCPPCell&&) = delete; \
	UCPPCell(const UCPPCell&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCPPCell); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCPPCell); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCPPCell) \
	NO_API virtual ~UCPPCell();


#define FID_G1Collab_Source_G1Collab_CPPCell_h_14_PROLOG
#define FID_G1Collab_Source_G1Collab_CPPCell_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_G1Collab_Source_G1Collab_CPPCell_h_17_INCLASS_NO_PURE_DECLS \
	FID_G1Collab_Source_G1Collab_CPPCell_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCPPCell;

// ********** End Class UCPPCell *******************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_G1Collab_Source_G1Collab_CPPCell_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
