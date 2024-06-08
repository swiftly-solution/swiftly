#ifndef _gparticlecollisionmode_t_h
#define _gparticlecollisionmode_t_h

enum class ParticleCollisionMode_t : uint64_t
{
    COLLISION_MODE_PER_PARTICLE_TRACE = 0x3,
    COLLISION_MODE_USE_NEAREST_TRACE = 0x2,
    COLLISION_MODE_PER_FRAME_PLANESET = 0x1,
    COLLISION_MODE_INITIAL_TRACE_DOWN = 0x0,
    COLLISION_MODE_DISABLED = 0xffffffffffffffff,
};

#endif