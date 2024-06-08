#ifndef _gbegindeathlifestatetransition_t_h
#define _gbegindeathlifestatetransition_t_h

enum class BeginDeathLifeStateTransition_t : uint64_t
{
    NO_CHANGE_IN_LIFESTATE = 0x0,
    TRANSITION_TO_LIFESTATE_DYING = 0x1,
    TRANSITION_TO_LIFESTATE_DEAD = 0x2,
};

#endif