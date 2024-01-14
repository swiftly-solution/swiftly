#pragma once

#include <platform.h>
#include "globaltypes.h"
#include <tier1/utlvector.h>
#include "CCSWeaponBase.h"

class CBaseEntity;
class CCSPlayerPawn;

struct CSPerRoundStats_t
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CSPerRoundStats_t, true)

    SCHEMA_FIELD_OFFSET(int, m_iKills, 0)
    SCHEMA_FIELD_OFFSET(int, m_iDeaths, 0)
    SCHEMA_FIELD_OFFSET(int, m_iAssists, 0)
    SCHEMA_FIELD_OFFSET(int, m_iDamage, 0)
};

struct CSMatchStats_t : public CSPerRoundStats_t
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CSMatchStats_t, true)
};

class CCSPlayerController_ActionTrackingServices
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSPlayerController_ActionTrackingServices, false)

    SCHEMA_FIELD_OFFSET(CSMatchStats_t, m_matchStats, 0)
};

class CPlayer_MovementServices
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CPlayer_MovementServices, false)

    SCHEMA_FIELD_OFFSET(CInButtonState, m_nButtons, 0)
    SCHEMA_FIELD_OFFSET(uint64_t, m_nQueuedButtonDownMask, 0)
    SCHEMA_FIELD_OFFSET(uint64_t, m_nQueuedButtonChangeMask, 0)
    SCHEMA_FIELD_OFFSET(uint64_t, m_nButtonDoublePressed, 0)

    // m_pButtonPressedCmdNumber[64]
    SCHEMA_FIELD_POINTER_OFFSET(uint32_t, m_pButtonPressedCmdNumber, 0)
    SCHEMA_FIELD_OFFSET(uint32_t, m_nLastCommandNumberProcessed, 0)
    SCHEMA_FIELD_OFFSET(uint64_t, m_nToggleButtonDownMask, 0)
    SCHEMA_FIELD_OFFSET(float, m_flMaxspeed, 0)
};

class CPlayer_MovementServices_Humanoid : CPlayer_MovementServices
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CPlayer_MovementServices_Humanoid, false)
};

class CCSPlayer_MovementServices : CPlayer_MovementServices_Humanoid
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSPlayer_MovementServices, false)
};

class CCSPlayerController_InGameMoneyServices
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSPlayerController_InGameMoneyServices, false)

    SCHEMA_FIELD_OFFSET(int, m_iAccount, 0)
};

class CCSPlayer_ItemServices
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSPlayer_ItemServices, false)

    virtual ~CCSPlayer_ItemServices() = 0;

private:
    virtual void unk_01() = 0;
    virtual void unk_02() = 0;
    virtual void unk_03() = 0;
    virtual void unk_04() = 0;
    virtual void unk_05() = 0;
    virtual void unk_06() = 0;
    virtual void unk_07() = 0;
    virtual void unk_08() = 0;
    virtual void unk_09() = 0;
    virtual void unk_10() = 0;
    virtual void unk_11() = 0;
    virtual void unk_12() = 0;
    virtual void unk_13() = 0;
    virtual void unk_14() = 0;
    virtual CBaseEntity *_GiveNamedItem(const char *pchName) = 0;

public:
    virtual bool GiveNamedItemBool(const char *pchName) = 0;
    virtual CBaseEntity *GiveNamedItem(const char *pchName) = 0;
    virtual void DropPlayerWeapon(CBasePlayerWeapon *weapon) = 0;
    virtual void StripPlayerWeapons() = 0;
};

// We need an exactly sized class to be able to iterate the vector, our schema system implementation can't do this
class WeaponPurchaseCount_t
{
private:
    virtual void unk01(){};
    uint64_t unk1 = 0;  // 0x8
    uint64_t unk2 = 0;  // 0x10
    uint64_t unk3 = 0;  // 0x18
    uint64_t unk4 = 0;  // 0x20
    uint64_t unk5 = -1; // 0x28
public:
    uint16_t m_nItemDefIndex; // 0x30
    uint16_t m_nCount;        // 0x32
private:
    uint32_t unk6 = 0;
};

struct WeaponPurchaseTracker_t
{
public:
    DECLARE_SCHEMA_CLASS_BASE(WeaponPurchaseTracker_t, true)

    SCHEMA_FIELD_POINTER_OFFSET(CUtlVector<WeaponPurchaseCount_t>, m_weaponPurchases, 0)
};

class CCSPlayer_ActionTrackingServices
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSPlayer_ActionTrackingServices, false)

    SCHEMA_FIELD_OFFSET(WeaponPurchaseTracker_t, m_weaponPurchasesThisRound, 0)
};

class CPlayerPawnComponent
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CPlayerPawnComponent, false)

    SCHEMA_FIELD_OFFSET(CCSPlayerPawn *, __m_pChainEntity, 0)
};

class CPlayer_WeaponServices : public CPlayerPawnComponent
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CPlayer_WeaponServices, false)

    SCHEMA_FIELD_POINTER_OFFSET(CUtlVector<CHandle<CBasePlayerWeapon>>, m_hMyWeapons, 0)
    SCHEMA_FIELD_OFFSET(CHandle<CBasePlayerWeapon>, m_hActiveWeapon, 0)

    void RemoveWeapon(CBasePlayerWeapon *weapon)
    {
        CALL_VIRTUAL(void, 20, weapon, nullptr, nullptr);
    }
};