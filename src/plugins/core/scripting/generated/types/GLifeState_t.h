#ifndef _glifestate_t_h
#define _glifestate_t_h

enum class LifeState_t : uint64_t
{
    LIFE_ALIVE = 0x0,
    LIFE_DYING = 0x1,
    LIFE_DEAD = 0x2,
    LIFE_RESPAWNABLE = 0x3,
    LIFE_RESPAWNING = 0x4,
};

#endif