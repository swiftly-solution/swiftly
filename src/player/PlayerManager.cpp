#include "PlayerManager.h"

PlayerManager::PlayerManager() {}
PlayerManager::~PlayerManager() {}

void PlayerManager::LoadPlayers()
{
    for (uint16_t i = 0; i < MAX_PLAYERS; i++)
    {
        Player *player = this->GetPlayer(i);
        if (!player)
            continue;

        if (player->IsAuthenticated() || player->IsFakeClient())
            continue;

        if (engine->IsClientFullyAuthenticated(i))
        {
            player->Authenticate();
        }
    }
}

void PlayerManager::RegisterPlayer(Player *player)
{
    this->g_Players[player->GetSlot().Get()] = player;
}

void PlayerManager::UnregisterPlayer(CPlayerSlot slot)
{
    int sl = slot.Get();

    delete this->g_Players[sl];
    this->g_Players[sl] = nullptr;
}

uint16_t PlayerManager::GetPlayers()
{
    uint16_t count = 0;
    for (uint16_t i = 0; i < MAX_PLAYERS; i++)
    {
        if (this->g_Players[i] == nullptr)
            continue;

        ++count;
    }
    return count;
}

Player *PlayerManager::FindPlayerBySteamID(uint64 steamid)
{
    if (steamid == 0)
        return nullptr;

    for (int i = 0; i < this->GetPlayerCap(); i++)
    {
        Player *player = this->GetPlayer(i);
        if (!player)
            continue;

        if (player->GetSteamID() == steamid)
            return player;
    }
    return nullptr;
}