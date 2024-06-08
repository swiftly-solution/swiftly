#include "../../../core/scripting/generated/classes/GCLogicPlayerProxy.h"
#include "../core.h"

void SetupLuaClassGCLogicPlayerProxy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicPlayerProxy>("CLogicPlayerProxy")
        .addProperty("Player", &GCLogicPlayerProxy::GetPlayer, &GCLogicPlayerProxy::SetPlayer)
        .addProperty("PlayerHasAmmo", &GCLogicPlayerProxy::GetPlayerHasAmmo, &GCLogicPlayerProxy::SetPlayerHasAmmo)
        .addProperty("PlayerHasNoAmmo", &GCLogicPlayerProxy::GetPlayerHasNoAmmo, &GCLogicPlayerProxy::SetPlayerHasNoAmmo)
        .addProperty("PlayerDied", &GCLogicPlayerProxy::GetPlayerDied, &GCLogicPlayerProxy::SetPlayerDied)
        .endClass();
}