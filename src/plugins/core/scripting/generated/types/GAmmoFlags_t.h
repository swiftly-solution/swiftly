#ifndef _gammoflags_t_h
#define _gammoflags_t_h

enum class AmmoFlags_t : uint64_t
{
    AMMO_FORCE_DROP_IF_CARRIED = 0x1,
    AMMO_RESERVE_STAYS_WITH_WEAPON = 0x2,
    AMMO_FLAG_MAX = 0x2,
};

#endif