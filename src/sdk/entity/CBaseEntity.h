#pragma once

#include "../schema.h"

#include "../../common.h"
#include "globaltypes.h"
#include "CCollisionProperty.h"
#include "ehandle.h"
#include "mathlib/vector.h"

#define CS_TEAM_NONE 0
#define CS_TEAM_SPECTATOR 1
#define CS_TEAM_T 2
#define CS_TEAM_CT 3

class Z_CBaseEntity : public CBaseEntity
{
public:
    typedef Z_CBaseEntity ThisClass;
    static constexpr const char *ThisClassName = "CBaseEntity";
    static constexpr bool IsStruct = false;

    SCHEMA_FIELD_OFFSET(CBitVec<64>, m_isSteadyState, 0)
    SCHEMA_FIELD_OFFSET(float, m_lastNetworkChange, 0)
    SCHEMA_FIELD_POINTER_OFFSET(CNetworkTransmitComponent, m_NetworkTransmitComponent, 0)
    SCHEMA_FIELD_OFFSET(int, m_iHealth, 0)
    SCHEMA_FIELD_OFFSET(int, m_iTeamNum, 0)
    SCHEMA_FIELD_OFFSET(MoveType_t, m_MoveType, 0)
    SCHEMA_FIELD_OFFSET(uint32, m_spawnflags, 0)
    SCHEMA_FIELD_OFFSET(uint32, m_fFlags, 0)
    SCHEMA_FIELD_OFFSET(LifeState_t, m_lifeState, 0)
    SCHEMA_FIELD_OFFSET(CCollisionProperty *, m_pCollision, 0)
};