#ifndef _gparticletexturelayerblendtype_t_h
#define _gparticletexturelayerblendtype_t_h

enum class ParticleTextureLayerBlendType_t : uint64_t
{
    SPRITECARD_TEXTURE_BLEND_MULTIPLY = 0x0,
    SPRITECARD_TEXTURE_BLEND_MOD2X = 0x1,
    SPRITECARD_TEXTURE_BLEND_REPLACE = 0x2,
    SPRITECARD_TEXTURE_BLEND_ADD = 0x3,
    SPRITECARD_TEXTURE_BLEND_SUBTRACT = 0x4,
    SPRITECARD_TEXTURE_BLEND_AVERAGE = 0x5,
    SPRITECARD_TEXTURE_BLEND_LUMINANCE = 0x6,
};

#endif