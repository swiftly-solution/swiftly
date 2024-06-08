#ifndef _gparticlefallofffunction_t_h
#define _gparticlefallofffunction_t_h

enum class ParticleFalloffFunction_t : uint64_t
{
    PARTICLE_FALLOFF_CONSTANT = 0x0,
    PARTICLE_FALLOFF_LINEAR = 0x1,
    PARTICLE_FALLOFF_EXPONENTIAL = 0x2,
};

#endif