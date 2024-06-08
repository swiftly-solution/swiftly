#ifndef _gfacingmode_h
#define _gfacingmode_h

enum class FacingMode : uint64_t
{
    FacingMode_Invalid = 0x0,
    FacingMode_Manual = 0x1,
    FacingMode_Path = 0x2,
    FacingMode_LookTarget = 0x3,
    FacingMode_ManualPosition = 0x4,
};

#endif