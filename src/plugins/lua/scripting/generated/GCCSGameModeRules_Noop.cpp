#include "../../../core/scripting/generated/classes/GCCSGameModeRules_Noop.h"
#include "../core.h"

void SetupLuaClassGCCSGameModeRules_Noop(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGameModeRules_Noop>("CCSGameModeRules_Noop")

        .endClass();
}