#ifndef _components_plugins_inc_plugin_h
#define _components_plugins_inc_plugin_h

#include "../../../common.h"
#include <map>
#include <vector>
#include <metamod_oslink.h>
#include <filesystem>

#ifndef _WIN32
#include <dlfcn.h>
#endif

const std::string funcsToLoad[] = {
    "RegisterPlayer",
    "UnregisterPlayer",
    "OnProgramLoad",
    "OnPluginStart",
    "OnPluginStop",
    "OnClientConnect",
    "OnClientDisconnect",
    "OnPlayerSpawn",
    "OnGameTick",
    "OnPlayerChat",
    "OnRoundStart",
    "OnRoundPrestart",
    "OnRoundEnd",
    "BombBeginPlant",
    "BombAbortPlant",
    "BombPlanted",
    "BombBeginDefuse",
    "BombAbortDefuse",
    "BombDefused",
    "BombExploded",
    "BombDropped",
    "BombPickup",
    "OnMapLoad",
    "OnMapUnload",
};

class Plugin
{
private:
    std::string m_path;
    std::map<std::string, void *> functions;
    HINSTANCE m_hModule;
    std::string m_pluginName;
    bool isPluginLoaded = false;

    void RegisterFunction(std::string function)
    {
        if (this->functions.find(function) != this->functions.end())
            return;

        void *func = reinterpret_cast<void *>(dlsym(this->m_hModule, function.c_str()));
        if (func == nullptr)
            return;

        this->functions.insert(std::make_pair(function, func));
    }

public:
    Plugin(std::string path) : m_path(path)
    {
        std::vector<std::string> exploded = explode(path, WIN_LINUX("\\", "/"));
        this->m_pluginName = explode(exploded[exploded.size() - 1], ".")[0];
    }
    ~Plugin()
    {
        this->m_path.clear();
        dlclose(this->m_hModule);
    }

    void LoadPlugin()
    {
#ifdef _WIN32
        this->m_hModule = dlmount(this->m_path.c_str());
#else
        this->m_hModule = dlopen(string_format("%s/%s", std::filesystem::current_path().string().c_str(), this->m_path.c_str()).c_str(), RTLD_NOW);

        if (!this->m_hModule)
        {
            PRINTF("LoadPlugin", "Failed to load module: %s\n", std::string(dlerror()).c_str());
            return;
        }
#endif
        for (uint16 i = 0; i < ARR_SIZE(funcsToLoad); i++)
            this->RegisterFunction("Internal_" + funcsToLoad[i]);

        this->RegisterFunction("GetPluginAuthor");
        this->RegisterFunction("GetPluginVersion");
        this->RegisterFunction("GetPluginName");
        this->RegisterFunction("GetPluginWebsite");
    }

    void StartPlugin();
    void StopPlugin();
    inline void SetPluginLoaded(bool loaded) { this->isPluginLoaded = loaded; };
    inline bool IsPluginLoaded() { return this->isPluginLoaded; };
    std::string GetName() { return this->m_pluginName; }

    void *FetchFunction(std::string function)
    {
        if (this->functions.find(function) == this->functions.end())
            return nullptr;

        return this->functions.at(function);
    }
};

std::map<std::string, Plugin *> FetchPluginsMap();
void AddPluginInMap(Plugin *plugin);
bool ExistsPluginInMap(std::string plugin_name);
Plugin *FetchPluginFromMap(std::string plugin_name);

extern std::vector<Plugin *> plugins;

#endif