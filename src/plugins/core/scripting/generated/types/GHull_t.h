#ifndef _ghull_t_h
#define _ghull_t_h

enum class Hull_t : uint64_t
{
    HULL_HUMAN = 0x0,
    HULL_SMALL_CENTERED = 0x1,
    HULL_WIDE_HUMAN = 0x2,
    HULL_TINY = 0x3,
    HULL_MEDIUM = 0x4,
    HULL_TINY_CENTERED = 0x5,
    HULL_LARGE = 0x6,
    HULL_LARGE_CENTERED = 0x7,
    HULL_MEDIUM_TALL = 0x8,
    HULL_SMALL = 0x9,
    NUM_HULLS = 0xa,
    HULL_NONE = 0xb,
};

#endif