#include "entrypoint.h"

#include <tier1/convar.h>
#include <interfaces/interfaces.h>
#include <metamod_oslink.h>
#include <public/tier0/platform.h>

#include <utils/common.h>

#include <core/configuration/setup.h>
#include <core/console/console.h>

#include <scripting/core.h>

#include <engine/convars/manager.h>
#include <engine/convars/query.h>
#include <engine/vgui/vgui.h>
#include <engine/gameevents/gameevents.h>
#include <engine/precacher/precacher.h>
#include <engine/precacher/game_system.h>

#include <entities/system.h>

#include <sdk/schema.h>

#include <server/configuration/configuration.h>
#include <server/translations/translations.h>
#include <server/player/manager.h>
#include <server/commands/manager.h>
#include <server/menus/MenuManager.h>

#include <filesystem/logs/logger.h>

#include <memory/gamedata/gamedata.h>
#include <memory/hooks/manager.h>

#include <network/usermessages/usermessages.h>

#include <extensions/manager.h>
#include <server/chat/chat.h>
#include <engine/voicemanager/manager.h>

#include <plugins/manager.h>

#include <sdk/access.h>
#include <sdk/game.h>

#include <schemasystem/schemasystem.h>

#include <network/database/DatabaseManager.h>

#include <tools/crashreporter/callstack.h>
#include <tools/crashreporter/crashreporter.h>
#include <tools/resourcemonitor/monitor.h>

#include <public/tier0/icommandline.h>
#include <public/steam/steam_gameserver.h>
#include <utils/utils.h>

//////////////////////////////////////////////////////////////
/////////////////       SourceHook Hooks       //////////////
////////////////////////////////////////////////////////////

class GameSessionConfiguration_t
{
};

SH_DECL_HOOK3_void(INetworkServerService, StartupServer, SH_NOATTRIB, 0, const GameSessionConfiguration_t&, ISource2WorldSession*, const char*);
SH_DECL_HOOK0_void(IServerGameDLL, GameServerSteamAPIActivated, SH_NOATTRIB, 0);
SH_DECL_HOOK0_void(IServerGameDLL, GameServerSteamAPIDeactivated, SH_NOATTRIB, 0);
SH_DECL_HOOK3_void(IServerGameDLL, GameFrame, SH_NOATTRIB, 0, bool, bool, bool);
SH_DECL_HOOK3_void(ICvar, DispatchConCommand, SH_NOATTRIB, 0, ConCommandRef, const CCommandContext&, const CCommand&);
SH_DECL_HOOK6(IServerGameClients, ClientConnect, SH_NOATTRIB, 0, bool, CPlayerSlot, const char*, uint64, const char*, bool, CBufferString*);
SH_DECL_HOOK7_void(ISource2GameEntities, CheckTransmit, SH_NOATTRIB, 0, CCheckTransmitInfo**, int, CBitVec<16384>&, CBitVec<16384>&, const Entity2Networkable_t**, const uint16_t*, int);
SH_DECL_HOOK6_void(IServerGameClients, OnClientConnected, SH_NOATTRIB, 0, CPlayerSlot, const char*, uint64, const char*, const char*, bool);
SH_DECL_HOOK4_void(IServerGameClients, ClientPutInServer, SH_NOATTRIB, 0, CPlayerSlot, char const*, int, uint64);
SH_DECL_HOOK5_void(IServerGameClients, ClientDisconnect, SH_NOATTRIB, 0, CPlayerSlot, ENetworkDisconnectionReason, const char*, uint64, const char*);
SH_DECL_HOOK8_void(IGameEventSystem, PostEventAbstract, SH_NOATTRIB, 0, CSplitScreenSlot, bool, int, const uint64*, INetworkMessageInternal*, const CNetMessage*, unsigned long, NetChannelBufType_t);
SH_DECL_HOOK3(IVEngineServer2, SetClientListening, SH_NOATTRIB, 0, bool, CPlayerSlot, CPlayerSlot, bool);
SH_DECL_HOOK2_void(IServerGameClients, ClientCommand, SH_NOATTRIB, 0, CPlayerSlot, const CCommand&);

bool shuttingDown = false;

//////////////////////////////////////////////////////////////
/////////////////  Core Variables & Functions  //////////////
////////////////////////////////////////////////////////////

SwiftlyS2 g_Plugin;
IVEngineServer2* engine = nullptr;
ISource2Server* server = nullptr;
CSchemaSystem* g_pSchemaSystem2 = nullptr;
CGameEntitySystem* g_pGameEntitySystem = nullptr;
IGameResourceService* g_pGameResourceService = nullptr;
CEntitySystem* g_pEntitySystem = nullptr;
IGameEventManager2* g_gameEventManager = nullptr;
IGameEventSystem* g_pGameEventSystem = nullptr;
IServerGameClients* gameclients = nullptr;
ICvar* g_pcVar = nullptr;

CSteamGameServerAPIContext g_SteamAPI;

//////////////////////////////////////////////////////////////
/////////////////      Internal Variables      //////////////
////////////////////////////////////////////////////////////

Configuration g_Config;
Logger g_Logger;
Translations g_translations;
GameData g_GameData;
SDKAccess g_sdk;
PluginsManager g_pluginManager;
EventManager g_eventManager;
Precacher g_precacher;
EntitySystem g_entSystem;
PlayerManager g_playerManager;
CommandsManager g_commandsManager;
VGUI g_VGUI;
CvarQuery g_convarQuery;
ConvarManager g_cvarManager;
CallStackManager g_callStack;
ResourceMonitor g_ResourceMonitor;
ExtensionManager extManager;
ChatProcessor g_chatProcessor;
VoiceManager g_voiceManager;
MenuManager g_MenuManager;
DatabaseManager g_dbManager;
HookManager g_hookManager;
UserMessages g_ums;

std::map<std::string, std::string> gameEventsRegister;
std::vector<ClassLoader*> loaderClasses;

//////////////////////////////////////////////////////////////
/////////////////          Core Class          //////////////
////////////////////////////////////////////////////////////

std::string GeneratePath(std::string path);
bool InitializeHostFXR(std::string origin_path);

PLUGIN_EXPOSE(SwiftlyS2, g_Plugin);
bool SwiftlyS2::Load(PluginId id, ISmmAPI* ismm, char* error, size_t maxlen, bool late)
{
    PLUGIN_SAVEVARS();
    g_SMAPI->AddListener(this, this);

    if (GetGameName() == "unknown") {
        ismm->Format(error, maxlen, "Unknown game detected.");
        return false;
    }

    SetupConsoleColors();

    GET_V_IFACE_CURRENT(GetEngineFactory, g_pCVar, ICvar, CVAR_INTERFACE_VERSION);
    GET_V_IFACE_CURRENT(GetEngineFactory, engine, IVEngineServer2, INTERFACEVERSION_VENGINESERVER);
    GET_V_IFACE_CURRENT(GetEngineFactory, g_pSchemaSystem2, CSchemaSystem, SCHEMASYSTEM_INTERFACE_VERSION);
    GET_V_IFACE_CURRENT(GetEngineFactory, g_pGameEventSystem, IGameEventSystem, GAMEEVENTSYSTEM_INTERFACE_VERSION);
    GET_V_IFACE_CURRENT(GetEngineFactory, g_pGameResourceService, IGameResourceService, GAMERESOURCESERVICESERVER_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetServerFactory, server, ISource2Server, INTERFACEVERSION_SERVERGAMEDLL);
    GET_V_IFACE_ANY(GetFileSystemFactory, g_pFullFileSystem, IFileSystem, FILESYSTEM_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetServerFactory, gameclients, IServerGameClients, INTERFACEVERSION_SERVERGAMECLIENTS);
    GET_V_IFACE_ANY(GetEngineFactory, g_pNetworkMessages, INetworkMessages, NETWORKMESSAGES_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetServerFactory, g_pSource2GameEntities, ISource2GameEntities, SOURCE2GAMEENTITIES_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetEngineFactory, g_pNetworkServerService, INetworkServerService, NETWORKSERVERSERVICE_INTERFACE_VERSION);

    SH_ADD_HOOK_MEMFUNC(IServerGameDLL, GameServerSteamAPIActivated, server, this, &SwiftlyS2::Hook_GameServerSteamAPIActivated, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameDLL, GameServerSteamAPIDeactivated, server, this, &SwiftlyS2::Hook_GameServerSteamAPIDeactivated, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameDLL, GameFrame, server, this, &SwiftlyS2::GameFrame, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientCommand, gameclients, this, &SwiftlyS2::Hook_OnClientCommand, false);

    HandleConfigExamples();
    InitializeHostFXR(GeneratePath(""));

    if (g_Config.LoadConfiguration())
        PRINT("The configurations has been succesfully loaded.\n");
    else
        PRINTRET("Failed to load configurations. The framework will not work.\n", false);

    if (!LoadManifestSchema())
        PRINTRET("Failed to load plugin manifest schema located at 'addons/swiftly/gamedata/manifest.json'. The framework will not work.\n", false);

    g_Logger.AddLogger("core", false);

    g_sdk.LoadSDKData();
    g_Config.LoadPluginConfigurations();
    g_GameData.LoadGameData();
    g_GameData.PerformPatches();

    g_ums.Initialize();
    g_convarQuery.Initialize();
    g_eventManager.Initialize();
    g_entSystem.Initialize();
    g_playerManager.Initialize();
    g_commandsManager.Initialize();
    g_VGUI.Initialize();
    g_chatProcessor.Initialize();
    g_hookManager.Initialize();
    g_voiceManager.OnAllInitialized();

    g_chatProcessor.LoadMessages();
    g_translations.LoadTranslations();

    extManager.LoadExtensions();

    g_dbManager.LoadDatabases();

    META_CONVAR_REGISTER(FCVAR_RELEASE | FCVAR_SERVER_CAN_EXECUTE | FCVAR_CLIENT_CAN_EXECUTE | FCVAR_GAMEDLL);

    g_pluginManager.LoadPlugins("");
    g_pluginManager.StartPlugins();

    if (!InitGameSystem())
        PRINTRET("Failed to setup Game System (Precacher).\n", false);

    if (late)
    {
        g_eventManager.RegisterGameEvents();
        g_SteamAPI.Init();
        g_playerManager.SteamAPIServerActivated();
        if (!BeginCrashListener()) PRINTRET("Failed to setup crash listener.\n", false);
    }

    PRINT("Succesfully started.\n");

    return true;
}

bool SwiftlyS2::Unload(char* error, size_t maxlen)
{
    shuttingDown = true;

    g_pluginManager.StopPlugins(false);
    g_pluginManager.UnloadPlugins();

    extManager.UnloadExtensions();
    g_ums.Destroy();
    g_convarQuery.Shutdown();
    g_eventManager.Shutdown();
    g_entSystem.Shutdown();
    g_playerManager.Shutdown();
    g_commandsManager.Shutdown();
    g_VGUI.Shutdown();
    g_chatProcessor.Shutdown();
    g_hookManager.Shutdown();
    g_voiceManager.OnShutdown();

    SH_REMOVE_HOOK_MEMFUNC(IServerGameDLL, GameServerSteamAPIActivated, server, this, &SwiftlyS2::Hook_GameServerSteamAPIActivated, false);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameDLL, GameServerSteamAPIDeactivated, server, this, &SwiftlyS2::Hook_GameServerSteamAPIDeactivated, false);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameDLL, GameFrame, server, this, &SwiftlyS2::GameFrame, true);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientCommand, gameclients, this, &SwiftlyS2::Hook_OnClientCommand, false);

    EndCrashListener();
    return true;
}

bool OnClientCommand(int playerid, std::string command)
{
    ClassData* data = new ClassData({ { "plugin_name", std::string("core") } }, "Event", nullptr);
    g_pluginManager.ExecuteEvent("core", "OnClientCommand", { playerid, command }, data);

    bool response = true;
    try
    {
        response = std::any_cast<bool>(data->GetAnyData("event_return"));
    }
    catch (std::bad_any_cast& e)
    {
        response = true;
    }

    delete data;

    return response;
}

void SwiftlyS2::Hook_OnClientCommand(CPlayerSlot slot, const CCommand& cmd)
{
    if (!OnClientCommand(slot.Get(), cmd.GetCommandString()))
        RETURN_META(MRES_SUPERCEDE);

    RETURN_META(MRES_IGNORED);
}

void SwiftlyS2::RegisterTimeout(int64_t delay, std::function<void()> callback)
{
    timeoutsArray.push_back({ GetTime() + delay, callback });
    processingTimeouts = true;
}

void SwiftlyS2::AllPluginsLoaded()
{

}

std::string currentMap = "None";

void SwiftlyS2::OnLevelInit(char const* pMapName, char const* pMapEntities, char const* pOldLevel, char const* pLandmarkName, bool loadGame, bool background)
{
    currentMap = pMapName;
    g_pluginManager.ExecuteEvent("core", "OnMapLoad", { currentMap }, nullptr);
}

void SwiftlyS2::OnLevelShutdown()
{
    g_translations.LoadTranslations();
    g_Config.LoadPluginConfigurations();

    g_pluginManager.ExecuteEvent("core", "OnMapUnload", { currentMap }, nullptr);
}

std::list<std::list<std::pair<int64_t, std::function<void()>>>::iterator> queueRemoveTimeouts;

void UpdatePlayers()
{
    // Credits to: https://github.com/Source2ZE/ServerListPlayersFix (Source2ZE Team)
    if (!engine->GetServerGlobals() || !g_SteamAPI.SteamGameServer())
        return;

    for (int i = 0; i < engine->GetServerGlobals()->maxClients; i++)
    {
        auto steamId = engine->GetClientSteamID(CPlayerSlot(i));
        if (steamId)
        {
            auto controller = g_pEntitySystem->GetEntityInstance(CEntityIndex(i + 1));
            if (controller)
                g_SteamAPI.SteamGameServer()->BUpdateUserData(*steamId, schema::GetPropPtr<char>(controller, "CBasePlayerController", "m_iszPlayerName"), gameclients->GetPlayerScore(CPlayerSlot(i)));
        }
    }
}

ClassData* gfData = new ClassData({ { "plugin_name", std::string("core") } }, "Event", nullptr);

void SwiftlyS2::GameFrame(bool simulate, bool first, bool last)
{
    if (processingTimeouts) {
        int64_t t = GetTime();
        for (auto it = timeoutsArray.begin(); it != timeoutsArray.end(); ++it) {
            if (it->first <= t) {
                queueRemoveTimeouts.push_back(it);
                it->second();
            }
        }

        for (auto it = queueRemoveTimeouts.rbegin(); it != queueRemoveTimeouts.rend(); ++it)
            timeoutsArray.erase(*it);

        queueRemoveTimeouts.clear();
        processingTimeouts = (timeoutsArray.size() > 0);
    }

    static double g_flNextUpdate = 0.0;
    double curtime = Plat_FloatTime();
    if (curtime > g_flNextUpdate)
    {
        // Credits to: https://github.com/Source2ZE/ServerListPlayersFix (Source2ZE Team)
        UpdatePlayers();

        g_flNextUpdate = curtime + 5.0;
    }

    g_pluginManager.ExecuteEvent("core", "OnGameTick", { simulate, first, last }, gfData);
}

void SwiftlyS2::Hook_GameServerSteamAPIActivated()
{
    if (!CommandLine()->HasParm("-dedicated") || g_SteamAPI.SteamUGC())
        return;

    g_SteamAPI.Init();

    ExecuteOnce(BeginCrashListener());
    RETURN_META(MRES_IGNORED);
}

void SwiftlyS2::Hook_GameServerSteamAPIDeactivated()
{
    RETURN_META(MRES_IGNORED);
}

bool SwiftlyS2::Pause(char* error, size_t maxlen)
{
    return true;
}

bool SwiftlyS2::Unpause(char* error, size_t maxlen)
{
    return true;
}

const char* SwiftlyS2::GetLicense()
{
    return "GNU GPL 3";
}

const char* SwiftlyS2::GetVersion()
{
#ifndef SWIFTLY_VERSION
    return "Local";
#else
    return SWIFTLY_VERSION;
#endif
}

const char* SwiftlyS2::GetDate()
{
    return __DATE__;
}

const char* SwiftlyS2::GetLogTag()
{
    return "SWIFTLY";
}

const char* SwiftlyS2::GetAuthor()
{
    return "Swiftly Development Team";
}

const char* SwiftlyS2::GetDescription()
{
    return "SwiftlyS2 - Framework";
}

const char* SwiftlyS2::GetName()
{
    return "SwiftlyS2";
}

const char* SwiftlyS2::GetURL()
{
    return "https://github.com/swiftly-solution/swiftly";
}
