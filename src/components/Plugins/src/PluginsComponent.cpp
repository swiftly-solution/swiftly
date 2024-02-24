#include "../inc/PluginsComponent.h"
#include "../../../common.h"
#include "../../../files/Files.h"
#include "../inc/plugins/CPPPlugin.h"
#include "../inc/plugins/LuaPlugin.h"

std::map<std::string, Plugin *> pluginsMap;

bool ends_with(std::string value, std::string ending)
{
    if (value.size() < ending.size())
        return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

bool starts_with(std::string value, std::string starting)
{
    if (value.size() < starting.size())
        return false;
    return std::equal(starting.begin(), starting.end(), value.begin());
}

void PluginsComponent::LoadComponent()
{
    std::vector<std::string> directories = Files::FetchDirectories("addons/swiftly/plugins");
    for (std::string directory : directories)
    {
        if (directory.find("disabled") != std::string::npos)
            continue;

        directory = replace(directory, "addons/swiftly/plugins", "");
        directory = replace(directory, WIN_LINUX("\\", "/"), "");

        this->LoadPlugin("addons/swiftly/plugins", directory);
    }
}

void PluginsComponent::LoadPlugin(std::string init_path, std::string dir)
{
    Plugin *plugin = nullptr;

    std::vector<std::string> files = Files::FetchFileNames("addons/swiftly/plugins/" + dir);

    for (const std::string &file : files)
    {
        if (ends_with(file, WIN_LINUX(".dll", ".so")))
        {
            plugin = new CPPPlugin(file, dir, PluginType_t::PLUGIN_CPP);
            break;
        }
        else if (ends_with(file, ".lua"))
        {
            plugin = new LuaPlugin(std::string(std::filesystem::current_path().string() + "/addons/swiftly/plugins/" + dir), dir, PluginType_t::PLUGIN_LUA);
            break;
        }
    }

    if (plugin)
    {
        plugins.push_back(plugin);
        pluginsMap.insert(std::make_pair(plugin->GetName(), plugin));
        plugin->LoadPlugin();
    }
}

template <typename... Args>
void ExecuteGameEventWithNoReturn(Plugin *plugin, std::string game_event_name, Args &&...args);

void PluginsComponent::StartPlugins()
{
    for (uint32 i = 0; i < plugins.size(); i++)
        plugins[i]->StartPlugin();

    g_Plugin.m_allpluginsloaded = true;

    for (uint32 i = 0; i < plugins.size(); i++)
        ExecuteGameEventWithNoReturn(plugins[i], "AllPluginsLoaded");
}

std::map<std::string, Plugin *> FetchPluginsMap()
{
    return pluginsMap;
}

void AddPluginInMap(Plugin *plugin)
{
    plugins.push_back(plugin);
    pluginsMap.insert(std::make_pair(plugin->GetName(), plugin));
}

bool ExistsPluginInMap(std::string plugin_name)
{
    return (pluginsMap.find(plugin_name) != pluginsMap.end());
}

Plugin *FetchPluginFromMap(std::string plugin_name)
{
    if (!ExistsPluginInMap(plugin_name))
        return nullptr;

    return pluginsMap.at(plugin_name);
}