#include "../../../core/scripting/generated/classes/GC_OP_RemapAverageScalarValuetoCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapAverageScalarValuetoCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapAverageScalarValuetoCP>("C_OP_RemapAverageScalarValuetoCP")
        .addProperty("OutControlPointNumber", &GC_OP_RemapAverageScalarValuetoCP::GetOutControlPointNumber, &GC_OP_RemapAverageScalarValuetoCP::SetOutControlPointNumber)
        .addProperty("OutVectorField", &GC_OP_RemapAverageScalarValuetoCP::GetOutVectorField, &GC_OP_RemapAverageScalarValuetoCP::SetOutVectorField)
        .addProperty("Field", &GC_OP_RemapAverageScalarValuetoCP::GetField, &GC_OP_RemapAverageScalarValuetoCP::SetField)
        .addProperty("InputMin", &GC_OP_RemapAverageScalarValuetoCP::GetInputMin, &GC_OP_RemapAverageScalarValuetoCP::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapAverageScalarValuetoCP::GetInputMax, &GC_OP_RemapAverageScalarValuetoCP::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapAverageScalarValuetoCP::GetOutputMin, &GC_OP_RemapAverageScalarValuetoCP::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapAverageScalarValuetoCP::GetOutputMax, &GC_OP_RemapAverageScalarValuetoCP::SetOutputMax)
        .endClass();
}