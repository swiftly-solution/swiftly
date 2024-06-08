#include "../../../core/scripting/generated/classes/GC_INIT_PositionWarp.h"
#include "../core.h"

void SetupLuaClassGC_INIT_PositionWarp(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_PositionWarp>("C_INIT_PositionWarp")
        .addProperty("ScaleControlPointNumber", &GC_INIT_PositionWarp::GetScaleControlPointNumber, &GC_INIT_PositionWarp::SetScaleControlPointNumber)
        .addProperty("ControlPointNumber", &GC_INIT_PositionWarp::GetControlPointNumber, &GC_INIT_PositionWarp::SetControlPointNumber)
        .addProperty("RadiusComponent", &GC_INIT_PositionWarp::GetRadiusComponent, &GC_INIT_PositionWarp::SetRadiusComponent)
        .addProperty("WarpTime", &GC_INIT_PositionWarp::GetWarpTime, &GC_INIT_PositionWarp::SetWarpTime)
        .addProperty("WarpStartTime", &GC_INIT_PositionWarp::GetWarpStartTime, &GC_INIT_PositionWarp::SetWarpStartTime)
        .addProperty("PrevPosScale", &GC_INIT_PositionWarp::GetPrevPosScale, &GC_INIT_PositionWarp::SetPrevPosScale)
        .addProperty("InvertWarp", &GC_INIT_PositionWarp::GetInvertWarp, &GC_INIT_PositionWarp::SetInvertWarp)
        .addProperty("UseCount", &GC_INIT_PositionWarp::GetUseCount, &GC_INIT_PositionWarp::SetUseCount)
        .endClass();
}