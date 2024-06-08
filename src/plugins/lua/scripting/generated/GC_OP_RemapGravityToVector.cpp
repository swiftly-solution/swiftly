#include "../../../core/scripting/generated/classes/GC_OP_RemapGravityToVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapGravityToVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapGravityToVector>("C_OP_RemapGravityToVector")
        .addProperty("Input1", &GC_OP_RemapGravityToVector::GetInput1, &GC_OP_RemapGravityToVector::SetInput1)
        .addProperty("OutputField", &GC_OP_RemapGravityToVector::GetOutputField, &GC_OP_RemapGravityToVector::SetOutputField)
        .addProperty("SetMethod", &GC_OP_RemapGravityToVector::GetSetMethod, &GC_OP_RemapGravityToVector::SetSetMethod)
        .addProperty("NormalizedOutput", &GC_OP_RemapGravityToVector::GetNormalizedOutput, &GC_OP_RemapGravityToVector::SetNormalizedOutput)
        .endClass();
}