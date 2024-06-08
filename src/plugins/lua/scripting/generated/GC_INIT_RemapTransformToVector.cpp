#include "../../../core/scripting/generated/classes/GC_INIT_RemapTransformToVector.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapTransformToVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapTransformToVector>("C_INIT_RemapTransformToVector")
        .addProperty("FieldOutput", &GC_INIT_RemapTransformToVector::GetFieldOutput, &GC_INIT_RemapTransformToVector::SetFieldOutput)
        .addProperty("InputMin", &GC_INIT_RemapTransformToVector::GetInputMin, &GC_INIT_RemapTransformToVector::SetInputMin)
        .addProperty("InputMax", &GC_INIT_RemapTransformToVector::GetInputMax, &GC_INIT_RemapTransformToVector::SetInputMax)
        .addProperty("OutputMin", &GC_INIT_RemapTransformToVector::GetOutputMin, &GC_INIT_RemapTransformToVector::SetOutputMin)
        .addProperty("OutputMax", &GC_INIT_RemapTransformToVector::GetOutputMax, &GC_INIT_RemapTransformToVector::SetOutputMax)
        .addProperty("TransformInput", &GC_INIT_RemapTransformToVector::GetTransformInput, &GC_INIT_RemapTransformToVector::SetTransformInput)
        .addProperty("LocalSpaceTransform", &GC_INIT_RemapTransformToVector::GetLocalSpaceTransform, &GC_INIT_RemapTransformToVector::SetLocalSpaceTransform)
        .addProperty("StartTime", &GC_INIT_RemapTransformToVector::GetStartTime, &GC_INIT_RemapTransformToVector::SetStartTime)
        .addProperty("EndTime", &GC_INIT_RemapTransformToVector::GetEndTime, &GC_INIT_RemapTransformToVector::SetEndTime)
        .addProperty("SetMethod", &GC_INIT_RemapTransformToVector::GetSetMethod, &GC_INIT_RemapTransformToVector::SetSetMethod)
        .addProperty("Offset", &GC_INIT_RemapTransformToVector::GetOffset, &GC_INIT_RemapTransformToVector::SetOffset)
        .addProperty("Accelerate", &GC_INIT_RemapTransformToVector::GetAccelerate, &GC_INIT_RemapTransformToVector::SetAccelerate)
        .addProperty("RemapBias", &GC_INIT_RemapTransformToVector::GetRemapBias, &GC_INIT_RemapTransformToVector::SetRemapBias)
        .endClass();
}