#ifndef _gchoicemethod_h
#define _gchoicemethod_h

enum class ChoiceMethod : uint64_t
{
    WeightedRandom = 0x0,
    WeightedRandomNoRepeat = 0x1,
    Iterate = 0x2,
    IterateRandom = 0x3,
};

#endif