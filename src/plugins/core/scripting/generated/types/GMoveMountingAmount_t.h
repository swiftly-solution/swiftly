#ifndef _gmovemountingamount_t_h
#define _gmovemountingamount_t_h

enum class MoveMountingAmount_t : uint64_t
{
    MOVE_MOUNT_NONE = 0x0,
    MOVE_MOUNT_LOW = 0x1,
    MOVE_MOUNT_HIGH = 0x2,
    MOVE_MOUNT_MAXCOUNT = 0x3,
};

#endif