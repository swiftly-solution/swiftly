#include <stdio.h>
#include <thread>
#include "entrypoint.h"

#include <tier1/convar.h>
#include <interfaces/interfaces.h>
#include <metamod_oslink.h>

#include <steam/steam_gameserver.h>

#include "sdk/entity/CRecipientFilters.h"
#include "engine/addons/addons.h"
#include "engine/addons/clients.h"
#include "memory/encoders/msgpack.h"
#include "entitysystem/entities/listener.h"
#include "network/http/HTTPManager.h"
#include "server/configuration/Configuration.h"
#include "server/commands/CommandsManager.h"
#include "tools/crashreporter/CallStack.h"
#include "tools/crashreporter/CrashReport.h"
#include "network/database/DatabaseManager.h"
#include "engine/gameevents/gameevents.h"
#include "engine/convars/convars.h"
#include "filesystem/logs/Logger.h"
#include "entitysystem/precacher/precacher.h"
#include "server/translations/Translations.h"
#include "tools/filters/ConsoleFilter.h"
#include "server/menus/MenuManager.h"
#include "tools/resourcemonitor/ResourceMonitor.h"
#include "memory/hooks/NativeHooks.h"
#include "player/playermanager/PlayerManager.h"
#include "player/player/Chat.h"
#include "plugins/PluginManager.h"
#include "plugins/core/scripting.h"
#include "memory/signatures/Signatures.h"
#include "memory/signatures/Patches.h"
#include "memory/signatures/Offsets.h"
#include "engine/voicemanager/VoiceManager.h"
#include "network/usermessages/usermessages.h"
#include "sdk/access/sdkaccess.h"
#include "utils/plat.h"

#ifdef _WIN32
#include <windows.h>
#endif

SH_DECL_HOOK3_void(INetworkServerService, StartupServer, SH_NOATTRIB, 0, const GameSessionConfiguration_t&, ISource2WorldSession*, const char*);
SH_DECL_HOOK3_void(IServerGameDLL, GameFrame, SH_NOATTRIB, 0, bool, bool, bool);
SH_DECL_HOOK5_void(IServerGameClients, ClientDisconnect, SH_NOATTRIB, 0, CPlayerSlot, ENetworkDisconnectionReason, const char*, uint64, const char*);
SH_DECL_HOOK6_void(IServerGameClients, OnClientConnected, SH_NOATTRIB, 0, CPlayerSlot, const char*, uint64, const char*, const char*, bool);
SH_DECL_HOOK6(IServerGameClients, ClientConnect, SH_NOATTRIB, 0, bool, CPlayerSlot, const char*, uint64, const char*, bool, CBufferString*);
SH_DECL_HOOK0_void(IServerGameDLL, GameServerSteamAPIActivated, SH_NOATTRIB, 0);
SH_DECL_HOOK0_void(IServerGameDLL, GameServerSteamAPIDeactivated, SH_NOATTRIB, 0);
SH_DECL_HOOK2_void(IServerGameClients, ClientCommand, SH_NOATTRIB, 0, CPlayerSlot, const CCommand&);
SH_DECL_HOOK3_void(ICvar, DispatchConCommand, SH_NOATTRIB, 0, ConCommandHandle, const CCommandContext&, const CCommand&);
SH_DECL_HOOK8_void(IGameEventSystem, PostEventAbstract, SH_NOATTRIB, 0, CSplitScreenSlot, bool, int, const uint64*, INetworkMessageInternal*, const CNetMessage*, unsigned long, NetChannelBufType_t)
SH_DECL_HOOK7_void(ISource2GameEntities, CheckTransmit, SH_NOATTRIB, 0, CCheckTransmitInfo**, int, CBitVec<16384>&, const Entity2Networkable_t**, const uint16*, int, bool);
SH_DECL_HOOK3(IVEngineServer2, SetClientListening, SH_NOATTRIB, 0, bool, CPlayerSlot, CPlayerSlot, bool);

#ifdef _WIN32
FILE _ioccc[] = { *stdin, *stdout, *stderr };
extern "C" FILE* __cdecl __iob_func(void)
{
    return _ioccc;
}
#endif

//////////////////////////////////////////////////////////////
/////////////////  Core Variables & Functions  //////////////
////////////////////////////////////////////////////////////

Swiftly g_Plugin;
ISource2Server* server = nullptr;
IServerGameClients* gameclients = nullptr;
IVEngineServer2* engine = nullptr;
IServerGameClients* g_clientsManager = nullptr;
ICvar* icvar = nullptr;
ICvar* g_pcVar = nullptr;
IGameResourceService* g_pGameResourceService = nullptr;
CEntitySystem* g_pEntitySystem = nullptr;
CGameEntitySystem* g_pGameEntitySystem = nullptr;
IGameEventManager2* g_gameEventManager = nullptr;
IGameEventSystem* g_pGameEventSystem = nullptr;
CSteamGameServerAPIContext g_SteamAPI;
ISteamHTTP* g_http = nullptr;
CSchemaSystem* g_pSchemaSystem2 = nullptr;
CCSGameRules* gameRules = nullptr;

//////////////////////////////////////////////////////////////
/////////////////      Internal Variables      //////////////
////////////////////////////////////////////////////////////

CUtlVector<FuncHookBase*> g_vecHooks;
std::vector<Player*> g_Players;

Addons g_addons;
PlayerChat g_playerChat;
EntityListener g_EntityListener;
CommandsManager* g_commandsManager = nullptr;
Configuration* g_Config = nullptr;
ConsoleFilter* g_conFilter = nullptr;
Translations* g_translations = nullptr;
Logger* g_Logger = nullptr;
PlayerManager* g_playerManager = nullptr;
PluginManager* g_pluginManager = nullptr;
Offsets* g_Offsets = nullptr;
Signatures* g_Signatures = nullptr;
Precacher* g_precacher = nullptr;
DatabaseManager* g_dbManager = nullptr;
MenuManager* g_MenuManager = nullptr;
ResourceMonitor* g_ResourceMonitor = nullptr;
Patches* g_Patches = nullptr;
CallStack* g_callStack = nullptr;
EventManager* eventManager = nullptr;
HTTPManager* g_httpManager = nullptr;
UserMessages* g_userMessages = nullptr;
SDKAccess* g_sdk = nullptr;
ConvarQuery* g_cvarQuery = nullptr;
PluginMisc* g_misc = nullptr;
VoiceManager g_voiceManager;

//////////////////////////////////////////////////////////////
/////////////////          Core Class          //////////////
////////////////////////////////////////////////////////////

PLUGIN_EXPOSE(Swiftly, g_Plugin);
bool Swiftly::Load(PluginId id, ISmmAPI* ismm, char* error, size_t maxlen, bool late)
{
    PLUGIN_SAVEVARS();

    g_SMAPI->AddListener(this, this);

#if _WIN32
    auto hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            dwMode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }

        FILE* fp;

        if(freopen_s(&fp, "CONOUT$", "w", stdout) == 0)
            setvbuf(stdout, NULL, _IONBF, 0);
    }
#endif

    GET_V_IFACE_CURRENT(GetEngineFactory, engine, IVEngineServer, INTERFACEVERSION_VENGINESERVER);
    GET_V_IFACE_CURRENT(GetEngineFactory, icvar, ICvar, CVAR_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetServerFactory, server, ISource2Server, INTERFACEVERSION_SERVERGAMEDLL);
    GET_V_IFACE_ANY(GetServerFactory, gameclients, IServerGameClients, INTERFACEVERSION_SERVERGAMECLIENTS);
    GET_V_IFACE_ANY(GetServerFactory, g_clientsManager, IServerGameClients, INTERFACEVERSION_SERVERGAMECLIENTS);
    GET_V_IFACE_ANY(GetEngineFactory, g_pNetworkServerService, INetworkServerService, NETWORKSERVERSERVICE_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetEngineFactory, g_pNetworkMessages, INetworkMessages, NETWORKMESSAGES_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetServerFactory, g_pSource2GameEntities, ISource2GameEntities, SOURCE2GAMEENTITIES_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetFileSystemFactory, g_pFullFileSystem, IFileSystem, FILESYSTEM_INTERFACE_VERSION);
    GET_V_IFACE_CURRENT(GetEngineFactory, g_pGameResourceService, IGameResourceService, GAMERESOURCESERVICESERVER_INTERFACE_VERSION);
    GET_V_IFACE_CURRENT(GetEngineFactory, g_pGameEventSystem, IGameEventSystem, GAMEEVENTSYSTEM_INTERFACE_VERSION);
    GET_V_IFACE_CURRENT(GetEngineFactory, g_pSchemaSystem2, CSchemaSystem, SCHEMASYSTEM_INTERFACE_VERSION);
    GET_V_IFACE_CURRENT(GetEngineFactory, g_pNetworkSystem, INetworkSystem, NETWORKSYSTEM_INTERFACE_VERSION);

    SH_ADD_HOOK_MEMFUNC(IServerGameDLL, GameFrame, server, this, &Swiftly::Hook_GameFrame, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientDisconnect, gameclients, this, &Swiftly::Hook_ClientDisconnect, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, OnClientConnected, gameclients, this, &Swiftly::Hook_OnClientConnected, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientConnect, gameclients, this, &Swiftly::Hook_ClientConnect, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientCommand, gameclients, this, &Swiftly::Hook_OnClientCommand, false);
    SH_ADD_HOOK_MEMFUNC(INetworkServerService, StartupServer, g_pNetworkServerService, this, &Swiftly::Hook_StartupServer, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameDLL, GameServerSteamAPIActivated, server, this, &Swiftly::Hook_GameServerSteamAPIActivated, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameDLL, GameServerSteamAPIDeactivated, server, this, &Swiftly::Hook_GameServerSteamAPIDeactivated, false);
    SH_ADD_HOOK_MEMFUNC(ISource2GameEntities, CheckTransmit, g_pSource2GameEntities, this, &Swiftly::Hook_CheckTransmit, true);

    g_pCVar = icvar;

    ConVar_Register(FCVAR_RELEASE | FCVAR_SERVER_CAN_EXECUTE | FCVAR_CLIENT_CAN_EXECUTE | FCVAR_GAMEDLL);

    if (!BeginCrashListener())
        PRINTRET("Crash Reporter failed to initialize.\n", false);

    g_httpManager = new HTTPManager();
    g_pluginManager = new PluginManager();
    g_Config = new Configuration();
    g_conFilter = new ConsoleFilter();
    g_Signatures = new Signatures();
    g_Offsets = new Offsets();
    g_Patches = new Patches();
    g_playerManager = new PlayerManager();
    g_Logger = new Logger();
    g_translations = new Translations();
    g_precacher = new Precacher();
    g_commandsManager = new CommandsManager();
    g_dbManager = new DatabaseManager();
    g_MenuManager = new MenuManager();
    g_ResourceMonitor = new ResourceMonitor();
    g_callStack = new CallStack();
    eventManager = new EventManager();
    g_userMessages = new UserMessages();
    g_sdk = new SDKAccess();
    g_cvarQuery = new ConvarQuery();
    g_misc = new PluginMisc();

    if (g_Config->LoadConfiguration())
        PRINT("The configurations has been succesfully loaded.\n");
    else
        PRINTRET("Failed to load configurations. The plugin will not work.\n", false);

    g_Logger->AddLogger("core", false);

    g_sdk->LoadSDKData();
    g_Config->LoadPluginConfigurations();
    g_Signatures->LoadSignatures();
    g_Offsets->LoadOffsets();
    g_Patches->LoadPatches();
    g_Patches->PerformPatches();

    g_dbManager->LoadDatabases();

    g_addons.LoadAddons();
    g_addons.Initialize();
    g_userMessages->Initialize();
    eventManager->Initialize();
    g_cvarQuery->Initialize();
    g_misc->Initialize();
    g_playerChat.Initialize();
    g_EntityListener.Initialize();

    if (!InitializeHooks())
        PRINTRET("Hooks failed to initialize.\n", false)
    else
        PRINT("Hooks initialized succesfully.\n");

    g_conFilter->LoadFilters();
    g_translations->LoadTranslations();

    if (g_Config->FetchValue<bool>("core.console_filtering"))
        g_conFilter->Toggle();

    g_pluginManager->LoadPlugins("");
    g_pluginManager->StartPlugins();

    if (late)
    {
        g_SteamAPI.Init();
        g_http = g_SteamAPI.SteamHTTP();
        g_httpManager->ProcessPendingHTTPRequests();
        m_CallbackDownloadItemResult.Register(this, &Swiftly::OnAddonDownloaded);
    }

    g_addons.SetupThread();

    g_voiceManager.OnAllInitialized();

    PRINT("Succesfully started.\n");

    return true;
}

void Swiftly::Hook_GameServerSteamAPIActivated()
{
    if (!CommandLine()->HasParm("-dedicated") || g_SteamAPI.SteamUGC())
        return;

    g_SteamAPI.Init();
    g_http = g_SteamAPI.SteamHTTP();
    g_httpManager->ProcessPendingHTTPRequests();
    m_CallbackDownloadItemResult.Register(this, &Swiftly::OnAddonDownloaded);

    std::thread([&]() -> void
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));

            if (g_addons.GetStatus())
                g_addons.RefreshAddons(true); })
        .detach();

    RETURN_META(MRES_IGNORED);
}

void Swiftly::Hook_GameServerSteamAPIDeactivated()
{
    g_http = nullptr;

    RETURN_META(MRES_IGNORED);
}

void Swiftly::OnAddonDownloaded(DownloadItemResult_t* pResult)
{
    g_addons.OnAddonDownloaded(pResult);
}

void Swiftly::AllPluginsLoaded()
{
}

bool Swiftly::Unload(char* error, size_t maxlen)
{
    g_addons.Destroy();
    g_voiceManager.OnShutdown();
    g_userMessages->Destroy();
    g_cvarQuery->Destroy();
    g_misc->Destroy();
    g_playerChat.Destroy();

    g_pluginManager->StopPlugins(false);
    g_pluginManager->UnloadPlugins();

    UnloadHooks();
    eventManager->Shutdown();

    g_EntityListener.Destroy();
    SH_REMOVE_HOOK_MEMFUNC(IServerGameDLL, GameFrame, server, this, &Swiftly::Hook_GameFrame, true);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientDisconnect, gameclients, this, &Swiftly::Hook_ClientDisconnect, true);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, OnClientConnected, gameclients, this, &Swiftly::Hook_OnClientConnected, false);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientConnect, gameclients, this, &Swiftly::Hook_ClientConnect, false);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientCommand, gameclients, this, &Swiftly::Hook_OnClientCommand, false);
    SH_REMOVE_HOOK_MEMFUNC(INetworkServerService, StartupServer, g_pNetworkServerService, this, &Swiftly::Hook_StartupServer, true);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameDLL, GameServerSteamAPIActivated, server, this, &Swiftly::Hook_GameServerSteamAPIActivated, false);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameDLL, GameServerSteamAPIDeactivated, server, this, &Swiftly::Hook_GameServerSteamAPIDeactivated, false);
    SH_REMOVE_HOOK_MEMFUNC(ISource2GameEntities, CheckTransmit, g_pSource2GameEntities, this, &Swiftly::Hook_CheckTransmit, true);

    ConVar_Unregister();
    return true;
}

std::string currentMap = "None";

void Swiftly::OnLevelInit(char const* pMapName, char const* pMapEntities, char const* pOldLevel, char const* pLandmarkName, bool loadGame, bool background)
{
    if (!g_precacher->GetSoundsPrecached())
    {
        g_precacher->CacheSounds();
        g_precacher->SetSoundsPrecached(true);
    }

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnMapLoad", encoders::msgpack::SerializeToString({ pMapName }), event);
    delete event;

    currentMap = pMapName;
}

void Swiftly::OnLevelShutdown()
{
    g_precacher->Reset();
    g_translations->LoadTranslations();
    g_Config->LoadPluginConfigurations();

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnMapUnload", encoders::msgpack::SerializeToString({ currentMap }), event);
    delete event;
}

void Swiftly::Hook_StartupServer(const GameSessionConfiguration_t& config, ISource2WorldSession*, const char*)
{
    g_ClientsPendingAddon.RemoveAll();

    if (g_addons.GetStatus())
        g_addons.RefreshAddons();
}

void Swiftly::UpdatePlayers()
{
    PERF_RECORD("UpdatePlayers", "core")

    // Credits to: https://github.com/Source2ZE/ServerListPlayersFix (Source2ZE Team)
    if (!engine->GetServerGlobals() || !g_SteamAPI.SteamGameServer())
        return;

    for (int i = 0; i < engine->GetServerGlobals()->maxClients; i++)
    {
        auto steamId = engine->GetClientSteamID(CPlayerSlot(i));
        if (steamId)
        {
            auto controller = (CBasePlayerController*)g_pEntitySystem->GetEntityInstance(CEntityIndex(i + 1));
            if (controller)
                g_SteamAPI.SteamGameServer()->BUpdateUserData(*steamId, controller->m_iszPlayerName(), gameclients->GetPlayerScore(CPlayerSlot(i)));
        }
    }
}

struct GameFrameMsgPackCache
{
    bool simulating;
    bool bFirstTick;
    bool bLastTick;
};

PluginEvent* gameFrameEvent = nullptr;
std::string gameFramePack;
GameFrameMsgPackCache gameFrameCache = {
    false,
    false,
    false,
};

void Swiftly::Hook_GameFrame(bool simulating, bool bFirstTick, bool bLastTick)
{
    PERF_RECORD("GameFrame", "core")

    static double g_flNextUpdate = 0.0;
    uint64_t time = GetTime();

    //////////////////////////////////////////////////////////////
    /////////////////         Server List          //////////////
    ////////////////////////////////////////////////////////////

    double curtime = Plat_FloatTime();
    if (curtime > g_flNextUpdate)
    {
        // Credits to: https://github.com/Source2ZE/ServerListPlayersFix (Source2ZE Team)
        UpdatePlayers();

        g_flNextUpdate = curtime + 5.0;
    }

    //////////////////////////////////////////////////////////////
    /////////////////         Game Event           //////////////
    ////////////////////////////////////////////////////////////
    if (gameFrameCache.bFirstTick != bFirstTick || gameFrameCache.bLastTick != bLastTick || gameFrameCache.simulating != simulating || gameFrameEvent == nullptr)
    {
        gameFramePack = encoders::msgpack::SerializeToString({ simulating, bFirstTick, bLastTick });

        gameFrameCache.bFirstTick = bFirstTick;
        gameFrameCache.bLastTick = bLastTick;
        gameFrameCache.simulating = simulating;
        if (gameFrameEvent == nullptr)
            gameFrameEvent = new PluginEvent("core", nullptr, nullptr);
    }
    g_pluginManager->ExecuteEvent("core", "OnGameTick", gameFramePack, gameFrameEvent);

    //////////////////////////////////////////////////////////////
    /////////////////            Player            //////////////
    ////////////////////////////////////////////////////////////
    for(std::size_t i = 0; i < g_Players.size(); i++)
    {
        Player* player = g_Players[i];
        CBasePlayerPawn* pawn = player->GetPawn();
        if (!pawn)
            continue;

        player->SetButtons(pawn->m_pMovementServices()->m_nButtons().m_pButtonStates()[0]);

        if (player->HasMenuShown())
            player->RenderMenu();
        else if (player->HasCenterText())
            player->RenderCenterText(time);
    }

    //////////////////////////////////////////////////////////////
    /////////////////         Next Frames          //////////////
    ////////////////////////////////////////////////////////////
    while (!m_nextFrame.empty())
    {
        auto pair = m_nextFrame.front();
        pair.first(pair.second);
        m_nextFrame.pop_front();
    }
}

//////////////////////////////////////////////////////////////
/////////////////        Check Transmit        //////////////
///////////////// May God rest our CPU usage  //////////////
///////////////////////////////////////////////////////////

PluginEvent* checktransmitEvent = nullptr;

void Swiftly::Hook_CheckTransmit(CCheckTransmitInfo** ppInfoList, int infoCount, CBitVec<16384>& unionTransmitEdicts, const Entity2Networkable_t** pNetworkables, const uint16* pEntityIndicies, int nEntities, bool bEnablePVSBits)
{
    if (!g_pGameEntitySystem)
        return;

    if(!checktransmitEvent)
        checktransmitEvent = new PluginEvent("core", nullptr, nullptr);

    static int offset = g_Offsets->GetOffset("CheckTransmitPlayerSlot");

    for (int i = 0; i < infoCount; i++)
    {
        auto& pInfo = ppInfoList[i];
        int playerid = (int)*((uint8*)pInfo + offset);
        Player* player = g_playerManager->GetPlayer(playerid);
        if(!player) continue;

        g_pluginManager->ExecuteEvent("core", "OnPlayerCheckTransmit", encoders::msgpack::SerializeToString({ playerid, string_format("%p", pInfo) }), checktransmitEvent);
    }
}

void Swiftly::Hook_ClientDisconnect(CPlayerSlot slot, ENetworkDisconnectionReason reason, const char* pszName, uint64 xuid, const char* pszNetworkID)
{
    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnClientDisconnect", encoders::msgpack::SerializeToString({ slot.Get() }), event);

    Player* player = g_playerManager->GetPlayer(slot);
    if (player) {
        auto it = std::find(g_Players.begin(), g_Players.end(), player);
        if(it != g_Players.end()) g_Players.erase(it);
        g_playerManager->UnregisterPlayer(slot);
    }
}

void Swiftly::Hook_OnClientConnected(CPlayerSlot slot, const char* pszName, uint64 xuid, const char* pszNetworkID, const char* pszAddress, bool bFakePlayer)
{
    if (bFakePlayer)
    {
        Player* player = new Player(true, slot.Get(), pszName, 0, "127.0.0.1");
        g_playerManager->RegisterPlayer(player);
    }
    else {
        if(g_Config->FetchValue<bool>("core.use_player_language"))
            g_cvarQuery->QueryCvarClient(slot, "cl_language");
    }
}

bool Swiftly::Hook_ClientConnect(CPlayerSlot slot, const char* pszName, uint64 xuid, const char* pszNetworkID, bool unk1, CBufferString* pRejectReason)
{
    if (!g_addons.OnClientConnect(xuid))
        RETURN_META_VALUE(MRES_IGNORED, true);

    std::string ip_address = explode(pszNetworkID, ":")[0];
    Player* player = new Player(false, slot.Get(), pszName, xuid, ip_address);
    g_playerManager->RegisterPlayer(player);
    g_Players.push_back(player);

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnClientConnect", encoders::msgpack::SerializeToString({ slot.Get() }), event);

    bool response = true;
    try
    {
        response = std::any_cast<bool>(event->GetReturnValue());
    }
    catch (std::bad_any_cast& e)
    {
        response = true;
    }
    delete event;

    if (!response)
        RETURN_META_VALUE(MRES_SUPERCEDE, false);

    RETURN_META_VALUE(MRES_IGNORED, true);
}

bool OnClientCommand(int playerid, std::string command);

void Swiftly::Hook_OnClientCommand(CPlayerSlot slot, const CCommand& cmd)
{
    if (!OnClientCommand(slot.Get(), cmd.GetCommandString()))
        RETURN_META(MRES_SUPERCEDE);

    RETURN_META(MRES_IGNORED);
}

void Swiftly::NextFrame(std::function<void(std::vector<std::any>)> fn, std::vector<std::any> param)
{
    m_nextFrame.push_back({ fn, param });
}

bool Swiftly::Pause(char* error, size_t maxlen)
{
    return true;
}

bool Swiftly::Unpause(char* error, size_t maxlen)
{
    return true;
}

const char* Swiftly::GetLicense()
{
    return "MIT License";
}

const char* Swiftly::GetVersion()
{
#ifndef SWIFTLY_VERSION
    return "Local";
#else
    return (std::string("v") + std::string(SWIFTLY_VERSION)).c_str();
#endif
}

const char* Swiftly::GetDate()
{
    return __DATE__;
}

const char* Swiftly::GetLogTag()
{
    return "SWIFTLY";
}

const char* Swiftly::GetAuthor()
{
    return "Swiftly Development Team";
}

const char* Swiftly::GetDescription()
{
    return "Swiftly - Framework";
}

const char* Swiftly::GetName()
{
    return "Swiftly";
}

const char* Swiftly::GetURL()
{
    return "https://github.com/swiftly-solution/swiftly";
}