#ifndef _gweaponattacktype_t_h
#define _gweaponattacktype_t_h

enum class WeaponAttackType_t : uint64_t
{
    eInvalid = 0xffffffffffffffff,
    ePrimary = 0x0,
    eSecondary = 0x1,
    eCount = 0x2,
};

#endif