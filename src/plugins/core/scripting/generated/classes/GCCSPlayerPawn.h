class GCCSPlayerPawn;

#ifndef _gcccsplayerpawn_h
#define _gcccsplayerpawn_h

#include "../../../scripting.h"

#include "../types/Gloadout_slot_t.h"
#include "../types/GCSPlayerBlockingUseAction_t.h"
#include "GCCSPlayer_BulletServices.h"
#include "GCCSPlayer_HostageServices.h"
#include "GCCSPlayer_BuyServices.h"
#include "GCCSPlayer_ActionTrackingServices.h"
#include "GCCSPlayer_RadioServices.h"
#include "GCCSPlayer_DamageReactServices.h"
#include "GCEconItemView.h"
#include "GEntitySpottedState_t.h"
#include "GCCSBot.h"

class GCCSPlayerPawn
{
private:
    void *m_ptr;

public:
    GCCSPlayerPawn() {}
    GCCSPlayerPawn(void *ptr) : m_ptr(ptr) {}

    GCCSPlayer_BulletServices* GetBulletServices() const { return GetSchemaValue<GCCSPlayer_BulletServices*>(m_ptr, "CCSPlayerPawn", "m_pBulletServices"); }
    void SetBulletServices(GCCSPlayer_BulletServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'BulletServices' is not possible.\n"); }
    GCCSPlayer_HostageServices* GetHostageServices() const { return GetSchemaValue<GCCSPlayer_HostageServices*>(m_ptr, "CCSPlayerPawn", "m_pHostageServices"); }
    void SetHostageServices(GCCSPlayer_HostageServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'HostageServices' is not possible.\n"); }
    GCCSPlayer_BuyServices* GetBuyServices() const { return GetSchemaValue<GCCSPlayer_BuyServices*>(m_ptr, "CCSPlayerPawn", "m_pBuyServices"); }
    void SetBuyServices(GCCSPlayer_BuyServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'BuyServices' is not possible.\n"); }
    GCCSPlayer_ActionTrackingServices* GetActionTrackingServices() const { return GetSchemaValue<GCCSPlayer_ActionTrackingServices*>(m_ptr, "CCSPlayerPawn", "m_pActionTrackingServices"); }
    void SetActionTrackingServices(GCCSPlayer_ActionTrackingServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ActionTrackingServices' is not possible.\n"); }
    GCCSPlayer_RadioServices* GetRadioServices() const { return GetSchemaValue<GCCSPlayer_RadioServices*>(m_ptr, "CCSPlayerPawn", "m_pRadioServices"); }
    void SetRadioServices(GCCSPlayer_RadioServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'RadioServices' is not possible.\n"); }
    GCCSPlayer_DamageReactServices* GetDamageReactServices() const { return GetSchemaValue<GCCSPlayer_DamageReactServices*>(m_ptr, "CCSPlayerPawn", "m_pDamageReactServices"); }
    void SetDamageReactServices(GCCSPlayer_DamageReactServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'DamageReactServices' is not possible.\n"); }
    uint16_t GetCharacterDefIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "CCSPlayerPawn", "m_nCharacterDefIndex"); }
    void SetCharacterDefIndex(uint16_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_nCharacterDefIndex", false, value); }
    bool GetHasFemaleVoice() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bHasFemaleVoice"); }
    void SetHasFemaleVoice(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bHasFemaleVoice", false, value); }
    CUtlString GetStrVOPrefix() const { return GetSchemaValue<CUtlString>(m_ptr, "CCSPlayerPawn", "m_strVOPrefix"); }
    void SetStrVOPrefix(CUtlString value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_strVOPrefix", false, value); }
    std::string GetLastPlaceName() const { return GetSchemaValue<char*>(m_ptr, "CCSPlayerPawn", "m_szLastPlaceName"); }
    void SetLastPlaceName(std::string value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_szLastPlaceName", false, value); }
    bool GetInHostageResetZone() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bInHostageResetZone"); }
    void SetInHostageResetZone(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bInHostageResetZone", false, value); }
    bool GetInBuyZone() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bInBuyZone"); }
    void SetInBuyZone(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bInBuyZone", false, value); }
    bool GetWasInBuyZone() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bWasInBuyZone"); }
    void SetWasInBuyZone(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bWasInBuyZone", false, value); }
    bool GetInHostageRescueZone() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bInHostageRescueZone"); }
    void SetInHostageRescueZone(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bInHostageRescueZone", false, value); }
    bool GetInBombZone() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bInBombZone"); }
    void SetInBombZone(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bInBombZone", false, value); }
    bool GetWasInHostageRescueZone() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bWasInHostageRescueZone"); }
    void SetWasInHostageRescueZone(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bWasInHostageRescueZone", false, value); }
    int32_t GetRetakesOffering() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_iRetakesOffering"); }
    void SetRetakesOffering(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iRetakesOffering", false, value); }
    int32_t GetRetakesOfferingCard() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_iRetakesOfferingCard"); }
    void SetRetakesOfferingCard(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iRetakesOfferingCard", false, value); }
    bool GetRetakesHasDefuseKit() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bRetakesHasDefuseKit"); }
    void SetRetakesHasDefuseKit(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bRetakesHasDefuseKit", false, value); }
    bool GetRetakesMVPLastRound() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bRetakesMVPLastRound"); }
    void SetRetakesMVPLastRound(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bRetakesMVPLastRound", false, value); }
    int32_t GetRetakesMVPBoostItem() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_iRetakesMVPBoostItem"); }
    void SetRetakesMVPBoostItem(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iRetakesMVPBoostItem", false, value); }
    loadout_slot_t GetRetakesMVPBoostExtraUtility() const { return GetSchemaValue<loadout_slot_t>(m_ptr, "CCSPlayerPawn", "m_RetakesMVPBoostExtraUtility"); }
    void SetRetakesMVPBoostExtraUtility(loadout_slot_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_RetakesMVPBoostExtraUtility", false, value); }
    float GetLandingTimeSeconds() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flLandingTimeSeconds"); }
    void SetLandingTimeSeconds(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flLandingTimeSeconds", false, value); }
    QAngle GetAimPunchAngle() const { return GetSchemaValue<QAngle>(m_ptr, "CCSPlayerPawn", "m_aimPunchAngle"); }
    void SetAimPunchAngle(QAngle value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_aimPunchAngle", false, value); }
    QAngle GetAimPunchAngleVel() const { return GetSchemaValue<QAngle>(m_ptr, "CCSPlayerPawn", "m_aimPunchAngleVel"); }
    void SetAimPunchAngleVel(QAngle value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_aimPunchAngleVel", false, value); }
    int32_t GetAimPunchTickBase() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_aimPunchTickBase"); }
    void SetAimPunchTickBase(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_aimPunchTickBase", false, value); }
    float GetAimPunchTickFraction() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_aimPunchTickFraction"); }
    void SetAimPunchTickFraction(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_aimPunchTickFraction", false, value); }
    std::vector<QAngle> GetAimPunchCache() const { CUtlVector<QAngle>* vec = GetSchemaValue<CUtlVector<QAngle>*>(m_ptr, "CCSPlayerPawn", "m_aimPunchCache"); std::vector<QAngle> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetAimPunchCache(std::vector<QAngle> value) { SetSchemaValueCUtlVector<QAngle>(m_ptr, "CCSPlayerPawn", "m_aimPunchCache", false, value); }
    bool GetIsBuyMenuOpen() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bIsBuyMenuOpen"); }
    void SetIsBuyMenuOpen(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bIsBuyMenuOpen", false, value); }
    bool GetLastHeadBoneTransformIsValid() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bLastHeadBoneTransformIsValid"); }
    void SetLastHeadBoneTransformIsValid(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bLastHeadBoneTransformIsValid", false, value); }
    bool GetOnGroundLastTick() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bOnGroundLastTick"); }
    void SetOnGroundLastTick(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bOnGroundLastTick", false, value); }
    int32_t GetPlayerLocked() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_iPlayerLocked"); }
    void SetPlayerLocked(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iPlayerLocked", false, value); }
    bool GetNextSprayDecalTimeExpedited() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bNextSprayDecalTimeExpedited"); }
    void SetNextSprayDecalTimeExpedited(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bNextSprayDecalTimeExpedited", false, value); }
    int32_t GetRagdollDamageBone() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_nRagdollDamageBone"); }
    void SetRagdollDamageBone(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_nRagdollDamageBone", false, value); }
    Vector GetRagdollDamageForce() const { return GetSchemaValue<Vector>(m_ptr, "CCSPlayerPawn", "m_vRagdollDamageForce"); }
    void SetRagdollDamageForce(Vector value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vRagdollDamageForce", false, value); }
    Vector GetRagdollDamagePosition() const { return GetSchemaValue<Vector>(m_ptr, "CCSPlayerPawn", "m_vRagdollDamagePosition"); }
    void SetRagdollDamagePosition(Vector value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vRagdollDamagePosition", false, value); }
    std::string GetRagdollDamageWeaponName() const { return GetSchemaValue<char*>(m_ptr, "CCSPlayerPawn", "m_szRagdollDamageWeaponName"); }
    void SetRagdollDamageWeaponName(std::string value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_szRagdollDamageWeaponName", false, value); }
    bool GetRagdollDamageHeadshot() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bRagdollDamageHeadshot"); }
    void SetRagdollDamageHeadshot(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bRagdollDamageHeadshot", false, value); }
    Vector GetRagdollServerOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CCSPlayerPawn", "m_vRagdollServerOrigin"); }
    void SetRagdollServerOrigin(Vector value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vRagdollServerOrigin", false, value); }
    GCEconItemView GetEconGloves() const { return GetSchemaValue<GCEconItemView>(m_ptr, "CCSPlayerPawn", "m_EconGloves"); }
    void SetEconGloves(GCEconItemView value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_EconGloves", false, value); }
    uint8_t GetEconGlovesChanged() const { return GetSchemaValue<uint8_t>(m_ptr, "CCSPlayerPawn", "m_nEconGlovesChanged"); }
    void SetEconGlovesChanged(uint8_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_nEconGlovesChanged", false, value); }
    QAngle GetDeathEyeAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CCSPlayerPawn", "m_qDeathEyeAngles"); }
    void SetDeathEyeAngles(QAngle value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_qDeathEyeAngles", false, value); }
    bool GetSkipOneHeadConstraintUpdate() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bSkipOneHeadConstraintUpdate"); }
    void SetSkipOneHeadConstraintUpdate(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bSkipOneHeadConstraintUpdate", false, value); }
    bool GetLeftHanded() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bLeftHanded"); }
    void SetLeftHanded(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bLeftHanded", false, value); }
    float GetViewmodelOffsetX() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flViewmodelOffsetX"); }
    void SetViewmodelOffsetX(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flViewmodelOffsetX", false, value); }
    float GetViewmodelOffsetY() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flViewmodelOffsetY"); }
    void SetViewmodelOffsetY(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flViewmodelOffsetY", false, value); }
    float GetViewmodelOffsetZ() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flViewmodelOffsetZ"); }
    void SetViewmodelOffsetZ(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flViewmodelOffsetZ", false, value); }
    float GetViewmodelFOV() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flViewmodelFOV"); }
    void SetViewmodelFOV(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flViewmodelFOV", false, value); }
    bool GetIsWalking() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bIsWalking"); }
    void SetIsWalking(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bIsWalking", false, value); }
    float GetLastGivenDefuserTime() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_fLastGivenDefuserTime"); }
    void SetLastGivenDefuserTime(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_fLastGivenDefuserTime", false, value); }
    float GetLastGivenBombTime() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_fLastGivenBombTime"); }
    void SetLastGivenBombTime(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_fLastGivenBombTime", false, value); }
    float GetDealtDamageToEnemyMostRecentTimestamp() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flDealtDamageToEnemyMostRecentTimestamp"); }
    void SetDealtDamageToEnemyMostRecentTimestamp(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flDealtDamageToEnemyMostRecentTimestamp", false, value); }
    uint32_t GetDisplayHistoryBits() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayerPawn", "m_iDisplayHistoryBits"); }
    void SetDisplayHistoryBits(uint32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iDisplayHistoryBits", false, value); }
    float GetLastAttackedTeammate() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flLastAttackedTeammate"); }
    void SetLastAttackedTeammate(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flLastAttackedTeammate", false, value); }
    bool GetResetArmorNextSpawn() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bResetArmorNextSpawn"); }
    void SetResetArmorNextSpawn(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bResetArmorNextSpawn", false, value); }
    CEntityIndex GetLastKillerIndex() const { return GetSchemaValue<CEntityIndex>(m_ptr, "CCSPlayerPawn", "m_nLastKillerIndex"); }
    void SetLastKillerIndex(CEntityIndex value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_nLastKillerIndex", false, value); }
    GEntitySpottedState_t GetEntitySpottedState() const { return GetSchemaValue<GEntitySpottedState_t>(m_ptr, "CCSPlayerPawn", "m_entitySpottedState"); }
    void SetEntitySpottedState(GEntitySpottedState_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_entitySpottedState", false, value); }
    int32_t GetSpotRules() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_nSpotRules"); }
    void SetSpotRules(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_nSpotRules", false, value); }
    bool GetIsScoped() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bIsScoped"); }
    void SetIsScoped(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bIsScoped", false, value); }
    bool GetResumeZoom() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bResumeZoom"); }
    void SetResumeZoom(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bResumeZoom", false, value); }
    bool GetIsDefusing() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bIsDefusing"); }
    void SetIsDefusing(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bIsDefusing", false, value); }
    bool GetIsGrabbingHostage() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bIsGrabbingHostage"); }
    void SetIsGrabbingHostage(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bIsGrabbingHostage", false, value); }
    CSPlayerBlockingUseAction_t GetBlockingUseActionInProgress() const { return GetSchemaValue<CSPlayerBlockingUseAction_t>(m_ptr, "CCSPlayerPawn", "m_iBlockingUseActionInProgress"); }
    void SetBlockingUseActionInProgress(CSPlayerBlockingUseAction_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iBlockingUseActionInProgress", false, value); }
    bool GetInNoDefuseArea() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bInNoDefuseArea"); }
    void SetInNoDefuseArea(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bInNoDefuseArea", false, value); }
    CEntityIndex GetBombSiteIndex() const { return GetSchemaValue<CEntityIndex>(m_ptr, "CCSPlayerPawn", "m_iBombSiteIndex"); }
    void SetBombSiteIndex(CEntityIndex value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iBombSiteIndex", false, value); }
    int32_t GetWhichBombZone() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_nWhichBombZone"); }
    void SetWhichBombZone(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_nWhichBombZone", false, value); }
    bool GetInBombZoneTrigger() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bInBombZoneTrigger"); }
    void SetInBombZoneTrigger(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bInBombZoneTrigger", false, value); }
    bool GetWasInBombZoneTrigger() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bWasInBombZoneTrigger"); }
    void SetWasInBombZoneTrigger(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bWasInBombZoneTrigger", false, value); }
    int32_t GetShotsFired() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_iShotsFired"); }
    void SetShotsFired(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iShotsFired", false, value); }
    float GetFlinchStack() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flFlinchStack"); }
    void SetFlinchStack(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flFlinchStack", false, value); }
    float GetVelocityModifier() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flVelocityModifier"); }
    void SetVelocityModifier(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flVelocityModifier", false, value); }
    float GetHitHeading() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flHitHeading"); }
    void SetHitHeading(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flHitHeading", false, value); }
    int32_t GetHitBodyPart() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_nHitBodyPart"); }
    void SetHitBodyPart(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_nHitBodyPart", false, value); }
    Vector GetTotalBulletForce() const { return GetSchemaValue<Vector>(m_ptr, "CCSPlayerPawn", "m_vecTotalBulletForce"); }
    void SetTotalBulletForce(Vector value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vecTotalBulletForce", false, value); }
    bool GetWaitForNoAttack() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bWaitForNoAttack"); }
    void SetWaitForNoAttack(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bWaitForNoAttack", false, value); }
    float GetIgnoreLadderJumpTime() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_ignoreLadderJumpTime"); }
    void SetIgnoreLadderJumpTime(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_ignoreLadderJumpTime", false, value); }
    bool GetKilledByHeadshot() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bKilledByHeadshot"); }
    void SetKilledByHeadshot(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bKilledByHeadshot", false, value); }
    int32_t GetLastHitBox() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_LastHitBox"); }
    void SetLastHitBox(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_LastHitBox", false, value); }
    int32_t GetLastHealth() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_LastHealth"); }
    void SetLastHealth(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_LastHealth", false, value); }
    GCCSBot* GetBot() const { return GetSchemaValue<GCCSBot*>(m_ptr, "CCSPlayerPawn", "m_pBot"); }
    void SetBot(GCCSBot* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Bot' is not possible.\n"); }
    bool GetBotAllowActive() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bBotAllowActive"); }
    void SetBotAllowActive(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bBotAllowActive", false, value); }
    QAngle GetThirdPersonHeading() const { return GetSchemaValue<QAngle>(m_ptr, "CCSPlayerPawn", "m_thirdPersonHeading"); }
    void SetThirdPersonHeading(QAngle value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_thirdPersonHeading", false, value); }
    float GetSlopeDropOffset() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flSlopeDropOffset"); }
    void SetSlopeDropOffset(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flSlopeDropOffset", false, value); }
    float GetSlopeDropHeight() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flSlopeDropHeight"); }
    void SetSlopeDropHeight(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flSlopeDropHeight", false, value); }
    Vector GetHeadConstraintOffset() const { return GetSchemaValue<Vector>(m_ptr, "CCSPlayerPawn", "m_vHeadConstraintOffset"); }
    void SetHeadConstraintOffset(Vector value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vHeadConstraintOffset", false, value); }
    int32_t GetLastPickupPriority() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_nLastPickupPriority"); }
    void SetLastPickupPriority(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_nLastPickupPriority", false, value); }
    float GetLastPickupPriorityTime() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flLastPickupPriorityTime"); }
    void SetLastPickupPriorityTime(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flLastPickupPriorityTime", false, value); }
    int32_t GetArmorValue() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_ArmorValue"); }
    void SetArmorValue(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_ArmorValue", false, value); }
    uint16_t GetCurrentEquipmentValue() const { return GetSchemaValue<uint16_t>(m_ptr, "CCSPlayerPawn", "m_unCurrentEquipmentValue"); }
    void SetCurrentEquipmentValue(uint16_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_unCurrentEquipmentValue", false, value); }
    uint16_t GetRoundStartEquipmentValue() const { return GetSchemaValue<uint16_t>(m_ptr, "CCSPlayerPawn", "m_unRoundStartEquipmentValue"); }
    void SetRoundStartEquipmentValue(uint16_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_unRoundStartEquipmentValue", false, value); }
    uint16_t GetFreezetimeEndEquipmentValue() const { return GetSchemaValue<uint16_t>(m_ptr, "CCSPlayerPawn", "m_unFreezetimeEndEquipmentValue"); }
    void SetFreezetimeEndEquipmentValue(uint16_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_unFreezetimeEndEquipmentValue", false, value); }
    int32_t GetLastWeaponFireUsercmd() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_iLastWeaponFireUsercmd"); }
    void SetLastWeaponFireUsercmd(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iLastWeaponFireUsercmd", false, value); }
    float GetLastFriendlyFireDamageReductionRatio() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flLastFriendlyFireDamageReductionRatio"); }
    void SetLastFriendlyFireDamageReductionRatio(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flLastFriendlyFireDamageReductionRatio", false, value); }
    bool GetIsSpawning() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bIsSpawning"); }
    void SetIsSpawning(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bIsSpawning", false, value); }
    int32_t GetDeathFlags() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawn", "m_iDeathFlags"); }
    void SetDeathFlags(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_iDeathFlags", false, value); }
    bool GetHasDeathInfo() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bHasDeathInfo"); }
    void SetHasDeathInfo(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bHasDeathInfo", false, value); }
    float GetDeathInfoTime() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawn", "m_flDeathInfoTime"); }
    void SetDeathInfoTime(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_flDeathInfoTime", false, value); }
    Vector GetDeathInfoOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CCSPlayerPawn", "m_vecDeathInfoOrigin"); }
    void SetDeathInfoOrigin(Vector value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vecDeathInfoOrigin", false, value); }
    std::vector<uint32_t> GetPlayerPatchEconIndices() const { uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CCSPlayerPawn", "m_vecPlayerPatchEconIndices"); std::vector<uint32_t> ret; for(int i = 0; i < 5; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetPlayerPatchEconIndices(std::vector<uint32_t> value) { uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CCSPlayerPawn", "m_vecPlayerPatchEconIndices"); for(int i = 0; i < 5; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vecPlayerPatchEconIndices", false, outValue); }
    Color GetGunGameImmunityColor() const { return GetSchemaValue<Color>(m_ptr, "CCSPlayerPawn", "m_GunGameImmunityColor"); }
    void SetGunGameImmunityColor(Color value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_GunGameImmunityColor", false, value); }
    bool GetGrenadeParametersStashed() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawn", "m_bGrenadeParametersStashed"); }
    void SetGrenadeParametersStashed(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_bGrenadeParametersStashed", false, value); }
    QAngle GetStashedShootAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CCSPlayerPawn", "m_angStashedShootAngles"); }
    void SetStashedShootAngles(QAngle value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_angStashedShootAngles", false, value); }
    Vector GetStashedGrenadeThrowPosition() const { return GetSchemaValue<Vector>(m_ptr, "CCSPlayerPawn", "m_vecStashedGrenadeThrowPosition"); }
    void SetStashedGrenadeThrowPosition(Vector value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vecStashedGrenadeThrowPosition", false, value); }
    Vector GetStashedVelocity() const { return GetSchemaValue<Vector>(m_ptr, "CCSPlayerPawn", "m_vecStashedVelocity"); }
    void SetStashedVelocity(Vector value) { SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vecStashedVelocity", false, value); }
    std::vector<QAngle> GetShootAngleHistory() const { QAngle* outValue = GetSchemaValue<QAngle*>(m_ptr, "CCSPlayerPawn", "m_angShootAngleHistory"); std::vector<QAngle> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetShootAngleHistory(std::vector<QAngle> value) { QAngle* outValue = GetSchemaValue<QAngle*>(m_ptr, "CCSPlayerPawn", "m_angShootAngleHistory"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_angShootAngleHistory", false, outValue); }
    std::vector<Vector> GetThrowPositionHistory() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CCSPlayerPawn", "m_vecThrowPositionHistory"); std::vector<Vector> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetThrowPositionHistory(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CCSPlayerPawn", "m_vecThrowPositionHistory"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vecThrowPositionHistory", false, outValue); }
    std::vector<Vector> GetVelocityHistory() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CCSPlayerPawn", "m_vecVelocityHistory"); std::vector<Vector> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetVelocityHistory(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CCSPlayerPawn", "m_vecVelocityHistory"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerPawn", "m_vecVelocityHistory", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif