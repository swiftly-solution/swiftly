#ifndef _gtoggle_state_h
#define _gtoggle_state_h

enum class TOGGLE_STATE : uint64_t
{
    TS_AT_TOP = 0x0,
    TS_AT_BOTTOM = 0x1,
    TS_GOING_UP = 0x2,
    TS_GOING_DOWN = 0x3,
    DOOR_OPEN = 0x0,
    DOOR_CLOSED = 0x1,
    DOOR_OPENING = 0x2,
    DOOR_CLOSING = 0x3,
};

#endif