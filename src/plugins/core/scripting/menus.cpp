#include "../scripting.h"

#include "../../../menus/MenuManager.h"

PluginMenus::PluginMenus(std::string m_plugin_name)
{
    this->plugin_name = m_plugin_name;
}

void PluginMenus::Register(std::string custom_id, std::string title, std::string color, std::vector<std::pair<std::string, std::string>> options)
{
    g_MenuManager->RegisterMenu(this->plugin_name, custom_id, title, color, options, false);
}

void PluginMenus::RegisterTemporary(std::string custom_id, std::string title, std::string color, std::vector<std::pair<std::string, std::string>> options)
{
    g_MenuManager->RegisterMenu(this->plugin_name, custom_id, title, color, options, true);
}

void PluginMenus::Unregister(std::string id)
{
    g_MenuManager->UnregisterMenu(id);
}