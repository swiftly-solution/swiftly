#ifndef _gaimmatrixblendmode_h
#define _gaimmatrixblendmode_h

enum class AimMatrixBlendMode : uint64_t
{
    AimMatrixBlendMode_None = 0x0,
    AimMatrixBlendMode_Additive = 0x1,
    AimMatrixBlendMode_ModelSpaceAdditive = 0x2,
    AimMatrixBlendMode_BoneMask = 0x3,
};

#endif