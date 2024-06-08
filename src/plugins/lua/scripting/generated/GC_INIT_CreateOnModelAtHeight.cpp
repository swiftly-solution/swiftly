#include "../../../core/scripting/generated/classes/GC_INIT_CreateOnModelAtHeight.h"
#include "../core.h"

void SetupLuaClassGC_INIT_CreateOnModelAtHeight(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_CreateOnModelAtHeight>("C_INIT_CreateOnModelAtHeight")
        .addProperty("UseBones", &GC_INIT_CreateOnModelAtHeight::GetUseBones, &GC_INIT_CreateOnModelAtHeight::SetUseBones)
        .addProperty("ForceZ", &GC_INIT_CreateOnModelAtHeight::GetForceZ, &GC_INIT_CreateOnModelAtHeight::SetForceZ)
        .addProperty("ControlPointNumber", &GC_INIT_CreateOnModelAtHeight::GetControlPointNumber, &GC_INIT_CreateOnModelAtHeight::SetControlPointNumber)
        .addProperty("HeightCP", &GC_INIT_CreateOnModelAtHeight::GetHeightCP, &GC_INIT_CreateOnModelAtHeight::SetHeightCP)
        .addProperty("UseWaterHeight", &GC_INIT_CreateOnModelAtHeight::GetUseWaterHeight, &GC_INIT_CreateOnModelAtHeight::SetUseWaterHeight)
        .addProperty("DesiredHeight", &GC_INIT_CreateOnModelAtHeight::GetDesiredHeight, &GC_INIT_CreateOnModelAtHeight::SetDesiredHeight)
        .addProperty("BiasType", &GC_INIT_CreateOnModelAtHeight::GetBiasType, &GC_INIT_CreateOnModelAtHeight::SetBiasType)
        .addProperty("LocalCoords", &GC_INIT_CreateOnModelAtHeight::GetLocalCoords, &GC_INIT_CreateOnModelAtHeight::SetLocalCoords)
        .addProperty("PreferMovingBoxes", &GC_INIT_CreateOnModelAtHeight::GetPreferMovingBoxes, &GC_INIT_CreateOnModelAtHeight::SetPreferMovingBoxes)
        .addProperty("HitboxSetName", &GC_INIT_CreateOnModelAtHeight::GetHitboxSetName, &GC_INIT_CreateOnModelAtHeight::SetHitboxSetName)
        .addProperty("HitboxVelocityScale", &GC_INIT_CreateOnModelAtHeight::GetHitboxVelocityScale, &GC_INIT_CreateOnModelAtHeight::SetHitboxVelocityScale)
        .addProperty("MaxBoneVelocity", &GC_INIT_CreateOnModelAtHeight::GetMaxBoneVelocity, &GC_INIT_CreateOnModelAtHeight::SetMaxBoneVelocity)
        .endClass();
}