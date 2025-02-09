#include "PluginManager.h"

#include "core/scripting.h"
#include "../server/menus/MenuManager.h"
#include "../extensions/ExtensionManager.h"
#include "../memory/encoders/msgpack.h"
#include <swiftly-ext/core.h>

#include <vector>

bool AllPluginsStarted = false;

PluginManager::PluginManager() {}

PluginManager::~PluginManager() {}

bool PluginManager::PluginExists(std::string plugin_name)
{
    return (pluginsMap.find(plugin_name) != pluginsMap.end());
}

void PluginManager::LoadPlugins(std::string directory)
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

void PluginManager::UnloadPlugins()
{
    std::vector<std::string> pluginNames;
    for (Plugin* plugin : pluginsList)
        pluginNames.push_back(plugin->GetName());

    for (std::string plugin_name : pluginNames)
        UnloadPlugin(plugin_name);
}

void PluginManager::LoadPlugin(std::string plugin_name)
{
    if (PluginExists(plugin_name))
        return;

    std::vector<std::string> files = Files::FetchFileNames(pluginBasePaths[plugin_name] + "/" + plugin_name);
    if (files.size() == 0)
        return;

    Plugin* plugin = nullptr;

    for (std::string file : files)
    {
        if (ends_with(file, ".lua"))
        {
            plugin = new Plugin(plugin_name, PluginKind_t::Lua);
            break;
        } 
        else if (ends_with(file, ".js"))
        {
            plugin = new Plugin(plugin_name, PluginKind_t::JavaScript);
            break;
        }
    }

    if (plugin == nullptr)
    {
        PRINTF("We couldn't determine a kind for the following plugin: %s\n", plugin_name.c_str());
        return;
    }

    pluginsList.push_back(plugin);
    pluginsMap.insert({ plugin_name, plugin });
}

void PluginManager::UnloadPlugin(std::string plugin_name)
{
    if (!PluginExists(plugin_name))
        return;

    Plugin* plugin = pluginsMap.at(plugin_name);

    auto it = std::find(pluginsList.begin(), pluginsList.end(), plugin);
    if (it != pluginsList.end())
        pluginsList.erase(it);

    delete plugin;
    pluginsMap.erase(plugin_name);
}

void PluginManager::StartPlugins()
{
    for (Plugin* plugin : pluginsList)
        if (!StartPlugin(plugin->GetName()))
            StopPlugin(plugin->GetName(), true);

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    this->ExecuteEvent("core", "OnAllPluginsLoaded", encoders::msgpack::SerializeToString({}), event);
    delete event;
    AllPluginsStarted = true;

    for(auto extension : extManager->GetExtensionsList())
        if(extension->IsLoaded())
            extension->GetAPI()->AllPluginsLoaded();
}

void PluginManager::StopPlugins(bool destroyStates)
{
    for (Plugin* plugin : pluginsList)
        StopPlugin(plugin->GetName(), destroyStates);
}

bool PluginManager::StartPlugin(std::string plugin_name)
{
    if (!PluginExists(plugin_name))
        return false;

    Plugin* plugin = pluginsMap.at(plugin_name);
    if (plugin->GetPluginState() == PluginState_t::Started)
        return true;

    if (!plugin->LoadScriptingEnvironment())
        return false;
    if (!plugin->ExecuteStart())
        return false;
    plugin->SetPluginState(PluginState_t::Started);

    if (AllPluginsStarted)
    {
        PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
        plugin->TriggerEvent("core", "OnAllPluginsLoaded", encoders::msgpack::SerializeToString({}), event);
        delete event;
    }

    return true;
}

void PluginManager::StopPlugin(std::string plugin_name, bool destroyStates)
{
    if (!PluginExists(plugin_name))
        return;

    Plugin* plugin = pluginsMap.at(plugin_name);
    if (plugin->GetPluginState() == PluginState_t::Stopped)
        return;

    if (!plugin->ExecuteStop())
        return;

    if (destroyStates) {
        plugin->DestroyScriptingEnvironment();
        plugin->SetPluginState(PluginState_t::Stopped);
    }
    g_MenuManager->UnregisterPluginMenus(plugin_name);
}

Plugin* PluginManager::FetchPlugin(std::string name)
{
    if (!PluginExists(name))
        return nullptr;

    return pluginsMap[name];
}

EventResult PluginManager::ExecuteEvent(std::string invokedBy, std::string eventName, std::string eventPayload, PluginEvent* event)
{
    for (std::size_t i = 0; i < this->pluginsList.size(); i++)
    {
        EventResult result = this->pluginsList[i]->TriggerEvent(invokedBy, eventName, eventPayload, event);
        if (result != EventResult::Continue)
            return result;
    }

    return EventResult::Continue;
}

std::vector<Plugin*> PluginManager::GetPluginsList()
{
    return this->pluginsList;
}

std::string PluginManager::GetPluginBasePath(std::string plugin_name)
{
    if (this->pluginBasePaths.find(plugin_name) == this->pluginBasePaths.end()) return "addons/swiftly/plugins";
    return this->pluginBasePaths[plugin_name];
}

EXT_API int swiftly_TriggerEvent(const char* ext_name, const char* evName, void* args, void* eventReturn)
{
    PluginEvent* ev = new PluginEvent(ext_name, nullptr, nullptr);
    auto result = g_pluginManager->ExecuteEvent(ext_name, evName, encoders::msgpack::SerializeToString(*(std::vector<std::any>*)args), ev);
    delete ev;

    *reinterpret_cast<std::any*>(eventReturn) = ev->GetReturnValue();
    return (int)result;
}