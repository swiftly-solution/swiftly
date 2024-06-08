#include "../../../core/scripting/generated/classes/GC_OP_DistanceToTransform.h"
#include "../core.h"

void SetupLuaClassGC_OP_DistanceToTransform(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_DistanceToTransform>("C_OP_DistanceToTransform")
        .addProperty("FieldOutput", &GC_OP_DistanceToTransform::GetFieldOutput, &GC_OP_DistanceToTransform::SetFieldOutput)
        .addProperty("InputMin", &GC_OP_DistanceToTransform::GetInputMin, &GC_OP_DistanceToTransform::SetInputMin)
        .addProperty("InputMax", &GC_OP_DistanceToTransform::GetInputMax, &GC_OP_DistanceToTransform::SetInputMax)
        .addProperty("OutputMin", &GC_OP_DistanceToTransform::GetOutputMin, &GC_OP_DistanceToTransform::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_DistanceToTransform::GetOutputMax, &GC_OP_DistanceToTransform::SetOutputMax)
        .addProperty("TransformStart", &GC_OP_DistanceToTransform::GetTransformStart, &GC_OP_DistanceToTransform::SetTransformStart)
        .addProperty("LOS", &GC_OP_DistanceToTransform::GetLOS, &GC_OP_DistanceToTransform::SetLOS)
        .addProperty("CollisionGroupName", &GC_OP_DistanceToTransform::GetCollisionGroupName, &GC_OP_DistanceToTransform::SetCollisionGroupName)
        .addProperty("TraceSet", &GC_OP_DistanceToTransform::GetTraceSet, &GC_OP_DistanceToTransform::SetTraceSet)
        .addProperty("MaxTraceLength", &GC_OP_DistanceToTransform::GetMaxTraceLength, &GC_OP_DistanceToTransform::SetMaxTraceLength)
        .addProperty("LOSScale", &GC_OP_DistanceToTransform::GetLOSScale, &GC_OP_DistanceToTransform::SetLOSScale)
        .addProperty("SetMethod", &GC_OP_DistanceToTransform::GetSetMethod, &GC_OP_DistanceToTransform::SetSetMethod)
        .addProperty("ActiveRange", &GC_OP_DistanceToTransform::GetActiveRange, &GC_OP_DistanceToTransform::SetActiveRange)
        .addProperty("Additive", &GC_OP_DistanceToTransform::GetAdditive, &GC_OP_DistanceToTransform::SetAdditive)
        .addProperty("ComponentScale", &GC_OP_DistanceToTransform::GetComponentScale, &GC_OP_DistanceToTransform::SetComponentScale)
        .endClass();
}