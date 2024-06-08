#ifndef _gpropdoorrotatingspawnpos_t_h
#define _gpropdoorrotatingspawnpos_t_h

enum class PropDoorRotatingSpawnPos_t : uint64_t
{
    DOOR_SPAWN_CLOSED = 0x0,
    DOOR_SPAWN_OPEN_FORWARD = 0x1,
    DOOR_SPAWN_OPEN_BACK = 0x2,
    DOOR_SPAWN_AJAR = 0x3,
};

#endif