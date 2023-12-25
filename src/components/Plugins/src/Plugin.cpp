#include "../inc/Plugin.h"
#include "../inc/Scripting.h"
#include "../../../common.h"
#include "../../../commands/CommandsManager.h"
#include "../../../player/PlayerManager.h"
#include <luacpp/luacpp.h>

void Plugin::StartPlugin()
{
    if (!this->FunctionExists("OnProgramLoad") || !this->FunctionExists("RegisterPlayer") || !this->FunctionExists("UnregisterPlayer") || !this->FunctionExists("GetPluginAuthor") || !this->FunctionExists("GetPluginVersion") || !this->FunctionExists("GetPluginName") || !this->FunctionExists("GetPluginWebsite"))
    {
        PRINT("Plugin", "Stopped loading plugin because the base functions are not present.\n");
        PRINTF("Plugin", "Plugin File: %s\n", this->m_path.c_str());
        return;
    }

    this->ExecuteFunction<OnProgramLoadFunction>("OnProgramLoad", this->GetName().c_str(), std::string(PATH).append(WIN_LINUX("/bin/win64/swiftly.dll", "/bin/linuxsteamrt64/swiftly.so")).c_str());

    for (uint16 i = 0; i < g_playerManager->GetPlayerCap(); i++)
    {
        Player *player = g_playerManager->GetPlayer(i);
        if (!player)
            continue;

        this->ExecuteFunction<Plugin_OnPlayerRegister>("RegisterPlayer", player->GetSlot()->Get(), player->IsFakeClient());
    }

    if (this->FunctionExists("OnPluginStart"))
        this->ExecuteFunction<OnPluginStartFunction>("OnPluginStart");

    this->SetPluginLoaded(true);
}

void Plugin::StopPlugin()
{
    if (this->FunctionExists("OnPluginStop"))
        this->ExecuteFunction<OnPluginStopFunction>("OnPluginStop");

    if (this->GetPluginType() == PluginType_t::PLUGIN_CPP)
        dlclose(this->m_hModule);
    else if (this->GetPluginType() == PluginType_t::PLUGIN_LUA)
        delete this->luaState;

    this->cppFunctions.clear();
    this->luaFunctions.clear();
    std::vector<std::string> cmds = g_commandsManager->FetchCommandsByPlugin(this->GetName());
    for (uint32 i = 0; i < cmds.size(); i++)
        g_commandsManager->UnregisterCommand(cmds[i]);

    this->SetPluginLoaded(false);
}