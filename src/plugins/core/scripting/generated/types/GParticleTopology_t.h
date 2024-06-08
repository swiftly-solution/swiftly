#ifndef _gparticletopology_t_h
#define _gparticletopology_t_h

enum class ParticleTopology_t : uint64_t
{
    PARTICLE_TOPOLOGY_POINTS = 0x0,
    PARTICLE_TOPOLOGY_LINES = 0x1,
    PARTICLE_TOPOLOGY_TRIS = 0x2,
    PARTICLE_TOPOLOGY_QUADS = 0x3,
    PARTICLE_TOPOLOGY_CUBES = 0x4,
};

#endif