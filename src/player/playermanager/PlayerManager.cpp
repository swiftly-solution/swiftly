#include "PlayerManager.h"
#include "../../memory/hooks/FuncHook.h"
#include "../../memory/encoders/msgpack.h"
#include "../../engine/convars/convars.h"
#include "../../plugins/PluginManager.h"
#include "../../plugins/core/scripting.h"

void Hook_CCSPlayer_MovementServices_CheckJumpPre(CCSPlayer_MovementServices* services, void* movementData);
void Hook_CCSPlayerPawnBase_PostThink(CCSPlayerPawnBase* _this);

FuncHook<decltype(Hook_CCSPlayer_MovementServices_CheckJumpPre)> TCCSPlayer_MovementServices_CheckJumpPre(Hook_CCSPlayer_MovementServices_CheckJumpPre, "CCSPlayer_MovementServices_CheckJumpPre");
FuncHook<decltype(Hook_CCSPlayerPawnBase_PostThink)> TCCSPlayerPawnBase_PostThink(Hook_CCSPlayerPawnBase_PostThink, "CCSPlayerPawnBase_PostThink");

PluginEvent* dummyEvent = nullptr;

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

void Hook_CCSPlayerPawnBase_PostThink(CCSPlayerPawnBase* _this)
{
    auto playerid = _this->m_hOriginalController()->entindex() - 1;
    
    if(!dummyEvent) dummyEvent = new PluginEvent("core", nullptr, nullptr);
    
    if(g_pluginManager->ExecuteEvent("core", "OnPlayerPostThink", encoders::msgpack::SerializeToString({ playerid }), dummyEvent) == EventResult::Stop)
        return;

    return TCCSPlayerPawnBase_PostThink(_this);
}