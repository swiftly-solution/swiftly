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

inline CEntityInstance *UTIL_FindEntityByClassname(CEntityInstance *pStart, const char *name)
{
    extern CEntitySystem *g_pEntitySystem;
    CEntityIdentity *pEntity = pStart ? pStart->m_pEntity->m_pNext : g_pEntitySystem->m_EntityList.m_pFirstActiveEntity;

    for (; pEntity; pEntity = pEntity->m_pNext)
    {
        if (!strcmp(pEntity->m_designerName.String(), name))
            return pEntity->m_pInstance;
    };

    return nullptr;
}

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

    void TakeDamage(int damage)
    {
        this->m_iHealth = this->m_iHealth() - damage;
    }
};