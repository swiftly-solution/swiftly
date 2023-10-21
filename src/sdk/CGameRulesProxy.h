#pragma once
#include "CBaseEntity.h"
#include "schemasystem.h"
#include "CGameRules.h"

class CGameRulesProxy : public SC_CBaseEntity
{
public:
};

class CCSGameRulesProxy : public CGameRulesProxy
{
public:
	SCHEMA_FIELD(CCSGameRules*, CCSGameRulesProxy, m_pGameRules);
};