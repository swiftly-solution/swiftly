#ifndef _gentitysubclassscope_t_h
#define _gentitysubclassscope_t_h

enum class EntitySubclassScope_t : uint64_t
{
    SUBCLASS_SCOPE_NONE = 0xffffffffffffffff,
    SUBCLASS_SCOPE_PRECIPITATION = 0x0,
    SUBCLASS_SCOPE_PLAYER_WEAPONS = 0x1,
    SUBCLASS_SCOPE_COUNT = 0x2,
};

#endif