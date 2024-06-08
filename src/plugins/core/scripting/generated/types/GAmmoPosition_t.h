#ifndef _gammoposition_t_h
#define _gammoposition_t_h

enum class AmmoPosition_t : uint64_t
{
    AMMO_POSITION_INVALID = 0xffffffffffffffff,
    AMMO_POSITION_PRIMARY = 0x0,
    AMMO_POSITION_SECONDARY = 0x1,
    AMMO_POSITION_COUNT = 0x2,
};

#endif