#pragma once
#include "CBasePlayerPawn.h"
#include "../schema.h"

enum CSPlayerState : uint32_t
{
    STATE_ACTIVE = 0x0,
    STATE_WELCOME = 0x1,
    STATE_PICKINGTEAM = 0x2,
    STATE_PICKINGCLASS = 0x3,
    STATE_DEATH_ANIM = 0x4,
    STATE_DEATH_WAIT_FOR_KEY = 0x5,
    STATE_OBSERVER_MODE = 0x6,
    STATE_GUNGAME_RESPAWN = 0x7,
    STATE_DORMANT = 0x8,
    NUM_PLAYER_STATES = 0x9,
};

enum CSPlayerBlockingUseAction_t : uint32_t
{
    k_CSPlayerBlockingUseAction_None = 0x0,
    k_CSPlayerBlockingUseAction_DefusingDefault = 0x1,
    k_CSPlayerBlockingUseAction_DefusingWithKit = 0x2,
    k_CSPlayerBlockingUseAction_HostageGrabbing = 0x3,
    k_CSPlayerBlockingUseAction_HostageDropping = 0x4,
    k_CSPlayerBlockingUseAction_OpeningSafe = 0x5,
    k_CSPlayerBlockingUseAction_EquippingParachute = 0x6,
    k_CSPlayerBlockingUseAction_EquippingHeavyArmor = 0x7,
    k_CSPlayerBlockingUseAction_EquippingContract = 0x8,
    k_CSPlayerBlockingUseAction_EquippingTabletUpgrade = 0x9,
    k_CSPlayerBlockingUseAction_TakingOffHeavyArmor = 0xa,
    k_CSPlayerBlockingUseAction_PayingToOpenDoor = 0xb,
    k_CSPlayerBlockingUseAction_CancelingSpawnRappelling = 0xc,
    k_CSPlayerBlockingUseAction_EquippingExoJump = 0xd,
    k_CSPlayerBlockingUseAction_PickingUpBumpMine = 0xe,
    k_CSPlayerBlockingUseAction_MapLongUseEntity_Pickup = 0xf,
    k_CSPlayerBlockingUseAction_MapLongUseEntity_Place = 0x10,
    k_CSPlayerBlockingUseAction_MaxCount = 0x11,
};

class CCSPlayerPawnBase : public CBasePlayerPawn
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSPlayerPawnBase, false)

    SCHEMA_FIELD_OFFSET(int, m_ArmorValue, 0)
    SCHEMA_FIELD_OFFSET(float, m_flFlashDuration, 0)
    SCHEMA_FIELD_OFFSET(float, m_flVelocityModifier, 0)
    SCHEMA_FIELD_OFFSET(QAngle, m_angEyeAngles, 0)

    SCHEMA_FIELD_OFFSET(uint32_t, m_iDisplayHistoryBits, 0)
    SCHEMA_FIELD_OFFSET(float, m_flLastAttackedTeammate, 0)
    SCHEMA_FIELD_OFFSET(float, m_blindUntilTime, 0)
    SCHEMA_FIELD_OFFSET(float, m_blindStartTime, 0)
    SCHEMA_FIELD_OFFSET(float, m_allowAutoFollowTime, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nSpotRules, 0)
    SCHEMA_FIELD_OFFSET(CSPlayerState, m_iPlayerState, 0)
    SCHEMA_FIELD_OFFSET(float, m_flLastDistanceTraveledNotice, 0)
    SCHEMA_FIELD_OFFSET(float, m_flAccumulatedDistanceTraveled, 0)
    SCHEMA_FIELD_OFFSET(float, m_flLastFriendlyFireDamageReductionRatio, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bRespawning, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nLastPickupPriority, 0)
    SCHEMA_FIELD_OFFSET(float, m_flLastPickupPriorityTime, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bIsScoped, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bIsWalking, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bResumeZoom, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bIsDefusing, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bIsGrabbingHostage, 0)
    SCHEMA_FIELD_OFFSET(CSPlayerBlockingUseAction_t, m_iBlockingUseActionInProgress, 0)
    SCHEMA_FIELD_OFFSET(float, m_fImmuneToGunGameDamageTime, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bGunGameImmunity, 0)
    SCHEMA_FIELD_OFFSET(float, m_fMolotovDamageTime, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bHasMovedSinceSpawn, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bCanMoveDuringFreezePeriod, 0)
    SCHEMA_FIELD_OFFSET(float, m_flGuardianTooFarDistFrac, 0)
    SCHEMA_FIELD_OFFSET(float, m_flNextGuardianTooFarHurtTime, 0)
    SCHEMA_FIELD_OFFSET(float, m_flDetectedByEnemySensorTime, 0)
    SCHEMA_FIELD_OFFSET(float, m_flDealtDamageToEnemyMostRecentTimestamp, 0)
    SCHEMA_FIELD_OFFSET(float, m_flLastEquippedHelmetTime, 0)
    SCHEMA_FIELD_OFFSET(float, m_flLastEquippedArmorTime, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nHeavyAssaultSuitCooldownRemaining, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bResetArmorNextSpawn, 0)
    SCHEMA_FIELD_OFFSET(float, m_flLastBumpMineBumpTime, 0)
    SCHEMA_FIELD_OFFSET(float, m_flEmitSoundTime, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iNumSpawns, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iShouldHaveCash, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bInvalidSteamLogonDelayed, 0)
    SCHEMA_FIELD_OFFSET(float, m_flLastAction, 0)
    SCHEMA_FIELD_OFFSET(float, m_fLastGivenDefuserTime, 0)
    SCHEMA_FIELD_OFFSET(float, m_fLastGivenBombTime, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bHasNightVision, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bNightVisionOn, 0)
    SCHEMA_FIELD_OFFSET(float, m_fNextRadarUpdateTime, 0)
    SCHEMA_FIELD_OFFSET(float, m_flLastMoneyUpdateTime, 0)
    SCHEMA_FIELD_OFFSET(float, m_fIntroCamTime, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bInNoDefuseArea, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bKilledByTaser, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iMoveState, 0)
    SCHEMA_FIELD_OFFSET(float, m_grenadeParameterStashTime, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bGrenadeParametersStashed, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bDiedAirborne, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nWhichBombZone, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bInBombZoneTrigger, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bWasInBombZoneTrigger, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iDirection, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iShotsFired, 0)
    SCHEMA_FIELD_OFFSET(float, m_flFlinchStack, 0)
    SCHEMA_FIELD_OFFSET(float, m_flHitHeading, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nHitBodyPart, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iHostagesKilled, 0)
    SCHEMA_FIELD_OFFSET(float, m_flFlashMaxAlpha, 0)
    SCHEMA_FIELD_OFFSET(float, m_flProgressBarStartTime, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iProgressBarDuration, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bWaitForNoAttack, 0)
    SCHEMA_FIELD_OFFSET(float, m_flLowerBodyYawTarget, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bStrafing, 0)
    SCHEMA_FIELD_OFFSET(float, m_ignoreLadderJumpTime, 0)
    SCHEMA_FIELD_OFFSET(float, m_flSlopeDropOffset, 0)
    SCHEMA_FIELD_OFFSET(float, m_flSlopeDropHeight, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iLastWeaponFireUsercmd, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bVCollisionInitted, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bIsSpawning, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bHideTargetID, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nNumDangerZoneDamageHits, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bHud_MiniScoreHidden, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bHud_RadarHidden, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nLastConcurrentKilled, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nDeathCamMusic, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iAddonBits, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iPrimaryAddon, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iSecondaryAddon, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_NumEnemiesKilledThisSpawn, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_NumEnemiesKilledThisRound, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_NumEnemiesAtRoundStart, 0)
    SCHEMA_FIELD_OFFSET(bool, m_wasNotKilledNaturally, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iDeathFlags, 0)
    SCHEMA_FIELD_OFFSET(uint16_t, m_unCurrentEquipmentValue, 0)
    SCHEMA_FIELD_OFFSET(uint16_t, m_unRoundStartEquipmentValue, 0)
    SCHEMA_FIELD_OFFSET(uint16_t, m_unFreezetimeEndEquipmentValue, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nSurvivalTeamNumber, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bHasDeathInfo, 0)
    SCHEMA_FIELD_OFFSET(float, m_flDeathInfoTime, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bKilledByHeadshot, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_LastHitBox, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_LastHealth, 0)
    SCHEMA_FIELD_OFFSET(float, m_flLastCollisionCeiling, 0)
    SCHEMA_FIELD_OFFSET(float, m_flLastCollisionCeilingChangeTime, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bBotAllowActive, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bCommittingSuicideOnTeamChange, 0)
};