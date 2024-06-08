#ifndef _gviewfademode_t_h
#define _gviewfademode_t_h

enum class ViewFadeMode_t : uint64_t
{
    VIEW_FADE_CONSTANT_COLOR = 0x0,
    VIEW_FADE_MODULATE = 0x1,
    VIEW_FADE_MOD2X = 0x2,
};

#endif