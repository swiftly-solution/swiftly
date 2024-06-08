#ifndef _gparticlerotationlocktype_t_h
#define _gparticlerotationlocktype_t_h

enum class ParticleRotationLockType_t : uint64_t
{
    PARTICLE_ROTATION_LOCK_NONE = 0x0,
    PARTICLE_ROTATION_LOCK_ROTATIONS = 0x1,
    PARTICLE_ROTATION_LOCK_NORMAL = 0x2,
};

#endif