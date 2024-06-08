#include "../../../core/scripting/generated/classes/GC_INIT_RemapCPtoScalar.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapCPtoScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapCPtoScalar>("C_INIT_RemapCPtoScalar")
        .addProperty("CPInput", &GC_INIT_RemapCPtoScalar::GetCPInput, &GC_INIT_RemapCPtoScalar::SetCPInput)
        .addProperty("FieldOutput", &GC_INIT_RemapCPtoScalar::GetFieldOutput, &GC_INIT_RemapCPtoScalar::SetFieldOutput)
        .addProperty("Field", &GC_INIT_RemapCPtoScalar::GetField, &GC_INIT_RemapCPtoScalar::SetField)
        .addProperty("InputMin", &GC_INIT_RemapCPtoScalar::GetInputMin, &GC_INIT_RemapCPtoScalar::SetInputMin)
        .addProperty("InputMax", &GC_INIT_RemapCPtoScalar::GetInputMax, &GC_INIT_RemapCPtoScalar::SetInputMax)
        .addProperty("OutputMin", &GC_INIT_RemapCPtoScalar::GetOutputMin, &GC_INIT_RemapCPtoScalar::SetOutputMin)
        .addProperty("OutputMax", &GC_INIT_RemapCPtoScalar::GetOutputMax, &GC_INIT_RemapCPtoScalar::SetOutputMax)
        .addProperty("StartTime", &GC_INIT_RemapCPtoScalar::GetStartTime, &GC_INIT_RemapCPtoScalar::SetStartTime)
        .addProperty("EndTime", &GC_INIT_RemapCPtoScalar::GetEndTime, &GC_INIT_RemapCPtoScalar::SetEndTime)
        .addProperty("SetMethod", &GC_INIT_RemapCPtoScalar::GetSetMethod, &GC_INIT_RemapCPtoScalar::SetSetMethod)
        .addProperty("RemapBias", &GC_INIT_RemapCPtoScalar::GetRemapBias, &GC_INIT_RemapCPtoScalar::SetRemapBias)
        .endClass();
}