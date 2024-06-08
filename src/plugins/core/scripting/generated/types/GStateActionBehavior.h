#ifndef _gstateactionbehavior_h
#define _gstateactionbehavior_h

enum class StateActionBehavior : uint64_t
{
    STATETAGBEHAVIOR_ACTIVE_WHILE_CURRENT = 0x0,
    STATETAGBEHAVIOR_FIRE_ON_ENTER = 0x1,
    STATETAGBEHAVIOR_FIRE_ON_EXIT = 0x2,
    STATETAGBEHAVIOR_FIRE_ON_ENTER_AND_EXIT = 0x3,
};

#endif