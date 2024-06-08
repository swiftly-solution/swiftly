#ifndef _giksolvertype_h
#define _giksolvertype_h

enum class IKSolverType : uint64_t
{
    IKSOLVER_Perlin = 0x0,
    IKSOLVER_TwoBone = 0x1,
    IKSOLVER_Fabrik = 0x2,
    IKSOLVER_DogLeg3Bone = 0x3,
    IKSOLVER_CCD = 0x4,
    IKSOLVER_COUNT = 0x5,
};

#endif