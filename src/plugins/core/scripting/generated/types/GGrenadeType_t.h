#ifndef _ggrenadetype_t_h
#define _ggrenadetype_t_h

enum class GrenadeType_t : uint64_t
{
    GRENADE_TYPE_EXPLOSIVE = 0x0,
    GRENADE_TYPE_FLASH = 0x1,
    GRENADE_TYPE_FIRE = 0x2,
    GRENADE_TYPE_DECOY = 0x3,
    GRENADE_TYPE_SMOKE = 0x4,
    GRENADE_TYPE_SENSOR = 0x5,
    GRENADE_TYPE_SNOWBALL = 0x6,
    GRENADE_TYPE_TOTAL = 0x7,
};

#endif