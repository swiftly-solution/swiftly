#ifndef _ganimationtype_t_h
#define _ganimationtype_t_h

enum class AnimationType_t : uint64_t
{
    ANIMATION_TYPE_FIXED_RATE = 0x0,
    ANIMATION_TYPE_FIT_LIFETIME = 0x1,
    ANIMATION_TYPE_MANUAL_FRAMES = 0x2,
};

#endif