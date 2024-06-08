#include "../../../core/scripting/generated/classes/GCTeamplayRules.h"
#include "../core.h"

void SetupLuaClassGCTeamplayRules(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTeamplayRules>("CTeamplayRules")

        .endClass();
}