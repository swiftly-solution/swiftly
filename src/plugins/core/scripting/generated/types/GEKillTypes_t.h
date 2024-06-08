#ifndef _gekilltypes_t_h
#define _gekilltypes_t_h

enum class EKillTypes_t : uint64_t
{
    KILL_NONE = 0x0,
    KILL_DEFAULT = 0x1,
    KILL_HEADSHOT = 0x2,
    KILL_BLAST = 0x3,
    KILL_BURN = 0x4,
    KILL_SLASH = 0x5,
    KILL_SHOCK = 0x6,
    KILLTYPE_COUNT = 0x7,
};

#endif