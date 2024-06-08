#include "../../../core/scripting/generated/classes/GC_OP_NormalizeVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_NormalizeVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_NormalizeVector>("C_OP_NormalizeVector")
        .addProperty("FieldOutput", &GC_OP_NormalizeVector::GetFieldOutput, &GC_OP_NormalizeVector::SetFieldOutput)
        .addProperty("Scale", &GC_OP_NormalizeVector::GetScale, &GC_OP_NormalizeVector::SetScale)
        .endClass();
}