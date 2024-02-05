#ifndef _swiftly_menus_h
#define _swiftly_menus_h

#include <string>
#include <vector>
#include <map>

#include "Menu.h"
#include "../player/PlayerManager.h"

class GameMenus
{
private:
    std::map<std::string, Menu *> menu_ids;
    std::map<std::string, std::string> menu_id_by_plugin;

public:
    GameMenus() {}

    void RegisterMenu(std::string plugin_name, std::string id, std::string title, std::string color, std::unordered_map<std::string, std::string> options)
    {
        if (this->menu_ids.find(id) != this->menu_ids.end())
            return;

        Menu *menu = new Menu(id, title, color, options);
        this->menu_ids.insert(std::make_pair(id, menu));
        this->menu_id_by_plugin.insert(std::make_pair(plugin_name, id));
    }

    void UnregisterMenu(std::string plugin_name, std::string id)
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

    void UnregisterPluginMenus(std::string plugin_name)
    {
        for (std::map<std::string, std::string>::iterator it = this->menu_id_by_plugin.begin(); it != this->menu_id_by_plugin.end(); ++it)
            this->UnregisterMenu(it->first, it->second);

        this->menu_id_by_plugin.erase(plugin_name);
    }

    Menu *FetchMenu(std::string menu_id)
    {
        if (this->menu_ids.find(menu_id) == this->menu_ids.end())
            return nullptr;

        return this->menu_ids.at(menu_id);
    }
};

extern GameMenus *g_menus;

#endif