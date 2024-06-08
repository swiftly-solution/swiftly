#ifndef _gparticlefloatbiastype_t_h
#define _gparticlefloatbiastype_t_h

enum class ParticleFloatBiasType_t : uint64_t
{
    PF_BIAS_TYPE_INVALID = 0xffffffffffffffff,
    PF_BIAS_TYPE_STANDARD = 0x0,
    PF_BIAS_TYPE_GAIN = 0x1,
    PF_BIAS_TYPE_EXPONENTIAL = 0x2,
    PF_BIAS_TYPE_COUNT = 0x3,
};

#endif