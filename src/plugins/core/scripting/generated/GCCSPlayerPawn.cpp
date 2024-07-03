#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayerPawn::GCCSPlayerPawn(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayerPawn::GCCSPlayerPawn(void *ptr) {
    m_ptr = ptr;
}
GCCSPlayer_BulletServices GCCSPlayerPawn::GetBulletServices() const {
    GCCSPlayer_BulletServices value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerPawn", "m_pBulletServices"));
    return value;
}
void GCCSPlayerPawn::SetBulletServices(GCCSPlayer_BulletServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'BulletServices' is not possible.\n");
}
GCCSPlayer_HostageServices GCCSPlayerPawn::GetHostageServices() const {
    GCCSPlayer_HostageServices value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerPawn", "m_pHostageServices"));
    return value;
}
void GCCSPlayerPawn::SetHostageServices(GCCSPlayer_HostageServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'HostageServices' is not possible.\n");
}
GCCSPlayer_BuyServices GCCSPlayerPawn::GetBuyServices() const {
    GCCSPlayer_BuyServices value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerPawn", "m_pBuyServices"));
    return value;
}
void GCCSPlayerPawn::SetBuyServices(GCCSPlayer_BuyServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'BuyServices' is not possible.\n");
}
GCCSPlayer_ActionTrackingServices GCCSPlayerPawn::GetActionTrackingServices() const {
    GCCSPlayer_ActionTrackingServices value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerPawn", "m_pActionTrackingServices"));
    return value;
}
void GCCSPlayerPawn::SetActionTrackingServices(GCCSPlayer_ActionTrackingServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ActionTrackingServices' is not possible.\n");
}
GCCSPlayer_RadioServices GCCSPlayerPawn::GetRadioServices() const {
    GCCSPlayer_RadioServices value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerPawn", "m_pRadioServices"));
    return value;
}
void GCCSPlayerPawn::SetRadioServices(GCCSPlayer_RadioServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'RadioServices' is not possible.\n");
}
GCCSPlayer_DamageReactServices GCCSPlayerPawn::GetDamageReactServices() const {
    GCCSPlayer_DamageReactServices value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerPawn", "m_pDamageReactServices"));
    return value;
}
void GCCSPlayerPawn::SetDamageReactServices(GCCSPlayer_DamageReactServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'DamageReactServices' is not possible.\n");
}
uint16_t GCCSPlayerPawn::GetCharacterDefIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CCSPlayerPawn", "m_nCharacterDefIndex");
}
void GCCSPlayerPawn::SetCharacterDefIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_nCharacterDefIndex", false, value);
}
bool GCCSPlayerPawn::GetHasFemaleVoice() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bHasFemaleVoice");
}
void GCCSPlayerPawn::SetHasFemaleVoice(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bHasFemaleVoice", false, value);
}
std::string GCCSPlayerPawn::GetStrVOPrefix() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CCSPlayerPawn", "m_strVOPrefix").Get();
}
void GCCSPlayerPawn::SetStrVOPrefix(std::string value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_strVOPrefix", false, CUtlString(value.c_str()));
}
std::string GCCSPlayerPawn::GetLastPlaceName() const {
    return GetSchemaValuePtr<char>(m_ptr, "CCSPlayerPawn", "m_szLastPlaceName");
}
void GCCSPlayerPawn::SetLastPlaceName(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CCSPlayerPawn", "m_szLastPlaceName", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 18);
}
bool GCCSPlayerPawn::GetInHostageResetZone() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bInHostageResetZone");
}
void GCCSPlayerPawn::SetInHostageResetZone(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bInHostageResetZone", false, value);
}
bool GCCSPlayerPawn::GetInBuyZone() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bInBuyZone");
}
void GCCSPlayerPawn::SetInBuyZone(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bInBuyZone", false, value);
}
bool GCCSPlayerPawn::GetWasInBuyZone() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bWasInBuyZone");
}
void GCCSPlayerPawn::SetWasInBuyZone(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bWasInBuyZone", false, value);
}
bool GCCSPlayerPawn::GetInHostageRescueZone() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bInHostageRescueZone");
}
void GCCSPlayerPawn::SetInHostageRescueZone(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bInHostageRescueZone", false, value);
}
bool GCCSPlayerPawn::GetInBombZone() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bInBombZone");
}
void GCCSPlayerPawn::SetInBombZone(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bInBombZone", false, value);
}
bool GCCSPlayerPawn::GetWasInHostageRescueZone() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bWasInHostageRescueZone");
}
void GCCSPlayerPawn::SetWasInHostageRescueZone(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bWasInHostageRescueZone", false, value);
}
int32_t GCCSPlayerPawn::GetRetakesOffering() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_iRetakesOffering");
}
void GCCSPlayerPawn::SetRetakesOffering(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iRetakesOffering", false, value);
}
int32_t GCCSPlayerPawn::GetRetakesOfferingCard() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_iRetakesOfferingCard");
}
void GCCSPlayerPawn::SetRetakesOfferingCard(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iRetakesOfferingCard", false, value);
}
bool GCCSPlayerPawn::GetRetakesHasDefuseKit() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bRetakesHasDefuseKit");
}
void GCCSPlayerPawn::SetRetakesHasDefuseKit(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bRetakesHasDefuseKit", false, value);
}
bool GCCSPlayerPawn::GetRetakesMVPLastRound() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bRetakesMVPLastRound");
}
void GCCSPlayerPawn::SetRetakesMVPLastRound(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bRetakesMVPLastRound", false, value);
}
int32_t GCCSPlayerPawn::GetRetakesMVPBoostItem() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_iRetakesMVPBoostItem");
}
void GCCSPlayerPawn::SetRetakesMVPBoostItem(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iRetakesMVPBoostItem", false, value);
}
uint64_t GCCSPlayerPawn::GetRetakesMVPBoostExtraUtility() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCSPlayerPawn", "m_RetakesMVPBoostExtraUtility");
}
void GCCSPlayerPawn::SetRetakesMVPBoostExtraUtility(uint64_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_RetakesMVPBoostExtraUtility", false, value);
}
float GCCSPlayerPawn::GetHealthShotBoostExpirationTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flHealthShotBoostExpirationTime");
}
void GCCSPlayerPawn::SetHealthShotBoostExpirationTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flHealthShotBoostExpirationTime", false, value);
}
float GCCSPlayerPawn::GetLandingTimeSeconds() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flLandingTimeSeconds");
}
void GCCSPlayerPawn::SetLandingTimeSeconds(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flLandingTimeSeconds", false, value);
}
QAngle GCCSPlayerPawn::GetAimPunchAngle() const {
    return GetSchemaValue<QAngle>(m_ptr, "CCSPlayerPawn", "m_aimPunchAngle");
}
void GCCSPlayerPawn::SetAimPunchAngle(QAngle value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_aimPunchAngle", false, value);
}
QAngle GCCSPlayerPawn::GetAimPunchAngleVel() const {
    return GetSchemaValue<QAngle>(m_ptr, "CCSPlayerPawn", "m_aimPunchAngleVel");
}
void GCCSPlayerPawn::SetAimPunchAngleVel(QAngle value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_aimPunchAngleVel", false, value);
}
int32_t GCCSPlayerPawn::GetAimPunchTickBase() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_aimPunchTickBase");
}
void GCCSPlayerPawn::SetAimPunchTickBase(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_aimPunchTickBase", false, value);
}
float GCCSPlayerPawn::GetAimPunchTickFraction() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_aimPunchTickFraction");
}
void GCCSPlayerPawn::SetAimPunchTickFraction(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_aimPunchTickFraction", false, value);
}
std::vector<QAngle> GCCSPlayerPawn::GetAimPunchCache() const {
    CUtlVector<QAngle>* vec = GetSchemaValue<CUtlVector<QAngle>*>(m_ptr, "CCSPlayerPawn", "m_aimPunchCache"); std::vector<QAngle> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCCSPlayerPawn::SetAimPunchCache(std::vector<QAngle> value) {
    SetSchemaValueCUtlVector<QAngle>(m_ptr, "CCSPlayerPawn", "m_aimPunchCache", false, value);
}
bool GCCSPlayerPawn::GetIsBuyMenuOpen() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bIsBuyMenuOpen");
}
void GCCSPlayerPawn::SetIsBuyMenuOpen(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bIsBuyMenuOpen", false, value);
}
bool GCCSPlayerPawn::GetLastHeadBoneTransformIsValid() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bLastHeadBoneTransformIsValid");
}
void GCCSPlayerPawn::SetLastHeadBoneTransformIsValid(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bLastHeadBoneTransformIsValid", false, value);
}
float GCCSPlayerPawn::GetLastLandTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_lastLandTime");
}
void GCCSPlayerPawn::SetLastLandTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_lastLandTime", false, value);
}
bool GCCSPlayerPawn::GetOnGroundLastTick() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bOnGroundLastTick");
}
void GCCSPlayerPawn::SetOnGroundLastTick(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bOnGroundLastTick", false, value);
}
int32_t GCCSPlayerPawn::GetPlayerLocked() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_iPlayerLocked");
}
void GCCSPlayerPawn::SetPlayerLocked(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iPlayerLocked", false, value);
}
float GCCSPlayerPawn::GetTimeOfLastInjury() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flTimeOfLastInjury");
}
void GCCSPlayerPawn::SetTimeOfLastInjury(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flTimeOfLastInjury", false, value);
}
float GCCSPlayerPawn::GetNextSprayDecalTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flNextSprayDecalTime");
}
void GCCSPlayerPawn::SetNextSprayDecalTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flNextSprayDecalTime", false, value);
}
bool GCCSPlayerPawn::GetNextSprayDecalTimeExpedited() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bNextSprayDecalTimeExpedited");
}
void GCCSPlayerPawn::SetNextSprayDecalTimeExpedited(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bNextSprayDecalTimeExpedited", false, value);
}
int32_t GCCSPlayerPawn::GetRagdollDamageBone() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_nRagdollDamageBone");
}
void GCCSPlayerPawn::SetRagdollDamageBone(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_nRagdollDamageBone", false, value);
}
Vector GCCSPlayerPawn::GetRagdollDamageForce() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSPlayerPawn", "m_vRagdollDamageForce");
}
void GCCSPlayerPawn::SetRagdollDamageForce(Vector value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vRagdollDamageForce", false, value);
}
Vector GCCSPlayerPawn::GetRagdollDamagePosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSPlayerPawn", "m_vRagdollDamagePosition");
}
void GCCSPlayerPawn::SetRagdollDamagePosition(Vector value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vRagdollDamagePosition", false, value);
}
std::string GCCSPlayerPawn::GetRagdollDamageWeaponName() const {
    return GetSchemaValuePtr<char>(m_ptr, "CCSPlayerPawn", "m_szRagdollDamageWeaponName");
}
void GCCSPlayerPawn::SetRagdollDamageWeaponName(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CCSPlayerPawn", "m_szRagdollDamageWeaponName", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 64);
}
bool GCCSPlayerPawn::GetRagdollDamageHeadshot() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bRagdollDamageHeadshot");
}
void GCCSPlayerPawn::SetRagdollDamageHeadshot(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bRagdollDamageHeadshot", false, value);
}
Vector GCCSPlayerPawn::GetRagdollServerOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSPlayerPawn", "m_vRagdollServerOrigin");
}
void GCCSPlayerPawn::SetRagdollServerOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vRagdollServerOrigin", false, value);
}
GCEconItemView GCCSPlayerPawn::GetEconGloves() const {
    GCEconItemView value(GetSchemaPtr(m_ptr, "CCSPlayerPawn", "m_EconGloves"));
    return value;
}
void GCCSPlayerPawn::SetEconGloves(GCEconItemView value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_EconGloves", false, value);
}
uint8_t GCCSPlayerPawn::GetEconGlovesChanged() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CCSPlayerPawn", "m_nEconGlovesChanged");
}
void GCCSPlayerPawn::SetEconGlovesChanged(uint8_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_nEconGlovesChanged", false, value);
}
QAngle GCCSPlayerPawn::GetDeathEyeAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CCSPlayerPawn", "m_qDeathEyeAngles");
}
void GCCSPlayerPawn::SetDeathEyeAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_qDeathEyeAngles", false, value);
}
bool GCCSPlayerPawn::GetSkipOneHeadConstraintUpdate() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bSkipOneHeadConstraintUpdate");
}
void GCCSPlayerPawn::SetSkipOneHeadConstraintUpdate(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bSkipOneHeadConstraintUpdate", false, value);
}
bool GCCSPlayerPawn::GetLeftHanded() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bLeftHanded");
}
void GCCSPlayerPawn::SetLeftHanded(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bLeftHanded", false, value);
}
float GCCSPlayerPawn::GetSwitchedHandednessTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_fSwitchedHandednessTime");
}
void GCCSPlayerPawn::SetSwitchedHandednessTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_fSwitchedHandednessTime", false, value);
}
float GCCSPlayerPawn::GetViewmodelOffsetX() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flViewmodelOffsetX");
}
void GCCSPlayerPawn::SetViewmodelOffsetX(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flViewmodelOffsetX", false, value);
}
float GCCSPlayerPawn::GetViewmodelOffsetY() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flViewmodelOffsetY");
}
void GCCSPlayerPawn::SetViewmodelOffsetY(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flViewmodelOffsetY", false, value);
}
float GCCSPlayerPawn::GetViewmodelOffsetZ() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flViewmodelOffsetZ");
}
void GCCSPlayerPawn::SetViewmodelOffsetZ(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flViewmodelOffsetZ", false, value);
}
float GCCSPlayerPawn::GetViewmodelFOV() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flViewmodelFOV");
}
void GCCSPlayerPawn::SetViewmodelFOV(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flViewmodelFOV", false, value);
}
bool GCCSPlayerPawn::GetIsWalking() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bIsWalking");
}
void GCCSPlayerPawn::SetIsWalking(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bIsWalking", false, value);
}
float GCCSPlayerPawn::GetLastGivenDefuserTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_fLastGivenDefuserTime");
}
void GCCSPlayerPawn::SetLastGivenDefuserTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_fLastGivenDefuserTime", false, value);
}
float GCCSPlayerPawn::GetLastGivenBombTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_fLastGivenBombTime");
}
void GCCSPlayerPawn::SetLastGivenBombTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_fLastGivenBombTime", false, value);
}
float GCCSPlayerPawn::GetDealtDamageToEnemyMostRecentTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flDealtDamageToEnemyMostRecentTimestamp");
}
void GCCSPlayerPawn::SetDealtDamageToEnemyMostRecentTimestamp(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flDealtDamageToEnemyMostRecentTimestamp", false, value);
}
uint32_t GCCSPlayerPawn::GetDisplayHistoryBits() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerPawn", "m_iDisplayHistoryBits");
}
void GCCSPlayerPawn::SetDisplayHistoryBits(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iDisplayHistoryBits", false, value);
}
float GCCSPlayerPawn::GetLastAttackedTeammate() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flLastAttackedTeammate");
}
void GCCSPlayerPawn::SetLastAttackedTeammate(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flLastAttackedTeammate", false, value);
}
float GCCSPlayerPawn::GetAllowAutoFollowTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_allowAutoFollowTime");
}
void GCCSPlayerPawn::SetAllowAutoFollowTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_allowAutoFollowTime", false, value);
}
bool GCCSPlayerPawn::GetResetArmorNextSpawn() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bResetArmorNextSpawn");
}
void GCCSPlayerPawn::SetResetArmorNextSpawn(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bResetArmorNextSpawn", false, value);
}
CEntityIndex GCCSPlayerPawn::GetLastKillerIndex() const {
    return GetSchemaValue<CEntityIndex>(m_ptr, "CCSPlayerPawn", "m_nLastKillerIndex");
}
void GCCSPlayerPawn::SetLastKillerIndex(CEntityIndex value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_nLastKillerIndex", false, value);
}
GEntitySpottedState_t GCCSPlayerPawn::GetEntitySpottedState() const {
    GEntitySpottedState_t value(GetSchemaPtr(m_ptr, "CCSPlayerPawn", "m_entitySpottedState"));
    return value;
}
void GCCSPlayerPawn::SetEntitySpottedState(GEntitySpottedState_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_entitySpottedState", false, value);
}
int32_t GCCSPlayerPawn::GetSpotRules() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_nSpotRules");
}
void GCCSPlayerPawn::SetSpotRules(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_nSpotRules", false, value);
}
bool GCCSPlayerPawn::GetIsScoped() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bIsScoped");
}
void GCCSPlayerPawn::SetIsScoped(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bIsScoped", false, value);
}
bool GCCSPlayerPawn::GetResumeZoom() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bResumeZoom");
}
void GCCSPlayerPawn::SetResumeZoom(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bResumeZoom", false, value);
}
bool GCCSPlayerPawn::GetIsDefusing() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bIsDefusing");
}
void GCCSPlayerPawn::SetIsDefusing(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bIsDefusing", false, value);
}
bool GCCSPlayerPawn::GetIsGrabbingHostage() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bIsGrabbingHostage");
}
void GCCSPlayerPawn::SetIsGrabbingHostage(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bIsGrabbingHostage", false, value);
}
uint64_t GCCSPlayerPawn::GetBlockingUseActionInProgress() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCSPlayerPawn", "m_iBlockingUseActionInProgress");
}
void GCCSPlayerPawn::SetBlockingUseActionInProgress(uint64_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iBlockingUseActionInProgress", false, value);
}
float GCCSPlayerPawn::GetEmitSoundTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flEmitSoundTime");
}
void GCCSPlayerPawn::SetEmitSoundTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flEmitSoundTime", false, value);
}
bool GCCSPlayerPawn::GetInNoDefuseArea() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bInNoDefuseArea");
}
void GCCSPlayerPawn::SetInNoDefuseArea(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bInNoDefuseArea", false, value);
}
CEntityIndex GCCSPlayerPawn::GetBombSiteIndex() const {
    return GetSchemaValue<CEntityIndex>(m_ptr, "CCSPlayerPawn", "m_iBombSiteIndex");
}
void GCCSPlayerPawn::SetBombSiteIndex(CEntityIndex value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iBombSiteIndex", false, value);
}
int32_t GCCSPlayerPawn::GetWhichBombZone() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_nWhichBombZone");
}
void GCCSPlayerPawn::SetWhichBombZone(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_nWhichBombZone", false, value);
}
bool GCCSPlayerPawn::GetInBombZoneTrigger() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bInBombZoneTrigger");
}
void GCCSPlayerPawn::SetInBombZoneTrigger(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bInBombZoneTrigger", false, value);
}
bool GCCSPlayerPawn::GetWasInBombZoneTrigger() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bWasInBombZoneTrigger");
}
void GCCSPlayerPawn::SetWasInBombZoneTrigger(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bWasInBombZoneTrigger", false, value);
}
int32_t GCCSPlayerPawn::GetShotsFired() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_iShotsFired");
}
void GCCSPlayerPawn::SetShotsFired(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iShotsFired", false, value);
}
float GCCSPlayerPawn::GetFlinchStack() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flFlinchStack");
}
void GCCSPlayerPawn::SetFlinchStack(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flFlinchStack", false, value);
}
float GCCSPlayerPawn::GetVelocityModifier() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flVelocityModifier");
}
void GCCSPlayerPawn::SetVelocityModifier(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flVelocityModifier", false, value);
}
float GCCSPlayerPawn::GetHitHeading() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flHitHeading");
}
void GCCSPlayerPawn::SetHitHeading(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flHitHeading", false, value);
}
int32_t GCCSPlayerPawn::GetHitBodyPart() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_nHitBodyPart");
}
void GCCSPlayerPawn::SetHitBodyPart(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_nHitBodyPart", false, value);
}
Vector GCCSPlayerPawn::GetTotalBulletForce() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSPlayerPawn", "m_vecTotalBulletForce");
}
void GCCSPlayerPawn::SetTotalBulletForce(Vector value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vecTotalBulletForce", false, value);
}
bool GCCSPlayerPawn::GetWaitForNoAttack() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bWaitForNoAttack");
}
void GCCSPlayerPawn::SetWaitForNoAttack(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bWaitForNoAttack", false, value);
}
float GCCSPlayerPawn::GetIgnoreLadderJumpTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_ignoreLadderJumpTime");
}
void GCCSPlayerPawn::SetIgnoreLadderJumpTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_ignoreLadderJumpTime", false, value);
}
bool GCCSPlayerPawn::GetKilledByHeadshot() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bKilledByHeadshot");
}
void GCCSPlayerPawn::SetKilledByHeadshot(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bKilledByHeadshot", false, value);
}
int32_t GCCSPlayerPawn::GetLastHitBox() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_LastHitBox");
}
void GCCSPlayerPawn::SetLastHitBox(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_LastHitBox", false, value);
}
int32_t GCCSPlayerPawn::GetLastHealth() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_LastHealth");
}
void GCCSPlayerPawn::SetLastHealth(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_LastHealth", false, value);
}
GCCSBot GCCSPlayerPawn::GetBot() const {
    GCCSBot value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerPawn", "m_pBot"));
    return value;
}
void GCCSPlayerPawn::SetBot(GCCSBot* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Bot' is not possible.\n");
}
bool GCCSPlayerPawn::GetBotAllowActive() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bBotAllowActive");
}
void GCCSPlayerPawn::SetBotAllowActive(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bBotAllowActive", false, value);
}
QAngle GCCSPlayerPawn::GetThirdPersonHeading() const {
    return GetSchemaValue<QAngle>(m_ptr, "CCSPlayerPawn", "m_thirdPersonHeading");
}
void GCCSPlayerPawn::SetThirdPersonHeading(QAngle value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_thirdPersonHeading", false, value);
}
float GCCSPlayerPawn::GetSlopeDropOffset() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flSlopeDropOffset");
}
void GCCSPlayerPawn::SetSlopeDropOffset(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flSlopeDropOffset", false, value);
}
float GCCSPlayerPawn::GetSlopeDropHeight() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flSlopeDropHeight");
}
void GCCSPlayerPawn::SetSlopeDropHeight(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flSlopeDropHeight", false, value);
}
Vector GCCSPlayerPawn::GetHeadConstraintOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSPlayerPawn", "m_vHeadConstraintOffset");
}
void GCCSPlayerPawn::SetHeadConstraintOffset(Vector value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vHeadConstraintOffset", false, value);
}
int32_t GCCSPlayerPawn::GetLastPickupPriority() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_nLastPickupPriority");
}
void GCCSPlayerPawn::SetLastPickupPriority(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_nLastPickupPriority", false, value);
}
float GCCSPlayerPawn::GetLastPickupPriorityTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flLastPickupPriorityTime");
}
void GCCSPlayerPawn::SetLastPickupPriorityTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flLastPickupPriorityTime", false, value);
}
int32_t GCCSPlayerPawn::GetArmorValue() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_ArmorValue");
}
void GCCSPlayerPawn::SetArmorValue(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_ArmorValue", false, value);
}
uint16_t GCCSPlayerPawn::GetCurrentEquipmentValue() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CCSPlayerPawn", "m_unCurrentEquipmentValue");
}
void GCCSPlayerPawn::SetCurrentEquipmentValue(uint16_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_unCurrentEquipmentValue", false, value);
}
uint16_t GCCSPlayerPawn::GetRoundStartEquipmentValue() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CCSPlayerPawn", "m_unRoundStartEquipmentValue");
}
void GCCSPlayerPawn::SetRoundStartEquipmentValue(uint16_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_unRoundStartEquipmentValue", false, value);
}
uint16_t GCCSPlayerPawn::GetFreezetimeEndEquipmentValue() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CCSPlayerPawn", "m_unFreezetimeEndEquipmentValue");
}
void GCCSPlayerPawn::SetFreezetimeEndEquipmentValue(uint16_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_unFreezetimeEndEquipmentValue", false, value);
}
int32_t GCCSPlayerPawn::GetLastWeaponFireUsercmd() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_iLastWeaponFireUsercmd");
}
void GCCSPlayerPawn::SetLastWeaponFireUsercmd(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iLastWeaponFireUsercmd", false, value);
}
float GCCSPlayerPawn::GetLastFriendlyFireDamageReductionRatio() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flLastFriendlyFireDamageReductionRatio");
}
void GCCSPlayerPawn::SetLastFriendlyFireDamageReductionRatio(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flLastFriendlyFireDamageReductionRatio", false, value);
}
bool GCCSPlayerPawn::GetIsSpawning() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bIsSpawning");
}
void GCCSPlayerPawn::SetIsSpawning(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bIsSpawning", false, value);
}
int32_t GCCSPlayerPawn::GetDeathFlags() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_iDeathFlags");
}
void GCCSPlayerPawn::SetDeathFlags(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iDeathFlags", false, value);
}
bool GCCSPlayerPawn::GetHasDeathInfo() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bHasDeathInfo");
}
void GCCSPlayerPawn::SetHasDeathInfo(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bHasDeathInfo", false, value);
}
float GCCSPlayerPawn::GetDeathInfoTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flDeathInfoTime");
}
void GCCSPlayerPawn::SetDeathInfoTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flDeathInfoTime", false, value);
}
Vector GCCSPlayerPawn::GetDeathInfoOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSPlayerPawn", "m_vecDeathInfoOrigin");
}
void GCCSPlayerPawn::SetDeathInfoOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vecDeathInfoOrigin", false, value);
}
std::vector<uint32_t> GCCSPlayerPawn::GetPlayerPatchEconIndices() const {
    uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CCSPlayerPawn", "m_vecPlayerPatchEconIndices"); std::vector<uint32_t> ret; for(int i = 0; i < 5; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSPlayerPawn::SetPlayerPatchEconIndices(std::vector<uint32_t> value) {
    uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CCSPlayerPawn", "m_vecPlayerPatchEconIndices"); for(int i = 0; i < 5; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vecPlayerPatchEconIndices", false, outValue);
}
Color GCCSPlayerPawn::GetGunGameImmunityColor() const {
    return GetSchemaValue<Color>(m_ptr, "CCSPlayerPawn", "m_GunGameImmunityColor");
}
void GCCSPlayerPawn::SetGunGameImmunityColor(Color value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_GunGameImmunityColor", false, value);
}
float GCCSPlayerPawn::GetGrenadeParameterStashTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_grenadeParameterStashTime");
}
void GCCSPlayerPawn::SetGrenadeParameterStashTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_grenadeParameterStashTime", false, value);
}
bool GCCSPlayerPawn::GetGrenadeParametersStashed() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bGrenadeParametersStashed");
}
void GCCSPlayerPawn::SetGrenadeParametersStashed(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bGrenadeParametersStashed", false, value);
}
QAngle GCCSPlayerPawn::GetStashedShootAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CCSPlayerPawn", "m_angStashedShootAngles");
}
void GCCSPlayerPawn::SetStashedShootAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_angStashedShootAngles", false, value);
}
Vector GCCSPlayerPawn::GetStashedGrenadeThrowPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSPlayerPawn", "m_vecStashedGrenadeThrowPosition");
}
void GCCSPlayerPawn::SetStashedGrenadeThrowPosition(Vector value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vecStashedGrenadeThrowPosition", false, value);
}
Vector GCCSPlayerPawn::GetStashedVelocity() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSPlayerPawn", "m_vecStashedVelocity");
}
void GCCSPlayerPawn::SetStashedVelocity(Vector value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vecStashedVelocity", false, value);
}
std::vector<QAngle> GCCSPlayerPawn::GetShootAngleHistory() const {
    QAngle* outValue = GetSchemaValue<QAngle*>(m_ptr, "CCSPlayerPawn", "m_angShootAngleHistory"); std::vector<QAngle> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSPlayerPawn::SetShootAngleHistory(std::vector<QAngle> value) {
    QAngle* outValue = GetSchemaValue<QAngle*>(m_ptr, "CCSPlayerPawn", "m_angShootAngleHistory"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_angShootAngleHistory", false, outValue);
}
std::vector<Vector> GCCSPlayerPawn::GetThrowPositionHistory() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CCSPlayerPawn", "m_vecThrowPositionHistory"); std::vector<Vector> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSPlayerPawn::SetThrowPositionHistory(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CCSPlayerPawn", "m_vecThrowPositionHistory"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vecThrowPositionHistory", false, outValue);
}
std::vector<Vector> GCCSPlayerPawn::GetVelocityHistory() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CCSPlayerPawn", "m_vecVelocityHistory"); std::vector<Vector> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSPlayerPawn::SetVelocityHistory(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CCSPlayerPawn", "m_vecVelocityHistory"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vecVelocityHistory", false, outValue);
}
std::string GCCSPlayerPawn::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayerPawn::IsValid() {
    return (m_ptr != nullptr);
}
GCCSPlayerPawnBase GCCSPlayerPawn::GetParent() const {
    GCCSPlayerPawnBase value(m_ptr);
    return value;
}
void GCCSPlayerPawn::SetParent(GCCSPlayerPawnBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayerPawn(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayerPawn>("CCSPlayerPawn")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BulletServices", &GCCSPlayerPawn::GetBulletServices, &GCCSPlayerPawn::SetBulletServices)
        .addProperty("HostageServices", &GCCSPlayerPawn::GetHostageServices, &GCCSPlayerPawn::SetHostageServices)
        .addProperty("BuyServices", &GCCSPlayerPawn::GetBuyServices, &GCCSPlayerPawn::SetBuyServices)
        .addProperty("ActionTrackingServices", &GCCSPlayerPawn::GetActionTrackingServices, &GCCSPlayerPawn::SetActionTrackingServices)
        .addProperty("RadioServices", &GCCSPlayerPawn::GetRadioServices, &GCCSPlayerPawn::SetRadioServices)
        .addProperty("DamageReactServices", &GCCSPlayerPawn::GetDamageReactServices, &GCCSPlayerPawn::SetDamageReactServices)
        .addProperty("CharacterDefIndex", &GCCSPlayerPawn::GetCharacterDefIndex, &GCCSPlayerPawn::SetCharacterDefIndex)
        .addProperty("HasFemaleVoice", &GCCSPlayerPawn::GetHasFemaleVoice, &GCCSPlayerPawn::SetHasFemaleVoice)
        .addProperty("StrVOPrefix", &GCCSPlayerPawn::GetStrVOPrefix, &GCCSPlayerPawn::SetStrVOPrefix)
        .addProperty("LastPlaceName", &GCCSPlayerPawn::GetLastPlaceName, &GCCSPlayerPawn::SetLastPlaceName)
        .addProperty("InHostageResetZone", &GCCSPlayerPawn::GetInHostageResetZone, &GCCSPlayerPawn::SetInHostageResetZone)
        .addProperty("InBuyZone", &GCCSPlayerPawn::GetInBuyZone, &GCCSPlayerPawn::SetInBuyZone)
        .addProperty("WasInBuyZone", &GCCSPlayerPawn::GetWasInBuyZone, &GCCSPlayerPawn::SetWasInBuyZone)
        .addProperty("InHostageRescueZone", &GCCSPlayerPawn::GetInHostageRescueZone, &GCCSPlayerPawn::SetInHostageRescueZone)
        .addProperty("InBombZone", &GCCSPlayerPawn::GetInBombZone, &GCCSPlayerPawn::SetInBombZone)
        .addProperty("WasInHostageRescueZone", &GCCSPlayerPawn::GetWasInHostageRescueZone, &GCCSPlayerPawn::SetWasInHostageRescueZone)
        .addProperty("RetakesOffering", &GCCSPlayerPawn::GetRetakesOffering, &GCCSPlayerPawn::SetRetakesOffering)
        .addProperty("RetakesOfferingCard", &GCCSPlayerPawn::GetRetakesOfferingCard, &GCCSPlayerPawn::SetRetakesOfferingCard)
        .addProperty("RetakesHasDefuseKit", &GCCSPlayerPawn::GetRetakesHasDefuseKit, &GCCSPlayerPawn::SetRetakesHasDefuseKit)
        .addProperty("RetakesMVPLastRound", &GCCSPlayerPawn::GetRetakesMVPLastRound, &GCCSPlayerPawn::SetRetakesMVPLastRound)
        .addProperty("RetakesMVPBoostItem", &GCCSPlayerPawn::GetRetakesMVPBoostItem, &GCCSPlayerPawn::SetRetakesMVPBoostItem)
        .addProperty("RetakesMVPBoostExtraUtility", &GCCSPlayerPawn::GetRetakesMVPBoostExtraUtility, &GCCSPlayerPawn::SetRetakesMVPBoostExtraUtility)
        .addProperty("HealthShotBoostExpirationTime", &GCCSPlayerPawn::GetHealthShotBoostExpirationTime, &GCCSPlayerPawn::SetHealthShotBoostExpirationTime)
        .addProperty("LandingTimeSeconds", &GCCSPlayerPawn::GetLandingTimeSeconds, &GCCSPlayerPawn::SetLandingTimeSeconds)
        .addProperty("AimPunchAngle", &GCCSPlayerPawn::GetAimPunchAngle, &GCCSPlayerPawn::SetAimPunchAngle)
        .addProperty("AimPunchAngleVel", &GCCSPlayerPawn::GetAimPunchAngleVel, &GCCSPlayerPawn::SetAimPunchAngleVel)
        .addProperty("AimPunchTickBase", &GCCSPlayerPawn::GetAimPunchTickBase, &GCCSPlayerPawn::SetAimPunchTickBase)
        .addProperty("AimPunchTickFraction", &GCCSPlayerPawn::GetAimPunchTickFraction, &GCCSPlayerPawn::SetAimPunchTickFraction)
        .addProperty("AimPunchCache", &GCCSPlayerPawn::GetAimPunchCache, &GCCSPlayerPawn::SetAimPunchCache)
        .addProperty("IsBuyMenuOpen", &GCCSPlayerPawn::GetIsBuyMenuOpen, &GCCSPlayerPawn::SetIsBuyMenuOpen)
        .addProperty("LastHeadBoneTransformIsValid", &GCCSPlayerPawn::GetLastHeadBoneTransformIsValid, &GCCSPlayerPawn::SetLastHeadBoneTransformIsValid)
        .addProperty("LastLandTime", &GCCSPlayerPawn::GetLastLandTime, &GCCSPlayerPawn::SetLastLandTime)
        .addProperty("OnGroundLastTick", &GCCSPlayerPawn::GetOnGroundLastTick, &GCCSPlayerPawn::SetOnGroundLastTick)
        .addProperty("PlayerLocked", &GCCSPlayerPawn::GetPlayerLocked, &GCCSPlayerPawn::SetPlayerLocked)
        .addProperty("TimeOfLastInjury", &GCCSPlayerPawn::GetTimeOfLastInjury, &GCCSPlayerPawn::SetTimeOfLastInjury)
        .addProperty("NextSprayDecalTime", &GCCSPlayerPawn::GetNextSprayDecalTime, &GCCSPlayerPawn::SetNextSprayDecalTime)
        .addProperty("NextSprayDecalTimeExpedited", &GCCSPlayerPawn::GetNextSprayDecalTimeExpedited, &GCCSPlayerPawn::SetNextSprayDecalTimeExpedited)
        .addProperty("RagdollDamageBone", &GCCSPlayerPawn::GetRagdollDamageBone, &GCCSPlayerPawn::SetRagdollDamageBone)
        .addProperty("RagdollDamageForce", &GCCSPlayerPawn::GetRagdollDamageForce, &GCCSPlayerPawn::SetRagdollDamageForce)
        .addProperty("RagdollDamagePosition", &GCCSPlayerPawn::GetRagdollDamagePosition, &GCCSPlayerPawn::SetRagdollDamagePosition)
        .addProperty("RagdollDamageWeaponName", &GCCSPlayerPawn::GetRagdollDamageWeaponName, &GCCSPlayerPawn::SetRagdollDamageWeaponName)
        .addProperty("RagdollDamageHeadshot", &GCCSPlayerPawn::GetRagdollDamageHeadshot, &GCCSPlayerPawn::SetRagdollDamageHeadshot)
        .addProperty("RagdollServerOrigin", &GCCSPlayerPawn::GetRagdollServerOrigin, &GCCSPlayerPawn::SetRagdollServerOrigin)
        .addProperty("EconGloves", &GCCSPlayerPawn::GetEconGloves, &GCCSPlayerPawn::SetEconGloves)
        .addProperty("EconGlovesChanged", &GCCSPlayerPawn::GetEconGlovesChanged, &GCCSPlayerPawn::SetEconGlovesChanged)
        .addProperty("DeathEyeAngles", &GCCSPlayerPawn::GetDeathEyeAngles, &GCCSPlayerPawn::SetDeathEyeAngles)
        .addProperty("SkipOneHeadConstraintUpdate", &GCCSPlayerPawn::GetSkipOneHeadConstraintUpdate, &GCCSPlayerPawn::SetSkipOneHeadConstraintUpdate)
        .addProperty("LeftHanded", &GCCSPlayerPawn::GetLeftHanded, &GCCSPlayerPawn::SetLeftHanded)
        .addProperty("SwitchedHandednessTime", &GCCSPlayerPawn::GetSwitchedHandednessTime, &GCCSPlayerPawn::SetSwitchedHandednessTime)
        .addProperty("ViewmodelOffsetX", &GCCSPlayerPawn::GetViewmodelOffsetX, &GCCSPlayerPawn::SetViewmodelOffsetX)
        .addProperty("ViewmodelOffsetY", &GCCSPlayerPawn::GetViewmodelOffsetY, &GCCSPlayerPawn::SetViewmodelOffsetY)
        .addProperty("ViewmodelOffsetZ", &GCCSPlayerPawn::GetViewmodelOffsetZ, &GCCSPlayerPawn::SetViewmodelOffsetZ)
        .addProperty("ViewmodelFOV", &GCCSPlayerPawn::GetViewmodelFOV, &GCCSPlayerPawn::SetViewmodelFOV)
        .addProperty("IsWalking", &GCCSPlayerPawn::GetIsWalking, &GCCSPlayerPawn::SetIsWalking)
        .addProperty("LastGivenDefuserTime", &GCCSPlayerPawn::GetLastGivenDefuserTime, &GCCSPlayerPawn::SetLastGivenDefuserTime)
        .addProperty("LastGivenBombTime", &GCCSPlayerPawn::GetLastGivenBombTime, &GCCSPlayerPawn::SetLastGivenBombTime)
        .addProperty("DealtDamageToEnemyMostRecentTimestamp", &GCCSPlayerPawn::GetDealtDamageToEnemyMostRecentTimestamp, &GCCSPlayerPawn::SetDealtDamageToEnemyMostRecentTimestamp)
        .addProperty("DisplayHistoryBits", &GCCSPlayerPawn::GetDisplayHistoryBits, &GCCSPlayerPawn::SetDisplayHistoryBits)
        .addProperty("LastAttackedTeammate", &GCCSPlayerPawn::GetLastAttackedTeammate, &GCCSPlayerPawn::SetLastAttackedTeammate)
        .addProperty("AllowAutoFollowTime", &GCCSPlayerPawn::GetAllowAutoFollowTime, &GCCSPlayerPawn::SetAllowAutoFollowTime)
        .addProperty("ResetArmorNextSpawn", &GCCSPlayerPawn::GetResetArmorNextSpawn, &GCCSPlayerPawn::SetResetArmorNextSpawn)
        .addProperty("LastKillerIndex", &GCCSPlayerPawn::GetLastKillerIndex, &GCCSPlayerPawn::SetLastKillerIndex)
        .addProperty("EntitySpottedState", &GCCSPlayerPawn::GetEntitySpottedState, &GCCSPlayerPawn::SetEntitySpottedState)
        .addProperty("SpotRules", &GCCSPlayerPawn::GetSpotRules, &GCCSPlayerPawn::SetSpotRules)
        .addProperty("IsScoped", &GCCSPlayerPawn::GetIsScoped, &GCCSPlayerPawn::SetIsScoped)
        .addProperty("ResumeZoom", &GCCSPlayerPawn::GetResumeZoom, &GCCSPlayerPawn::SetResumeZoom)
        .addProperty("IsDefusing", &GCCSPlayerPawn::GetIsDefusing, &GCCSPlayerPawn::SetIsDefusing)
        .addProperty("IsGrabbingHostage", &GCCSPlayerPawn::GetIsGrabbingHostage, &GCCSPlayerPawn::SetIsGrabbingHostage)
        .addProperty("BlockingUseActionInProgress", &GCCSPlayerPawn::GetBlockingUseActionInProgress, &GCCSPlayerPawn::SetBlockingUseActionInProgress)
        .addProperty("EmitSoundTime", &GCCSPlayerPawn::GetEmitSoundTime, &GCCSPlayerPawn::SetEmitSoundTime)
        .addProperty("InNoDefuseArea", &GCCSPlayerPawn::GetInNoDefuseArea, &GCCSPlayerPawn::SetInNoDefuseArea)
        .addProperty("BombSiteIndex", &GCCSPlayerPawn::GetBombSiteIndex, &GCCSPlayerPawn::SetBombSiteIndex)
        .addProperty("WhichBombZone", &GCCSPlayerPawn::GetWhichBombZone, &GCCSPlayerPawn::SetWhichBombZone)
        .addProperty("InBombZoneTrigger", &GCCSPlayerPawn::GetInBombZoneTrigger, &GCCSPlayerPawn::SetInBombZoneTrigger)
        .addProperty("WasInBombZoneTrigger", &GCCSPlayerPawn::GetWasInBombZoneTrigger, &GCCSPlayerPawn::SetWasInBombZoneTrigger)
        .addProperty("ShotsFired", &GCCSPlayerPawn::GetShotsFired, &GCCSPlayerPawn::SetShotsFired)
        .addProperty("FlinchStack", &GCCSPlayerPawn::GetFlinchStack, &GCCSPlayerPawn::SetFlinchStack)
        .addProperty("VelocityModifier", &GCCSPlayerPawn::GetVelocityModifier, &GCCSPlayerPawn::SetVelocityModifier)
        .addProperty("HitHeading", &GCCSPlayerPawn::GetHitHeading, &GCCSPlayerPawn::SetHitHeading)
        .addProperty("HitBodyPart", &GCCSPlayerPawn::GetHitBodyPart, &GCCSPlayerPawn::SetHitBodyPart)
        .addProperty("TotalBulletForce", &GCCSPlayerPawn::GetTotalBulletForce, &GCCSPlayerPawn::SetTotalBulletForce)
        .addProperty("WaitForNoAttack", &GCCSPlayerPawn::GetWaitForNoAttack, &GCCSPlayerPawn::SetWaitForNoAttack)
        .addProperty("IgnoreLadderJumpTime", &GCCSPlayerPawn::GetIgnoreLadderJumpTime, &GCCSPlayerPawn::SetIgnoreLadderJumpTime)
        .addProperty("KilledByHeadshot", &GCCSPlayerPawn::GetKilledByHeadshot, &GCCSPlayerPawn::SetKilledByHeadshot)
        .addProperty("LastHitBox", &GCCSPlayerPawn::GetLastHitBox, &GCCSPlayerPawn::SetLastHitBox)
        .addProperty("LastHealth", &GCCSPlayerPawn::GetLastHealth, &GCCSPlayerPawn::SetLastHealth)
        .addProperty("Bot", &GCCSPlayerPawn::GetBot, &GCCSPlayerPawn::SetBot)
        .addProperty("BotAllowActive", &GCCSPlayerPawn::GetBotAllowActive, &GCCSPlayerPawn::SetBotAllowActive)
        .addProperty("ThirdPersonHeading", &GCCSPlayerPawn::GetThirdPersonHeading, &GCCSPlayerPawn::SetThirdPersonHeading)
        .addProperty("SlopeDropOffset", &GCCSPlayerPawn::GetSlopeDropOffset, &GCCSPlayerPawn::SetSlopeDropOffset)
        .addProperty("SlopeDropHeight", &GCCSPlayerPawn::GetSlopeDropHeight, &GCCSPlayerPawn::SetSlopeDropHeight)
        .addProperty("HeadConstraintOffset", &GCCSPlayerPawn::GetHeadConstraintOffset, &GCCSPlayerPawn::SetHeadConstraintOffset)
        .addProperty("LastPickupPriority", &GCCSPlayerPawn::GetLastPickupPriority, &GCCSPlayerPawn::SetLastPickupPriority)
        .addProperty("LastPickupPriorityTime", &GCCSPlayerPawn::GetLastPickupPriorityTime, &GCCSPlayerPawn::SetLastPickupPriorityTime)
        .addProperty("ArmorValue", &GCCSPlayerPawn::GetArmorValue, &GCCSPlayerPawn::SetArmorValue)
        .addProperty("CurrentEquipmentValue", &GCCSPlayerPawn::GetCurrentEquipmentValue, &GCCSPlayerPawn::SetCurrentEquipmentValue)
        .addProperty("RoundStartEquipmentValue", &GCCSPlayerPawn::GetRoundStartEquipmentValue, &GCCSPlayerPawn::SetRoundStartEquipmentValue)
        .addProperty("FreezetimeEndEquipmentValue", &GCCSPlayerPawn::GetFreezetimeEndEquipmentValue, &GCCSPlayerPawn::SetFreezetimeEndEquipmentValue)
        .addProperty("LastWeaponFireUsercmd", &GCCSPlayerPawn::GetLastWeaponFireUsercmd, &GCCSPlayerPawn::SetLastWeaponFireUsercmd)
        .addProperty("LastFriendlyFireDamageReductionRatio", &GCCSPlayerPawn::GetLastFriendlyFireDamageReductionRatio, &GCCSPlayerPawn::SetLastFriendlyFireDamageReductionRatio)
        .addProperty("IsSpawning", &GCCSPlayerPawn::GetIsSpawning, &GCCSPlayerPawn::SetIsSpawning)
        .addProperty("DeathFlags", &GCCSPlayerPawn::GetDeathFlags, &GCCSPlayerPawn::SetDeathFlags)
        .addProperty("HasDeathInfo", &GCCSPlayerPawn::GetHasDeathInfo, &GCCSPlayerPawn::SetHasDeathInfo)
        .addProperty("DeathInfoTime", &GCCSPlayerPawn::GetDeathInfoTime, &GCCSPlayerPawn::SetDeathInfoTime)
        .addProperty("DeathInfoOrigin", &GCCSPlayerPawn::GetDeathInfoOrigin, &GCCSPlayerPawn::SetDeathInfoOrigin)
        .addProperty("PlayerPatchEconIndices", &GCCSPlayerPawn::GetPlayerPatchEconIndices, &GCCSPlayerPawn::SetPlayerPatchEconIndices)
        .addProperty("GunGameImmunityColor", &GCCSPlayerPawn::GetGunGameImmunityColor, &GCCSPlayerPawn::SetGunGameImmunityColor)
        .addProperty("GrenadeParameterStashTime", &GCCSPlayerPawn::GetGrenadeParameterStashTime, &GCCSPlayerPawn::SetGrenadeParameterStashTime)
        .addProperty("GrenadeParametersStashed", &GCCSPlayerPawn::GetGrenadeParametersStashed, &GCCSPlayerPawn::SetGrenadeParametersStashed)
        .addProperty("StashedShootAngles", &GCCSPlayerPawn::GetStashedShootAngles, &GCCSPlayerPawn::SetStashedShootAngles)
        .addProperty("StashedGrenadeThrowPosition", &GCCSPlayerPawn::GetStashedGrenadeThrowPosition, &GCCSPlayerPawn::SetStashedGrenadeThrowPosition)
        .addProperty("StashedVelocity", &GCCSPlayerPawn::GetStashedVelocity, &GCCSPlayerPawn::SetStashedVelocity)
        .addProperty("ShootAngleHistory", &GCCSPlayerPawn::GetShootAngleHistory, &GCCSPlayerPawn::SetShootAngleHistory)
        .addProperty("ThrowPositionHistory", &GCCSPlayerPawn::GetThrowPositionHistory, &GCCSPlayerPawn::SetThrowPositionHistory)
        .addProperty("VelocityHistory", &GCCSPlayerPawn::GetVelocityHistory, &GCCSPlayerPawn::SetVelocityHistory)
        .addProperty("Parent", &GCCSPlayerPawn::GetParent, &GCCSPlayerPawn::SetParent)
        .addFunction("ToPtr", &GCCSPlayerPawn::ToPtr)
        .addFunction("IsValid", &GCCSPlayerPawn::IsValid)
        .endClass();
}