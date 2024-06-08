#ifndef _gresetcycleoption_h
#define _gresetcycleoption_h

enum class ResetCycleOption : uint64_t
{
    Beginning = 0x0,
    SameCycleAsSource = 0x1,
    InverseSourceCycle = 0x2,
    FixedValue = 0x3,
    SameTimeAsSource = 0x4,
};

#endif