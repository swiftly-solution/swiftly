#ifndef _gparticlecolorblendmode_t_h
#define _gparticlecolorblendmode_t_h

enum class ParticleColorBlendMode_t : uint64_t
{
    PARTICLEBLEND_DEFAULT = 0x0,
    PARTICLEBLEND_OVERLAY = 0x1,
    PARTICLEBLEND_DARKEN = 0x2,
    PARTICLEBLEND_LIGHTEN = 0x3,
    PARTICLEBLEND_MULTIPLY = 0x4,
};

#endif