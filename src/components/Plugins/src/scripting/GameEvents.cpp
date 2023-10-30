#include "../../../../common.h"
#include "../../../../hooks/Hooks.h"
#include "../../../../hooks/GameEvents.h"
#include "../../../../player/Player.h"
#include "../../inc/PluginsComponent.h"
#include "../../inc/Plugin.h"

typedef bool (*PluginOnClientConnected)();
typedef bool (*PluginOnClientConnect)();
typedef void (*PluginOnPlayerSpawn)();

void scripting_OnClientConnectedOnServer(const OnClientConnected *e)
{
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_OnClientConnected = plugin->FetchFunction("Internal_OnClientConnected");
            if (plugin_OnClientConnected)
                if (!reinterpret_cast<PluginOnClientConnected>(plugin_OnClientConnected)())
                    break;
        }
    }
};

void scripting_OnClientConnectOnServer(const OnClientConnect *e)
{
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_OnClientConnect = plugin->FetchFunction("Internal_OnClientConnect");
            if (plugin_OnClientConnect)
                if (!reinterpret_cast<PluginOnClientConnect>(plugin_OnClientConnect)())
                    break;
        }
    }
};

void scripting_OnClientSpawn(const OnPlayerSpawn *e)
{
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_OnPlayerSpawn = plugin->FetchFunction("Internal_OnPlayerSpawn");
            if (plugin_OnPlayerSpawn)
            {
                PRINT("Plugin", "OnPlayerSpawn for plugins called\n");
                reinterpret_cast<PluginOnPlayerSpawn>(plugin_OnPlayerSpawn)();
            }
        }
    }
}

void PluginsComponent::RegisterGameEvents()
{
    hooks::on<OnClientConnected>(scripting_OnClientConnectedOnServer);
    hooks::on<OnClientConnect>(scripting_OnClientConnectOnServer);

    gameevents::on<OnPlayerSpawn>(scripting_OnClientSpawn);
}