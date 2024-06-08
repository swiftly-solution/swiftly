#include "../../../core/scripting/generated/classes/GC_OP_DistanceBetweenTransforms.h"
#include "../core.h"

void SetupLuaClassGC_OP_DistanceBetweenTransforms(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_DistanceBetweenTransforms>("C_OP_DistanceBetweenTransforms")
        .addProperty("FieldOutput", &GC_OP_DistanceBetweenTransforms::GetFieldOutput, &GC_OP_DistanceBetweenTransforms::SetFieldOutput)
        .addProperty("TransformStart", &GC_OP_DistanceBetweenTransforms::GetTransformStart, &GC_OP_DistanceBetweenTransforms::SetTransformStart)
        .addProperty("TransformEnd", &GC_OP_DistanceBetweenTransforms::GetTransformEnd, &GC_OP_DistanceBetweenTransforms::SetTransformEnd)
        .addProperty("InputMin", &GC_OP_DistanceBetweenTransforms::GetInputMin, &GC_OP_DistanceBetweenTransforms::SetInputMin)
        .addProperty("InputMax", &GC_OP_DistanceBetweenTransforms::GetInputMax, &GC_OP_DistanceBetweenTransforms::SetInputMax)
        .addProperty("OutputMin", &GC_OP_DistanceBetweenTransforms::GetOutputMin, &GC_OP_DistanceBetweenTransforms::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_DistanceBetweenTransforms::GetOutputMax, &GC_OP_DistanceBetweenTransforms::SetOutputMax)
        .addProperty("MaxTraceLength", &GC_OP_DistanceBetweenTransforms::GetMaxTraceLength, &GC_OP_DistanceBetweenTransforms::SetMaxTraceLength)
        .addProperty("LOSScale", &GC_OP_DistanceBetweenTransforms::GetLOSScale, &GC_OP_DistanceBetweenTransforms::SetLOSScale)
        .addProperty("CollisionGroupName", &GC_OP_DistanceBetweenTransforms::GetCollisionGroupName, &GC_OP_DistanceBetweenTransforms::SetCollisionGroupName)
        .addProperty("TraceSet", &GC_OP_DistanceBetweenTransforms::GetTraceSet, &GC_OP_DistanceBetweenTransforms::SetTraceSet)
        .addProperty("LOS", &GC_OP_DistanceBetweenTransforms::GetLOS, &GC_OP_DistanceBetweenTransforms::SetLOS)
        .addProperty("SetMethod", &GC_OP_DistanceBetweenTransforms::GetSetMethod, &GC_OP_DistanceBetweenTransforms::SetSetMethod)
        .endClass();
}