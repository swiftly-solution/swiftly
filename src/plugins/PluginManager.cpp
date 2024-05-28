#include "PluginManager.h"

PluginManager::PluginManager() {}

PluginManager::~PluginManager() {}

bool PluginManager::PluginExists(std::string plugin_name)
{
    return (pluginsMap.find(plugin_name) != pluginsMap.end());
}

void PluginManager::LoadPlugins()
{
    if (!Files::ExistsPath("addons/swiftly/plugins"))
        Files::CreateDirectory("addons/swiftly/plugins");

    std::vector<std::string> plugins = Files::FetchDirectories("addons/swiftly/plugins");
    for (std::string folder : plugins)
    {
        // Skips over disabled
        if (folder.find("disabled") != std::string::npos)
            continue;

        folder = replace(folder, "addons/swiftly/plugins", "");
        std::string plugin_name = replace(folder, WIN_LINUX("\\", "/"), "");

        LoadPlugin(plugin_name);
    }
}

void PluginManager::UnloadPlugins()
{
    std::vector<std::string> pluginNames;
    for (Plugin *plugin : pluginsList)
        pluginNames.push_back(plugin->GetName());

    for (std::string plugin_name : pluginNames)
        UnloadPlugin(plugin_name);
}

void PluginManager::LoadPlugin(std::string plugin_name)
{
    if (PluginExists(plugin_name))
        return;

    std::vector<std::string> files = Files::FetchFileNames("addons/swiftly/plugins/" + plugin_name);
    if (files.size() == 0)
        return;

    Plugin *plugin = nullptr;

    for (std::string file : files)
    {
        if (ends_with(file, ".lua"))
        {
            plugin = new LuaPlugin(plugin_name, PluginKind_t::Lua);
            break;
        }
    }

    if (plugin == nullptr)
    {
        PRINTF("We couldn't determine a kind for the following plugin: %s\n", plugin_name.c_str());
        return;
    }

    pluginsList.push_back(plugin);
    pluginsMap.insert({plugin_name, plugin});
}

void PluginManager::UnloadPlugin(std::string plugin_name)
{
    if (!PluginExists(plugin_name))
        return;

    Plugin *plugin = pluginsMap.at(plugin_name);

    auto it = std::find(pluginsList.begin(), pluginsList.end(), plugin);
    if (it != pluginsList.end())
        pluginsList.erase(it);

    delete plugin;
    pluginsMap.erase(plugin_name);
}

void PluginManager::StartPlugins()
{
    for (Plugin *plugin : pluginsList)
        if (!StartPlugin(plugin->GetName()))
            StopPlugin(plugin->GetName());
}

void PluginManager::StopPlugins()
{
    for (Plugin *plugin : pluginsList)
        StopPlugin(plugin->GetName());
}

bool PluginManager::StartPlugin(std::string plugin_name)
{
    if (!PluginExists(plugin_name))
        return false;

    Plugin *plugin = pluginsMap.at(plugin_name);
    if (plugin->GetPluginState() == PluginState_t::Started)
        return true;

    plugin->SetPluginState(PluginState_t::Started);
    if (!plugin->LoadScriptingEnvironment())
        return false;
    if (!plugin->ExecuteStart())
        return false;

    return true;
}

void PluginManager::StopPlugin(std::string plugin_name)
{
    if (!PluginExists(plugin_name))
        return;

    Plugin *plugin = pluginsMap.at(plugin_name);
    if (plugin->GetPluginState() == PluginState_t::Stopped)
        return;

    plugin->SetPluginState(PluginState_t::Stopped);

    plugin->ExecuteStop();
    plugin->DestroyScriptingEnvironment();
}

Plugin *PluginManager::FetchPlugin(std::string name)
{
    if (!PluginExists(name))
        return nullptr;

    return pluginsMap.at(name);
}