// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeG1Collab_init() {}
	G1COLLAB_API UFunction* Z_Construct_UDelegateFunction_G1Collab_CellUpdateSig__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_G1Collab;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_G1Collab()
	{
		if (!Z_Registration_Info_UPackage__Script_G1Collab.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_G1Collab_CellUpdateSig__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/G1Collab",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x0031EDCA,
				0xE7563B90,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_G1Collab.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_G1Collab.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_G1Collab(Z_Construct_UPackage__Script_G1Collab, TEXT("/Script/G1Collab"), Z_Registration_Info_UPackage__Script_G1Collab, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x0031EDCA, 0xE7563B90));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
