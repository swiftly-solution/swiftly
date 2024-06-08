#ifndef _gparticlefloatmaptype_t_h
#define _gparticlefloatmaptype_t_h

enum class ParticleFloatMapType_t : uint64_t
{
    PF_MAP_TYPE_INVALID = 0xffffffffffffffff,
    PF_MAP_TYPE_DIRECT = 0x0,
    PF_MAP_TYPE_MULT = 0x1,
    PF_MAP_TYPE_REMAP = 0x2,
    PF_MAP_TYPE_REMAP_BIASED = 0x3,
    PF_MAP_TYPE_CURVE = 0x4,
    PF_MAP_TYPE_NOTCHED = 0x5,
    PF_MAP_TYPE_COUNT = 0x6,
};

#endif