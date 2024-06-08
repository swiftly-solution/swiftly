#ifndef _gparticleorientationsetmode_t_h
#define _gparticleorientationsetmode_t_h

enum class ParticleOrientationSetMode_t : uint64_t
{
    PARTICLE_ORIENTATION_SET_FROM_VELOCITY = 0x0,
    PARTICLE_ORIENTATION_SET_FROM_ROTATIONS = 0x1,
};

#endif