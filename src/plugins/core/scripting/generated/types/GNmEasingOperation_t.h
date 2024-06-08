#ifndef _gnmeasingoperation_t_h
#define _gnmeasingoperation_t_h

enum class NmEasingOperation_t : uint64_t
{
    Linear = 0x0,
    InQuad = 0x1,
    OutQuad = 0x2,
    InOutQuad = 0x3,
    InCubic = 0x4,
    OutCubic = 0x5,
    InOutCubic = 0x6,
    InQuart = 0x7,
    OutQuart = 0x8,
    InOutQuart = 0x9,
    InQuint = 0xa,
    OutQuint = 0xb,
    InOutQuint = 0xc,
    InSine = 0xd,
    OutSine = 0xe,
    InOutSine = 0xf,
    InExpo = 0x10,
    OutExpo = 0x11,
    InOutExpo = 0x12,
    InCirc = 0x13,
    OutCirc = 0x14,
    InOutCirc = 0x15,
    None = 0x16,
};

#endif