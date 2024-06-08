#include "../../../core/scripting/generated/classes/GC_INIT_CreateOnModel.h"
#include "../core.h"

void SetupLuaClassGC_INIT_CreateOnModel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_CreateOnModel>("C_INIT_CreateOnModel")
        .addProperty("ModelInput", &GC_INIT_CreateOnModel::GetModelInput, &GC_INIT_CreateOnModel::SetModelInput)
        .addProperty("TransformInput", &GC_INIT_CreateOnModel::GetTransformInput, &GC_INIT_CreateOnModel::SetTransformInput)
        .addProperty("ForceInModel", &GC_INIT_CreateOnModel::GetForceInModel, &GC_INIT_CreateOnModel::SetForceInModel)
        .addProperty("ScaleToVolume", &GC_INIT_CreateOnModel::GetScaleToVolume, &GC_INIT_CreateOnModel::SetScaleToVolume)
        .addProperty("EvenDistribution", &GC_INIT_CreateOnModel::GetEvenDistribution, &GC_INIT_CreateOnModel::SetEvenDistribution)
        .addProperty("DesiredHitbox", &GC_INIT_CreateOnModel::GetDesiredHitbox, &GC_INIT_CreateOnModel::SetDesiredHitbox)
        .addProperty("HitboxValueFromControlPointIndex", &GC_INIT_CreateOnModel::GetHitboxValueFromControlPointIndex, &GC_INIT_CreateOnModel::SetHitboxValueFromControlPointIndex)
        .addProperty("BoneVelocity", &GC_INIT_CreateOnModel::GetBoneVelocity, &GC_INIT_CreateOnModel::SetBoneVelocity)
        .addProperty("MaxBoneVelocity", &GC_INIT_CreateOnModel::GetMaxBoneVelocity, &GC_INIT_CreateOnModel::SetMaxBoneVelocity)
        .addProperty("HitboxSetName", &GC_INIT_CreateOnModel::GetHitboxSetName, &GC_INIT_CreateOnModel::SetHitboxSetName)
        .addProperty("LocalCoords", &GC_INIT_CreateOnModel::GetLocalCoords, &GC_INIT_CreateOnModel::SetLocalCoords)
        .addProperty("UseBones", &GC_INIT_CreateOnModel::GetUseBones, &GC_INIT_CreateOnModel::SetUseBones)
        .addProperty("UseMesh", &GC_INIT_CreateOnModel::GetUseMesh, &GC_INIT_CreateOnModel::SetUseMesh)
        .addProperty("ShellSize", &GC_INIT_CreateOnModel::GetShellSize, &GC_INIT_CreateOnModel::SetShellSize)
        .endClass();
}