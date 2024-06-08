#include "../../../core/scripting/generated/classes/GCAnimCycle.h"
#include "../core.h"

void SetupLuaClassGCAnimCycle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimCycle>("CAnimCycle")

        .endClass();
}