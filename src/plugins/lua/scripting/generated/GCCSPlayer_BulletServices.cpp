#include "../../../core/scripting/generated/classes/GCCSPlayer_BulletServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayer_BulletServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_BulletServices>("CCSPlayer_BulletServices")
        .addProperty("TotalHitsOnServer", &GCCSPlayer_BulletServices::GetTotalHitsOnServer, &GCCSPlayer_BulletServices::SetTotalHitsOnServer)
        .endClass();
}