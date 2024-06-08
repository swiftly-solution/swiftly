#ifndef _gnmfootphase_t_h
#define _gnmfootphase_t_h

enum class NmFootPhase_t : uint64_t
{
    LeftFootDown = 0x0,
    RightFootPassing = 0x1,
    RightFootDown = 0x2,
    LeftFootPassing = 0x3,
};

#endif