#ifndef _common_h
#define _common_h

#pragma warning(disable : 4005)
#pragma warning(disable : 4267)

#define META_IS_SOURCE2 1
#define MAX_PLAYERS 64

#include <public/playerslot.h>
#include <ISmmPlugin.h>
#include <iplayerinfo.h>
#include <sh_vector.h>
#include <functional>
#include <map>
#include <string>
#include <vector>
#include <igameevents.h>
#include "iserver.h"
#include "KeyValues.h"
#include <entity2/entitysystem.h>
#include <entity2/entityidentity.h>
#include <ctime>
#include "utils.h"

#ifdef _WIN32
#define CONFIG_PATH "addons/swiftly/configs"
#else
#define CONFIG_PATH "addons/swiftly/configs"
#endif

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

public:
    void Hook_StartupServer(const GameSessionConfiguration_t &config, ISource2WorldSession *, const char *);
    void Hook_GameFrame(bool simulating, bool bFirstTick, bool bLastTick);
    void Hook_ClientActive(CPlayerSlot slot, bool bLoadGame, const char *pszName, uint64 xuid);
    void Hook_ClientDisconnect(CPlayerSlot slot, int reason, const char *pszName, uint64 xuid, const char *pszNetworkID);
    void Hook_ClientPutInServer(CPlayerSlot slot, char const *pszName, int type, uint64 xuid);
    void Hook_ClientSettingsChanged(CPlayerSlot slot);
    void Hook_OnClientConnected(CPlayerSlot slot, const char *pszName, uint64 xuid, const char *pszNetworkID, const char *pszAddress, bool bFakePlayer);
    bool Hook_ClientConnect(CPlayerSlot slot, const char *pszName, uint64 xuid, const char *pszNetworkID, bool unk1, CBufferString *pRejectReason);
    void Hook_ClientCommand(CPlayerSlot nSlot, const CCommand &_cmd);

public:
    const char *GetAuthor();
    const char *GetName();
    const char *GetDescription();
    const char *GetURL();
    const char *GetLicense();
    const char *GetVersion();
    const char *GetDate();
    const char *GetLogTag();
};

extern SwiftlyPlugin g_Plugin;
extern IVEngineServer2 *engine;
extern IServerGameClients *g_clientsManager;
extern CEntitySystem *g_pEntitySystem;
extern IServerGameDLL *server;

PLUGIN_GLOBALVARS();

#endif