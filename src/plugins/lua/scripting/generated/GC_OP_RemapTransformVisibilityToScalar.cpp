#include "../../../core/scripting/generated/classes/GC_OP_RemapTransformVisibilityToScalar.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapTransformVisibilityToScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapTransformVisibilityToScalar>("C_OP_RemapTransformVisibilityToScalar")
        .addProperty("SetMethod", &GC_OP_RemapTransformVisibilityToScalar::GetSetMethod, &GC_OP_RemapTransformVisibilityToScalar::SetSetMethod)
        .addProperty("TransformInput", &GC_OP_RemapTransformVisibilityToScalar::GetTransformInput, &GC_OP_RemapTransformVisibilityToScalar::SetTransformInput)
        .addProperty("FieldOutput", &GC_OP_RemapTransformVisibilityToScalar::GetFieldOutput, &GC_OP_RemapTransformVisibilityToScalar::SetFieldOutput)
        .addProperty("InputMin", &GC_OP_RemapTransformVisibilityToScalar::GetInputMin, &GC_OP_RemapTransformVisibilityToScalar::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapTransformVisibilityToScalar::GetInputMax, &GC_OP_RemapTransformVisibilityToScalar::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapTransformVisibilityToScalar::GetOutputMin, &GC_OP_RemapTransformVisibilityToScalar::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapTransformVisibilityToScalar::GetOutputMax, &GC_OP_RemapTransformVisibilityToScalar::SetOutputMax)
        .addProperty("Radius", &GC_OP_RemapTransformVisibilityToScalar::GetRadius, &GC_OP_RemapTransformVisibilityToScalar::SetRadius)
        .endClass();
}