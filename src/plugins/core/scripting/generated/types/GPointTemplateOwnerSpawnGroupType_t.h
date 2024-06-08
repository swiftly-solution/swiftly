#ifndef _gpointtemplateownerspawngrouptype_t_h
#define _gpointtemplateownerspawngrouptype_t_h

enum class PointTemplateOwnerSpawnGroupType_t : uint64_t
{
    INSERT_INTO_POINT_TEMPLATE_SPAWN_GROUP = 0x0,
    INSERT_INTO_CURRENTLY_ACTIVE_SPAWN_GROUP = 0x1,
    INSERT_INTO_NEWLY_CREATED_SPAWN_GROUP = 0x2,
};

#endif