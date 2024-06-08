#ifndef _gentitydisolvetype_t_h
#define _gentitydisolvetype_t_h

enum class EntityDisolveType_t : uint64_t
{
    ENTITY_DISSOLVE_INVALID = 0xffffffffffffffff,
    ENTITY_DISSOLVE_NORMAL = 0x0,
    ENTITY_DISSOLVE_ELECTRICAL = 0x1,
    ENTITY_DISSOLVE_ELECTRICAL_LIGHT = 0x2,
    ENTITY_DISSOLVE_CORE = 0x3,
};

#endif