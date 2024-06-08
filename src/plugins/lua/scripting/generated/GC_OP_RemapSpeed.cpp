#include "../../../core/scripting/generated/classes/GC_OP_RemapSpeed.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapSpeed(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapSpeed>("C_OP_RemapSpeed")
        .addProperty("FieldOutput", &GC_OP_RemapSpeed::GetFieldOutput, &GC_OP_RemapSpeed::SetFieldOutput)
        .addProperty("InputMin", &GC_OP_RemapSpeed::GetInputMin, &GC_OP_RemapSpeed::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapSpeed::GetInputMax, &GC_OP_RemapSpeed::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapSpeed::GetOutputMin, &GC_OP_RemapSpeed::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapSpeed::GetOutputMax, &GC_OP_RemapSpeed::SetOutputMax)
        .addProperty("SetMethod", &GC_OP_RemapSpeed::GetSetMethod, &GC_OP_RemapSpeed::SetSetMethod)
        .addProperty("IgnoreDelta", &GC_OP_RemapSpeed::GetIgnoreDelta, &GC_OP_RemapSpeed::SetIgnoreDelta)
        .endClass();
}