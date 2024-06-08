#include "../../../core/scripting/generated/classes/GCCSGameRulesProxy.h"
#include "../core.h"

void SetupLuaClassGCCSGameRulesProxy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGameRulesProxy>("CCSGameRulesProxy")
        .addProperty("GameRules", &GCCSGameRulesProxy::GetGameRules, &GCCSGameRulesProxy::SetGameRules)
        .endClass();
}