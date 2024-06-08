#include "../../../core/scripting/generated/classes/GC_INIT_LifespanFromVelocity.h"
#include "../core.h"

void SetupLuaClassGC_INIT_LifespanFromVelocity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_LifespanFromVelocity>("C_INIT_LifespanFromVelocity")
        .addProperty("ComponentScale", &GC_INIT_LifespanFromVelocity::GetComponentScale, &GC_INIT_LifespanFromVelocity::SetComponentScale)
        .addProperty("TraceOffset", &GC_INIT_LifespanFromVelocity::GetTraceOffset, &GC_INIT_LifespanFromVelocity::SetTraceOffset)
        .addProperty("MaxTraceLength", &GC_INIT_LifespanFromVelocity::GetMaxTraceLength, &GC_INIT_LifespanFromVelocity::SetMaxTraceLength)
        .addProperty("TraceTolerance", &GC_INIT_LifespanFromVelocity::GetTraceTolerance, &GC_INIT_LifespanFromVelocity::SetTraceTolerance)
        .addProperty("MaxPlanes", &GC_INIT_LifespanFromVelocity::GetMaxPlanes, &GC_INIT_LifespanFromVelocity::SetMaxPlanes)
        .addProperty("CollisionGroupName", &GC_INIT_LifespanFromVelocity::GetCollisionGroupName, &GC_INIT_LifespanFromVelocity::SetCollisionGroupName)
        .addProperty("TraceSet", &GC_INIT_LifespanFromVelocity::GetTraceSet, &GC_INIT_LifespanFromVelocity::SetTraceSet)
        .addProperty("IncludeWater", &GC_INIT_LifespanFromVelocity::GetIncludeWater, &GC_INIT_LifespanFromVelocity::SetIncludeWater)
        .endClass();
}