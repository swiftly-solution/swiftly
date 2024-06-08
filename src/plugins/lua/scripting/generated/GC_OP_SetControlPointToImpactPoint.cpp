#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointToImpactPoint.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointToImpactPoint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointToImpactPoint>("C_OP_SetControlPointToImpactPoint")
        .addProperty("CPOut", &GC_OP_SetControlPointToImpactPoint::GetCPOut, &GC_OP_SetControlPointToImpactPoint::SetCPOut)
        .addProperty("CPIn", &GC_OP_SetControlPointToImpactPoint::GetCPIn, &GC_OP_SetControlPointToImpactPoint::SetCPIn)
        .addProperty("UpdateRate", &GC_OP_SetControlPointToImpactPoint::GetUpdateRate, &GC_OP_SetControlPointToImpactPoint::SetUpdateRate)
        .addProperty("TraceLength", &GC_OP_SetControlPointToImpactPoint::GetTraceLength, &GC_OP_SetControlPointToImpactPoint::SetTraceLength)
        .addProperty("StartOffset", &GC_OP_SetControlPointToImpactPoint::GetStartOffset, &GC_OP_SetControlPointToImpactPoint::SetStartOffset)
        .addProperty("Offset", &GC_OP_SetControlPointToImpactPoint::GetOffset, &GC_OP_SetControlPointToImpactPoint::SetOffset)
        .addProperty("TraceDir", &GC_OP_SetControlPointToImpactPoint::GetTraceDir, &GC_OP_SetControlPointToImpactPoint::SetTraceDir)
        .addProperty("CollisionGroupName", &GC_OP_SetControlPointToImpactPoint::GetCollisionGroupName, &GC_OP_SetControlPointToImpactPoint::SetCollisionGroupName)
        .addProperty("TraceSet", &GC_OP_SetControlPointToImpactPoint::GetTraceSet, &GC_OP_SetControlPointToImpactPoint::SetTraceSet)
        .addProperty("SetToEndpoint", &GC_OP_SetControlPointToImpactPoint::GetSetToEndpoint, &GC_OP_SetControlPointToImpactPoint::SetSetToEndpoint)
        .addProperty("TraceToClosestSurface", &GC_OP_SetControlPointToImpactPoint::GetTraceToClosestSurface, &GC_OP_SetControlPointToImpactPoint::SetTraceToClosestSurface)
        .addProperty("IncludeWater", &GC_OP_SetControlPointToImpactPoint::GetIncludeWater, &GC_OP_SetControlPointToImpactPoint::SetIncludeWater)
        .endClass();
}