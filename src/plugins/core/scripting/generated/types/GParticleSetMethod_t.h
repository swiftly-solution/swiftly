#ifndef _gparticlesetmethod_t_h
#define _gparticlesetmethod_t_h

enum class ParticleSetMethod_t : uint64_t
{
    PARTICLE_SET_REPLACE_VALUE = 0x0,
    PARTICLE_SET_SCALE_INITIAL_VALUE = 0x1,
    PARTICLE_SET_ADD_TO_INITIAL_VALUE = 0x2,
    PARTICLE_SET_RAMP_CURRENT_VALUE = 0x3,
    PARTICLE_SET_SCALE_CURRENT_VALUE = 0x4,
    PARTICLE_SET_ADD_TO_CURRENT_VALUE = 0x5,
};

#endif