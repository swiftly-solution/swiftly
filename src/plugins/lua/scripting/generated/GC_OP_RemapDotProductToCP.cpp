#include "../../../core/scripting/generated/classes/GC_OP_RemapDotProductToCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapDotProductToCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapDotProductToCP>("C_OP_RemapDotProductToCP")
        .addProperty("InputCP1", &GC_OP_RemapDotProductToCP::GetInputCP1, &GC_OP_RemapDotProductToCP::SetInputCP1)
        .addProperty("InputCP2", &GC_OP_RemapDotProductToCP::GetInputCP2, &GC_OP_RemapDotProductToCP::SetInputCP2)
        .addProperty("OutputCP", &GC_OP_RemapDotProductToCP::GetOutputCP, &GC_OP_RemapDotProductToCP::SetOutputCP)
        .addProperty("OutVectorField", &GC_OP_RemapDotProductToCP::GetOutVectorField, &GC_OP_RemapDotProductToCP::SetOutVectorField)
        .addProperty("InputMin", &GC_OP_RemapDotProductToCP::GetInputMin, &GC_OP_RemapDotProductToCP::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapDotProductToCP::GetInputMax, &GC_OP_RemapDotProductToCP::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapDotProductToCP::GetOutputMin, &GC_OP_RemapDotProductToCP::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapDotProductToCP::GetOutputMax, &GC_OP_RemapDotProductToCP::SetOutputMax)
        .endClass();
}