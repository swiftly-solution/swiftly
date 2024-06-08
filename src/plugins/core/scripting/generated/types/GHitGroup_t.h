#ifndef _ghitgroup_t_h
#define _ghitgroup_t_h

enum class HitGroup_t : uint64_t
{
    HITGROUP_INVALID = 0xffffffffffffffff,
    HITGROUP_GENERIC = 0x0,
    HITGROUP_HEAD = 0x1,
    HITGROUP_CHEST = 0x2,
    HITGROUP_STOMACH = 0x3,
    HITGROUP_LEFTARM = 0x4,
    HITGROUP_RIGHTARM = 0x5,
    HITGROUP_LEFTLEG = 0x6,
    HITGROUP_RIGHTLEG = 0x7,
    HITGROUP_NECK = 0x8,
    HITGROUP_UNUSED = 0x9,
    HITGROUP_GEAR = 0xa,
    HITGROUP_SPECIAL = 0xb,
    HITGROUP_COUNT = 0xc,
};

#endif