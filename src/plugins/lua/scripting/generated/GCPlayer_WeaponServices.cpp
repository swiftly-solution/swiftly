#include "../../../core/scripting/generated/classes/GCPlayer_WeaponServices.h"
#include "../core.h"

void SetupLuaClassGCPlayer_WeaponServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_WeaponServices>("CPlayer_WeaponServices")
        .addProperty("MyWeapons", &GCPlayer_WeaponServices::GetMyWeapons, &GCPlayer_WeaponServices::SetMyWeapons)
        .addProperty("ActiveWeapon", &GCPlayer_WeaponServices::GetActiveWeapon, &GCPlayer_WeaponServices::SetActiveWeapon)
        .addProperty("LastWeapon", &GCPlayer_WeaponServices::GetLastWeapon, &GCPlayer_WeaponServices::SetLastWeapon)
        .addProperty("Ammo", &GCPlayer_WeaponServices::GetAmmo, &GCPlayer_WeaponServices::SetAmmo)
        .addProperty("PreventWeaponPickup", &GCPlayer_WeaponServices::GetPreventWeaponPickup, &GCPlayer_WeaponServices::SetPreventWeaponPickup)
        .endClass();
}