#include "../../../core/scripting/generated/classes/GC_INIT_CreateWithinSphereTransform.h"
#include "../core.h"

void SetupLuaClassGC_INIT_CreateWithinSphereTransform(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_CreateWithinSphereTransform>("C_INIT_CreateWithinSphereTransform")
        .addProperty("RadiusMin", &GC_INIT_CreateWithinSphereTransform::GetRadiusMin, &GC_INIT_CreateWithinSphereTransform::SetRadiusMin)
        .addProperty("RadiusMax", &GC_INIT_CreateWithinSphereTransform::GetRadiusMax, &GC_INIT_CreateWithinSphereTransform::SetRadiusMax)
        .addProperty("DistanceBias", &GC_INIT_CreateWithinSphereTransform::GetDistanceBias, &GC_INIT_CreateWithinSphereTransform::SetDistanceBias)
        .addProperty("DistanceBiasAbs", &GC_INIT_CreateWithinSphereTransform::GetDistanceBiasAbs, &GC_INIT_CreateWithinSphereTransform::SetDistanceBiasAbs)
        .addProperty("TransformInput", &GC_INIT_CreateWithinSphereTransform::GetTransformInput, &GC_INIT_CreateWithinSphereTransform::SetTransformInput)
        .addProperty("SpeedMin", &GC_INIT_CreateWithinSphereTransform::GetSpeedMin, &GC_INIT_CreateWithinSphereTransform::SetSpeedMin)
        .addProperty("SpeedMax", &GC_INIT_CreateWithinSphereTransform::GetSpeedMax, &GC_INIT_CreateWithinSphereTransform::SetSpeedMax)
        .addProperty("SpeedRandExp", &GC_INIT_CreateWithinSphereTransform::GetSpeedRandExp, &GC_INIT_CreateWithinSphereTransform::SetSpeedRandExp)
        .addProperty("LocalCoords", &GC_INIT_CreateWithinSphereTransform::GetLocalCoords, &GC_INIT_CreateWithinSphereTransform::SetLocalCoords)
        .addProperty("EndCPGrowthTime", &GC_INIT_CreateWithinSphereTransform::GetEndCPGrowthTime, &GC_INIT_CreateWithinSphereTransform::SetEndCPGrowthTime)
        .addProperty("LocalCoordinateSystemSpeedMin", &GC_INIT_CreateWithinSphereTransform::GetLocalCoordinateSystemSpeedMin, &GC_INIT_CreateWithinSphereTransform::SetLocalCoordinateSystemSpeedMin)
        .addProperty("LocalCoordinateSystemSpeedMax", &GC_INIT_CreateWithinSphereTransform::GetLocalCoordinateSystemSpeedMax, &GC_INIT_CreateWithinSphereTransform::SetLocalCoordinateSystemSpeedMax)
        .addProperty("FieldOutput", &GC_INIT_CreateWithinSphereTransform::GetFieldOutput, &GC_INIT_CreateWithinSphereTransform::SetFieldOutput)
        .addProperty("FieldVelocity", &GC_INIT_CreateWithinSphereTransform::GetFieldVelocity, &GC_INIT_CreateWithinSphereTransform::SetFieldVelocity)
        .endClass();
}