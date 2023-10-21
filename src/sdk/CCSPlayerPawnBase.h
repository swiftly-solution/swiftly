#pragma once
#include "CBasePlayerPawn.h"
#include "schemasystem.h"

class CCSPlayerPawnBase : public CBasePlayerPawn
{
public:
	SCHEMA_FIELD(int32_t, CCSPlayerPawnBase, m_ArmorValue);
};