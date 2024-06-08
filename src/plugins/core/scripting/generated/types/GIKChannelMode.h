#ifndef _gikchannelmode_h
#define _gikchannelmode_h

enum class IKChannelMode : uint64_t
{
    TwoBone = 0x0,
    TwoBone_Translate = 0x1,
    OneBone = 0x2,
    OneBone_Translate = 0x3,
};

#endif