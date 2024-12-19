#include "PlayerManager.h"
#include "../../memory/hooks/FuncHook.h"
#include "../../memory/encoders/msgpack.h"
#include "../../engine/convars/convars.h"
#include "../../plugins/PluginManager.h"
#include "../../plugins/core/scripting.h"

void Hook_CCSPlayerPawnBase_PostThink(CCSPlayerPawnBase* _this);

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

void Hook_CCSPlayerPawnBase_PostThink(CCSPlayerPawnBase* _this)
{
    if(!_this) return TCCSPlayerPawnBase_PostThink(_this);
    
    auto originalController = _this->m_hOriginalController();
    if(!originalController) return TCCSPlayerPawnBase_PostThink(_this);

    auto playerid = originalController.GetEntryIndex() - 1;
    
    if(!dummyEvent) dummyEvent = new PluginEvent("core", nullptr, nullptr);
    
    if(g_pluginManager->ExecuteEvent("core", "OnPlayerPostThink", encoders::msgpack::SerializeToString({ playerid }), dummyEvent) == EventResult::Stop)
        return;

    return TCCSPlayerPawnBase_PostThink(_this);
}