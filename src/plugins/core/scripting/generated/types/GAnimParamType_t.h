#ifndef _ganimparamtype_t_h
#define _ganimparamtype_t_h

enum class AnimParamType_t : uint64_t
{
    ANIMPARAM_UNKNOWN = 0x0,
    ANIMPARAM_BOOL = 0x1,
    ANIMPARAM_ENUM = 0x2,
    ANIMPARAM_INT = 0x3,
    ANIMPARAM_FLOAT = 0x4,
    ANIMPARAM_VECTOR = 0x5,
    ANIMPARAM_QUATERNION = 0x6,
    ANIMPARAM_GLOBALSYMBOL = 0x7,
    ANIMPARAM_COUNT = 0x8,
};

#endif