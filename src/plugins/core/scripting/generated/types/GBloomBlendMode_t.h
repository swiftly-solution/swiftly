#ifndef _gbloomblendmode_t_h
#define _gbloomblendmode_t_h

enum class BloomBlendMode_t : uint64_t
{
    BLOOM_BLEND_ADD = 0x0,
    BLOOM_BLEND_SCREEN = 0x1,
    BLOOM_BLEND_BLUR = 0x2,
};

#endif