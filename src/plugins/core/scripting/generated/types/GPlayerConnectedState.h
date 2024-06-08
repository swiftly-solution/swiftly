#ifndef _gplayerconnectedstate_h
#define _gplayerconnectedstate_h

enum class PlayerConnectedState : uint64_t
{
    PlayerNeverConnected = 0xffffffffffffffff,
    PlayerConnected = 0x0,
    PlayerConnecting = 0x1,
    PlayerReconnecting = 0x2,
    PlayerDisconnecting = 0x3,
    PlayerDisconnected = 0x4,
    PlayerReserved = 0x5,
};

#endif