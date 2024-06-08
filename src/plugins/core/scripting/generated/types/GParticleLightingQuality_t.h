#ifndef _gparticlelightingquality_t_h
#define _gparticlelightingquality_t_h

enum class ParticleLightingQuality_t : uint64_t
{
    PARTICLE_LIGHTING_PER_PARTICLE = 0x0,
    PARTICLE_LIGHTING_PER_VERTEX = 0x1,
    PARTICLE_LIGHTING_PER_PIXEL = 0xffffffffffffffff,
};

#endif