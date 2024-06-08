#include "../../../core/scripting/generated/classes/GCPointConstraint.h"
#include "../core.h"

void SetupLuaClassGCPointConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointConstraint>("CPointConstraint")

        .endClass();
}