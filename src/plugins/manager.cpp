#include "manager.h"

#include <utils/utils.h>
#include <filesystem/files/files.h>
#include <extensions/manager.h>
#include <server/menus/MenuManager.h>
#include <swiftly-ext/core.h>

bool alreadyStarted = false;

bool PluginsManager::PluginExists(std::string plugin_name)
{
    return (pluginsMap.find(plugin_name) != pluginsMap.end());
}

void PluginsManager::LoadPlugins(std::string directory)
{
    std::string baseDir = "addons/swiftly/plugins" + directory;
    if (!Files::ExistsPath(baseDir))
        Files::CreateDirectory(baseDir);

    std::vector<std::string> plugins = Files::FetchDirectories(baseDir);
    for (std::string folder : plugins)
    {
        // Skips over disabled
        if (folder.find("disabled") != std::string::npos)
            continue;

        auto directory_name = explode(folder, WIN_LINUX("\\", "/")).back();

        if (directory_name.find("[") != std::string::npos)
            LoadPlugins(directory + "/" + directory_name);
        else
        {
            folder = replace(folder, baseDir, "");
            std::string plugin_name = replace(folder, WIN_LINUX("\\", "/"), "");

            pluginBasePaths[plugin_name] = baseDir;

            LoadPlugin(plugin_name);
        }
    }
}

void PluginsManager::UnloadPlugins()
{
    std::vector<std::string> pluginNames;
    for (PluginObject* plugin : pluginsList)
        pluginNames.push_back(plugin->GetName());

    for (std::string plugin_name : pluginNames)
        UnloadPlugin(plugin_name);
}

void PluginsManager::LoadPlugin(std::string plugin_name)
{
    if (PluginExists(plugin_name))
        return;

    std::vector<std::string> files = Files::FetchFileNames(pluginBasePaths[plugin_name] + "/" + plugin_name);
    if (files.size() == 0)
        return;

    ContextKinds ct;

    for (std::string file : files)
    {
        if (ends_with(file, ".lua"))
        {
            ct = ContextKinds::Lua;
            break;
        }
        else if (ends_with(file, ".js"))
        {
            ct = ContextKinds::JavaScript;
            break;
        }
    }

    if ((int)ct == 0)
    {
        PRINTF("We couldn't determine a kind for the following plugin: %s\n", plugin_name.c_str());
        return;
    }

    pluginsList.push_back(new PluginObject(plugin_name, ct));
    pluginsMap.insert({ plugin_name, pluginsList.back() });
}

void PluginsManager::UnloadPlugin(std::string plugin_name)
{
    if (!PluginExists(plugin_name))
        return;

    auto plugin = pluginsMap.at(plugin_name);

    for (auto it = pluginsList.begin(); it != pluginsList.end(); ++it)
    {
        if ((*it)->GetName() == plugin_name)
            pluginsList.erase(it);
    }

    pluginsMap.erase(plugin_name);
}

void PluginsManager::StartPlugins()
{
    for (PluginObject* plugin : pluginsList)
        if (!StartPlugin(plugin->GetName()))
            StopPlugin(plugin->GetName(), true);

    ExecuteEvent("core", "OnAllPluginsLoaded", std::vector<std::any>{}, {});
    alreadyStarted = true;

    for (auto extension : extManager.GetExtensionsList())
        if (extension->IsLoaded())
            extension->GetAPI()->AllPluginsLoaded();
}

EventResult PluginsManager::ExecuteEvent(std::string invokedBy, std::string eventName, std::vector<std::any> eventPayload, ClassData* eventObject)
{
    for (std::size_t i = 0; i < pluginsList.size(); i++)
    {
        EventResult result = pluginsList[i]->TriggerEvent(invokedBy, eventName, eventPayload, eventObject);
        if (result != EventResult::Continue)
            return result;
    }

    return EventResult::Continue;
}

EventResult PluginsManager::ExecuteEventJSON(std::string invokedBy, std::string eventName, std::string eventPayload, ClassData* eventObject)
{
    for (std::size_t i = 0; i < pluginsList.size(); i++)
    {
        EventResult result = pluginsList[i]->TriggerEventJSON(invokedBy, eventName, eventPayload, eventObject);
        if (result != EventResult::Continue)
            return result;
    }

    return EventResult::Continue;
}

void PluginsManager::StopPlugins(bool destroyStates)
{
    for (PluginObject* plugin : pluginsList)
        StopPlugin(plugin->GetName(), destroyStates);
}

bool PluginsManager::StartPlugin(std::string plugin_name)
{
    if (!PluginExists(plugin_name))
        return false;

    PluginObject* plugin = pluginsMap.at(plugin_name);
    if (plugin->GetPluginState() == PluginState_t::Started)
        return true;

    if (!plugin->LoadScriptingEnvironment())
        return false;
    if (!plugin->ExecuteStart())
        return false;
    plugin->SetPluginState(PluginState_t::Started);

    if (alreadyStarted)
    {
        plugin->TriggerEvent("core", "OnAllPluginsLoaded", std::vector<std::any>{}, {});
    }

    return true;
}

void PluginsManager::StopPlugin(std::string plugin_name, bool destroyStates)
{
    if (!PluginExists(plugin_name))
        return;

    PluginObject* plugin = pluginsMap.at(plugin_name);
    if (plugin->GetPluginState() == PluginState_t::Stopped)
        return;

    if (!plugin->ExecuteStop())
        return;

    if (destroyStates)
    {
        plugin->DestroyScriptingEnvironment();
        plugin->SetPluginState(PluginState_t::Stopped);
    }
    g_MenuManager.UnregisterPluginMenus(plugin_name);
}

PluginObject* PluginsManager::FetchPlugin(std::string name)
{
    if (!PluginExists(name))
        return nullptr;

    return pluginsMap[name];
}

std::vector<PluginObject*> PluginsManager::GetPluginsList()
{
    return pluginsList;
}

std::string PluginsManager::GetPluginBasePath(std::string plugin_name)
{
    if (pluginBasePaths.find(plugin_name) == pluginBasePaths.end())
        return "addons/swiftly/plugins";
    return pluginBasePaths[plugin_name];
}

EXT_API int swiftly_TriggerEvent(const char* ext_name, const char* evName, void* args, void* eventReturn)
{
    ClassData data({ { "plugin_name", std::string(ext_name) } }, "Event", nullptr);
    auto result = g_pluginManager.ExecuteEvent(ext_name, evName, *(std::vector<std::any>*)args, &data);
    *reinterpret_cast<std::any*>(eventReturn) = data.GetAnyData("event_return");

    return (int)result;
}