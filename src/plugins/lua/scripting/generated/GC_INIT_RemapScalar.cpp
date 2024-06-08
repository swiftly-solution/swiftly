#include "../../../core/scripting/generated/classes/GC_INIT_RemapScalar.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapScalar>("C_INIT_RemapScalar")
        .addProperty("FieldInput", &GC_INIT_RemapScalar::GetFieldInput, &GC_INIT_RemapScalar::SetFieldInput)
        .addProperty("FieldOutput", &GC_INIT_RemapScalar::GetFieldOutput, &GC_INIT_RemapScalar::SetFieldOutput)
        .addProperty("InputMin", &GC_INIT_RemapScalar::GetInputMin, &GC_INIT_RemapScalar::SetInputMin)
        .addProperty("InputMax", &GC_INIT_RemapScalar::GetInputMax, &GC_INIT_RemapScalar::SetInputMax)
        .addProperty("OutputMin", &GC_INIT_RemapScalar::GetOutputMin, &GC_INIT_RemapScalar::SetOutputMin)
        .addProperty("OutputMax", &GC_INIT_RemapScalar::GetOutputMax, &GC_INIT_RemapScalar::SetOutputMax)
        .addProperty("StartTime", &GC_INIT_RemapScalar::GetStartTime, &GC_INIT_RemapScalar::SetStartTime)
        .addProperty("EndTime", &GC_INIT_RemapScalar::GetEndTime, &GC_INIT_RemapScalar::SetEndTime)
        .addProperty("SetMethod", &GC_INIT_RemapScalar::GetSetMethod, &GC_INIT_RemapScalar::SetSetMethod)
        .addProperty("ActiveRange", &GC_INIT_RemapScalar::GetActiveRange, &GC_INIT_RemapScalar::SetActiveRange)
        .addProperty("RemapBias", &GC_INIT_RemapScalar::GetRemapBias, &GC_INIT_RemapScalar::SetRemapBias)
        .endClass();
}