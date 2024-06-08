#ifndef _gblendkeytype_h
#define _gblendkeytype_h

enum class BlendKeyType : uint64_t
{
    BlendKey_UserValue = 0x0,
    BlendKey_Velocity = 0x1,
    BlendKey_Distance = 0x2,
    BlendKey_RemainingDistance = 0x3,
};

#endif