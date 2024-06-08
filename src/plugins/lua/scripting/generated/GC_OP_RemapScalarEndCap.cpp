#include "../../../core/scripting/generated/classes/GC_OP_RemapScalarEndCap.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapScalarEndCap(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapScalarEndCap>("C_OP_RemapScalarEndCap")
        .addProperty("FieldInput", &GC_OP_RemapScalarEndCap::GetFieldInput, &GC_OP_RemapScalarEndCap::SetFieldInput)
        .addProperty("FieldOutput", &GC_OP_RemapScalarEndCap::GetFieldOutput, &GC_OP_RemapScalarEndCap::SetFieldOutput)
        .addProperty("InputMin", &GC_OP_RemapScalarEndCap::GetInputMin, &GC_OP_RemapScalarEndCap::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapScalarEndCap::GetInputMax, &GC_OP_RemapScalarEndCap::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapScalarEndCap::GetOutputMin, &GC_OP_RemapScalarEndCap::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapScalarEndCap::GetOutputMax, &GC_OP_RemapScalarEndCap::SetOutputMax)
        .endClass();
}