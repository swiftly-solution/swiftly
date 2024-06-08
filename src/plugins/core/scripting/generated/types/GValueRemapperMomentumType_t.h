#ifndef _gvalueremappermomentumtype_t_h
#define _gvalueremappermomentumtype_t_h

enum class ValueRemapperMomentumType_t : uint64_t
{
    MomentumType_None = 0x0,
    MomentumType_Friction = 0x1,
    MomentumType_SpringTowardSnapValue = 0x2,
    MomentumType_SpringAwayFromSnapValue = 0x3,
};

#endif