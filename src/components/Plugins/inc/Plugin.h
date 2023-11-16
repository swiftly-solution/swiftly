#ifndef _components_plugins_inc_plugin_h
#define _components_plugins_inc_plugin_h

#include "../../../common.h"
#include <map>
#include <vector>
#include <metamod_oslink.h>

const std::string funcsToLoad[] = {
    "RegisterPlayer",
    "OnProgramLoad",
    "OnPluginStart",
    "OnPluginStop",
    "OnClientConnected",
    "OnClientConnect",
    "OnPlayerSpawn",
    "OnGameTick",
    "OnPlayerChat",
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
        this->m_hModule = dlmount(WIN_LINUX(this->m_path.c_str(), this->m_path.c_str()));
        PRINTF("LoadPlugin", "dlmount: %p\n", this->m_hModule);

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

extern std::map<std::string, Plugin *> pluginsMap;
extern std::vector<Plugin *> plugins;

#endif