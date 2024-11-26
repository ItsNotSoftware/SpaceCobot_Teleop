// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "VRCharacterBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SPACECOBOT_TELEOP_VRCharacterBase_generated_h
#error "VRCharacterBase.generated.h already included, missing '#pragma once' in VRCharacterBase.h"
#endif
#define SPACECOBOT_TELEOP_VRCharacterBase_generated_h

#define FID_diogoferreira_CodeWs_SpaceCobot_Teleop_SpaceCobot_Teleop_Source_SpaceCobot_Teleop_Public_VRCharacterBase_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCharacterMoveForward);


#define FID_diogoferreira_CodeWs_SpaceCobot_Teleop_SpaceCobot_Teleop_Source_SpaceCobot_Teleop_Public_VRCharacterBase_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVRCharacterBase(); \
	friend struct Z_Construct_UClass_AVRCharacterBase_Statics; \
public: \
	DECLARE_CLASS(AVRCharacterBase, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceCobot_Teleop"), NO_API) \
	DECLARE_SERIALIZER(AVRCharacterBase)


#define FID_diogoferreira_CodeWs_SpaceCobot_Teleop_SpaceCobot_Teleop_Source_SpaceCobot_Teleop_Public_VRCharacterBase_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AVRCharacterBase(AVRCharacterBase&&); \
	AVRCharacterBase(const AVRCharacterBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVRCharacterBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVRCharacterBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVRCharacterBase) \
	NO_API virtual ~AVRCharacterBase();


#define FID_diogoferreira_CodeWs_SpaceCobot_Teleop_SpaceCobot_Teleop_Source_SpaceCobot_Teleop_Public_VRCharacterBase_h_9_PROLOG
#define FID_diogoferreira_CodeWs_SpaceCobot_Teleop_SpaceCobot_Teleop_Source_SpaceCobot_Teleop_Public_VRCharacterBase_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_diogoferreira_CodeWs_SpaceCobot_Teleop_SpaceCobot_Teleop_Source_SpaceCobot_Teleop_Public_VRCharacterBase_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_diogoferreira_CodeWs_SpaceCobot_Teleop_SpaceCobot_Teleop_Source_SpaceCobot_Teleop_Public_VRCharacterBase_h_11_INCLASS_NO_PURE_DECLS \
	FID_diogoferreira_CodeWs_SpaceCobot_Teleop_SpaceCobot_Teleop_Source_SpaceCobot_Teleop_Public_VRCharacterBase_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SPACECOBOT_TELEOP_API UClass* StaticClass<class AVRCharacterBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_diogoferreira_CodeWs_SpaceCobot_Teleop_SpaceCobot_Teleop_Source_SpaceCobot_Teleop_Public_VRCharacterBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
