#ifndef _gshatterdamagecause_h
#define _gshatterdamagecause_h

enum class ShatterDamageCause : uint64_t
{
    SHATTERDAMAGE_BULLET = 0x0,
    SHATTERDAMAGE_MELEE = 0x1,
    SHATTERDAMAGE_THROWN = 0x2,
    SHATTERDAMAGE_SCRIPT = 0x3,
    SHATTERDAMAGE_EXPLOSIVE = 0x4,
};

#endif