#include "../../../core/scripting/generated/classes/GCCSPlayerController_DamageServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayerController_DamageServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayerController_DamageServices>("CCSPlayerController_DamageServices")
        .addProperty("SendUpdate", &GCCSPlayerController_DamageServices::GetSendUpdate, &GCCSPlayerController_DamageServices::SetSendUpdate)
        .addProperty("DamageList", &GCCSPlayerController_DamageServices::GetDamageList, &GCCSPlayerController_DamageServices::SetDamageList)
        .endClass();
}