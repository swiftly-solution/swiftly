#ifndef _gcfuncmover__move_t_h
#define _gcfuncmover__move_t_h

enum class CFuncMover__Move_t : uint64_t
{
    MOVE_LOOP = 0x0,
    MOVE_OSCILLATE = 0x1,
    MOVE_STOP_AT_END = 0x2,
};

#endif