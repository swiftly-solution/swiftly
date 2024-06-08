#ifndef _gparticleimpulsetype_t_h
#define _gparticleimpulsetype_t_h

enum class ParticleImpulseType_t : uint64_t
{
    IMPULSE_TYPE_NONE = 0x0,
    IMPULSE_TYPE_GENERIC = 0x1,
    IMPULSE_TYPE_ROPE = 0x2,
    IMPULSE_TYPE_EXPLOSION = 0x4,
    IMPULSE_TYPE_EXPLOSION_UNDERWATER = 0x8,
    IMPULSE_TYPE_PARTICLE_SYSTEM = 0x10,
};

#endif