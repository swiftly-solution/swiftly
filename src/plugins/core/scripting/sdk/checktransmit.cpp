#include "../../scripting.h"

#include "../../../../player/PlayerManager.h"

PluginCCheckTransmitInfo::PluginCCheckTransmitInfo(std::string ptr)
{
    this->m_ptr = (CCheckTransmitInfo*)(strtol(ptr.c_str(), nullptr, 16));
}

std::map<int, int> PluginCCheckTransmitInfo::GetPlayers()
{
    std::map<int, int> player_entindex;

    for(uint16_t i = 0; i < g_playerManager->GetPlayerCap(); i++) {
        Player* player = g_playerManager->GetPlayer(i);
        if(!player) continue;
        CCSPlayerPawn* playerPawn = player->GetPlayerPawn();
        if(!playerPawn) continue;

        player_entindex.insert({ i, playerPawn->entindex() });
    }

    return player_entindex;
}

std::vector<int> PluginCCheckTransmitInfo::GetEntities()
{
    std::vector<int> entities_list;

    for(int i = 0; i < MAX_EDICTS; i++)
        if(this->m_ptr->m_pTransmitEntity->IsBitSet(i))
            entities_list.push_back(i);

    return entities_list;
}

void PluginCCheckTransmitInfo::SetEntities(std::vector<int> tbl)
{
    this->m_ptr->m_pTransmitEntity->ClearAll();
    for(int i = 0; i < tbl.size(); i++)
        this->m_ptr->m_pTransmitEntity->Set(tbl[i]);
}