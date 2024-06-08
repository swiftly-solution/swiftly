#ifndef _gparticleendcapmode_t_h
#define _gparticleendcapmode_t_h

enum class ParticleEndcapMode_t : uint64_t
{
    PARTICLE_ENDCAP_ALWAYS_ON = 0xffffffffffffffff,
    PARTICLE_ENDCAP_ENDCAP_OFF = 0x0,
    PARTICLE_ENDCAP_ENDCAP_ON = 0x1,
};

#endif