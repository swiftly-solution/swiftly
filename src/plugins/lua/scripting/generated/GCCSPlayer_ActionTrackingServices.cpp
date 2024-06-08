#include "../../../core/scripting/generated/classes/GCCSPlayer_ActionTrackingServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayer_ActionTrackingServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_ActionTrackingServices>("CCSPlayer_ActionTrackingServices")
        .addProperty("LastWeaponBeforeC4AutoSwitch", &GCCSPlayer_ActionTrackingServices::GetLastWeaponBeforeC4AutoSwitch, &GCCSPlayer_ActionTrackingServices::SetLastWeaponBeforeC4AutoSwitch)
        .addProperty("IsRescuing", &GCCSPlayer_ActionTrackingServices::GetIsRescuing, &GCCSPlayer_ActionTrackingServices::SetIsRescuing)
        .addProperty("WeaponPurchasesThisMatch", &GCCSPlayer_ActionTrackingServices::GetWeaponPurchasesThisMatch, &GCCSPlayer_ActionTrackingServices::SetWeaponPurchasesThisMatch)
        .addProperty("WeaponPurchasesThisRound", &GCCSPlayer_ActionTrackingServices::GetWeaponPurchasesThisRound, &GCCSPlayer_ActionTrackingServices::SetWeaponPurchasesThisRound)
        .endClass();
}