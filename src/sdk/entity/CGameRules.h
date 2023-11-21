#pragma once
#include <platform.h>
#include "globaltypes.h"
#include "CBaseEntity.h"

class CGameRules
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CGameRules, false)
};

class CCSGameRules : public CGameRules
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSGameRules, false)

    SCHEMA_FIELD_OFFSET(float, m_fMatchStartTime, 0)
    SCHEMA_FIELD_OFFSET(float, m_flGameStartTime, 0)
    SCHEMA_FIELD_OFFSET(int, m_totalRoundsPlayed, 0)
    SCHEMA_FIELD_OFFSET(GameTime_t, m_fRoundStartTime, 0)
    SCHEMA_FIELD_OFFSET(GameTime_t, m_flRestartRoundTime, 0)
};

class CCSGameRulesProxy : public Z_CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSGameRulesProxy, false)

    SCHEMA_FIELD_OFFSET(CCSGameRules *, m_pGameRules, 0)
};