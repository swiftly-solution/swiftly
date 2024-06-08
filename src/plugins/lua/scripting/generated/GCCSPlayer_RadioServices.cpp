#include "../../../core/scripting/generated/classes/GCCSPlayer_RadioServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayer_RadioServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_RadioServices>("CCSPlayer_RadioServices")
        .addProperty("IgnoreRadio", &GCCSPlayer_RadioServices::GetIgnoreRadio, &GCCSPlayer_RadioServices::SetIgnoreRadio)
        .endClass();
}