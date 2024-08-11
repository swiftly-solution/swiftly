#include "../scripting.h"

#include "../../../player/PlayerManager.h"

PluginPlayerManager::PluginPlayerManager(std::string m_plugin_name)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginPlayerManager::PluginPlayerManager(m_plugin_name=\"%s\")", m_plugin_name.c_str()));

    this->plugin_name = m_plugin_name;
}

uint16_t PluginPlayerManager::GetPlayerCount()
{
    REGISTER_CALLSTACK(this->plugin_name, "PluginPlayerManager::GetPlayerCount()");

    return g_playerManager->GetPlayers();
}

uint16_t PluginPlayerManager::GetPlayerCap()
{
    REGISTER_CALLSTACK(this->plugin_name, "PluginPlayerManager::GetPlayerCap()");

    return g_playerManager->GetPlayerCap();
}

void PluginPlayerManager::SendMsg(int destination, std::string text)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginPlayerManager::SendMsg(destination=%d)", destination));

    for (uint16_t i = 0; i < g_playerManager->GetPlayerCap(); i++)
    {
        Player* player = g_playerManager->GetPlayer(i);
        if (!player)
            continue;
        if (player->IsFakeClient())
            continue;
        if (!player->GetController())
            continue;

        player->SendMsg(destination, text.c_str());
    }
}