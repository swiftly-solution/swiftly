#include "../../../core/scripting/generated/classes/GC_OP_RemapCPtoCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapCPtoCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapCPtoCP>("C_OP_RemapCPtoCP")
        .addProperty("InputControlPoint", &GC_OP_RemapCPtoCP::GetInputControlPoint, &GC_OP_RemapCPtoCP::SetInputControlPoint)
        .addProperty("OutputControlPoint", &GC_OP_RemapCPtoCP::GetOutputControlPoint, &GC_OP_RemapCPtoCP::SetOutputControlPoint)
        .addProperty("InputField", &GC_OP_RemapCPtoCP::GetInputField, &GC_OP_RemapCPtoCP::SetInputField)
        .addProperty("OutputField", &GC_OP_RemapCPtoCP::GetOutputField, &GC_OP_RemapCPtoCP::SetOutputField)
        .addProperty("InputMin", &GC_OP_RemapCPtoCP::GetInputMin, &GC_OP_RemapCPtoCP::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapCPtoCP::GetInputMax, &GC_OP_RemapCPtoCP::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapCPtoCP::GetOutputMin, &GC_OP_RemapCPtoCP::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapCPtoCP::GetOutputMax, &GC_OP_RemapCPtoCP::SetOutputMax)
        .addProperty("Derivative", &GC_OP_RemapCPtoCP::GetDerivative, &GC_OP_RemapCPtoCP::SetDerivative)
        .addProperty("InterpRate", &GC_OP_RemapCPtoCP::GetInterpRate, &GC_OP_RemapCPtoCP::SetInterpRate)
        .endClass();
}