#ifndef _gdoorstate_t_h
#define _gdoorstate_t_h

enum class DoorState_t : uint64_t
{
    DOOR_STATE_CLOSED = 0x0,
    DOOR_STATE_OPENING = 0x1,
    DOOR_STATE_OPEN = 0x2,
    DOOR_STATE_CLOSING = 0x3,
    DOOR_STATE_AJAR = 0x4,
};

#endif