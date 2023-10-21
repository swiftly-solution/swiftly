#pragma once
#include "schemasystem.h"

enum GamePhase : int32_t
{
	GAMEPHASE_WARMUP_ROUND,
	GAMEPHASE_PLAYING_STANDARD,
	GAMEPHASE_PLAYING_FIRST_HALF,
	GAMEPHASE_PLAYING_SECOND_HALF,
	GAMEPHASE_HALFTIME,
	GAMEPHASE_MATCH_ENDED,
	GAMEPHASE_MAX
};

class CGameRules
{
public:
};

class CMultiplayRules : public CGameRules
{
public:
};

class CTeamplayRules : public CMultiplayRules
{
public:
};

class CCSGameRules : public CTeamplayRules
{
public:
	SCHEMA_FIELD(bool, CCSGameRules, m_bWarmupPeriod);
	SCHEMA_FIELD(bool, CCSGameRules, m_bGameRestart);
	SCHEMA_FIELD(GamePhase, CCSGameRules, m_gamePhase);
	SCHEMA_FIELD(int32_t, CCSGameRules, m_totalRoundsPlayed);
	SCHEMA_FIELD(int32_t, CCSGameRules, m_nOvertimePlaying);
	SCHEMA_FIELD(bool, CCSGameRules, m_bSwitchingTeamsAtRoundReset);
};