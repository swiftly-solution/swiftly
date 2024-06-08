#ifndef _gcsweaponstate_t_h
#define _gcsweaponstate_t_h

enum class CSWeaponState_t : uint64_t
{
    WEAPON_NOT_CARRIED = 0x0,
    WEAPON_IS_CARRIED_BY_PLAYER = 0x1,
    WEAPON_IS_ACTIVE = 0x2,
};

#endif