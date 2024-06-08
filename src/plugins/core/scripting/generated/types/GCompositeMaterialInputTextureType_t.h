#ifndef _gcompositematerialinputtexturetype_t_h
#define _gcompositematerialinputtexturetype_t_h

enum class CompositeMaterialInputTextureType_t : uint64_t
{
    INPUT_TEXTURE_TYPE_DEFAULT = 0x0,
    INPUT_TEXTURE_TYPE_NORMALMAP = 0x1,
    INPUT_TEXTURE_TYPE_COLOR = 0x2,
    INPUT_TEXTURE_TYPE_MASKS = 0x3,
    INPUT_TEXTURE_TYPE_ROUGHNESS = 0x4,
    INPUT_TEXTURE_TYPE_PEARLESCENCE_MASK = 0x5,
    INPUT_TEXTURE_TYPE_AO = 0x6,
};

#endif