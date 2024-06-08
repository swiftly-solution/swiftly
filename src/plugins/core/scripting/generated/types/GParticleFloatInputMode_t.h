#ifndef _gparticlefloatinputmode_t_h
#define _gparticlefloatinputmode_t_h

enum class ParticleFloatInputMode_t : uint64_t
{
    PF_INPUT_MODE_INVALID = 0xffffffffffffffff,
    PF_INPUT_MODE_CLAMPED = 0x0,
    PF_INPUT_MODE_LOOPED = 0x1,
    PF_INPUT_MODE_COUNT = 0x2,
};

#endif