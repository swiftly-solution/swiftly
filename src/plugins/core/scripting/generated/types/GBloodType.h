#ifndef _gbloodtype_h
#define _gbloodtype_h

enum class BloodType : uint64_t
{
    None = 0xffffffffffffffff,
    ColorRed = 0x0,
    ColorYellow = 0x1,
    ColorGreen = 0x2,
    ColorRedLVL2 = 0x3,
    ColorRedLVL3 = 0x4,
    ColorRedLVL4 = 0x5,
    ColorRedLVL5 = 0x6,
    ColorRedLVL6 = 0x7,
};

#endif