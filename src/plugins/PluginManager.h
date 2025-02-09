#ifndef _plugins_PluginManager_h
#define _plugins_PluginManager_h

#include <vector>
#include <map>
#include <string>

#include "../filesystem/files/Files.h"
#include "Plugin.h"
#include "../types/EventResult.h"

class PluginEvent;

class PluginManager
{
private:
    std::vector<Plugin*> pluginsList;
    std::map<std::string, Plugin*> pluginsMap;
    std::map<std::string, std::string> pluginBasePaths;

public:
    PluginManager();
    ~PluginManager();

    std::string GetPluginBasePath(std::string plugin_name);

    bool PluginExists(std::string plugin_name);

    void LoadPlugins(std::string directory);
    void UnloadPlugins();

    void LoadPlugin(std::string plugin_name);
    void UnloadPlugin(std::string plugin_name);

    void StartPlugins();
    void StopPlugins(bool destroyStates);

    bool StartPlugin(std::string plugin_name);
    void StopPlugin(std::string plugin_name, bool destroyStates);

    Plugin* FetchPlugin(std::string name);

    std::vector<Plugin*> GetPluginsList();

    EventResult ExecuteEvent(std::string invokedBy, std::string eventName, std::string eventPayload, PluginEvent* event);
};

extern PluginManager* g_pluginManager;

#endif