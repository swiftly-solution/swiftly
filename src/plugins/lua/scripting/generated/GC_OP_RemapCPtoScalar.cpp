#include "../../../core/scripting/generated/classes/GC_OP_RemapCPtoScalar.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapCPtoScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapCPtoScalar>("C_OP_RemapCPtoScalar")
        .addProperty("CPInput", &GC_OP_RemapCPtoScalar::GetCPInput, &GC_OP_RemapCPtoScalar::SetCPInput)
        .addProperty("FieldOutput", &GC_OP_RemapCPtoScalar::GetFieldOutput, &GC_OP_RemapCPtoScalar::SetFieldOutput)
        .addProperty("Field", &GC_OP_RemapCPtoScalar::GetField, &GC_OP_RemapCPtoScalar::SetField)
        .addProperty("InputMin", &GC_OP_RemapCPtoScalar::GetInputMin, &GC_OP_RemapCPtoScalar::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapCPtoScalar::GetInputMax, &GC_OP_RemapCPtoScalar::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapCPtoScalar::GetOutputMin, &GC_OP_RemapCPtoScalar::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapCPtoScalar::GetOutputMax, &GC_OP_RemapCPtoScalar::SetOutputMax)
        .addProperty("StartTime", &GC_OP_RemapCPtoScalar::GetStartTime, &GC_OP_RemapCPtoScalar::SetStartTime)
        .addProperty("EndTime", &GC_OP_RemapCPtoScalar::GetEndTime, &GC_OP_RemapCPtoScalar::SetEndTime)
        .addProperty("InterpRate", &GC_OP_RemapCPtoScalar::GetInterpRate, &GC_OP_RemapCPtoScalar::SetInterpRate)
        .addProperty("SetMethod", &GC_OP_RemapCPtoScalar::GetSetMethod, &GC_OP_RemapCPtoScalar::SetSetMethod)
        .endClass();
}