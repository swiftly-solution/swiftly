#pragma once

#include "CBaseEntity.h"

class CEconItemView
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CEconItemView, true)

    SCHEMA_FIELD_OFFSET(uint16_t, m_iItemDefinitionIndex, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bInitialized, 0)
};

class CAttributeContainer
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CAttributeContainer, true)

    SCHEMA_FIELD_OFFSET(CEconItemView, m_Item, 0)
};

class CEconEntity : public Z_CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CEconEntity, false)

    SCHEMA_FIELD_OFFSET(CAttributeContainer, m_AttributeManager, 0)
};

class CCSWeaponBase : public CEconEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSWeaponBase, false)
};
