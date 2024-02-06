#pragma once

#include "CBaseEntity.h"

enum gear_slot_t : uint32_t
{
    GEAR_SLOT_INVALID = 0xffffffff,
    GEAR_SLOT_RIFLE = 0x0,
    GEAR_SLOT_PISTOL = 0x1,
    GEAR_SLOT_KNIFE = 0x2,
    GEAR_SLOT_GRENADES = 0x3,
    GEAR_SLOT_C4 = 0x4,
    GEAR_SLOT_RESERVED_SLOT6 = 0x5,
    GEAR_SLOT_RESERVED_SLOT7 = 0x6,
    GEAR_SLOT_RESERVED_SLOT8 = 0x7,
    GEAR_SLOT_RESERVED_SLOT9 = 0x8,
    GEAR_SLOT_RESERVED_SLOT10 = 0x9,
    GEAR_SLOT_RESERVED_SLOT11 = 0xa,
    GEAR_SLOT_BOOSTS = 0xb,
    GEAR_SLOT_UTILITY = 0xc,
    GEAR_SLOT_COUNT = 0xd,
    GEAR_SLOT_CURRENT_WEAPON = 0xe,
    GEAR_SLOT_FIRST = 0x0,
    GEAR_SLOT_LAST = 0xc,
};

class CEconItemView
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CEconItemView, true)

    SCHEMA_FIELD_OFFSET(uint16_t, m_iItemDefinitionIndex, 0)
    SCHEMA_FIELD_OFFSET(uint64_t, m_iItemID, 0)
    SCHEMA_FIELD_OFFSET(uint32_t, m_iItemIDHigh, 0)
    SCHEMA_FIELD_OFFSET(uint32_t, m_iItemIDLow, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bInitialized, 0)
    SCHEMA_FIELD_OFFSET(uint32_t, m_iAccountID, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_iEntityQuality, 0)

    SCHEMA_FIELD_OFFSET(char *, m_szCustomName, 0)
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
    SCHEMA_FIELD_OFFSET(int32_t, m_nFallbackPaintKit, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nFallbackSeed, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nFallbackStatTrak, 0)
    SCHEMA_FIELD_OFFSET(float, m_flFallbackWear, 0)
    SCHEMA_FIELD_OFFSET(uint64_t, m_OriginalOwnerXuidLow, 0)
    SCHEMA_FIELD_OFFSET(uint64_t, m_OriginalOwnerXuidHigh, 0)
};

class CBasePlayerWeaponVData : public CEntitySubclassVDataBase
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CBasePlayerWeaponVData, false)
    SCHEMA_FIELD_OFFSET(int, m_iMaxClip1, 0)
};

class CCSWeaponBaseVData : public CBasePlayerWeaponVData
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSWeaponBaseVData, false)

    SCHEMA_FIELD_OFFSET(gear_slot_t, m_GearSlot, 0)
    SCHEMA_FIELD_OFFSET(int, m_nPrice, 0)
    SCHEMA_FIELD_OFFSET(int, m_nPrimaryReserveAmmoMax, 0)
};

class CEconWearable : public CEconEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CEconWearable, false)

    SCHEMA_FIELD_OFFSET(int32_t, m_nForceSkin, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bAlwaysAllow, 0)
};

class CBasePlayerWeapon : public CEconEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CBasePlayerWeapon, false)

    CCSWeaponBaseVData *GetWeaponVData() { return (CCSWeaponBaseVData *)GetVData(); }
};

class CCSWeaponBase : public CBasePlayerWeapon
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSWeaponBase, false)
};