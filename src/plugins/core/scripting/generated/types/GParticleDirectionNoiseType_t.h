#ifndef _gparticledirectionnoisetype_t_h
#define _gparticledirectionnoisetype_t_h

enum class ParticleDirectionNoiseType_t : uint64_t
{
    PARTICLE_DIR_NOISE_PERLIN = 0x0,
    PARTICLE_DIR_NOISE_CURL = 0x1,
    PARTICLE_DIR_NOISE_WORLEY_BASIC = 0x2,
};

#endif