#ifndef _playermanager_h
#define _playermanager_h

#include "../common.h"
#include "Player.h"

class PlayerManager
{
public:
    PlayerManager()
    {
    }

    ~PlayerManager()
    {
    }

    void LoadPlayers();
    void SetupHooks();

    inline void RegisterPlayer(Player *player)
    {
        if (playerCount < MAX_PLAYERS)
            ++playerCount;

        this->g_Players[player->GetSlot()->Get()] = player;
    }

    inline void UnregisterPlayer(CPlayerSlot *slot)
    {
        this->g_Players[slot->Get()] = nullptr;
        if (playerCount > 0)
            --playerCount;
    }

    inline uint16 GetPlayers() { return playerCount; }
    inline Player *GetPlayer(uint16 slot) { return this->g_Players[slot]; };
    inline Player *GetPlayer(CPlayerSlot *slot) { return this->g_Players[slot->Get()]; };
    inline const uint16 GetPlayerCap() { return MAX_PLAYERS; };

private:
    Player *g_Players[MAX_PLAYERS] = {};
    uint16 playerCount = 0;
};

extern PlayerManager *g_playerManager;

#endif