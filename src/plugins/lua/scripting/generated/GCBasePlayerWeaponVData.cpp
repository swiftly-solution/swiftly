#include "../../../core/scripting/generated/classes/GCBasePlayerWeaponVData.h"
#include "../core.h"

void SetupLuaClassGCBasePlayerWeaponVData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBasePlayerWeaponVData>("CBasePlayerWeaponVData")
        .addProperty("BuiltRightHanded", &GCBasePlayerWeaponVData::GetBuiltRightHanded, &GCBasePlayerWeaponVData::SetBuiltRightHanded)
        .addProperty("AllowFlipping", &GCBasePlayerWeaponVData::GetAllowFlipping, &GCBasePlayerWeaponVData::SetAllowFlipping)
        .addProperty("MuzzleAttachment", &GCBasePlayerWeaponVData::GetMuzzleAttachment, &GCBasePlayerWeaponVData::SetMuzzleAttachment)
        .addProperty("Flags", &GCBasePlayerWeaponVData::GetFlags, &GCBasePlayerWeaponVData::SetFlags)
        .addProperty("PrimaryAmmoType", &GCBasePlayerWeaponVData::GetPrimaryAmmoType, &GCBasePlayerWeaponVData::SetPrimaryAmmoType)
        .addProperty("SecondaryAmmoType", &GCBasePlayerWeaponVData::GetSecondaryAmmoType, &GCBasePlayerWeaponVData::SetSecondaryAmmoType)
        .addProperty("MaxClip1", &GCBasePlayerWeaponVData::GetMaxClip1, &GCBasePlayerWeaponVData::SetMaxClip1)
        .addProperty("MaxClip2", &GCBasePlayerWeaponVData::GetMaxClip2, &GCBasePlayerWeaponVData::SetMaxClip2)
        .addProperty("DefaultClip1", &GCBasePlayerWeaponVData::GetDefaultClip1, &GCBasePlayerWeaponVData::SetDefaultClip1)
        .addProperty("DefaultClip2", &GCBasePlayerWeaponVData::GetDefaultClip2, &GCBasePlayerWeaponVData::SetDefaultClip2)
        .addProperty("Weight", &GCBasePlayerWeaponVData::GetWeight, &GCBasePlayerWeaponVData::SetWeight)
        .addProperty("AutoSwitchTo", &GCBasePlayerWeaponVData::GetAutoSwitchTo, &GCBasePlayerWeaponVData::SetAutoSwitchTo)
        .addProperty("AutoSwitchFrom", &GCBasePlayerWeaponVData::GetAutoSwitchFrom, &GCBasePlayerWeaponVData::SetAutoSwitchFrom)
        .addProperty("RumbleEffect", &GCBasePlayerWeaponVData::GetRumbleEffect, &GCBasePlayerWeaponVData::SetRumbleEffect)
        .addProperty("LinkedCooldowns", &GCBasePlayerWeaponVData::GetLinkedCooldowns, &GCBasePlayerWeaponVData::SetLinkedCooldowns)
        .addProperty("Slot", &GCBasePlayerWeaponVData::GetSlot, &GCBasePlayerWeaponVData::SetSlot)
        .addProperty("Position", &GCBasePlayerWeaponVData::GetPosition, &GCBasePlayerWeaponVData::SetPosition)
        .endClass();
}