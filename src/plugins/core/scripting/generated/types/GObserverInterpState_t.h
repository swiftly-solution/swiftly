#ifndef _gobserverinterpstate_t_h
#define _gobserverinterpstate_t_h

enum class ObserverInterpState_t : uint64_t
{
    OBSERVER_INTERP_NONE = 0x0,
    OBSERVER_INTERP_TRAVELING = 0x1,
    OBSERVER_INTERP_SETTLING = 0x2,
};

#endif