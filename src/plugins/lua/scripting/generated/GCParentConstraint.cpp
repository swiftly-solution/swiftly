#include "../../../core/scripting/generated/classes/GCParentConstraint.h"
#include "../core.h"

void SetupLuaClassGCParentConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParentConstraint>("CParentConstraint")

        .endClass();
}