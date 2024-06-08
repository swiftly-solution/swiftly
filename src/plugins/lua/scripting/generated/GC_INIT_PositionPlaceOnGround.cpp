#include "../../../core/scripting/generated/classes/GC_INIT_PositionPlaceOnGround.h"
#include "../core.h"

void SetupLuaClassGC_INIT_PositionPlaceOnGround(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_PositionPlaceOnGround>("C_INIT_PositionPlaceOnGround")
        .addProperty("Offset", &GC_INIT_PositionPlaceOnGround::GetOffset, &GC_INIT_PositionPlaceOnGround::SetOffset)
        .addProperty("MaxTraceLength", &GC_INIT_PositionPlaceOnGround::GetMaxTraceLength, &GC_INIT_PositionPlaceOnGround::SetMaxTraceLength)
        .addProperty("CollisionGroupName", &GC_INIT_PositionPlaceOnGround::GetCollisionGroupName, &GC_INIT_PositionPlaceOnGround::SetCollisionGroupName)
        .addProperty("TraceSet", &GC_INIT_PositionPlaceOnGround::GetTraceSet, &GC_INIT_PositionPlaceOnGround::SetTraceSet)
        .addProperty("TraceMissBehavior", &GC_INIT_PositionPlaceOnGround::GetTraceMissBehavior, &GC_INIT_PositionPlaceOnGround::SetTraceMissBehavior)
        .addProperty("IncludeWater", &GC_INIT_PositionPlaceOnGround::GetIncludeWater, &GC_INIT_PositionPlaceOnGround::SetIncludeWater)
        .addProperty("SetNormal", &GC_INIT_PositionPlaceOnGround::GetSetNormal, &GC_INIT_PositionPlaceOnGround::SetSetNormal)
        .addProperty("SetPXYZOnly", &GC_INIT_PositionPlaceOnGround::GetSetPXYZOnly, &GC_INIT_PositionPlaceOnGround::SetSetPXYZOnly)
        .addProperty("TraceAlongNormal", &GC_INIT_PositionPlaceOnGround::GetTraceAlongNormal, &GC_INIT_PositionPlaceOnGround::SetTraceAlongNormal)
        .addProperty("OffsetonColOnly", &GC_INIT_PositionPlaceOnGround::GetOffsetonColOnly, &GC_INIT_PositionPlaceOnGround::SetOffsetonColOnly)
        .addProperty("OffsetByRadiusFactor", &GC_INIT_PositionPlaceOnGround::GetOffsetByRadiusFactor, &GC_INIT_PositionPlaceOnGround::SetOffsetByRadiusFactor)
        .addProperty("PreserveOffsetCP", &GC_INIT_PositionPlaceOnGround::GetPreserveOffsetCP, &GC_INIT_PositionPlaceOnGround::SetPreserveOffsetCP)
        .addProperty("IgnoreCP", &GC_INIT_PositionPlaceOnGround::GetIgnoreCP, &GC_INIT_PositionPlaceOnGround::SetIgnoreCP)
        .endClass();
}