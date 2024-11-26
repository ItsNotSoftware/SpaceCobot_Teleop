// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SpaceCobot_Teleop/Public/VRCharacterBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVRCharacterBase() {}

// Begin Cross Module References
CINEMATICCAMERA_API UClass* Z_Construct_UClass_UCineCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
SPACECOBOT_TELEOP_API UClass* Z_Construct_UClass_AVRCharacterBase();
SPACECOBOT_TELEOP_API UClass* Z_Construct_UClass_AVRCharacterBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_SpaceCobot_Teleop();
// End Cross Module References

// Begin Class AVRCharacterBase Function CharacterMoveForward
struct Z_Construct_UFunction_AVRCharacterBase_CharacterMoveForward_Statics
{
	struct VRCharacterBase_eventCharacterMoveForward_Parms
	{
		float Ratio;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VRCharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Ratio_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Ratio;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVRCharacterBase_CharacterMoveForward_Statics::NewProp_Ratio = { "Ratio", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRCharacterBase_eventCharacterMoveForward_Parms, Ratio), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Ratio_MetaData), NewProp_Ratio_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVRCharacterBase_CharacterMoveForward_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVRCharacterBase_CharacterMoveForward_Statics::NewProp_Ratio,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVRCharacterBase_CharacterMoveForward_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVRCharacterBase_CharacterMoveForward_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVRCharacterBase, nullptr, "CharacterMoveForward", nullptr, nullptr, Z_Construct_UFunction_AVRCharacterBase_CharacterMoveForward_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVRCharacterBase_CharacterMoveForward_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVRCharacterBase_CharacterMoveForward_Statics::VRCharacterBase_eventCharacterMoveForward_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVRCharacterBase_CharacterMoveForward_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVRCharacterBase_CharacterMoveForward_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AVRCharacterBase_CharacterMoveForward_Statics::VRCharacterBase_eventCharacterMoveForward_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVRCharacterBase_CharacterMoveForward()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVRCharacterBase_CharacterMoveForward_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVRCharacterBase::execCharacterMoveForward)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Ratio);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CharacterMoveForward(Z_Param_Ratio);
	P_NATIVE_END;
}
// End Class AVRCharacterBase Function CharacterMoveForward

// Begin Class AVRCharacterBase
void AVRCharacterBase::StaticRegisterNativesAVRCharacterBase()
{
	UClass* Class = AVRCharacterBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CharacterMoveForward", &AVRCharacterBase::execCharacterMoveForward },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVRCharacterBase);
UClass* Z_Construct_UClass_AVRCharacterBase_NoRegister()
{
	return AVRCharacterBase::StaticClass();
}
struct Z_Construct_UClass_AVRCharacterBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "VRCharacterBase.h" },
		{ "ModuleRelativePath", "Public/VRCharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VROffset_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VRCharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VRCamera_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VRCharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxSpeed_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/VRCharacterBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VROffset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VRCamera;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxSpeed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AVRCharacterBase_CharacterMoveForward, "CharacterMoveForward" }, // 444142031
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVRCharacterBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRCharacterBase_Statics::NewProp_VROffset = { "VROffset", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRCharacterBase, VROffset), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VROffset_MetaData), NewProp_VROffset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVRCharacterBase_Statics::NewProp_VRCamera = { "VRCamera", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRCharacterBase, VRCamera), Z_Construct_UClass_UCineCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VRCamera_MetaData), NewProp_VRCamera_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVRCharacterBase_Statics::NewProp_MaxSpeed = { "MaxSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVRCharacterBase, MaxSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxSpeed_MetaData), NewProp_MaxSpeed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVRCharacterBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRCharacterBase_Statics::NewProp_VROffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRCharacterBase_Statics::NewProp_VRCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVRCharacterBase_Statics::NewProp_MaxSpeed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVRCharacterBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AVRCharacterBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_SpaceCobot_Teleop,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVRCharacterBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AVRCharacterBase_Statics::ClassParams = {
	&AVRCharacterBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AVRCharacterBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AVRCharacterBase_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVRCharacterBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AVRCharacterBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AVRCharacterBase()
{
	if (!Z_Registration_Info_UClass_AVRCharacterBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVRCharacterBase.OuterSingleton, Z_Construct_UClass_AVRCharacterBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AVRCharacterBase.OuterSingleton;
}
template<> SPACECOBOT_TELEOP_API UClass* StaticClass<AVRCharacterBase>()
{
	return AVRCharacterBase::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AVRCharacterBase);
AVRCharacterBase::~AVRCharacterBase() {}
// End Class AVRCharacterBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_diogoferreira_CodeWs_SpaceCobot_Teleop_SpaceCobot_Teleop_Source_SpaceCobot_Teleop_Public_VRCharacterBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AVRCharacterBase, AVRCharacterBase::StaticClass, TEXT("AVRCharacterBase"), &Z_Registration_Info_UClass_AVRCharacterBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVRCharacterBase), 3798257937U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_diogoferreira_CodeWs_SpaceCobot_Teleop_SpaceCobot_Teleop_Source_SpaceCobot_Teleop_Public_VRCharacterBase_h_3107031391(TEXT("/Script/SpaceCobot_Teleop"),
	Z_CompiledInDeferFile_FID_diogoferreira_CodeWs_SpaceCobot_Teleop_SpaceCobot_Teleop_Source_SpaceCobot_Teleop_Public_VRCharacterBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_diogoferreira_CodeWs_SpaceCobot_Teleop_SpaceCobot_Teleop_Source_SpaceCobot_Teleop_Public_VRCharacterBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
