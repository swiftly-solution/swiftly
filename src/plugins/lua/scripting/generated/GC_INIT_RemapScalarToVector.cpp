#include "../../../core/scripting/generated/classes/GC_INIT_RemapScalarToVector.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapScalarToVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapScalarToVector>("C_INIT_RemapScalarToVector")
        .addProperty("FieldInput", &GC_INIT_RemapScalarToVector::GetFieldInput, &GC_INIT_RemapScalarToVector::SetFieldInput)
        .addProperty("FieldOutput", &GC_INIT_RemapScalarToVector::GetFieldOutput, &GC_INIT_RemapScalarToVector::SetFieldOutput)
        .addProperty("InputMin", &GC_INIT_RemapScalarToVector::GetInputMin, &GC_INIT_RemapScalarToVector::SetInputMin)
        .addProperty("InputMax", &GC_INIT_RemapScalarToVector::GetInputMax, &GC_INIT_RemapScalarToVector::SetInputMax)
        .addProperty("OutputMin", &GC_INIT_RemapScalarToVector::GetOutputMin, &GC_INIT_RemapScalarToVector::SetOutputMin)
        .addProperty("OutputMax", &GC_INIT_RemapScalarToVector::GetOutputMax, &GC_INIT_RemapScalarToVector::SetOutputMax)
        .addProperty("StartTime", &GC_INIT_RemapScalarToVector::GetStartTime, &GC_INIT_RemapScalarToVector::SetStartTime)
        .addProperty("EndTime", &GC_INIT_RemapScalarToVector::GetEndTime, &GC_INIT_RemapScalarToVector::SetEndTime)
        .addProperty("SetMethod", &GC_INIT_RemapScalarToVector::GetSetMethod, &GC_INIT_RemapScalarToVector::SetSetMethod)
        .addProperty("ControlPointNumber", &GC_INIT_RemapScalarToVector::GetControlPointNumber, &GC_INIT_RemapScalarToVector::SetControlPointNumber)
        .addProperty("LocalCoords", &GC_INIT_RemapScalarToVector::GetLocalCoords, &GC_INIT_RemapScalarToVector::SetLocalCoords)
        .addProperty("RemapBias", &GC_INIT_RemapScalarToVector::GetRemapBias, &GC_INIT_RemapScalarToVector::SetRemapBias)
        .endClass();
}