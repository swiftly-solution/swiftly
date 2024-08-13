#include "core.h"

void SetupLuaWeapons(LuaPlugin* plugin, lua_State* state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<PluginWeaponManager>("WeaponManager")
        .addFunction("GiveWeapon", &PluginWeaponManager::GiveWeapon)
        .addFunction("RemoveWeapons", &PluginWeaponManager::RemoveWeapons)
        .addFunction("DropWeapons", &PluginWeaponManager::DropWeapons)
        .addFunction("GetWeapons", &PluginWeaponManager::GetWeapons)
        .endClass()

        .beginClass<PluginWeapon>("Weapon")
        .addFunction("CBasePlayerWeapon", &PluginWeapon::GetCBasePlayerWeapon)
        .addFunction("CCSWeaponBase", &PluginWeapon::GetCCSWeaponBase)
        .addFunction("CBasePlayerWeaponVData", &PluginWeapon::GetCBasePlayerWeaponVData)
        .addFunction("CCSWeaponBaseVData", &PluginWeapon::GetCCSWeaponBaseVData)
        .addFunction("SetDefaultAttributes", &PluginWeapon::SetDefaultAttributes)
        .addFunction("Drop", &PluginWeapon::Drop)
        .addFunction("Remove", &PluginWeapon::Remove)
        .endClass();
}