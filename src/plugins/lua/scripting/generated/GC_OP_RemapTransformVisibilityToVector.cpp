#include "../../../core/scripting/generated/classes/GC_OP_RemapTransformVisibilityToVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapTransformVisibilityToVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapTransformVisibilityToVector>("C_OP_RemapTransformVisibilityToVector")
        .addProperty("SetMethod", &GC_OP_RemapTransformVisibilityToVector::GetSetMethod, &GC_OP_RemapTransformVisibilityToVector::SetSetMethod)
        .addProperty("TransformInput", &GC_OP_RemapTransformVisibilityToVector::GetTransformInput, &GC_OP_RemapTransformVisibilityToVector::SetTransformInput)
        .addProperty("FieldOutput", &GC_OP_RemapTransformVisibilityToVector::GetFieldOutput, &GC_OP_RemapTransformVisibilityToVector::SetFieldOutput)
        .addProperty("InputMin", &GC_OP_RemapTransformVisibilityToVector::GetInputMin, &GC_OP_RemapTransformVisibilityToVector::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapTransformVisibilityToVector::GetInputMax, &GC_OP_RemapTransformVisibilityToVector::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapTransformVisibilityToVector::GetOutputMin, &GC_OP_RemapTransformVisibilityToVector::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapTransformVisibilityToVector::GetOutputMax, &GC_OP_RemapTransformVisibilityToVector::SetOutputMax)
        .addProperty("Radius", &GC_OP_RemapTransformVisibilityToVector::GetRadius, &GC_OP_RemapTransformVisibilityToVector::SetRadius)
        .endClass();
}