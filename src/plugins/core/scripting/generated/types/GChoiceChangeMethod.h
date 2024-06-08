#ifndef _gchoicechangemethod_h
#define _gchoicechangemethod_h

enum class ChoiceChangeMethod : uint64_t
{
    OnReset = 0x0,
    OnCycleEnd = 0x1,
    OnResetOrCycleEnd = 0x2,
};

#endif