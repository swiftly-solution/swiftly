#include "PlayerManager.h"
#include "../../memory/hooks/FuncHook.h"
#include "../../engine/convars/convars.h"

void Hook_CCSPlayer_MovementServices_CheckJumpPre(CCSPlayer_MovementServices* services, void* movementData);

FuncHook<decltype(Hook_CCSPlayer_MovementServices_CheckJumpPre)> TCCSPlayer_MovementServices_CheckJumpPre(Hook_CCSPlayer_MovementServices_CheckJumpPre, "CCSPlayer_MovementServices_CheckJumpPre");

PlayerManager::PlayerManager() {}
PlayerManager::~PlayerManager() {}

void PlayerManager::RegisterPlayer(Player* player)
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

ConVar* autobunnyhoppingcvar = nullptr;

void Hook_CCSPlayer_MovementServices_CheckJumpPre(CCSPlayer_MovementServices* services, void* movementData)
{
    if (autobunnyhoppingcvar == nullptr)
        autobunnyhoppingcvar = FetchCVar("sv_autobunnyhopping");

    bool& autobunnyhopping = *reinterpret_cast<bool*>(&autobunnyhoppingcvar->values);

    if (!autobunnyhopping)
    {
        Player* player = g_playerManager->GetPlayer(((CPlayer_MovementServices*)services)->m_pPawn->m_hController().GetEntryIndex() - 1);
        if (player)
        {
            if (player->bunnyhopState)
            {
                autobunnyhopping = true;

                TCCSPlayer_MovementServices_CheckJumpPre(services, movementData);

                autobunnyhopping = false;
                return;
            }
        }
    }

    TCCSPlayer_MovementServices_CheckJumpPre(services, movementData);
}