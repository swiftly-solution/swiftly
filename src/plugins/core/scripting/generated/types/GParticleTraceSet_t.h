#ifndef _gparticletraceset_t_h
#define _gparticletraceset_t_h

enum class ParticleTraceSet_t : uint64_t
{
    PARTICLE_TRACE_SET_ALL = 0x0,
    PARTICLE_TRACE_SET_STATIC = 0x1,
    PARTICLE_TRACE_SET_STATIC_AND_KEYFRAMED = 0x2,
    PARTICLE_TRACE_SET_DYNAMIC = 0x3,
};

#endif