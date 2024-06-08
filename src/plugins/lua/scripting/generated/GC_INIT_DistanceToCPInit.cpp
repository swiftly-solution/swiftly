#include "../../../core/scripting/generated/classes/GC_INIT_DistanceToCPInit.h"
#include "../core.h"

void SetupLuaClassGC_INIT_DistanceToCPInit(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_DistanceToCPInit>("C_INIT_DistanceToCPInit")
        .addProperty("FieldOutput", &GC_INIT_DistanceToCPInit::GetFieldOutput, &GC_INIT_DistanceToCPInit::SetFieldOutput)
        .addProperty("InputMin", &GC_INIT_DistanceToCPInit::GetInputMin, &GC_INIT_DistanceToCPInit::SetInputMin)
        .addProperty("InputMax", &GC_INIT_DistanceToCPInit::GetInputMax, &GC_INIT_DistanceToCPInit::SetInputMax)
        .addProperty("OutputMin", &GC_INIT_DistanceToCPInit::GetOutputMin, &GC_INIT_DistanceToCPInit::SetOutputMin)
        .addProperty("OutputMax", &GC_INIT_DistanceToCPInit::GetOutputMax, &GC_INIT_DistanceToCPInit::SetOutputMax)
        .addProperty("StartCP", &GC_INIT_DistanceToCPInit::GetStartCP, &GC_INIT_DistanceToCPInit::SetStartCP)
        .addProperty("LOS", &GC_INIT_DistanceToCPInit::GetLOS, &GC_INIT_DistanceToCPInit::SetLOS)
        .addProperty("CollisionGroupName", &GC_INIT_DistanceToCPInit::GetCollisionGroupName, &GC_INIT_DistanceToCPInit::SetCollisionGroupName)
        .addProperty("TraceSet", &GC_INIT_DistanceToCPInit::GetTraceSet, &GC_INIT_DistanceToCPInit::SetTraceSet)
        .addProperty("MaxTraceLength", &GC_INIT_DistanceToCPInit::GetMaxTraceLength, &GC_INIT_DistanceToCPInit::SetMaxTraceLength)
        .addProperty("LOSScale", &GC_INIT_DistanceToCPInit::GetLOSScale, &GC_INIT_DistanceToCPInit::SetLOSScale)
        .addProperty("SetMethod", &GC_INIT_DistanceToCPInit::GetSetMethod, &GC_INIT_DistanceToCPInit::SetSetMethod)
        .addProperty("ActiveRange", &GC_INIT_DistanceToCPInit::GetActiveRange, &GC_INIT_DistanceToCPInit::SetActiveRange)
        .addProperty("DistanceScale", &GC_INIT_DistanceToCPInit::GetDistanceScale, &GC_INIT_DistanceToCPInit::SetDistanceScale)
        .addProperty("RemapBias", &GC_INIT_DistanceToCPInit::GetRemapBias, &GC_INIT_DistanceToCPInit::SetRemapBias)
        .endClass();
}