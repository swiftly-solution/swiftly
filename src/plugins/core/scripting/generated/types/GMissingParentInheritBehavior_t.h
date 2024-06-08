#ifndef _gmissingparentinheritbehavior_t_h
#define _gmissingparentinheritbehavior_t_h

enum class MissingParentInheritBehavior_t : uint64_t
{
    MISSING_PARENT_DO_NOTHING = 0xffffffffffffffff,
    MISSING_PARENT_KILL = 0x0,
    MISSING_PARENT_FIND_NEW = 0x1,
    MISSING_PARENT_SAME_INDEX = 0x2,
};

#endif