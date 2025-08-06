#include "manager.h"

#include <utils/utils.h>
#include <filesystem/files/files.h>
#include <extensions/manager.h>
#include <server/menus/MenuManager.h>
#include <swiftly-ext/core.h>
#include <sdk/game.h>
#include <regex>

#ifdef GetObject
#undef GetObject
#endif
#include <memory/encoders/json.h>

bool alreadyStarted = false;
bool schemaLoaded = false;
rapidjson::Document schemaDocument;

bool LoadManifestSchema() {
    if (!Files::ExistsPath("addons/swiftly/gamedata/manifest.json")) return false;

    schemaDocument = encoders::json::FromString(Files::Read("addons/swiftly/gamedata/manifest.json"), "addons/swiftly/gamedata/manifest.json");
    if (!schemaDocument.IsObject()) return false;

    return schemaDocument.MemberCount() > 0;
}

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

    for (int i = 0; i < pluginNames.size(); i++) {
        UnloadPlugin(pluginNames[i]);
    }
}

void PluginsManager::ReloadManifests()
{
    for (PluginObject* plugin : pluginsList) {
        ReloadManifest(plugin->GetName());
    }
}

std::vector<int> ParseSemver(std::string ver)
{
    std::vector<int> res;
    static std::regex re(R"(^(\d+)\.(\d+)\.(\d+)(?:-([0-9A-Za-z\.-]+))?)");
    std::smatch match;

    if (std::regex_match(ver, match, re)) {
        res.push_back(std::stoi(match[1].str()));
        res.push_back(std::stoi(match[2].str()));
        res.push_back(std::stoi(match[3].str()));
    }
    else {
        res.push_back(0);
        res.push_back(0);
        res.push_back(0);
    }

    return res;
}

bool PluginsManager::ReloadManifest(std::string plugin_name)
{
    if (Files::ExistsPath(pluginBasePaths[plugin_name] + "/" + plugin_name + "/manifest.json")) {
        auto manifestContent = Files::Read(pluginBasePaths[plugin_name] + "/" + plugin_name + "/manifest.json");
        auto json = encoders::json::FromString(manifestContent, pluginBasePaths[plugin_name] + "/" + plugin_name + "/manifest.json");

        rapidjson::SchemaDocument schema(schemaDocument);
        rapidjson::SchemaValidator validator(schema);

        if (!json.Accept(validator)) {
            rapidjson::StringBuffer sb;
            validator.GetInvalidSchemaPointer().StringifyUriFragment(sb);
            PRINTF("An error has occured while trying to validate the plugin manifest for '%s'.\nInvalid schema: %s\nInvalid keyword: %s\n", plugin_name.c_str(), sb.GetString(), validator.GetInvalidSchemaKeyword());
            validator.GetInvalidDocumentPointer();
            PRINTF("Invalid document: %s\n", sb.GetString());

            return false;
        }

        auto deps = json["dependencies"].GetObject();
        auto& depsRTArray = deps["runtime"];
        std::vector<std::string> runtime;
        for (int i = 0; i < depsRTArray.Size(); i++) {
            if (depsRTArray[i].IsString()) {
                runtime.push_back(std::string(depsRTArray[i].GetString()));
            }
        }

        for (int i = 0; i < runtime.size(); i++) {
            if (!starts_with(runtime[i], "/")) {
                PRINTF("Invalid runtime dependency flag '%s' in plugin '%s', skipping.\n", runtime[i].c_str(), plugin_name.c_str());
                continue;
            }
            auto value = explode(runtime[i], ":");
            if (value.size() != 2) {
                PRINTF("Invalid runtime dependency flag '%s' in plugin '%s', skipping.\n", runtime[i].c_str(), plugin_name.c_str());
                continue;
            }

            auto flg = value[0];
            auto val = value[1];

            if (flg == "/version") {
                auto minimVersion = ParseSemver(val);
                auto serverVersion = ParseSemver(g_Plugin.GetVersion());

                if (serverVersion[0] == 0) serverVersion = minimVersion;
                if (minimVersion[0] > serverVersion[0] || minimVersion[1] > serverVersion[1] || minimVersion[2] > serverVersion[2]) {
                    PRINTF("Minimum server version for plugin '%s' is '%s', you're currently running '%s'.\n", plugin_name.c_str(), val.c_str(), g_Plugin.GetVersion());
                    return false;
                }
            }
        }
    }

    return true;
}

void PluginsManager::LoadPlugin(std::string plugin_name)
{
    if (PluginExists(plugin_name))
        return;

    ContextKinds ct;
    bool hasManifest = Files::ExistsPath(pluginBasePaths[plugin_name] + "/" + plugin_name + "/manifest.json");
    bool isValidManifest = false;
    rapidjson::Document manifestDoc;

    if (hasManifest) {
        isValidManifest = ReloadManifest(plugin_name);
        if (isValidManifest) {
            manifestDoc = encoders::json::FromString(Files::Read(pluginBasePaths[plugin_name] + "/" + plugin_name + "/manifest.json"), pluginBasePaths[plugin_name] + "/" + plugin_name + "/manifest.json");
            std::string pluginKind = manifestDoc["kind"].GetString();
            if (pluginKind == "lua") {
                ct = ContextKinds::Lua;
            }
            else if (pluginKind == "cs") {
                ct = ContextKinds::Dotnet;
            }

            std::set<std::string> forgames;
            for (auto& v : manifestDoc["games"].GetArray()) {
                if (v.IsString()) {
                    forgames.insert(std::string(v.GetString()));
                }
            }

            if (forgames.size() > 0 && forgames.find(GetGameName()) == forgames.end()) {
                PRINTF("The plugin '%s' doesn't support '%s'.\n", plugin_name.c_str(), GetGameName().c_str());
                return;
            }
        }
    }
    else {
        std::vector<std::string> files = Files::FetchFileNames(pluginBasePaths[plugin_name] + "/" + plugin_name);
        if (files.size() == 0)
            return;

        for (std::string file : files)
        {
            if (ends_with(file, ".lua"))
            {
                ct = ContextKinds::Lua;
                break;
            }
        }

    }

    if ((int)ct == 0)
    {
        PRINTF("We couldn't determine a kind for the following plugin: %s\n", plugin_name.c_str());
        return;
    }

    pluginsList.push_back(new PluginObject(plugin_name, ct, hasManifest, isValidManifest, pluginBasePaths[plugin_name] + "/" + plugin_name + "/manifest.json"));
    pluginsMap.insert({ plugin_name, pluginsList.back() });
}

void PluginsManager::UnloadPlugin(std::string plugin_name)
{
    if (!PluginExists(plugin_name))
        return;

    auto plugin = pluginsMap.at(plugin_name);

    for (auto it = pluginsList.begin(); it != pluginsList.end(); ++it)
    {
        if ((*it)->GetName() == plugin_name) {
            delete (*it);
            pluginsList.erase(it);
            break;
        }
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
    ClassData* data = new ClassData({ { "plugin_name", std::string(ext_name) } }, "Event", nullptr);
    auto result = g_pluginManager.ExecuteEvent(ext_name, evName, *(std::vector<std::any>*)args, data);
    *reinterpret_cast<std::any*>(eventReturn) = data->GetAnyData("event_return");
    delete data;
    return (int)result;
}

EXT_API int swiftly_TriggerEventV2(const char* ext_name, const char* evName, void* args, void* eventReturn, const char* specific_plugin)
{
    ClassData* data = new ClassData({ { "plugin_name", std::string(ext_name) } }, "Event", nullptr);
    std::string plugin = specific_plugin;
    EventResult result = EventResult::Continue;
    if (plugin != "") {
        auto plg = g_pluginManager.FetchPlugin(plugin);
        if (plg) result = plg->TriggerEvent(ext_name, evName, *(std::vector<std::any>*)args, data);
    }
    else {
        result = g_pluginManager.ExecuteEvent(ext_name, evName, *(std::vector<std::any>*)args, data);
    }
    *reinterpret_cast<std::any*>(eventReturn) = data->GetAnyData("event_return");
    delete data;
    return (int)result;
}