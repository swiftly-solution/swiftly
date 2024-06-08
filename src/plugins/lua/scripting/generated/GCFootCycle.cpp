#include "../../../core/scripting/generated/classes/GCFootCycle.h"
#include "../core.h"

void SetupLuaClassGCFootCycle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootCycle>("CFootCycle")

        .endClass();
}