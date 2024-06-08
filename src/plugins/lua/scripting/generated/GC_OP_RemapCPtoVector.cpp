#include "../../../core/scripting/generated/classes/GC_OP_RemapCPtoVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapCPtoVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapCPtoVector>("C_OP_RemapCPtoVector")
        .addProperty("CPInput", &GC_OP_RemapCPtoVector::GetCPInput, &GC_OP_RemapCPtoVector::SetCPInput)
        .addProperty("FieldOutput", &GC_OP_RemapCPtoVector::GetFieldOutput, &GC_OP_RemapCPtoVector::SetFieldOutput)
        .addProperty("LocalSpaceCP", &GC_OP_RemapCPtoVector::GetLocalSpaceCP, &GC_OP_RemapCPtoVector::SetLocalSpaceCP)
        .addProperty("InputMin", &GC_OP_RemapCPtoVector::GetInputMin, &GC_OP_RemapCPtoVector::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapCPtoVector::GetInputMax, &GC_OP_RemapCPtoVector::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapCPtoVector::GetOutputMin, &GC_OP_RemapCPtoVector::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapCPtoVector::GetOutputMax, &GC_OP_RemapCPtoVector::SetOutputMax)
        .addProperty("StartTime", &GC_OP_RemapCPtoVector::GetStartTime, &GC_OP_RemapCPtoVector::SetStartTime)
        .addProperty("EndTime", &GC_OP_RemapCPtoVector::GetEndTime, &GC_OP_RemapCPtoVector::SetEndTime)
        .addProperty("InterpRate", &GC_OP_RemapCPtoVector::GetInterpRate, &GC_OP_RemapCPtoVector::SetInterpRate)
        .addProperty("SetMethod", &GC_OP_RemapCPtoVector::GetSetMethod, &GC_OP_RemapCPtoVector::SetSetMethod)
        .addProperty("Offset", &GC_OP_RemapCPtoVector::GetOffset, &GC_OP_RemapCPtoVector::SetOffset)
        .addProperty("Accelerate", &GC_OP_RemapCPtoVector::GetAccelerate, &GC_OP_RemapCPtoVector::SetAccelerate)
        .endClass();
}