#ifndef _gmorphbundletype_t_h
#define _gmorphbundletype_t_h

enum class MorphBundleType_t : uint64_t
{
    MORPH_BUNDLE_TYPE_NONE = 0x0,
    MORPH_BUNDLE_TYPE_POSITION_SPEED = 0x1,
    MORPH_BUNDLE_TYPE_NORMAL_WRINKLE = 0x2,
    MORPH_BUNDLE_TYPE_COUNT = 0x3,
};

#endif