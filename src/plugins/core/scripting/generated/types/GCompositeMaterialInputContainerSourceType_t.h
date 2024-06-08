#ifndef _gcompositematerialinputcontainersourcetype_t_h
#define _gcompositematerialinputcontainersourcetype_t_h

enum class CompositeMaterialInputContainerSourceType_t : uint64_t
{
    CONTAINER_SOURCE_TYPE_TARGET_MATERIAL = 0x0,
    CONTAINER_SOURCE_TYPE_MATERIAL_FROM_TARGET_ATTR = 0x1,
    CONTAINER_SOURCE_TYPE_SPECIFIC_MATERIAL = 0x2,
    CONTAINER_SOURCE_TYPE_LOOSE_VARIABLES = 0x3,
    CONTAINER_SOURCE_TYPE_VARIABLE_FROM_TARGET_ATTR = 0x4,
    CONTAINER_SOURCE_TYPE_TARGET_INSTANCE_MATERIAL = 0x5,
};

#endif