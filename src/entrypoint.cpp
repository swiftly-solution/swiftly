#include <stdio.h>
#include "entrypoint.h"

#include <interfaces/interfaces.h>
#include <metamod_oslink.h>

#include <steam/steam_gameserver.h>

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

#ifdef _WIN32
FILE _ioccc[] = {*stdin, *stdout, *stderr};
extern "C" FILE *__cdecl __iob_func(void)
{
    return _ioccc;
}
#endif

Swiftly g_Plugin;
IServerGameDLL *server = nullptr;
IServerGameClients *gameclients = nullptr;
IVEngineServer2 *engine = nullptr;
IServerGameClients *g_clientsManager = nullptr;
ICvar *icvar = nullptr;
IGameResourceService *g_pGameResourceService = nullptr;
CEntitySystem *g_pEntitySystem = nullptr;
CGameEntitySystem *g_pGameEntitySystem = nullptr;
IGameEventManager2 *g_gameEventManager = nullptr;
IGameEventSystem *g_pGameEventSystem = nullptr;
CEntityListener g_entityListener;

class CGameResourceService
{
public:
    CGameEntitySystem *GetGameEntitySystem()
    {
        return *reinterpret_cast<CGameEntitySystem **>((uintptr_t)(this) + WIN_LINUX(88, 80));
    }
};

CGameEntitySystem *GameEntitySystem()
{
    return g_pGameEntitySystem;
}

PLUGIN_EXPOSE(Swiftly, g_Plugin);
bool Swiftly::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
    PLUGIN_SAVEVARS();

    g_SMAPI->AddListener(this, this);

    GET_V_IFACE_CURRENT(GetEngineFactory, engine, IVEngineServer, INTERFACEVERSION_VENGINESERVER);
    GET_V_IFACE_CURRENT(GetEngineFactory, icvar, ICvar, CVAR_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetServerFactory, server, IServerGameDLL, INTERFACEVERSION_SERVERGAMEDLL);
    GET_V_IFACE_ANY(GetServerFactory, gameclients, IServerGameClients, INTERFACEVERSION_SERVERGAMECLIENTS);
    GET_V_IFACE_ANY(GetServerFactory, g_clientsManager, IServerGameClients, INTERFACEVERSION_SERVERGAMECLIENTS);
    GET_V_IFACE_ANY(GetEngineFactory, g_pNetworkServerService, INetworkServerService, NETWORKSERVERSERVICE_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetEngineFactory, g_pNetworkMessages, INetworkMessages, NETWORKMESSAGES_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetFileSystemFactory, g_pFullFileSystem, IFileSystem, FILESYSTEM_INTERFACE_VERSION);
    GET_V_IFACE_CURRENT(GetEngineFactory, g_pGameResourceService, IGameResourceService, GAMERESOURCESERVICESERVER_INTERFACE_VERSION);
    GET_V_IFACE_CURRENT(GetEngineFactory, g_pGameEventSystem, IGameEventSystem, GAMEEVENTSYSTEM_INTERFACE_VERSION);

    SH_ADD_HOOK_MEMFUNC(IServerGameDLL, GameFrame, server, this, &Swiftly::Hook_GameFrame, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientActive, gameclients, this, &Swiftly::Hook_ClientActive, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientDisconnect, gameclients, this, &Swiftly::Hook_ClientDisconnect, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientSettingsChanged, gameclients, this, &Swiftly::Hook_ClientSettingsChanged, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, OnClientConnected, gameclients, this, &Swiftly::Hook_OnClientConnected, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientConnect, gameclients, this, &Swiftly::Hook_ClientConnect, false);
    SH_ADD_HOOK_MEMFUNC(INetworkServerService, StartupServer, g_pNetworkServerService, this, &Swiftly::Hook_StartupServer, true);
    SH_ADD_HOOK_MEMFUNC(ICvar, DispatchConCommand, icvar, this, &Swiftly::Hook_DispatchConCommand, false);

    ConVar_Register(FCVAR_RELEASE | FCVAR_CLIENT_CAN_EXECUTE | FCVAR_SERVER_CAN_EXECUTE | FCVAR_GAMEDLL);

    return true;
}

void Swiftly::AllPluginsLoaded()
{
}

bool Swiftly::Unload(char *error, size_t maxlen)
{
    ConVar_Unregister();
    return true;
}

void Swiftly::OnLevelInit(char const *pMapName, char const *pMapEntities, char const *pOldLevel, char const *pLandmarkName, bool loadGame, bool background)
{
}

void Swiftly::OnLevelShutdown()
{
}

bool bDone = false;
void Swiftly::Hook_StartupServer(const GameSessionConfiguration_t &config, ISource2WorldSession *, const char *)
{
    if (!bDone)
    {
        g_pGameEntitySystem = ((CGameResourceService *)g_pGameResourceService)->GetGameEntitySystem();
        g_pEntitySystem = g_pGameEntitySystem;

        g_pGameEntitySystem->AddListenerEntity(&g_entityListener);

        bDone = true;
    }
}

void Swiftly::Hook_GameFrame(bool simulating, bool bFirstTick, bool bLastTick)
{
    while (!m_nextFrame.empty())
    {
        m_nextFrame.front()();
        m_nextFrame.pop_front();
    }
}

void Swiftly::Hook_ClientActive(CPlayerSlot slot, bool bLoadGame, const char *pszName, uint64 xuid)
{
}

void Swiftly::Hook_ClientDisconnect(CPlayerSlot slot, ENetworkDisconnectionReason reason, const char *pszName, uint64 xuid, const char *pszNetworkID)
{
}

void Swiftly::Hook_ClientSettingsChanged(CPlayerSlot slot)
{
}

void Swiftly::Hook_OnClientConnected(CPlayerSlot slot, const char *pszName, uint64 xuid, const char *pszNetworkID, const char *pszAddress, bool bFakePlayer)
{
}

bool Swiftly::Hook_ClientConnect(CPlayerSlot slot, const char *pszName, uint64 xuid, const char *pszNetworkID, bool unk1, CBufferString *pRejectReason)
{
    RETURN_META_VALUE(MRES_IGNORED, true);
}

void Swiftly::Hook_DispatchConCommand(ConCommandHandle cmd, const CCommandContext &ctx, const CCommand &args)
{
}

void Swiftly::NextFrame(std::function<void()> fn)
{
    m_nextFrame.push_back(fn);
}

void CEntityListener::OnEntitySpawned(CEntityInstance *pEntity)
{
}

void CEntityListener::OnEntityParentChanged(CEntityInstance *pEntity, CEntityInstance *pNewParent)
{
}

void CEntityListener::OnEntityCreated(CEntityInstance *pEntity)
{
}

void CEntityListener::OnEntityDeleted(CEntityInstance *pEntity)
{
}

bool Swiftly::Pause(char *error, size_t maxlen)
{
    return true;
}

bool Swiftly::Unpause(char *error, size_t maxlen)
{
    return true;
}

const char *Swiftly::GetLicense()
{
    return "MIT License";
}

const char *Swiftly::GetVersion()
{
    return "rework";
}

const char *Swiftly::GetDate()
{
    return __DATE__;
}

const char *Swiftly::GetLogTag()
{
    return "SWIFTLY";
}

const char *Swiftly::GetAuthor()
{
    return "Swiftly Development Team";
}

const char *Swiftly::GetDescription()
{
    return "Swiftly - Framework";
}

const char *Swiftly::GetName()
{
    return "Swiftly";
}

const char *Swiftly::GetURL()
{
    return "https://github.com/swiftly-solution/swiftly/tree/rework";
}