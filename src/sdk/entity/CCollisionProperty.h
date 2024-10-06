#pragma once

#include "CBaseEntity.h"

struct VPhysicsCollisionAttribute_t
{
    DECLARE_SCHEMA_CLASS_BASE(VPhysicsCollisionAttribute_t)

    SCHEMA_FIELD_OFFSET(uint8, m_nCollisionGroup, 0);
    SCHEMA_FIELD_OFFSET(uint64_t, m_nInteractsAs, 0);
    SCHEMA_FIELD_OFFSET(uint64_t, m_nInteractsWith, 0);
    SCHEMA_FIELD_OFFSET(uint64_t, m_nInteractsExclude, 0);
};

/*
keep this always on struct, no matter what
*/
class CCollisionProperty
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCollisionProperty)

    SCHEMA_FIELD_OFFSET(VPhysicsCollisionAttribute_t, m_collisionAttribute, 0);
    SCHEMA_FIELD_OFFSET(SolidType_t, m_nSolidType, 0);
    SCHEMA_FIELD_OFFSET(uint8, m_usSolidFlags, 0);
    SCHEMA_FIELD_OFFSET(uint8, m_CollisionGroup, 0);
};