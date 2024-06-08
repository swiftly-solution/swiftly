#include "../../../core/scripting/generated/classes/GCCSPlayer_PingServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayer_PingServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_PingServices>("CCSPlayer_PingServices")
        .addProperty("PlayerPing", &GCCSPlayer_PingServices::GetPlayerPing, &GCCSPlayer_PingServices::SetPlayerPing)
        .endClass();
}