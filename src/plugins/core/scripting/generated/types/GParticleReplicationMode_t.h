#ifndef _gparticlereplicationmode_t_h
#define _gparticlereplicationmode_t_h

enum class ParticleReplicationMode_t : uint64_t
{
    PARTICLE_REPLICATIONMODE_NONE = 0x0,
    PARTICLE_REPLICATIONMODE_REPLICATE_FOR_EACH_PARENT_PARTICLE = 0x1,
};

#endif