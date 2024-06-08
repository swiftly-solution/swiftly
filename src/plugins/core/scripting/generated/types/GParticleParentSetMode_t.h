#ifndef _gparticleparentsetmode_t_h
#define _gparticleparentsetmode_t_h

enum class ParticleParentSetMode_t : uint64_t
{
    PARTICLE_SET_PARENT_NO = 0x0,
    PARTICLE_SET_PARENT_IMMEDIATE = 0x1,
    PARTICLE_SET_PARENT_ROOT = 0x1,
};

#endif