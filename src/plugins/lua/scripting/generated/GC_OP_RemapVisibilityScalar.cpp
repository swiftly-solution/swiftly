#include "../../../core/scripting/generated/classes/GC_OP_RemapVisibilityScalar.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapVisibilityScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapVisibilityScalar>("C_OP_RemapVisibilityScalar")
        .addProperty("FieldInput", &GC_OP_RemapVisibilityScalar::GetFieldInput, &GC_OP_RemapVisibilityScalar::SetFieldInput)
        .addProperty("FieldOutput", &GC_OP_RemapVisibilityScalar::GetFieldOutput, &GC_OP_RemapVisibilityScalar::SetFieldOutput)
        .addProperty("InputMin", &GC_OP_RemapVisibilityScalar::GetInputMin, &GC_OP_RemapVisibilityScalar::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapVisibilityScalar::GetInputMax, &GC_OP_RemapVisibilityScalar::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapVisibilityScalar::GetOutputMin, &GC_OP_RemapVisibilityScalar::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapVisibilityScalar::GetOutputMax, &GC_OP_RemapVisibilityScalar::SetOutputMax)
        .addProperty("RadiusScale", &GC_OP_RemapVisibilityScalar::GetRadiusScale, &GC_OP_RemapVisibilityScalar::SetRadiusScale)
        .endClass();
}