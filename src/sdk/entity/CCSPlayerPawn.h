#pragma once

#include "CBasePlayerPawn.h"
#include "CBaseViewModel.h"

class CCSPlayerPawn : public CBasePlayerPawn
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSPlayerPawn, false)

    SCHEMA_FIELD_OFFSET(CCSPlayer_ActionTrackingServices *, m_pActionTrackingServices, 0)
    SCHEMA_FIELD_OFFSET(CCSPlayer_ViewModelServices *, m_pViewModelServices, 0)
    SCHEMA_FIELD_POINTER_OFFSET(CEconItemView, m_EconGloves, 0)
    SCHEMA_FIELD_OFFSET(float, m_flHealthShotBoostExpirationTime, 0)

    SCHEMA_FIELD_OFFSET(uint16_t, m_nCharacterDefIndex, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bHasFemaleVoice, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bInHostageResetZone, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bInBuyZone, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bWasInBuyZone, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bInHostageRescueZone, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bInBombZone, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bWasInHostageRescueZone, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iRetakesOffering, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iRetakesOfferingCard, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bRetakesHasDefuseKit, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bRetakesMVPLastRound, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iRetakesMVPBoostItem, 0)
    SCHEMA_FIELD_OFFSET(float, m_flLandseconds, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_aimPunchTickBase, 0)
    SCHEMA_FIELD_OFFSET(float, m_aimPunchTickFraction, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bIsBuyMenuOpen, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bLastHeadBoneTransformIsValid, 0)
    SCHEMA_FIELD_OFFSET(float, m_lastLandTime, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bOnGroundLastTick, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iPlayerLocked, 0)
    SCHEMA_FIELD_OFFSET(float, m_flTimeOfLastInjury, 0)
    SCHEMA_FIELD_OFFSET(float, m_flNextSprayDecalTime, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bNextSprayDecalTimeExpedited, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nRagdollDamageBone, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bRagdollDamageHeadshot, 0)
    SCHEMA_FIELD_OFFSET(uint8_t, m_nEconGlovesChanged, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bSkipOneHeadConstraintUpdate, 0)

    void GiveNamedItem(const char *item)
    {
        if (this->m_pItemServices() == nullptr)
            return;

        g_Signatures->FetchSignature<GiveNamedItem_t>("GiveNamedItem")(this->m_pItemServices(), item, 0, 0, 0, 0);
    }
};