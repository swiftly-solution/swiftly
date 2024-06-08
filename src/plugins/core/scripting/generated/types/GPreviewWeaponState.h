#ifndef _gpreviewweaponstate_h
#define _gpreviewweaponstate_h

enum class PreviewWeaponState : uint64_t
{
    DROPPED = 0x0,
    HOLSTERED = 0x1,
    DEPLOYED = 0x2,
    PLANTED = 0x3,
    INSPECT = 0x4,
    ICON = 0x5,
};

#endif