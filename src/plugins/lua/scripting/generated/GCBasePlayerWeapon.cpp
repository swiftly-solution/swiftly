#include "../../../core/scripting/generated/classes/GCBasePlayerWeapon.h"
#include "../core.h"

void SetupLuaClassGCBasePlayerWeapon(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBasePlayerWeapon>("CBasePlayerWeapon")
        .addProperty("NextPrimaryAttackTickRatio", &GCBasePlayerWeapon::GetNextPrimaryAttackTickRatio, &GCBasePlayerWeapon::SetNextPrimaryAttackTickRatio)
        .addProperty("NextSecondaryAttackTickRatio", &GCBasePlayerWeapon::GetNextSecondaryAttackTickRatio, &GCBasePlayerWeapon::SetNextSecondaryAttackTickRatio)
        .addProperty("Clip1", &GCBasePlayerWeapon::GetClip1, &GCBasePlayerWeapon::SetClip1)
        .addProperty("Clip2", &GCBasePlayerWeapon::GetClip2, &GCBasePlayerWeapon::SetClip2)
        .addProperty("ReserveAmmo", &GCBasePlayerWeapon::GetReserveAmmo, &GCBasePlayerWeapon::SetReserveAmmo)
        .addProperty("OnPlayerUse", &GCBasePlayerWeapon::GetOnPlayerUse, &GCBasePlayerWeapon::SetOnPlayerUse)
        .endClass();
}