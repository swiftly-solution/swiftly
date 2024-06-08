#include "../../../core/scripting/generated/classes/GCGameRulesProxy.h"
#include "../core.h"

void SetupLuaClassGCGameRulesProxy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameRulesProxy>("CGameRulesProxy")

        .endClass();
}