#include "../../../core/scripting/generated/classes/GC_OP_RemapVelocityToVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapVelocityToVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapVelocityToVector>("C_OP_RemapVelocityToVector")
        .addProperty("FieldOutput", &GC_OP_RemapVelocityToVector::GetFieldOutput, &GC_OP_RemapVelocityToVector::SetFieldOutput)
        .addProperty("Scale", &GC_OP_RemapVelocityToVector::GetScale, &GC_OP_RemapVelocityToVector::SetScale)
        .addProperty("Normalize", &GC_OP_RemapVelocityToVector::GetNormalize, &GC_OP_RemapVelocityToVector::SetNormalize)
        .endClass();
}