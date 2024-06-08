#ifndef _gforcedcrouchstate_t_h
#define _gforcedcrouchstate_t_h

enum class ForcedCrouchState_t : uint64_t
{
    FORCEDCROUCH_NONE = 0x0,
    FORCEDCROUCH_CROUCHED = 0x1,
    FORCEDCROUCH_UNCROUCHED = 0x2,
};

#endif