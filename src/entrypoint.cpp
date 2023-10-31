#include <stdio.h>
#include "common.h"

#include <interfaces/interfaces.h>
#include <metamod_oslink.h>

#include "player/PlayerManager.h"
#include "events/gameevents.h"
#include "configuration/Configuration.h"
#include "hooks/Hooks.h"
#include "hooks/GameEvents.h"
#include "components/BasicComponent/inc/BasicComponent.h"
#include "components/Plugins/inc/PluginsComponent.h"
#include "sdk/schemasystem.h"
#include "sdk/CBaseEntity.h"

#define LOAD_COMPONENT(TYPE, VARIABLE_NAME) \
    {                                       \
        TYPE *VARIABLE_NAME = new TYPE();   \
        VARIABLE_NAME->LoadComponent();     \
    }

SH_DECL_HOOK3_void(INetworkServerService, StartupServer, SH_NOATTRIB, 0, const GameSessionConfiguration_t &, ISource2WorldSession *, const char *);
SH_DECL_HOOK3_void(IServerGameDLL, GameFrame, SH_NOATTRIB, 0, bool, bool, bool);
SH_DECL_HOOK4_void(IServerGameClients, ClientActive, SH_NOATTRIB, 0, CPlayerSlot, bool, const char *, uint64);
SH_DECL_HOOK5_void(IServerGameClients, ClientDisconnect, SH_NOATTRIB, 0, CPlayerSlot, int, const char *, uint64, const char *);
SH_DECL_HOOK4_void(IServerGameClients, ClientPutInServer, SH_NOATTRIB, 0, CPlayerSlot, char const *, int, uint64);
SH_DECL_HOOK1_void(IServerGameClients, ClientSettingsChanged, SH_NOATTRIB, 0, CPlayerSlot);
SH_DECL_HOOK6_void(IServerGameClients, OnClientConnected, SH_NOATTRIB, 0, CPlayerSlot, const char *, uint64, const char *, const char *, bool);
SH_DECL_HOOK6(IServerGameClients, ClientConnect, SH_NOATTRIB, 0, bool, CPlayerSlot, const char *, uint64, const char *, bool, CBufferString *);
SH_DECL_HOOK2(IGameEventManager2, FireEvent, SH_NOATTRIB, 0, bool, IGameEvent *, bool);
SH_DECL_HOOK2_void(IServerGameClients, ClientCommand, SH_NOATTRIB, 0, CPlayerSlot, const CCommand &);

#ifdef _WIN32
FILE _ioccc[] = {*stdin, *stdout, *stderr};
extern "C" FILE *__cdecl __iob_func(void)
{
    return _ioccc;
}
#endif

EventMap eventMap;
GameEventMap gameEventMap;
SwiftlyPlugin g_Plugin;
Configuration g_Config;
IServerGameDLL *server = nullptr;
IServerGameClients *gameclients = nullptr;
IVEngineServer2 *engine = nullptr;
IFileSystem *filesystem = nullptr;
IServerGameClients *g_clientsManager = nullptr;
ICvar *icvar = nullptr;
IGameResourceServiceServer *g_pGameResourceService = nullptr;
CSchemaSystem *g_pCSchemaSystem = nullptr;
CEntitySystem *g_pEntitySystem = nullptr;
CGameEntitySystem *g_pGameEntitySystem = nullptr;
IGameEventManager2 *g_gameEventManager = nullptr;
PlayerManager *g_playerManager = nullptr;
ICvar *g_pcVar = nullptr;
PluginsComponent *plugins_component = nullptr;

CGlobalVars *GetGameGlobals()
{
    INetworkGameServer *server = g_pNetworkServerService->GetIGameServer();

    if (!server)
        return nullptr;

    return g_pNetworkServerService->GetIGameServer()->GetGlobals();
}

PLUGIN_EXPOSE(SwiftlyPlugin, g_Plugin);
bool SwiftlyPlugin::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
    PLUGIN_SAVEVARS();

    GET_V_IFACE_CURRENT(GetEngineFactory, engine, IVEngineServer, INTERFACEVERSION_VENGINESERVER);
    GET_V_IFACE_CURRENT(GetEngineFactory, icvar, ICvar, CVAR_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetServerFactory, server, IServerGameDLL, INTERFACEVERSION_SERVERGAMEDLL);
    GET_V_IFACE_ANY(GetServerFactory, gameclients, IServerGameClients, INTERFACEVERSION_SERVERGAMECLIENTS);
    GET_V_IFACE_ANY(GetServerFactory, g_clientsManager, IServerGameClients, INTERFACEVERSION_SERVERGAMECLIENTS);
    GET_V_IFACE_ANY(GetEngineFactory, g_pNetworkServerService, INetworkServerService, NETWORKSERVERSERVICE_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetFileSystemFactory, filesystem, IFileSystem, FILESYSTEM_INTERFACE_VERSION);
    GET_V_IFACE_CURRENT(GetEngineFactory, g_pGameResourceService, IGameResourceServiceServer, GAMERESOURCESERVICESERVER_INTERFACE_VERSION);

    {
        HINSTANCE m_hModule = dlmount(WIN_LINUX(TEXT("schemasystem.dll"), "libschemasystem.so"));
        g_pCSchemaSystem = reinterpret_cast<CSchemaSystem *>(reinterpret_cast<CreateInterfaceFn>(dlsym(m_hModule, "CreateInterface"))(SCHEMASYSTEM_INTERFACE_VERSION, nullptr));
        dlclose(m_hModule);
    }

    PRINT("Configurations", "Loading configurations...\n");

    if (g_Config.LoadConfiguration())
        PRINT("Configurations", "The configurations has been succesfully loaded.\n");
    else
        PRINT("Configurations", "Failed to load configurations. The plugin will not work.\n");

    PRINT("Hooks", "Loading Hooks...\n");

    SH_ADD_HOOK_MEMFUNC(IServerGameDLL, GameFrame, server, this, &SwiftlyPlugin::Hook_GameFrame, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientActive, gameclients, this, &SwiftlyPlugin::Hook_ClientActive, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientDisconnect, gameclients, this, &SwiftlyPlugin::Hook_ClientDisconnect, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientPutInServer, gameclients, this, &SwiftlyPlugin::Hook_ClientPutInServer, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientSettingsChanged, gameclients, this, &SwiftlyPlugin::Hook_ClientSettingsChanged, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, OnClientConnected, gameclients, this, &SwiftlyPlugin::Hook_OnClientConnected, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientConnect, gameclients, this, &SwiftlyPlugin::Hook_ClientConnect, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientCommand, gameclients, this, &SwiftlyPlugin::Hook_ClientCommand, false);
    SH_ADD_HOOK_MEMFUNC(INetworkServerService, StartupServer, g_pNetworkServerService, this, &SwiftlyPlugin::Hook_StartupServer, true);

    PRINT("Hooks", "All hooks has been loaded!\n");

    g_gameEventManager = (IGameEventManager2 *)(CALL_VIRTUAL(uintptr_t, 91, server) - 8);
    g_playerManager = new PlayerManager();

    g_pCVar = icvar;
    ConVar_Register(FCVAR_RELEASE | FCVAR_CLIENT_CAN_EXECUTE | FCVAR_SERVER_CAN_EXECUTE | FCVAR_GAMEDLL);

    g_playerManager->SetupHooks();
    g_playerManager->LoadPlayers();

    PRINT("Components", "Loading components...\n");

    LOAD_COMPONENT(BasicComponent, basic_component);
    plugins_component->LoadComponent();

    PRINT("Components", "All components has been loaded!\n");

    plugins_component->RegisterGameEvents();
    plugins_component->StartPlugins();

    return true;
}

void SwiftlyPlugin::AllPluginsLoaded()
{
    PRINT("Game Events", "Loading game events...\n");
    RegisterEventListeners();
    PRINT("Game Events", "Game events has been succesfully loaded.\n");
}

bool SwiftlyPlugin::Unload(char *error, size_t maxlen)
{
    SH_REMOVE_HOOK_MEMFUNC(IServerGameDLL, GameFrame, server, this, &SwiftlyPlugin::Hook_GameFrame, true);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientActive, gameclients, this, &SwiftlyPlugin::Hook_ClientActive, true);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientDisconnect, gameclients, this, &SwiftlyPlugin::Hook_ClientDisconnect, true);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientPutInServer, gameclients, this, &SwiftlyPlugin::Hook_ClientPutInServer, true);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientSettingsChanged, gameclients, this, &SwiftlyPlugin::Hook_ClientSettingsChanged, false);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, OnClientConnected, gameclients, this, &SwiftlyPlugin::Hook_OnClientConnected, false);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientConnect, gameclients, this, &SwiftlyPlugin::Hook_ClientConnect, false);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientCommand, gameclients, this, &SwiftlyPlugin::Hook_ClientCommand, false);
    SH_REMOVE_HOOK_MEMFUNC(INetworkServerService, StartupServer, g_pNetworkServerService, this, &SwiftlyPlugin::Hook_StartupServer, true);

    UnregisterEventListeners();

    ConVar_Unregister();
    return true;
}

bool bDone = false;
void SwiftlyPlugin::Hook_StartupServer(const GameSessionConfiguration_t &config, ISource2WorldSession *, const char *)
{
    if (!bDone)
    {
        g_pGameEntitySystem = *reinterpret_cast<CGameEntitySystem **>(reinterpret_cast<uintptr_t>(g_pGameResourceService) + WIN_LINUX(0x58, 0x50));
        g_pEntitySystem = g_pGameEntitySystem;

        bDone = true;
    }
}

void SwiftlyPlugin::Hook_ClientActive(CPlayerSlot slot, bool bLoadGame, const char *pszName, uint64 xuid)
{
    hooks::emit(OnClientActive(&slot, bLoadGame, pszName, xuid));
}

void SwiftlyPlugin::Hook_ClientCommand(CPlayerSlot slot, const CCommand &args)
{
    hooks::emit(OnClientCommand(&slot, &args));
}

void SwiftlyPlugin::Hook_ClientSettingsChanged(CPlayerSlot slot)
{
    hooks::emit(OnClientSettingsChanged(&slot));
}

void SwiftlyPlugin::Hook_OnClientConnected(CPlayerSlot slot, const char *pszName, uint64 xuid, const char *pszNetworkID, const char *pszAddress, bool bFakePlayer)
{
    hooks::emit(OnClientConnected(&slot, pszName, xuid, pszNetworkID, pszAddress, bFakePlayer));
}

bool SwiftlyPlugin::Hook_ClientConnect(CPlayerSlot slot, const char *pszName, uint64 xuid, const char *pszNetworkID, bool unk1, CBufferString *pRejectReason)
{
    hooks::emit(OnClientConnect(&slot, pszName, xuid, pszNetworkID, unk1, pRejectReason));

    RETURN_META_VALUE(MRES_IGNORED, true);
}

void SwiftlyPlugin::Hook_ClientPutInServer(CPlayerSlot slot, char const *pszName, int type, uint64 xuid)
{
    hooks::emit(OnClientPutInServer(&slot, pszName, type, xuid));
}

void SwiftlyPlugin::Hook_ClientDisconnect(CPlayerSlot slot, int reason, const char *pszName, uint64 xuid, const char *pszNetworkID)
{
    hooks::emit(OnClientDisconnect(&slot, reason, pszName, xuid, pszNetworkID));
}

void SwiftlyPlugin::Hook_GameFrame(bool simulating, bool bFirstTick, bool bLastTick)
{
    hooks::emit(OnGameFrame(simulating, bFirstTick, bLastTick));
}

bool SwiftlyPlugin::Pause(char *error, size_t maxlen)
{
    return true;
}

bool SwiftlyPlugin::Unpause(char *error, size_t maxlen)
{
    return true;
}

const char *SwiftlyPlugin::GetLicense()
{
    return "MIT License";
}

const char *SwiftlyPlugin::GetVersion()
{
    return "1.0.0";
}

const char *SwiftlyPlugin::GetDate()
{
    return __DATE__;
}

const char *SwiftlyPlugin::GetLogTag()
{
    return "SWIFTLY";
}

const char *SwiftlyPlugin::GetAuthor()
{
    return "Swiftly Team";
}

const char *SwiftlyPlugin::GetDescription()
{
    return "Swiftly - Plugin";
}

const char *SwiftlyPlugin::GetName()
{
    return "Swiftly";
}

const char *SwiftlyPlugin::GetURL()
{
    return "https://";
}
