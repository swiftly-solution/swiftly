#ifndef _plugins_manager_h
#define _plugins_manager_h

#include "object.h"

#include <vector>
#include <string>
#include <map>
#include <optional>
#include <any>

#include <types/EventResult.h>

bool LoadManifestSchema();

class PluginsManager
{
private:
    std::vector<PluginObject*> pluginsList;
    std::map<std::string, PluginObject*> pluginsMap;
    std::map<std::string, std::string> pluginBasePaths;
public:
    std::string GetPluginBasePath(std::string plugin_name);

    bool PluginExists(std::string plugin_name);

    void LoadPlugins(std::string directory);
    void UnloadPlugins();

    void LoadPlugin(std::string plugin_name);
    void UnloadPlugin(std::string plugin_name);

    void ReloadManifests();
    bool ReloadManifest(std::string plugin_name);

    void StartPlugins();
    void StopPlugins(bool destroyStates);

    bool StartPlugin(std::string plugin_name);
    void StopPlugin(std::string plugin_name, bool destroyStates);

    PluginObject* FetchPlugin(std::string name);

    std::vector<PluginObject*> GetPluginsList();

    EventResult ExecuteEvent(std::string invokedBy, std::string eventName, std::vector<std::any> eventPayload, ClassData* eventObject);
    EventResult ExecuteEventJSON(std::string invokedBy, std::string eventName, std::string eventPayload, ClassData* eventObject);
};

extern PluginsManager g_pluginManager;

#endif