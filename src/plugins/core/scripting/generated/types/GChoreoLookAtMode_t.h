#ifndef _gchoreolookatmode_t_h
#define _gchoreolookatmode_t_h

enum class ChoreoLookAtMode_t : uint64_t
{
    eInvalid = 0xffffffffffffffff,
    eChest = 0x0,
    eHead = 0x1,
    eEyesOnly = 0x2,
};

#endif