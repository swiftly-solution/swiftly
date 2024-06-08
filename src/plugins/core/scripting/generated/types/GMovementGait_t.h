#ifndef _gmovementgait_t_h
#define _gmovementgait_t_h

enum class MovementGait_t : uint64_t
{
    eInvalid = 0xffffffffffffffff,
    eSlow = 0x0,
    eMedium = 0x1,
    eFast = 0x2,
    eVeryFast = 0x3,
    eCount = 0x4,
};

#endif