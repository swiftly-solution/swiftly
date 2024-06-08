#ifndef _gchickenactivity_h
#define _gchickenactivity_h

enum class ChickenActivity : uint64_t
{
    IDLE = 0x0,
    SQUAT = 0x1,
    WALK = 0x2,
    RUN = 0x3,
    GLIDE = 0x4,
    LAND = 0x5,
    PANIC = 0x6,
};

#endif