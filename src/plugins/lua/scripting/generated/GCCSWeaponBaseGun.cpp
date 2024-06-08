#include "../../../core/scripting/generated/classes/GCCSWeaponBaseGun.h"
#include "../core.h"

void SetupLuaClassGCCSWeaponBaseGun(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSWeaponBaseGun>("CCSWeaponBaseGun")
        .addProperty("ZoomLevel", &GCCSWeaponBaseGun::GetZoomLevel, &GCCSWeaponBaseGun::SetZoomLevel)
        .addProperty("BurstShotsRemaining", &GCCSWeaponBaseGun::GetBurstShotsRemaining, &GCCSWeaponBaseGun::SetBurstShotsRemaining)
        .addProperty("SilencedModelIndex", &GCCSWeaponBaseGun::GetSilencedModelIndex, &GCCSWeaponBaseGun::SetSilencedModelIndex)
        .addProperty("InPrecache", &GCCSWeaponBaseGun::GetInPrecache, &GCCSWeaponBaseGun::SetInPrecache)
        .addProperty("NeedsBoltAction", &GCCSWeaponBaseGun::GetNeedsBoltAction, &GCCSWeaponBaseGun::SetNeedsBoltAction)
        .addProperty("SkillReloadAvailable", &GCCSWeaponBaseGun::GetSkillReloadAvailable, &GCCSWeaponBaseGun::SetSkillReloadAvailable)
        .addProperty("SkillReloadLiftedReloadKey", &GCCSWeaponBaseGun::GetSkillReloadLiftedReloadKey, &GCCSWeaponBaseGun::SetSkillReloadLiftedReloadKey)
        .addProperty("SkillBoltInterruptAvailable", &GCCSWeaponBaseGun::GetSkillBoltInterruptAvailable, &GCCSWeaponBaseGun::SetSkillBoltInterruptAvailable)
        .addProperty("SkillBoltLiftedFireKey", &GCCSWeaponBaseGun::GetSkillBoltLiftedFireKey, &GCCSWeaponBaseGun::SetSkillBoltLiftedFireKey)
        .endClass();
}