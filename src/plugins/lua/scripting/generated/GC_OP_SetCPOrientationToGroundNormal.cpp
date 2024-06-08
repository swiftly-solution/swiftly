#include "../../../core/scripting/generated/classes/GC_OP_SetCPOrientationToGroundNormal.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetCPOrientationToGroundNormal(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetCPOrientationToGroundNormal>("C_OP_SetCPOrientationToGroundNormal")
        .addProperty("InterpRate", &GC_OP_SetCPOrientationToGroundNormal::GetInterpRate, &GC_OP_SetCPOrientationToGroundNormal::SetInterpRate)
        .addProperty("MaxTraceLength", &GC_OP_SetCPOrientationToGroundNormal::GetMaxTraceLength, &GC_OP_SetCPOrientationToGroundNormal::SetMaxTraceLength)
        .addProperty("Tolerance", &GC_OP_SetCPOrientationToGroundNormal::GetTolerance, &GC_OP_SetCPOrientationToGroundNormal::SetTolerance)
        .addProperty("TraceOffset", &GC_OP_SetCPOrientationToGroundNormal::GetTraceOffset, &GC_OP_SetCPOrientationToGroundNormal::SetTraceOffset)
        .addProperty("CollisionGroupName", &GC_OP_SetCPOrientationToGroundNormal::GetCollisionGroupName, &GC_OP_SetCPOrientationToGroundNormal::SetCollisionGroupName)
        .addProperty("TraceSet", &GC_OP_SetCPOrientationToGroundNormal::GetTraceSet, &GC_OP_SetCPOrientationToGroundNormal::SetTraceSet)
        .addProperty("InputCP", &GC_OP_SetCPOrientationToGroundNormal::GetInputCP, &GC_OP_SetCPOrientationToGroundNormal::SetInputCP)
        .addProperty("OutputCP", &GC_OP_SetCPOrientationToGroundNormal::GetOutputCP, &GC_OP_SetCPOrientationToGroundNormal::SetOutputCP)
        .addProperty("IncludeWater", &GC_OP_SetCPOrientationToGroundNormal::GetIncludeWater, &GC_OP_SetCPOrientationToGroundNormal::SetIncludeWater)
        .endClass();
}