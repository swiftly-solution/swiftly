#ifndef _gnmfootphasecondition_t_h
#define _gnmfootphasecondition_t_h

enum class NmFootPhaseCondition_t : uint64_t
{
    LeftFootDown = 0x0,
    LeftFootPassing = 0x1,
    LeftPhase = 0x4,
    RightFootDown = 0x2,
    RightFootPassing = 0x3,
    RightPhase = 0x5,
};

#endif