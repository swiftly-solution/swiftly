#ifndef _gmorphflexcontrollerremaptype_t_h
#define _gmorphflexcontrollerremaptype_t_h

enum class MorphFlexControllerRemapType_t : uint64_t
{
    MORPH_FLEXCONTROLLER_REMAP_PASSTHRU = 0x0,
    MORPH_FLEXCONTROLLER_REMAP_2WAY = 0x1,
    MORPH_FLEXCONTROLLER_REMAP_NWAY = 0x2,
    MORPH_FLEXCONTROLLER_REMAP_EYELID = 0x3,
};

#endif