#ifndef _gclosestpointtesttype_t_h
#define _gclosestpointtesttype_t_h

enum class ClosestPointTestType_t : uint64_t
{
    PARTICLE_CLOSEST_TYPE_BOX = 0x0,
    PARTICLE_CLOSEST_TYPE_CAPSULE = 0x1,
    PARTICLE_CLOSEST_TYPE_HYBRID = 0x2,
};

#endif