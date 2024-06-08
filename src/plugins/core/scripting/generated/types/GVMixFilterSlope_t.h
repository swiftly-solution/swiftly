#ifndef _gvmixfilterslope_t_h
#define _gvmixfilterslope_t_h

enum class VMixFilterSlope_t : uint64_t
{
    FILTER_SLOPE_1POLE_6dB = 0x0,
    FILTER_SLOPE_1POLE_12dB = 0x1,
    FILTER_SLOPE_1POLE_18dB = 0x2,
    FILTER_SLOPE_1POLE_24dB = 0x3,
    FILTER_SLOPE_12dB = 0x4,
    FILTER_SLOPE_24dB = 0x5,
    FILTER_SLOPE_36dB = 0x6,
    FILTER_SLOPE_48dB = 0x7,
    FILTER_SLOPE_MAX = 0x7,
};

#endif