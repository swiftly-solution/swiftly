#ifndef _gpfnoisemodifier_t_h
#define _gpfnoisemodifier_t_h

enum class PFNoiseModifier_t : uint64_t
{
    PF_NOISE_MODIFIER_NONE = 0x0,
    PF_NOISE_MODIFIER_LINES = 0x1,
    PF_NOISE_MODIFIER_CLUMPS = 0x2,
    PF_NOISE_MODIFIER_RINGS = 0x3,
};

#endif