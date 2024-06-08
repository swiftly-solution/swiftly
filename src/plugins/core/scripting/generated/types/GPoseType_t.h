#ifndef _gposetype_t_h
#define _gposetype_t_h

enum class PoseType_t : uint64_t
{
    POSETYPE_STATIC = 0x0,
    POSETYPE_DYNAMIC = 0x1,
    POSETYPE_INVALID = 0xff,
};

#endif