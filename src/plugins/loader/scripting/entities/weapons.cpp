#include "../../core.h"

LoadScriptingComponent(
    weaponmanager,
    [](Plugin* plugin, EContext* state)
    {
        BeginClass<PluginWeaponManager>("WeaponManager", state)
            .addFunction("GiveWeapon", &PluginWeaponManager::GiveWeapon)
            .addFunction("RemoveWeapons", &PluginWeaponManager::RemoveWeapons)
            .addFunction("DropWeapons", &PluginWeaponManager::DropWeapons)
            .addFunction("GetWeapons", &PluginWeaponManager::GetWeapons)
            .addFunction("RemoveByClassname", &PluginWeaponManager::RemoveByClassname)
            .addFunction("RemoveBySlot", &PluginWeaponManager::RemoveBySlot)
            .addFunction("GetFirstInSlot", &PluginWeaponManager::GetFirstInSlot)
            .addFunction("GetInSlot", &PluginWeaponManager::GetInSlot)
            .addFunction("RemoveByItemDefinition", &PluginWeaponManager::RemoveByItemDefinition)
        .endClass();
    }
);

void LoadWeapon(Plugin* plugin, EContext* state)
{
    BeginClass<PluginWeapon>("Weapon", state)
        .addConstructor<int,std::string>()
        .addFunction("CBasePlayerWeapon", &PluginWeapon::GetCBasePlayerWeapon)
        .addFunction("CCSWeaponBase", &PluginWeapon::GetCCSWeaponBase)
        .addFunction("CBasePlayerWeaponVData", &PluginWeapon::GetCBasePlayerWeaponVData)
        .addFunction("CCSWeaponBaseVData", &PluginWeapon::GetCCSWeaponBaseVData)
        .addFunction("SetDefaultAttributes", &PluginWeapon::SetDefaultAttributes)
        .addFunction("Drop", &PluginWeapon::Drop)
        .addFunction("Remove", &PluginWeapon::Remove)
    .endClass();
}

LoadScriptingComponent(
    weapon,
    LoadWeapon
);