#ifndef _ginputlayoutvariation_t_h
#define _ginputlayoutvariation_t_h

enum class InputLayoutVariation_t : uint64_t
{
    INPUT_LAYOUT_VARIATION_DEFAULT = 0x0,
    INPUT_LAYOUT_VARIATION_STREAM1_INSTANCEID = 0x1,
    INPUT_LAYOUT_VARIATION_STREAM1_INSTANCEID_MORPH_VERT_ID = 0x2,
    INPUT_LAYOUT_VARIATION_MAX = 0x3,
};

#endif