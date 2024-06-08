#ifndef _gplaybackmode_t_h
#define _gplaybackmode_t_h

enum class PlayBackMode_t : uint64_t
{
    Random = 0x0,
    RandomNoRepeats = 0x1,
    RandomAvoidLast = 0x2,
    Sequential = 0x3,
};

#endif