#include "../inc/PluginsComponent.h"
#include "../../../common.h"
#include "../../../files/Files.h"
#include "../inc/Plugin.h"

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
    std::vector<std::string> files = Files::FetchFileNames("addons/swiftly/plugins");
    for (const std::string &file : files)
    {
        if (!ends_with(file, WIN_LINUX(".dll", ".so")))
            continue;
        if (starts_with(file, WIN_LINUX("disabled\\", "disabled/")))
            continue;

        Plugin *plugin = new Plugin(file);

        plugins.push_back(plugin);
        pluginsMap.insert(std::make_pair(plugin->GetName(), plugin));

        plugin->LoadPlugin();
    }
}

void PluginsComponent::StartPlugins()
{
    for (uint32 i = 0; i < plugins.size(); i++)
        plugins[i]->StartPlugin();
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

    PRINTF("FetchPluginFromMap", "Plugin Name: %s\n", plugin_name.c_str());
    return pluginsMap.at(plugin_name);
}