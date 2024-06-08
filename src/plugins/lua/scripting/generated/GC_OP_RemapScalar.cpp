#include "../../../core/scripting/generated/classes/GC_OP_RemapScalar.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapScalar>("C_OP_RemapScalar")
        .addProperty("FieldInput", &GC_OP_RemapScalar::GetFieldInput, &GC_OP_RemapScalar::SetFieldInput)
        .addProperty("FieldOutput", &GC_OP_RemapScalar::GetFieldOutput, &GC_OP_RemapScalar::SetFieldOutput)
        .addProperty("InputMin", &GC_OP_RemapScalar::GetInputMin, &GC_OP_RemapScalar::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapScalar::GetInputMax, &GC_OP_RemapScalar::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapScalar::GetOutputMin, &GC_OP_RemapScalar::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapScalar::GetOutputMax, &GC_OP_RemapScalar::SetOutputMax)
        .addProperty("OldCode", &GC_OP_RemapScalar::GetOldCode, &GC_OP_RemapScalar::SetOldCode)
        .endClass();
}