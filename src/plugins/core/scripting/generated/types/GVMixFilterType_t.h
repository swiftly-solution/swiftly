#ifndef _gvmixfiltertype_t_h
#define _gvmixfiltertype_t_h

enum class VMixFilterType_t : uint64_t
{
    FILTER_UNKNOWN = 0xffffffffffffffff,
    FILTER_LOWPASS = 0x0,
    FILTER_HIGHPASS = 0x1,
    FILTER_BANDPASS = 0x2,
    FILTER_NOTCH = 0x3,
    FILTER_PEAKING_EQ = 0x4,
    FILTER_LOW_SHELF = 0x5,
    FILTER_HIGH_SHELF = 0x6,
    FILTER_ALLPASS = 0x7,
    FILTER_PASSTHROUGH = 0x8,
};

#endif