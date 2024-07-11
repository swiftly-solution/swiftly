#include "MenuManager.h"

#include "../player/PlayerManager.h"

MenuManager::MenuManager()
{
}

void MenuManager::RegisterMenu(std::string plugin_name, std::string id, std::string title, std::string color, std::vector<std::pair<std::string, std::string>> options, bool temporary)
{
    if (this->menu_ids.find(id) != this->menu_ids.end())
        return;

    Menu *menu = new Menu(id, title, color, options, temporary);
    this->menu_ids.insert(std::make_pair(id, menu));
    if (this->menu_id_by_plugin.find(plugin_name) == this->menu_id_by_plugin.end())
        this->menu_id_by_plugin.insert({plugin_name, {}});

    this->menu_id_by_plugin[plugin_name].push_back(id);
}

void MenuManager::UnregisterMenu(std::string id)
{
    if (this->menu_ids.find(id) == this->menu_ids.end())
        return;

    for (uint16_t i = 0; i < g_playerManager->GetPlayerCap(); i++)
    {
        Player *player = g_playerManager->GetPlayer(i);
        if (!player)
            continue;
        if (player->IsFakeClient())
            continue;
        if (!player->HasMenuShown())
            continue;

        if (player->GetMenu()->GetID() == id)
            player->HideMenu();
    }

    Menu *menu = this->menu_ids.at(id);
    delete menu;
    this->menu_ids.erase(id);
}

Menu *MenuManager::FetchMenu(std::string menu_id)
{
    if (this->menu_ids.find(menu_id) == this->menu_ids.end())
        return nullptr;

    return this->menu_ids.at(menu_id);
}

void MenuManager::UnregisterPluginMenus(std::string plugin_name)
{
    if (this->menu_id_by_plugin.find(plugin_name) == this->menu_id_by_plugin.end())
        return;

    for (std::string id : this->menu_id_by_plugin[plugin_name])
        this->UnregisterMenu(id);

    this->menu_id_by_plugin.erase(plugin_name);
}