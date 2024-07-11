#include "../scripting.h"

#include "../../../player/PlayerManager.h"

PluginPlayerManager::PluginPlayerManager(std::string m_plugin_name)
{
    this->plugin_name = m_plugin_name;
}

uint16_t PluginPlayerManager::GetPlayerCount()
{
    return g_playerManager->GetPlayers();
}

uint16_t PluginPlayerManager::GetPlayerCap()
{
    return g_playerManager->GetPlayerCap();
}

void PluginPlayerManager::SendMsg(int destination, std::string text)
{
    for (uint16_t i = 0; i < g_playerManager->GetPlayerCap(); i++)
    {
        Player *player = g_playerManager->GetPlayer(i);
        if (!player)
            continue;
        if (player->IsFakeClient())
            continue;
        if (!player->GetController())
            continue;

        player->SendMsg(destination, text.c_str());
    }
}