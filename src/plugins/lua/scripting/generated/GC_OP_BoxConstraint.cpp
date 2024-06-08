#include "../../../core/scripting/generated/classes/GC_OP_BoxConstraint.h"
#include "../core.h"

void SetupLuaClassGC_OP_BoxConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_BoxConstraint>("C_OP_BoxConstraint")
        .addProperty("CP", &GC_OP_BoxConstraint::GetCP, &GC_OP_BoxConstraint::SetCP)
        .addProperty("LocalSpace", &GC_OP_BoxConstraint::GetLocalSpace, &GC_OP_BoxConstraint::SetLocalSpace)
        .addProperty("AccountForRadius", &GC_OP_BoxConstraint::GetAccountForRadius, &GC_OP_BoxConstraint::SetAccountForRadius)
        .endClass();
}