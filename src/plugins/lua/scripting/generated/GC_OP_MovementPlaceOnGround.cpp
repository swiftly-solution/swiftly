#include "../../../core/scripting/generated/classes/GC_OP_MovementPlaceOnGround.h"
#include "../core.h"

void SetupLuaClassGC_OP_MovementPlaceOnGround(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_MovementPlaceOnGround>("C_OP_MovementPlaceOnGround")
        .addProperty("Offset", &GC_OP_MovementPlaceOnGround::GetOffset, &GC_OP_MovementPlaceOnGround::SetOffset)
        .addProperty("MaxTraceLength", &GC_OP_MovementPlaceOnGround::GetMaxTraceLength, &GC_OP_MovementPlaceOnGround::SetMaxTraceLength)
        .addProperty("Tolerance", &GC_OP_MovementPlaceOnGround::GetTolerance, &GC_OP_MovementPlaceOnGround::SetTolerance)
        .addProperty("TraceOffset", &GC_OP_MovementPlaceOnGround::GetTraceOffset, &GC_OP_MovementPlaceOnGround::SetTraceOffset)
        .addProperty("LerpRate", &GC_OP_MovementPlaceOnGround::GetLerpRate, &GC_OP_MovementPlaceOnGround::SetLerpRate)
        .addProperty("CollisionGroupName", &GC_OP_MovementPlaceOnGround::GetCollisionGroupName, &GC_OP_MovementPlaceOnGround::SetCollisionGroupName)
        .addProperty("TraceSet", &GC_OP_MovementPlaceOnGround::GetTraceSet, &GC_OP_MovementPlaceOnGround::SetTraceSet)
        .addProperty("RefCP1", &GC_OP_MovementPlaceOnGround::GetRefCP1, &GC_OP_MovementPlaceOnGround::SetRefCP1)
        .addProperty("RefCP2", &GC_OP_MovementPlaceOnGround::GetRefCP2, &GC_OP_MovementPlaceOnGround::SetRefCP2)
        .addProperty("LerpCP", &GC_OP_MovementPlaceOnGround::GetLerpCP, &GC_OP_MovementPlaceOnGround::SetLerpCP)
        .addProperty("TraceMissBehavior", &GC_OP_MovementPlaceOnGround::GetTraceMissBehavior, &GC_OP_MovementPlaceOnGround::SetTraceMissBehavior)
        .addProperty("IncludeShotHull", &GC_OP_MovementPlaceOnGround::GetIncludeShotHull, &GC_OP_MovementPlaceOnGround::SetIncludeShotHull)
        .addProperty("IncludeWater", &GC_OP_MovementPlaceOnGround::GetIncludeWater, &GC_OP_MovementPlaceOnGround::SetIncludeWater)
        .addProperty("SetNormal", &GC_OP_MovementPlaceOnGround::GetSetNormal, &GC_OP_MovementPlaceOnGround::SetSetNormal)
        .addProperty("ScaleOffset", &GC_OP_MovementPlaceOnGround::GetScaleOffset, &GC_OP_MovementPlaceOnGround::SetScaleOffset)
        .addProperty("PreserveOffsetCP", &GC_OP_MovementPlaceOnGround::GetPreserveOffsetCP, &GC_OP_MovementPlaceOnGround::SetPreserveOffsetCP)
        .addProperty("IgnoreCP", &GC_OP_MovementPlaceOnGround::GetIgnoreCP, &GC_OP_MovementPlaceOnGround::SetIgnoreCP)
        .endClass();
}