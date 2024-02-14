#include <stdio.h>
#include "common.h"

#include <interfaces/interfaces.h>
#include <metamod_oslink.h>
#include <chrono>

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
#include "sig/Patches.h"
#include "hooks/NativeHooks.h"
#include "filter/ConsoleFilter.h"
#include "translations/Translations.h"
#include "logs/Logger.h"
#include "http/HTTPManager.h"
#include "components/Plugins/inc/Scripting.h"
#include "entities/EntityManager.h"
#include "precacher/Precacher.h"
#include "menus/Menus.h"
#include "dumps/CrashDump.h"

#define LOAD_COMPONENT(TYPE, VARIABLE_NAME) \
    {                                       \
        TYPE *VARIABLE_NAME = new TYPE();   \
        VARIABLE_NAME->LoadComponent();     \
    }

SH_DECL_HOOK3_void(INetworkServerService, StartupServer, SH_NOATTRIB, 0, const GameSessionConfiguration_t &, ISource2WorldSession *, const char *);
SH_DECL_HOOK3_void(IServerGameDLL, GameFrame, SH_NOATTRIB, 0, bool, bool, bool);
SH_DECL_HOOK4_void(IServerGameClients, ClientActive, SH_NOATTRIB, 0, CPlayerSlot, bool, const char *, uint64);
SH_DECL_HOOK5_void(IServerGameClients, ClientDisconnect, SH_NOATTRIB, 0, CPlayerSlot, ENetworkDisconnectionReason, const char *, uint64, const char *);
SH_DECL_HOOK1_void(IServerGameClients, ClientSettingsChanged, SH_NOATTRIB, 0, CPlayerSlot);
SH_DECL_HOOK6_void(IServerGameClients, OnClientConnected, SH_NOATTRIB, 0, CPlayerSlot, const char *, uint64, const char *, const char *, bool);
SH_DECL_HOOK6(IServerGameClients, ClientConnect, SH_NOATTRIB, 0, bool, CPlayerSlot, const char *, uint64, const char *, bool, CBufferString *);
SH_DECL_HOOK2(IGameEventManager2, FireEvent, SH_NOATTRIB, 0, bool, IGameEvent *, bool);
SH_DECL_HOOK2_void(IServerGameClients, ClientCommand, SH_NOATTRIB, 0, CPlayerSlot, const CCommand &);
SH_DECL_HOOK3_void(ICvar, DispatchConCommand, SH_NOATTRIB, 0, ConCommandHandle, const CCommandContext &, const CCommand &);
SH_DECL_HOOK0_void(IServerGameDLL, GameServerSteamAPIActivated, SH_NOATTRIB, 0);

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
HTTPManager *g_httpManager = nullptr;
Patches *g_Patches = nullptr;
EntityManager *g_entityManager = nullptr;
Precacher *g_precacher = nullptr;
CEntityListener g_entityListener;
CGameRules *g_pGameRules = nullptr;
GameMenus *g_menus = nullptr;

class CGameResourceService
{
public:
    CGameEntitySystem *GetGameEntitySystem()
    {
        return *reinterpret_cast<CGameEntitySystem **>((uintptr_t)(this) + g_Offsets->GetOffset("GameEntitySystem"));
    }
};

CGameEntitySystem *GameEntitySystem()
{
    return g_pGameEntitySystem;
}

std::vector<Plugin *> plugins;

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
    GET_V_IFACE_ANY(GetEngineFactory, g_pNetworkMessages, INetworkMessages, NETWORKMESSAGES_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetFileSystemFactory, filesystem, IFileSystem, FILESYSTEM_INTERFACE_VERSION);
    GET_V_IFACE_CURRENT(GetEngineFactory, g_pGameResourceService, IGameResourceServiceServer, GAMERESOURCESERVICESERVER_INTERFACE_VERSION);
    GET_V_IFACE_CURRENT(GetEngineFactory, g_pSchemaSystem2, CSchemaSystem, SCHEMASYSTEM_INTERFACE_VERSION);

    PRINT("Configurations", "Loading configurations...\n");

    g_Config = new Configuration();
    if (g_Config->LoadConfiguration())
        PRINT("Configurations", "The configurations has been succesfully loaded.\n");
    else
    {
        PRINT("Configurations", "Failed to load configurations. The plugin will not work.\n");
        return false;
    }

    g_SMAPI->AddListener(this, this);

    PRINT("Hooks", "Loading Hooks...\n");

    g_gameEventManager = static_cast<IGameEventManager2 *>(CallVFunc<IToolGameEventAPI *>(93, server));

    SH_ADD_HOOK_MEMFUNC(IServerGameDLL, GameFrame, server, this, &SwiftlyPlugin::Hook_GameFrame, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientActive, gameclients, this, &SwiftlyPlugin::Hook_ClientActive, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientDisconnect, gameclients, this, &SwiftlyPlugin::Hook_ClientDisconnect, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientSettingsChanged, gameclients, this, &SwiftlyPlugin::Hook_ClientSettingsChanged, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, OnClientConnected, gameclients, this, &SwiftlyPlugin::Hook_OnClientConnected, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientConnect, gameclients, this, &SwiftlyPlugin::Hook_ClientConnect, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientCommand, gameclients, this, &SwiftlyPlugin::Hook_ClientCommand, false);
    SH_ADD_HOOK_MEMFUNC(INetworkServerService, StartupServer, g_pNetworkServerService, this, &SwiftlyPlugin::Hook_StartupServer, true);
    SH_ADD_HOOK_MEMFUNC(ICvar, DispatchConCommand, icvar, this, &SwiftlyPlugin::Hook_DispatchConCommand, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameDLL, GameServerSteamAPIActivated, server, this, &SwiftlyPlugin::Hook_GameServerSteamAPIActivated, false);

    g_playerManager = new PlayerManager();
    g_dbManager = new DatabaseManager();
    g_Signatures = new Signatures();
    g_Offsets = new Offsets();
    g_Patches = new Patches();
    g_commandsManager = new CommandsManager();
    g_conFilter = new ConsoleFilter();
    g_translations = new Translations();
    g_Logger = new Logger();
    g_httpManager = new HTTPManager();
    g_entityManager = new EntityManager();
    g_precacher = new Precacher();
    g_menus = new GameMenus();

    g_Config->LoadPluginConfigurations();

    g_pCVar = icvar;

    ConVar_Register(FCVAR_RELEASE | FCVAR_CLIENT_CAN_EXECUTE | FCVAR_SERVER_CAN_EXECUTE | FCVAR_GAMEDLL);

    g_playerManager->LoadPlayers();
    g_dbManager->LoadDatabases();
    g_conFilter->LoadFilters();
    g_translations->LoadTranslations();

    if (g_Config->FetchValue<bool>("core.console_filtering"))
        g_conFilter->Toggle();

    if (!BeginCrashListener())
        return false;

    PRINT("Components", "Loading components...\n");

    LOAD_COMPONENT(BasicComponent, basic_component);
    plugins_component->LoadComponent();

    PRINT("Components", "All components has been loaded!\n");

    plugins_component->RegisterGameEvents();
    plugins_component->StartPlugins();

    g_Signatures->LoadSignatures();
    g_Offsets->LoadOffsets();
    g_Patches->LoadPatches();

    g_Patches->PerformPatches();

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
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientSettingsChanged, gameclients, this, &SwiftlyPlugin::Hook_ClientSettingsChanged, false);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, OnClientConnected, gameclients, this, &SwiftlyPlugin::Hook_OnClientConnected, false);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientConnect, gameclients, this, &SwiftlyPlugin::Hook_ClientConnect, false);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientCommand, gameclients, this, &SwiftlyPlugin::Hook_ClientCommand, false);
    SH_REMOVE_HOOK_MEMFUNC(INetworkServerService, StartupServer, g_pNetworkServerService, this, &SwiftlyPlugin::Hook_StartupServer, true);
    SH_REMOVE_HOOK_MEMFUNC(ICvar, DispatchConCommand, g_pCVar, this, &SwiftlyPlugin::Hook_DispatchConCommand, false);

    g_pGameEntitySystem->RemoveListenerEntity(&g_entityListener);

    UnregisterEventListeners();

    ConVar_Unregister();
    return true;
}

void SwiftlyPlugin::Hook_DispatchConCommand(ConCommandHandle cmdHandle, const CCommandContext &ctx, const CCommand &args)
{
    CPlayerSlot sl = ctx.GetPlayerSlot();
    CPlayerSlot *slot = &sl;

    std::string command = args.Arg(0);

    if (slot->Get() != -1)
    {
        if (command == "say" || command == "say_team")
        {
            Player *player = g_playerManager->GetPlayer(slot);
            if (player == nullptr)
                return;

            CCSPlayerController *controller = player->GetPlayerController();

            if (controller)
            {
                IGameEvent *pEvent = g_gameEventManager->CreateEvent("player_chat");

                if (pEvent)
                {
                    pEvent->SetBool("teamonly", (command == "say_team"));
                    pEvent->SetInt("userid", slot->Get());
                    pEvent->SetString("text", args[1]);

                    g_gameEventManager->FireEvent(pEvent, true);
                }
            }

            int handleCommands = g_commandsManager->HandleCommands(player->GetController(), args[1]);
            if (handleCommands == 2)
            {
                RETURN_META(MRES_SUPERCEDE);
            }
            else if (!scripting_OnClientChat(player->GetController(), args[1], command == "say_team"))
            {
                RETURN_META(MRES_SUPERCEDE);
            }
            else
            {
                SH_CALL(g_pCVar, &ICvar::DispatchConCommand)
                (cmdHandle, ctx, args);
            }
        }
        else
            hooks::emit<OnClientExecuteCommand>(OnClientExecuteCommand(slot, args.GetCommandString()));
    }
    RETURN_META(MRES_SUPERCEDE);
}

void SwiftlyPlugin::Hook_GameServerSteamAPIActivated()
{
    RETURN_META(MRES_IGNORED);
}

std::string map = "None";

std::string SwiftlyPlugin::GetMap()
{
    return map;
}

void SwiftlyPlugin::OnLevelInit(char const *pMapName, char const *pMapEntities, char const *pOldLevel, char const *pLandmarkName, bool loadGame, bool background)
{
    if (!g_precacher->GetSoundsPrecached())
    {
        g_precacher->CacheSounds();
        g_precacher->SetSoundsPrecached(true);
    }

    map = pMapName;
    hooks::emit(OnMapLoad(pMapName));
}

void SwiftlyPlugin::OnLevelShutdown()
{
    g_precacher->Reset();
    g_translations->LoadTranslations();
    g_Config->LoadPluginConfigurations();

    hooks::emit(OnMapUnload(map.c_str()));
}

bool bDone = false;
void SwiftlyPlugin::Hook_StartupServer(const GameSessionConfiguration_t &config, ISource2WorldSession *, const char *)
{
    if (!bDone)
    {
        g_pGameEntitySystem = ((CGameResourceService *)g_pGameResourceService)->GetGameEntitySystem();
        g_pEntitySystem = g_pGameEntitySystem;

        g_pGameEntitySystem->AddListenerEntity(&g_entityListener);

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
    if (bFakePlayer)
    {
        Player *player = new Player(true, slot.Get(), pszName, 0, "127.0.0.1");
        g_playerManager->RegisterPlayer(player);
    }
}

bool scripting_OnClientConnect(const OnClientConnect *e);

bool SwiftlyPlugin::Hook_ClientConnect(CPlayerSlot slot, const char *pszName, uint64 xuid, const char *pszNetworkID, bool unk1, CBufferString *pRejectReason)
{
    std::string ip_address = explode(pszNetworkID, ":")[0];
    Player *player = new Player(false, slot.Get(), pszName, xuid, ip_address);
    g_playerManager->RegisterPlayer(player);

    player->SetConnected(true);

    OnClientConnect clientConnectEvent = OnClientConnect(&slot, pszName, xuid, pszNetworkID, unk1, pRejectReason);
    hooks::emit(clientConnectEvent);
    RETURN_META_VALUE(MRES_SUPERCEDE, scripting_OnClientConnect(&clientConnectEvent));
}

void scripting_OnClientDisconnect(const OnClientDisconnect *e);

void SwiftlyPlugin::Hook_ClientDisconnect(CPlayerSlot slot, ENetworkDisconnectionReason reason, const char *pszName, uint64 xuid, const char *pszNetworkID)
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

    for (uint16_t i = 0; i < MAX_PLAYERS; i++)
    {
        Player *player = g_playerManager->GetPlayer(i);
        if (!player)
            continue;
        if (player->IsFakeClient())
            continue;

        CBasePlayerPawn *pawn = player->GetPawn();
        if (!pawn)
            continue;

        CPlayer_MovementServices *movementServices = pawn->m_pMovementServices();
        if (!movementServices)
            continue;

        uint64_t buttons = movementServices->m_nButtons().m_pButtonStates()[0];
        player->SetButtons(buttons);

        if (player->HasMenuShown())
            player->RenderMenu();
        else
            player->RenderCenterText();
    }

    while (!m_nextFrame.empty())
    {
        m_nextFrame.front()();
        m_nextFrame.pop_front();
    }
}

void SwiftlyPlugin::NextFrame(std::function<void()> fn)
{
    m_nextFrame.push_back(fn);
}

void CEntityListener::OnEntitySpawned(CEntityInstance *pEntity)
{
    if (CBasePlayerWeapon *weapon = dynamic_cast<CBasePlayerWeapon *>(pEntity); weapon != nullptr)
    {
        g_Plugin.NextFrame([weapon]()
                           { hooks::emit(OnWeaponSpawned(weapon)); });
    }
}

void CEntityListener::OnEntityParentChanged(CEntityInstance *pEntity, CEntityInstance *pNewParent)
{
}

uint64_t GetTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
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
    return "0.0.5 - Alpha";
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
    return "Swiftly - Plugin Manager";
}

const char *SwiftlyPlugin::GetName()
{
    return "Swiftly";
}

const char *SwiftlyPlugin::GetURL()
{
    return "https://github.com/swiftly-solution/swiftly";
}
