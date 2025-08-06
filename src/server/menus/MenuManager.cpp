#include "MenuManager.h"

#include <server/player/manager.h>
#include <server/configuration/configuration.h>

std::map<std::string, bool> scheduledForDelete;

void MenuManager::RegisterMenu(std::string plugin_name, std::string id, std::string title, std::string color, std::vector<std::pair<std::string, std::string>> options, bool temporary, std::string kind)
{
    if (this->menu_ids.find(id) != this->menu_ids.end())
        return;
    if (options.size() <= 0)
        return;

    if (kind != "screen" && kind != "center") kind = g_Config.FetchValue<std::string>("core.menu.kind");

    Menu* menu = nullptr;
    // if (kind == "screen") {
        // menu = new ScreenMenu(id, title, color, options, temporary);
    // }
    // else if (kind == "center") {
    menu = new CenterMenu(id, title, color, options, temporary);
    // }
    if (!menu) return;

    this->menu_ids.insert(std::make_pair(id, menu));
    if (this->menu_id_by_plugin.find(plugin_name) == this->menu_id_by_plugin.end())
        this->menu_id_by_plugin.insert({ plugin_name, {} });

    this->menu_id_by_plugin[plugin_name].push_back(id);
}

void MenuManager::UnregisterMenu(std::string id)
{
    if (this->menu_ids.find(id) == this->menu_ids.end())
        return;
    if (scheduledForDelete.find(id) != scheduledForDelete.end())
        return;

    scheduledForDelete.insert({ id, true });
    for (uint16_t i = 0; i < g_playerManager.GetPlayerCap(); i++)
    {
        Player* player = g_playerManager.GetPlayer(i);
        if (!player)
            continue;
        if (player->IsFakeClient())
            continue;
        if (!player->menu_renderer->HasMenuShown())
            continue;

        if (player->menu_renderer->GetMenu()->GetID() == id)
            player->menu_renderer->HideMenu();
    }

    delete this->menu_ids[id];
    this->menu_ids.erase(id);
    scheduledForDelete.erase(id);
}

Menu* MenuManager::FetchMenu(std::string menu_id)
{
    if (this->menu_ids.find(menu_id) == this->menu_ids.end())
        return nullptr;

    return this->menu_ids[menu_id];
}

void MenuManager::UnregisterPluginMenus(std::string plugin_name)
{
    if (this->menu_id_by_plugin.find(plugin_name) == this->menu_id_by_plugin.end())
        return;

    for (std::string id : this->menu_id_by_plugin[plugin_name])
        this->UnregisterMenu(id);

    this->menu_id_by_plugin.erase(plugin_name);
}