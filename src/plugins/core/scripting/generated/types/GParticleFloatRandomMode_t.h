#ifndef _gparticlefloatrandommode_t_h
#define _gparticlefloatrandommode_t_h

enum class ParticleFloatRandomMode_t : uint64_t
{
    PF_RANDOM_MODE_INVALID = 0xffffffffffffffff,
    PF_RANDOM_MODE_CONSTANT = 0x0,
    PF_RANDOM_MODE_VARYING = 0x1,
    PF_RANDOM_MODE_COUNT = 0x2,
};

#endif