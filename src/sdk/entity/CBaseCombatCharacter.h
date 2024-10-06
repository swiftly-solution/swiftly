#ifndef _cbasecombatcharacter_sdk_h
#define _cbasecombatcharacter_sdk_h

#include "CBaseModelEntity.h"
#include "CCSWeaponBase.h"

class CBaseCombatCharacter : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CBaseCombatCharacter)

    SCHEMA_FIELD_POINTER_OFFSET(CUtlVector<CHandle<CEconWearable>>, m_hMyWearables, 0)
};

#endif