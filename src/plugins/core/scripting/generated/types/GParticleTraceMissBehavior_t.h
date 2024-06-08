#ifndef _gparticletracemissbehavior_t_h
#define _gparticletracemissbehavior_t_h

enum class ParticleTraceMissBehavior_t : uint64_t
{
    PARTICLE_TRACE_MISS_BEHAVIOR_NONE = 0x0,
    PARTICLE_TRACE_MISS_BEHAVIOR_KILL = 0x1,
    PARTICLE_TRACE_MISS_BEHAVIOR_TRACE_END = 0x2,
};

#endif