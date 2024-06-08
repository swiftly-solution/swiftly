#ifndef _grenderslottype_t_h
#define _grenderslottype_t_h

enum class RenderSlotType_t : uint64_t
{
    RENDER_SLOT_INVALID = 0xffffffffffffffff,
    RENDER_SLOT_PER_VERTEX = 0x0,
    RENDER_SLOT_PER_INSTANCE = 0x1,
};

#endif