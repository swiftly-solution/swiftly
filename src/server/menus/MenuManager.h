#pragma once

#include <string>
#include <map>
#include <vector>

#include "Menu.h"

class MenuManager
{
private:
    std::map<std::string, Menu *> menu_ids;
    std::map<std::string, std::vector<std::string>> menu_id_by_plugin;

public:
    MenuManager();
    void RegisterMenu(std::string plugin_name, std::string id, std::string title, std::string color, std::vector<std::pair<std::string, std::string>> options, bool temporary);
    void UnregisterMenu(std::string id);

    Menu *FetchMenu(std::string menu_id);
    void UnregisterPluginMenus(std::string plugin_name);
};

extern MenuManager *g_MenuManager;