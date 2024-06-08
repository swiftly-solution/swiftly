#include "../../../core/scripting/generated/classes/GC_OP_RemapVectortoCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapVectortoCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapVectortoCP>("C_OP_RemapVectortoCP")
        .addProperty("OutControlPointNumber", &GC_OP_RemapVectortoCP::GetOutControlPointNumber, &GC_OP_RemapVectortoCP::SetOutControlPointNumber)
        .addProperty("FieldInput", &GC_OP_RemapVectortoCP::GetFieldInput, &GC_OP_RemapVectortoCP::SetFieldInput)
        .addProperty("ParticleNumber", &GC_OP_RemapVectortoCP::GetParticleNumber, &GC_OP_RemapVectortoCP::SetParticleNumber)
        .endClass();
}