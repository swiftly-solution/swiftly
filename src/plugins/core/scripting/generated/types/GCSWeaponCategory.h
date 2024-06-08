#ifndef _gcsweaponcategory_h
#define _gcsweaponcategory_h

enum class CSWeaponCategory : uint64_t
{
    WEAPONCATEGORY_OTHER = 0x0,
    WEAPONCATEGORY_MELEE = 0x1,
    WEAPONCATEGORY_SECONDARY = 0x2,
    WEAPONCATEGORY_SMG = 0x3,
    WEAPONCATEGORY_RIFLE = 0x4,
    WEAPONCATEGORY_HEAVY = 0x5,
    WEAPONCATEGORY_COUNT = 0x6,
};

#endif