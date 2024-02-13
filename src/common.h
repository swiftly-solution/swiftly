#ifndef _common_h
#define _common_h

#ifdef _MSC_VER
#pragma warning(disable : 4005)
#pragma warning(disable : 4267)
#endif

#define META_IS_SOURCE2 1
#define MAX_PLAYERS 64

#define SITE_A 0
#define SITE_B 1
#define SITE_UNKNOWN 2

#include <public/playerslot.h>
#include <public/inetchannelinfo.h>
#include <ISmmPlugin.h>
#include <iplayerinfo.h>
#include <sh_vector.h>
#include <igameevents.h>
#include "iserver.h"
#include "KeyValues.h"
#include <entity2/entitysystem.h>
#include <entity2/entityidentity.h>
#include "utils.h"
#include <networksystem/inetworkserializer.h>
#include <networksystem/inetworkmessages.h>
#include <engine/igameeventsystem.h>

#include <deque>
#include <functional>

#define PATH "addons/swiftly"

class CGameRules;

class GameSessionConfiguration_t
{
};

class SwiftlyPlugin : public ISmmPlugin, public IMetamodListener
{
public:
    bool Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late);
    bool Unload(char *error, size_t maxlen);
    bool Pause(char *error, size_t maxlen);
    bool Unpause(char *error, size_t maxlen);
    void AllPluginsLoaded();
    void OnLevelInit(char const *pMapName, char const *pMapEntities, char const *pOldLevel, char const *pLandmarkName, bool loadGame, bool background);
    void OnLevelShutdown();
    void NextFrame(std::function<void()> fn);

    std::string GetMap();

public:
    void Hook_StartupServer(const GameSessionConfiguration_t &config, ISource2WorldSession *, const char *);
    void Hook_GameFrame(bool simulating, bool bFirstTick, bool bLastTick);
    void Hook_ClientActive(CPlayerSlot slot, bool bLoadGame, const char *pszName, uint64 xuid);
    void Hook_ClientDisconnect(CPlayerSlot slot, ENetworkDisconnectionReason reason, const char *pszName, uint64 xuid, const char *pszNetworkID);
    void Hook_ClientSettingsChanged(CPlayerSlot slot);
    void Hook_OnClientConnected(CPlayerSlot slot, const char *pszName, uint64 xuid, const char *pszNetworkID, const char *pszAddress, bool bFakePlayer);
    bool Hook_ClientConnect(CPlayerSlot slot, const char *pszName, uint64 xuid, const char *pszNetworkID, bool unk1, CBufferString *pRejectReason);
    void Hook_ClientCommand(CPlayerSlot nSlot, const CCommand &_cmd);
    void Hook_DispatchConCommand(ConCommandHandle cmd, const CCommandContext &ctx, const CCommand &args);
    void Hook_GameServerSteamAPIActivated();

public:
    const char *GetAuthor();
    const char *GetName();
    const char *GetDescription();
    const char *GetURL();
    const char *GetLicense();
    const char *GetVersion();
    const char *GetDate();
    const char *GetLogTag();

public:
    std::deque<std::function<void()>> m_nextFrame;
};

class CEntityListener : public IEntityListener
{
    void OnEntitySpawned(CEntityInstance *pEntity) override;
    void OnEntityParentChanged(CEntityInstance *pEntity, CEntityInstance *pNewParent) override;
};

extern SwiftlyPlugin g_Plugin;
extern IVEngineServer2 *engine;
extern IServerGameClients *g_clientsManager;
extern CEntitySystem *g_pEntitySystem;
extern IServerGameDLL *server;
extern ICvar *g_pcVar;
extern CGameRules *g_pGameRules;
extern INetworkMessages *g_pNetworkMessages;

PLUGIN_GLOBALVARS();

template <typename... T>
void PrintToClientOrConsole(CPlayerSlot *slot, std::string category, std::string message, T... args)
{
    if (slot->Get() == -1)
        PRINTF(category, message, args...);
    else
        CLIENT_PRINTF(*slot, category, message, args...);
}

bool ends_with(std::string value, std::string ending);
bool starts_with(std::string value, std::string starting);
std::string str_tolower(std::string s);
std::string replace(std::string str, const std::string from, const std::string to);
uint64_t GetTime();

enum PluginType_t : uint16_t
{
    PLUGIN_CPP = 1,
    PLUGIN_LUA = 2,
};

#endif