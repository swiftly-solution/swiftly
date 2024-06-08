#include "../../../core/scripting/generated/classes/GC_OP_WorldCollideConstraint.h"
#include "../core.h"

void SetupLuaClassGC_OP_WorldCollideConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_WorldCollideConstraint>("C_OP_WorldCollideConstraint")

        .endClass();
}