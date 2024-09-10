#ifndef _player_playermanager_h
#define _player_playermanager_h

#include "../common.h"
#include "../entrypoint.h"
#include "Player.h"

#include <public/playerslot.h>

class PlayerManager
{
public:
    PlayerManager();
    ~PlayerManager();

    void RegisterPlayer(Player *player);
    void UnregisterPlayer(CPlayerSlot slot);
    uint16_t GetPlayers();
    Player *GetPlayer(uint16 slot)
    {
        if(slot < 0 || slot > MAX_PLAYERS) return nullptr;

        return this->g_Players[slot];
    }
    Player *GetPlayer(CPlayerSlot slot) { return this->g_Players[slot.Get()]; }
    const uint16 GetPlayerCap() { return MAX_PLAYERS; }

private:
    Player *g_Players[MAX_PLAYERS] = {};
};

extern PlayerManager *g_playerManager;

#endif