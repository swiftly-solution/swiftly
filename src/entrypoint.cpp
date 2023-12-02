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
#include "sdk/schema.h"
#include "sdk/entity/CBaseEntity.h"
#include "database/DatabaseManager.h"
#include "commands/CommandsManager.h"
#include "sig/Signatures.h"
#include "sig/Offsets.h"
#include "hooks/NativeHooks.h"
#include "filter/ConsoleFilter.h"
#include "translations/Translations.h"
#include "logs/Logger.h"

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
Configuration *g_Config;
IServerGameDLL *server = nullptr;
IServerGameClients *gameclients = nullptr;
IVEngineServer2 *engine = nullptr;
IFileSystem *filesystem = nullptr;
IServerGameClients *g_clientsManager = nullptr;
ICvar *icvar = nullptr;
IGameResourceServiceServer *g_pGameResourceService = nullptr;
CSchemaSystem *g_pSchemaSystem2 = nullptr;
CEntitySystem *g_pEntitySystem = nullptr;
CGameEntitySystem *g_pGameEntitySystem = nullptr;
IGameEventManager2 *g_gameEventManager = nullptr;
PlayerManager *g_playerManager = nullptr;
ICvar *g_pcVar = nullptr;
PluginsComponent *plugins_component = nullptr;
DatabaseManager *g_dbManager = nullptr;
CommandsManager *g_commandsManager = nullptr;
Signatures *g_Signatures = nullptr;
ConsoleFilter *g_conFilter = nullptr;
Translations *g_translations = nullptr;
Logger *g_Logger = nullptr;
Offsets *g_Offsets = nullptr;

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
    GET_V_IFACE_CURRENT(GetEngineFactory, g_pSchemaSystem2, CSchemaSystem, SCHEMASYSTEM_INTERFACE_VERSION);

    PRINT("Configurations", "Loading configurations...\n");

    g_Config = new Configuration();
    if (g_Config->LoadConfiguration())
        PRINT("Configurations", "The configurations has been succesfully loaded.\n");
    else
        PRINT("Configurations", "Failed to load configurations. The plugin will not work.\n");

    g_SMAPI->AddListener(this, this);

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

    g_gameEventManager = static_cast<IGameEventManager2 *>(CallVFunc<IToolGameEventAPI *>(91, server));
    g_playerManager = new PlayerManager();
    g_dbManager = new DatabaseManager();
    g_Signatures = new Signatures();
    g_Offsets = new Offsets();
    g_commandsManager = new CommandsManager();
    g_conFilter = new ConsoleFilter();
    g_translations = new Translations();
    g_Logger = new Logger();

    g_Config->LoadPluginConfigurations();

    g_pCVar = icvar;
    ConVar_Register(FCVAR_RELEASE | FCVAR_CLIENT_CAN_EXECUTE | FCVAR_SERVER_CAN_EXECUTE | FCVAR_GAMEDLL);

    g_playerManager->SetupHooks();
    g_playerManager->LoadPlayers();
    g_dbManager->LoadDatabases();
    g_conFilter->LoadFilters();
    g_translations->LoadTranslations();

    if (g_Config->FetchValue<bool>("core.console_filtering"))
        g_conFilter->Toggle();

    PRINT("Components", "Loading components...\n");

    LOAD_COMPONENT(BasicComponent, basic_component);
    plugins_component->LoadComponent();

    PRINT("Components", "All components has been loaded!\n");

    plugins_component->RegisterGameEvents();
    plugins_component->StartPlugins();

    g_Signatures->LoadSignatures();
    g_Offsets->LoadOffsets();
    if (!InitializeHooks())
        PRINT("Hooks", "Failed to initialize hooks.\n");
    else
        PRINT("Hooks", "All hooks has been loaded!\n");

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

void SwiftlyPlugin::OnLevelInit(char const *pMapName, char const *pMapEntities, char const *pOldLevel, char const *pLandmarkName, bool loadGame, bool background)
{
    hooks::emit(OnMapLoad(pMapName));
}

void SwiftlyPlugin::OnLevelShutdown()
{
    hooks::emit(OnMapUnload(engine->GetServerGlobals()->mapname.ToCStr()));
}

bool bDone = false;
void SwiftlyPlugin::Hook_StartupServer(const GameSessionConfiguration_t &config, ISource2WorldSession *, const char *)
{
    if (!bDone)
    {
        g_pGameEntitySystem = *reinterpret_cast<CGameEntitySystem **>(reinterpret_cast<uintptr_t>(g_pGameResourceService) + g_Offsets->GetOffset("GameEntitySystem"));
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

void scripting_OnClientConnected(const OnClientConnected *e);

void SwiftlyPlugin::Hook_OnClientConnected(CPlayerSlot slot, const char *pszName, uint64 xuid, const char *pszNetworkID, const char *pszAddress, bool bFakePlayer)
{
    if (bFakePlayer)
    {
        Player *player = new Player(true, slot.Get(), pszName, 0);
        g_playerManager->RegisterPlayer(player);
    }

    OnClientConnected onClientConnected = OnClientConnected(&slot, pszName, xuid, pszNetworkID, pszAddress, bFakePlayer);
    scripting_OnClientConnected(&onClientConnected);
    hooks::emit(onClientConnected);
}

bool scripting_OnClientConnect(const OnClientConnect *e);

bool SwiftlyPlugin::Hook_ClientConnect(CPlayerSlot slot, const char *pszName, uint64 xuid, const char *pszNetworkID, bool unk1, CBufferString *pRejectReason)
{
    Player *player = new Player(false, slot.Get(), pszName, xuid);
    g_playerManager->RegisterPlayer(player);

    player->SetConnected(true);

    OnClientConnect clientConnectEvent = OnClientConnect(&slot, pszName, xuid, pszNetworkID, unk1, pRejectReason);
    hooks::emit(clientConnectEvent);
    RETURN_META_VALUE(MRES_SUPERCEDE, scripting_OnClientConnect(&clientConnectEvent));
}

void SwiftlyPlugin::Hook_ClientPutInServer(CPlayerSlot slot, char const *pszName, int type, uint64 xuid)
{
    hooks::emit(OnClientPutInServer(&slot, pszName, type, xuid));
}

void scripting_OnClientDisconnect(const OnClientDisconnect *e);

void SwiftlyPlugin::Hook_ClientDisconnect(CPlayerSlot slot, int reason, const char *pszName, uint64 xuid, const char *pszNetworkID)
{
    OnClientDisconnect clientDisconnectEvent = OnClientDisconnect(&slot, reason, pszName, xuid, pszNetworkID);
    scripting_OnClientDisconnect(&clientDisconnectEvent);

    Player *player = g_playerManager->GetPlayer(&slot);
    if (player)
        g_playerManager->UnregisterPlayer(&slot);

    hooks::emit(clientDisconnectEvent);
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
