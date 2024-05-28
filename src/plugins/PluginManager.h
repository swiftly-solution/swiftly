#ifndef _plugins_PluginManager_h
#define _plugins_PluginManager_h

#include <vector>
#include <map>
#include <string>

#include "../files/Files.h"
#include "Plugin.h"
#include "lua/LuaPlugin.h"

class PluginManager
{
private:
    std::vector<Plugin *> pluginsList;
    std::map<std::string, Plugin *> pluginsMap;

public:
    PluginManager();
    ~PluginManager();

    bool PluginExists(std::string plugin_name);

    void LoadPlugins();
    void UnloadPlugins();

    void LoadPlugin(std::string plugin_name);
    void UnloadPlugin(std::string plugin_name);

    void StartPlugins();
    void StopPlugins();

    bool StartPlugin(std::string plugin_name);
    void StopPlugin(std::string plugin_name);

    Plugin *FetchPlugin(std::string name);
};

extern PluginManager *g_pluginManager;

#endif