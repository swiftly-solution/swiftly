#ifndef _gparticlecontrolpointaxis_t_h
#define _gparticlecontrolpointaxis_t_h

enum class ParticleControlPointAxis_t : uint64_t
{
    PARTICLE_CP_AXIS_X = 0x0,
    PARTICLE_CP_AXIS_Y = 0x1,
    PARTICLE_CP_AXIS_Z = 0x2,
    PARTICLE_CP_AXIS_NEGATIVE_X = 0x3,
    PARTICLE_CP_AXIS_NEGATIVE_Y = 0x4,
    PARTICLE_CP_AXIS_NEGATIVE_Z = 0x5,
};

#endif