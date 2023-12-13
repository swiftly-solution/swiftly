#include "../inc/Plugin.h"
#include "../../../common.h"
#include "../../../commands/CommandsManager.h"
#include "../../../player/PlayerManager.h"
#include <thread>

typedef void (*OnPluginStartFunction)();
typedef void (*OnPluginStopFunction)();
typedef void (*OnProgramLoadFunction)(const char *, const char *);
typedef void (*Plugin_OnPlayerRegister)(uint32, bool);

void Plugin::StartPlugin()
{
    void *OnProgramLoad = this->FetchFunction("Internal_OnProgramLoad");
    void *RegisterPlayer = this->FetchFunction("Internal_RegisterPlayer");
    void *GetPluginAuthor = this->FetchFunction("GetPluginAuthor");
    void *GetPluginVersion = this->FetchFunction("GetPluginVersion");
    void *GetPluginName = this->FetchFunction("GetPluginName");
    void *GetPluginWebsite = this->FetchFunction("GetPluginWebsite");

    if (OnProgramLoad == nullptr || RegisterPlayer == nullptr || GetPluginAuthor == nullptr || GetPluginVersion == nullptr || GetPluginName == nullptr || GetPluginWebsite == nullptr)
    {
        PRINT("Plugin", "Stopped loading plugin because the base functions are not present.\n");
        PRINTF("Plugin", "Plugin File: %s\n", this->m_path.c_str());
        return;
    }

    reinterpret_cast<OnProgramLoadFunction>(OnProgramLoad)(this->GetName().c_str(), std::string(PATH).append(WIN_LINUX("/bin/win64/swiftly.dll", "/bin/linuxsteamrt64/swiftly.so")).c_str());

    for (uint16 i = 0; i < g_playerManager->GetPlayerCap(); i++)
    {
        Player *player = g_playerManager->GetPlayer(i);
        if (!player)
            continue;

        reinterpret_cast<Plugin_OnPlayerRegister>(RegisterPlayer)(player->GetSlot()->Get(), player->IsFakeClient());
    }

    void *OnPluginStart = this->FetchFunction("Internal_OnPluginStart");
    if (OnPluginStart)
    {
        std::thread th([OnPluginStart]()
                       { reinterpret_cast<OnPluginStartFunction>(OnPluginStart)(); });
        th.detach();
    }

    this->SetPluginLoaded(true);
}

void Plugin::StopPlugin()
{
    void *OnPluginStop = this->FetchFunction("Internal_OnPluginStop");
    if (OnPluginStop)
        reinterpret_cast<OnPluginStopFunction>(OnPluginStop)();

    dlclose(this->m_hModule);
    this->functions.clear();
    std::vector<std::string> cmds = g_commandsManager->FetchCommandsByPlugin(this->GetName());
    for (uint32 i = 0; i < cmds.size(); i++)
        g_commandsManager->UnregisterCommand(cmds[i]);

    this->SetPluginLoaded(false);
}