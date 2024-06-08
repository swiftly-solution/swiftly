#ifndef _gpulsenpccondition_t_h
#define _gpulsenpccondition_t_h

enum class PulseNPCCondition_t : uint64_t
{
    COND_SEE_PLAYER = 0x1,
    COND_LOST_PLAYER = 0x2,
    COND_HEAR_PLAYER = 0x3,
    COND_PLAYER_PUSHING = 0x4,
    COND_NO_PRIMARY_AMMO = 0x5,
};

#endif