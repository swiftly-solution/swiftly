#include "../../../core/scripting/generated/classes/GCCSGameModeRules.h"
#include "../core.h"

void SetupLuaClassGCCSGameModeRules(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGameModeRules>("CCSGameModeRules")
        .addProperty("__pChainEntity", &GCCSGameModeRules::Get__pChainEntity, &GCCSGameModeRules::Set__pChainEntity)
        .endClass();
}