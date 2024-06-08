#ifndef _gstancetype_t_h
#define _gstancetype_t_h

enum class StanceType_t : uint64_t
{
    STANCE_CURRENT = 0xffffffffffffffff,
    STANCE_DEFAULT = 0x0,
    STANCE_CROUCHING = 0x1,
    STANCE_PRONE = 0x2,
    NUM_STANCES = 0x3,
};

#endif