#ifndef _gparticlelighttypechoicelist_t_h
#define _gparticlelighttypechoicelist_t_h

enum class ParticleLightTypeChoiceList_t : uint64_t
{
    PARTICLE_LIGHT_TYPE_POINT = 0x0,
    PARTICLE_LIGHT_TYPE_SPOT = 0x1,
    PARTICLE_LIGHT_TYPE_FX = 0x2,
    PARTICLE_LIGHT_TYPE_CAPSULE = 0x3,
};

#endif