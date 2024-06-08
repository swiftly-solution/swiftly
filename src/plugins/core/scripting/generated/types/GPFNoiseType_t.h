#ifndef _gpfnoisetype_t_h
#define _gpfnoisetype_t_h

enum class PFNoiseType_t : uint64_t
{
    PF_NOISE_TYPE_PERLIN = 0x0,
    PF_NOISE_TYPE_SIMPLEX = 0x1,
    PF_NOISE_TYPE_WORLEY = 0x2,
    PF_NOISE_TYPE_CURL = 0x3,
};

#endif