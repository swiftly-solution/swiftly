#pragma once

#include "CBasePlayerController.h"
#include "services.h"

class CCSPlayerController : public CBasePlayerController
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSPlayerController, false)

    SCHEMA_FIELD_OFFSET(CCSPlayerController_InGameMoneyServices *, m_pInGameMoneyServices, 0)
    SCHEMA_FIELD_OFFSET(CCSPlayerController_ActionTrackingServices *, m_pActionTrackingServices, 0)
    SCHEMA_FIELD_OFFSET(CCSPlayerController_InventoryServices *, m_pInventoryServices, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bPawnIsAlive, 0)
    SCHEMA_FIELD_OFFSET(CHandle<CCSPlayerPawn>, m_hPlayerPawn, 0)
    SCHEMA_FIELD_OFFSET(CUtlSymbolLarge, m_szClan, 0)
    SCHEMA_FIELD_POINTER_OFFSET(char, m_szClanName, 0)

    SCHEMA_FIELD_OFFSET(int32_t, m_iCompetitiveRanking, 0)
    SCHEMA_FIELD_OFFSET(int8_t, m_iCompetitiveRankType, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_m_iCompetitiveWins, 0)

    SCHEMA_FIELD_OFFSET(bool, m_bHasCommunicationAbuseMute, 0)
    SCHEMA_FIELD_OFFSET(uint8_t, m_iPendingTeamNum, 0)
    SCHEMA_FIELD_OFFSET(float, m_flForceTeamTime, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iCompTeammateColor, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bEverPlayedOnTeam, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bAttemptedToGetColor, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iTeammatePreferredColor, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bTeamChanged, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bInSwitchTeam, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bHasSeenJoinGame, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bJustBecameSpectator, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bSwitchTeamsOnNextRoundReset, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bRemoveAllItemsOnNextRoundReset, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iCompetitiveRankingPredicted_Win, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iCompetitiveRankingPredicted_Loss, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iCompetitiveRankingPredicted_Tie, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nEndMatchNextMapVote, 0)
    SCHEMA_FIELD_OFFSET(uint16_t, m_unActiveQuestId, 0)
    SCHEMA_FIELD_OFFSET(uint32_t, m_unPlayerTvControlFlags, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iDraftIndex, 0)
    SCHEMA_FIELD_OFFSET(uint32_t, m_msQueuedModeDisconnectionTimestamp, 0)
    SCHEMA_FIELD_OFFSET(uint32_t, m_uiAbandonRecordedReason, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bCannotBeKicked, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bEverFullyConnected, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bAbandonAllowsSurrender, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bAbandonOffersInstantSurrender, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bDisconnection1MinWarningPrinted, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bScoreReported, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nDisconnectionTick, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bControllingBot, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bHasControlledBotThisRound, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bHasBeenControlledByPlayerThisRound, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nBotsControlledThisRound, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bCanControlObservedBot, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_DesiredObserverMode, 0)
    SCHEMA_FIELD_OFFSET(uint16_t, m_nPawnCharacterDefIndex, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iPawnLifetimeStart, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iPawnLifetimeEnd, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iPawnBotDifficulty, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iScore, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iRoundScore, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iRoundsWon, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iMVPs, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nUpdateCounter, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bShowHints, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iNextTimeCheck, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bJustDidTeamKill, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bPunishForTeamKill, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bGaveTeamDamageWarning, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bGaveTeamDamageWarningThisRound, 0)
    SCHEMA_FIELD_OFFSET(double, m_dblLastReceivedPacketPlatFloatTime, 0)
    SCHEMA_FIELD_OFFSET(float, m_LastTeamDamageWarningTime, 0)
    SCHEMA_FIELD_OFFSET(float, m_LastTimePlayerWasDisconnectedForPawnsRemove, 0)
    SCHEMA_FIELD_OFFSET(uint32_t, m_nSuspiciousHitCount, 0)
    SCHEMA_FIELD_OFFSET(uint32_t, m_nNonSuspiciousHitStreak, 0)

    void Respawn()
    {
        CCSPlayerPawn *pawn = m_hPlayerPawn.Get();
        if (!pawn)
            return;

        SetPawn(pawn);
        CALL_VIRTUAL(void, g_Offsets->GetOffset("Respawn"), this);
    }
};