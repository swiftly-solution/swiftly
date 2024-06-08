#include "../../../core/scripting/generated/classes/GC_OP_RemapSpeedtoCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapSpeedtoCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapSpeedtoCP>("C_OP_RemapSpeedtoCP")
        .addProperty("InControlPointNumber", &GC_OP_RemapSpeedtoCP::GetInControlPointNumber, &GC_OP_RemapSpeedtoCP::SetInControlPointNumber)
        .addProperty("OutControlPointNumber", &GC_OP_RemapSpeedtoCP::GetOutControlPointNumber, &GC_OP_RemapSpeedtoCP::SetOutControlPointNumber)
        .addProperty("Field", &GC_OP_RemapSpeedtoCP::GetField, &GC_OP_RemapSpeedtoCP::SetField)
        .addProperty("InputMin", &GC_OP_RemapSpeedtoCP::GetInputMin, &GC_OP_RemapSpeedtoCP::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapSpeedtoCP::GetInputMax, &GC_OP_RemapSpeedtoCP::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapSpeedtoCP::GetOutputMin, &GC_OP_RemapSpeedtoCP::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapSpeedtoCP::GetOutputMax, &GC_OP_RemapSpeedtoCP::SetOutputMax)
        .addProperty("UseDeltaV", &GC_OP_RemapSpeedtoCP::GetUseDeltaV, &GC_OP_RemapSpeedtoCP::SetUseDeltaV)
        .endClass();
}