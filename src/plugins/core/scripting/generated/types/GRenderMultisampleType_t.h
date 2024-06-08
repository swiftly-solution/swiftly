#ifndef _grendermultisampletype_t_h
#define _grendermultisampletype_t_h

enum class RenderMultisampleType_t : uint64_t
{
    RENDER_MULTISAMPLE_INVALID = 0xffffffffffffffff,
    RENDER_MULTISAMPLE_NONE = 0x0,
    RENDER_MULTISAMPLE_2X = 0x1,
    RENDER_MULTISAMPLE_4X = 0x2,
    RENDER_MULTISAMPLE_6X = 0x3,
    RENDER_MULTISAMPLE_8X = 0x4,
    RENDER_MULTISAMPLE_16X = 0x5,
    RENDER_MULTISAMPLE_TYPE_COUNT = 0x6,
};

#endif