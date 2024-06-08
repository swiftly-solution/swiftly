#ifndef _gnmposeblendmode_t_h
#define _gnmposeblendmode_t_h

enum class NmPoseBlendMode_t : uint64_t
{
    Overlay = 0x0,
    Additive = 0x1,
    GlobalSpace = 0x2,
};

#endif