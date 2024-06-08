#ifndef _gstepphase_h
#define _gstepphase_h

enum class StepPhase : uint64_t
{
    StepPhase_OnGround = 0x0,
    StepPhase_InAir = 0x1,
};

#endif