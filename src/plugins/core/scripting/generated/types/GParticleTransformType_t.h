#ifndef _gparticletransformtype_t_h
#define _gparticletransformtype_t_h

enum class ParticleTransformType_t : uint64_t
{
    PT_TYPE_INVALID = 0x0,
    PT_TYPE_NAMED_VALUE = 0x1,
    PT_TYPE_CONTROL_POINT = 0x2,
    PT_TYPE_CONTROL_POINT_RANGE = 0x3,
    PT_TYPE_COUNT = 0x4,
};

#endif