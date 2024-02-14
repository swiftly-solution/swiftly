#pragma once
#include "CBasePlayerPawn.h"
#include "../schema.h"

class CCSPlayerPawnBase : public CBasePlayerPawn
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSPlayerPawnBase, false)

    SCHEMA_FIELD_OFFSET(int, m_ArmorValue, 0)
    SCHEMA_FIELD_OFFSET(float, m_flFlashDuration, 0)
};