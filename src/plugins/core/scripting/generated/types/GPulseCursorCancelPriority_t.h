#ifndef _gpulsecursorcancelpriority_t_h
#define _gpulsecursorcancelpriority_t_h

enum class PulseCursorCancelPriority_t : uint64_t
{
    None = 0x0,
    CancelOnSucceeded = 0x1,
    SoftCancel = 0x2,
    HardCancel = 0x3,
};

#endif