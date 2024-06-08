#ifndef _ghierarchytype_t_h
#define _ghierarchytype_t_h

enum class HierarchyType_t : uint64_t
{
    HIERARCHY_NONE = 0x0,
    HIERARCHY_BONE_MERGE = 0x1,
    HIERARCHY_ATTACHMENT = 0x2,
    HIERARCHY_ABSORIGIN = 0x3,
    HIERARCHY_BONE = 0x4,
    HIERARCHY_TYPE_COUNT = 0x5,
};

#endif