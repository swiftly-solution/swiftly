#ifndef _gcanplaysequence_t_h
#define _gcanplaysequence_t_h

enum class CanPlaySequence_t : uint64_t
{
    CANNOT_PLAY = 0x0,
    CAN_PLAY_NOW = 0x1,
    CAN_PLAY_ENQUEUED = 0x2,
};

#endif