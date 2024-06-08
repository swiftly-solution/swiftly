#ifndef _gparticledepthfeatheringmode_t_h
#define _gparticledepthfeatheringmode_t_h

enum class ParticleDepthFeatheringMode_t : uint64_t
{
    PARTICLE_DEPTH_FEATHERING_OFF = 0x0,
    PARTICLE_DEPTH_FEATHERING_ON_OPTIONAL = 0x1,
    PARTICLE_DEPTH_FEATHERING_ON_REQUIRED = 0x2,
};

#endif