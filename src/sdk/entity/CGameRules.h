#pragma once
#include <platform.h>
#include "globaltypes.h"
#include "CBaseEntity.h"

class CGameRules
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CGameRules)
};

class CCSGameRules : public CGameRules
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSGameRules)

    SCHEMA_FIELD_OFFSET(float, m_fMatchStartTime, 0);
    SCHEMA_FIELD_OFFSET(float, m_flGameStartTime, 0);
    SCHEMA_FIELD_OFFSET(int, m_totalRoundsPlayed, 0);
    SCHEMA_FIELD_OFFSET(GameTime_t, m_fRoundStartTime, 0);
    SCHEMA_FIELD_OFFSET(GameTime_t, m_flRestartRoundTime, 0);
    SCHEMA_FIELD_OFFSET(int32_t, m_nOvertimePlaying, 0);
    SCHEMA_FIELD_OFFSET(bool, m_bSwitchingTeamsAtRoundReset, 0);
    SCHEMA_FIELD_OFFSET(bool, m_bGameRestart, 0);
    SCHEMA_FIELD_OFFSET(int, m_iRoundTime, 0);
    SCHEMA_FIELD_OFFSET(int, m_nRoundsPlayedThisPhase, 0);
    SCHEMA_FIELD_OFFSET(int, m_bWarmupPeriod, 0);
    SCHEMA_FIELD_OFFSET(int, m_bFreezePeriod, 0);
    SCHEMA_FIELD_OFFSET(bool, m_bIsQueuedMatchmaking, 0);
    SCHEMA_FIELD_OFFSET(int32_t, m_nQueuedMatchmakingMode, 0);
};

class CCSGameRulesProxy : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSGameRulesProxy)

    SCHEMA_FIELD_OFFSET(CCSGameRules*, m_pGameRules, 0)
};