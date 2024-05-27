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

    void LoadPlayers();
    void RegisterPlayer(Player *player);
    void UnregisterPlayer(CPlayerSlot slot);
    uint16_t GetPlayers();
    Player *GetPlayer(uint16 slot) { return this->g_Players[slot]; }
    Player *GetPlayer(CPlayerSlot slot) { return this->g_Players[slot.Get()]; }
    const uint16 GetPlayerCap() { return MAX_PLAYERS; }
    CPlayerSlot GetSlotFromUserId(uint16 userid) { return CPlayerSlot(userid & 0xFF); }
    Player *FindPlayerBySteamID(uint64 steamid);

private:
    Player *g_Players[MAX_PLAYERS] = {};
};

extern PlayerManager *g_playerManager;

#endif