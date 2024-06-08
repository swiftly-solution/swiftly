#include "../../../core/scripting/generated/classes/GC_OP_DistanceBetweenCPsToCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_DistanceBetweenCPsToCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_DistanceBetweenCPsToCP>("C_OP_DistanceBetweenCPsToCP")
        .addProperty("StartCP", &GC_OP_DistanceBetweenCPsToCP::GetStartCP, &GC_OP_DistanceBetweenCPsToCP::SetStartCP)
        .addProperty("EndCP", &GC_OP_DistanceBetweenCPsToCP::GetEndCP, &GC_OP_DistanceBetweenCPsToCP::SetEndCP)
        .addProperty("OutputCP", &GC_OP_DistanceBetweenCPsToCP::GetOutputCP, &GC_OP_DistanceBetweenCPsToCP::SetOutputCP)
        .addProperty("OutputCPField", &GC_OP_DistanceBetweenCPsToCP::GetOutputCPField, &GC_OP_DistanceBetweenCPsToCP::SetOutputCPField)
        .addProperty("SetOnce", &GC_OP_DistanceBetweenCPsToCP::GetSetOnce, &GC_OP_DistanceBetweenCPsToCP::SetSetOnce)
        .addProperty("InputMin", &GC_OP_DistanceBetweenCPsToCP::GetInputMin, &GC_OP_DistanceBetweenCPsToCP::SetInputMin)
        .addProperty("InputMax", &GC_OP_DistanceBetweenCPsToCP::GetInputMax, &GC_OP_DistanceBetweenCPsToCP::SetInputMax)
        .addProperty("OutputMin", &GC_OP_DistanceBetweenCPsToCP::GetOutputMin, &GC_OP_DistanceBetweenCPsToCP::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_DistanceBetweenCPsToCP::GetOutputMax, &GC_OP_DistanceBetweenCPsToCP::SetOutputMax)
        .addProperty("MaxTraceLength", &GC_OP_DistanceBetweenCPsToCP::GetMaxTraceLength, &GC_OP_DistanceBetweenCPsToCP::SetMaxTraceLength)
        .addProperty("LOSScale", &GC_OP_DistanceBetweenCPsToCP::GetLOSScale, &GC_OP_DistanceBetweenCPsToCP::SetLOSScale)
        .addProperty("LOS", &GC_OP_DistanceBetweenCPsToCP::GetLOS, &GC_OP_DistanceBetweenCPsToCP::SetLOS)
        .addProperty("CollisionGroupName", &GC_OP_DistanceBetweenCPsToCP::GetCollisionGroupName, &GC_OP_DistanceBetweenCPsToCP::SetCollisionGroupName)
        .addProperty("TraceSet", &GC_OP_DistanceBetweenCPsToCP::GetTraceSet, &GC_OP_DistanceBetweenCPsToCP::SetTraceSet)
        .addProperty("SetParent", &GC_OP_DistanceBetweenCPsToCP::GetSetParent, &GC_OP_DistanceBetweenCPsToCP::SetSetParent)
        .endClass();
}