#ifndef _ganimloopmode_t_h
#define _ganimloopmode_t_h

enum class AnimLoopMode_t : uint64_t
{
    ANIM_LOOP_MODE_INVALID = 0xffffffffffffffff,
    ANIM_LOOP_MODE_NOT_LOOPING = 0x0,
    ANIM_LOOP_MODE_LOOPING = 0x1,
    ANIM_LOOP_MODE_USE_SEQUENCE_SETTINGS = 0x2,
    ANIM_LOOP_MODE_COUNT = 0x3,
};

#endif