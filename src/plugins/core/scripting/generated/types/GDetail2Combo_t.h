#ifndef _gdetail2combo_t_h
#define _gdetail2combo_t_h

enum class Detail2Combo_t : uint64_t
{
    DETAIL_2_COMBO_UNINITIALIZED = 0xffffffffffffffff,
    DETAIL_2_COMBO_OFF = 0x0,
    DETAIL_2_COMBO_ADD = 0x1,
    DETAIL_2_COMBO_ADD_SELF_ILLUM = 0x2,
    DETAIL_2_COMBO_MOD2X = 0x3,
    DETAIL_2_COMBO_MUL = 0x4,
    DETAIL_2_COMBO_CROSSFADE = 0x5,
};

#endif