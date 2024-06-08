#ifndef _gweaponswitchreason_t_h
#define _gweaponswitchreason_t_h

enum class WeaponSwitchReason_t : uint64_t
{
    eDrawn = 0x0,
    eEquipped = 0x1,
    eUserInitiatedSwitchToLast = 0x2,
    eUserInitiatedSwitchHands = 0x3,
};

#endif