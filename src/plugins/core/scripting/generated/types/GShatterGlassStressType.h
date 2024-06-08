#ifndef _gshatterglassstresstype_h
#define _gshatterglassstresstype_h

enum class ShatterGlassStressType : uint64_t
{
    SHATTERGLASS_BLUNT = 0x0,
    SHATTERGLASS_BALLISTIC = 0x1,
    SHATTERGLASS_PULSE = 0x2,
    SHATTERDRYWALL_CHUNKS = 0x3,
    SHATTERGLASS_EXPLOSIVE = 0x4,
};

#endif