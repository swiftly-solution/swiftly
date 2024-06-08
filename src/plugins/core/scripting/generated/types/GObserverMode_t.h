#ifndef _gobservermode_t_h
#define _gobservermode_t_h

enum class ObserverMode_t : uint64_t
{
    OBS_MODE_NONE = 0x0,
    OBS_MODE_FIXED = 0x1,
    OBS_MODE_IN_EYE = 0x2,
    OBS_MODE_CHASE = 0x3,
    OBS_MODE_ROAMING = 0x4,
    OBS_MODE_DIRECTED = 0x5,
    NUM_OBSERVER_MODES = 0x6,
};

#endif