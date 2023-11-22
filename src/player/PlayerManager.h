#ifndef _playermanager_h
#define _playermanager_h

#include "../common.h"
#include "Player.h"
#include "../hooks/Hooks.h"

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

        hooks::emit(OnPlayerRegistered(player->GetSlot()));
    }

    inline void UnregisterPlayer(CPlayerSlot *slot)
    {
        hooks::emit(OnPlayerUnregistered(slot));

        int sl = slot->Get();

        delete this->g_Players[sl];
        this->g_Players[sl] = nullptr;
        if (playerCount > 0)
            --playerCount;
    }

    inline uint16 GetPlayers() { return playerCount; }
    inline Player *GetPlayer(uint16 slot) { return this->g_Players[slot]; }
    inline Player *GetPlayer(CPlayerSlot *slot) { return this->g_Players[slot->Get()]; }
    inline const uint16 GetPlayerCap() { return MAX_PLAYERS; }
    inline CPlayerSlot GetSlotFromUserId(uint16 userid) { return CPlayerSlot(userid & 0xFF); }

private:
    Player *g_Players[MAX_PLAYERS] = {};
    uint16 playerCount = 0;
};

extern PlayerManager *g_playerManager;

#endif