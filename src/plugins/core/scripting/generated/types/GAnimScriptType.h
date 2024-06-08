#ifndef _ganimscripttype_h
#define _ganimscripttype_h

enum class AnimScriptType : uint64_t
{
    ANIMSCRIPT_TYPE_INVALID = 0xffffffffffffffff,
    ANIMSCRIPT_FUSE_GENERAL = 0x0,
    ANIMSCRIPT_FUSE_STATEMACHINE = 0x1,
};

#endif