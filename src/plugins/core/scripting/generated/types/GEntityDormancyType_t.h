#ifndef _gentitydormancytype_t_h
#define _gentitydormancytype_t_h

enum class EntityDormancyType_t : uint64_t
{
    ENTITY_NOT_DORMANT = 0x0,
    ENTITY_DORMANT = 0x1,
    ENTITY_SUSPENDED = 0x2,
};

#endif