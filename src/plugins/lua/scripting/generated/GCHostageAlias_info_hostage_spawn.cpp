#include "../../../core/scripting/generated/classes/GCHostageAlias_info_hostage_spawn.h"
#include "../core.h"

void SetupLuaClassGCHostageAlias_info_hostage_spawn(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHostageAlias_info_hostage_spawn>("CHostageAlias_info_hostage_spawn")

        .endClass();
}