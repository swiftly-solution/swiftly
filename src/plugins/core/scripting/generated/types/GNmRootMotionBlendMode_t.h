#ifndef _gnmrootmotionblendmode_t_h
#define _gnmrootmotionblendmode_t_h

enum class NmRootMotionBlendMode_t : uint64_t
{
    Blend = 0x0,
    Additive = 0x1,
    IgnoreSource = 0x2,
    IgnoreTarget = 0x3,
};

#endif