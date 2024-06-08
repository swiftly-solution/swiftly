#include "../../../core/scripting/generated/classes/GCCSPlayer_WeaponServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayer_WeaponServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_WeaponServices>("CCSPlayer_WeaponServices")
        .addProperty("IsLookingAtWeapon", &GCCSPlayer_WeaponServices::GetIsLookingAtWeapon, &GCCSPlayer_WeaponServices::SetIsLookingAtWeapon)
        .addProperty("IsHoldingLookAtWeapon", &GCCSPlayer_WeaponServices::GetIsHoldingLookAtWeapon, &GCCSPlayer_WeaponServices::SetIsHoldingLookAtWeapon)
        .addProperty("SavedWeapon", &GCCSPlayer_WeaponServices::GetSavedWeapon, &GCCSPlayer_WeaponServices::SetSavedWeapon)
        .addProperty("TimeToMelee", &GCCSPlayer_WeaponServices::GetTimeToMelee, &GCCSPlayer_WeaponServices::SetTimeToMelee)
        .addProperty("TimeToSecondary", &GCCSPlayer_WeaponServices::GetTimeToSecondary, &GCCSPlayer_WeaponServices::SetTimeToSecondary)
        .addProperty("TimeToPrimary", &GCCSPlayer_WeaponServices::GetTimeToPrimary, &GCCSPlayer_WeaponServices::SetTimeToPrimary)
        .addProperty("TimeToSniperRifle", &GCCSPlayer_WeaponServices::GetTimeToSniperRifle, &GCCSPlayer_WeaponServices::SetTimeToSniperRifle)
        .addProperty("IsBeingGivenItem", &GCCSPlayer_WeaponServices::GetIsBeingGivenItem, &GCCSPlayer_WeaponServices::SetIsBeingGivenItem)
        .addProperty("IsPickingUpItemWithUse", &GCCSPlayer_WeaponServices::GetIsPickingUpItemWithUse, &GCCSPlayer_WeaponServices::SetIsPickingUpItemWithUse)
        .addProperty("PickedUpWeapon", &GCCSPlayer_WeaponServices::GetPickedUpWeapon, &GCCSPlayer_WeaponServices::SetPickedUpWeapon)
        .addProperty("DisableAutoDeploy", &GCCSPlayer_WeaponServices::GetDisableAutoDeploy, &GCCSPlayer_WeaponServices::SetDisableAutoDeploy)
        .addProperty("IsPickingUpGroundWeapon", &GCCSPlayer_WeaponServices::GetIsPickingUpGroundWeapon, &GCCSPlayer_WeaponServices::SetIsPickingUpGroundWeapon)
        .addProperty("OldShootPositionHistoryCount", &GCCSPlayer_WeaponServices::GetOldShootPositionHistoryCount, &GCCSPlayer_WeaponServices::SetOldShootPositionHistoryCount)
        .addProperty("OldInputHistoryCount", &GCCSPlayer_WeaponServices::GetOldInputHistoryCount, &GCCSPlayer_WeaponServices::SetOldInputHistoryCount)
        .endClass();
}