#ifndef _server_menus_manager_h
#define _server_menus_manager_h

#include <string>
#include <map>
#include <vector>

#include "kinds/ScreenMenu.h"
#include "kinds/CenterMenu.h"

class MenuManager
{
private:
    std::map<std::string, Menu*> menu_ids;
    std::map<std::string, std::vector<std::string>> menu_id_by_plugin;

public:
    void RegisterMenu(std::string plugin_name, std::string id, std::string title, std::string color, std::vector<std::pair<std::string, std::string>> options, bool temporary, std::string kind);
    void UnregisterMenu(std::string id);

    Menu* FetchMenu(std::string menu_id);
    void UnregisterPluginMenus(std::string plugin_name);
};

extern MenuManager g_MenuManager;

#endif