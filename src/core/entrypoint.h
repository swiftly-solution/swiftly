#ifndef _core_entrypoint_h
#define _core_entrypoint_h

#include <ISmmPlugin.h>
#include <public/igameevents.h>
#include <sh_vector.h>
#include <engine/igameeventsystem.h>
#include <public/networksystem/inetworkmessages.h>
#include <public/entity2/entitysystem.h>
#include <public/iserver.h>
#include <public/steam/steam_api_common.h>
#include <public/steam/isteamugc.h>
#include <functional>
#include <list>

class SwiftlyS2 : public ISmmPlugin, public IMetamodListener
{
private:
	std::list<std::pair<int64_t, std::function<void()>>> timeoutsArray;
	bool processingTimeouts = false;
public:
	bool Load(PluginId id, ISmmAPI* ismm, char* error, size_t maxlen, bool late);
	bool Unload(char* error, size_t maxlen);
	bool Pause(char* error, size_t maxlen);
	bool Unpause(char* error, size_t maxlen);
	void AllPluginsLoaded();

	void Hook_GameServerSteamAPIActivated();
	void Hook_GameServerSteamAPIDeactivated();
	void GameFrame(bool simulate, bool first, bool last);
	void Hook_OnClientCommand(CPlayerSlot slot, const CCommand& cmd);

	void OnLevelInit(char const* pMapName, char const* pMapEntities, char const* pOldLevel, char const* pLandmarkName, bool loadGame, bool background);
	void OnLevelShutdown();

	void RegisterTimeout(int64_t delay, std::function<void()> callback);

public:
	const char* GetAuthor();
	const char* GetName();
	const char* GetDescription();
	const char* GetURL();
	const char* GetLicense();
	const char* GetVersion();
	const char* GetDate();
	const char* GetLogTag();
};

extern SwiftlyS2 g_Plugin;
extern IVEngineServer2* engine;
extern ISource2Server* server;
extern CGameEntitySystem* g_pGameEntitySystem;
extern IGameResourceService* g_pGameResourceService;
extern CEntitySystem* g_pEntitySystem;
extern IGameEventManager2* g_gameEventManager;
extern IGameEventSystem* g_pGameEventSystem;
extern ICvar* g_pcVar;
extern IServerGameClients* gameclients;
extern CSteamGameServerAPIContext g_SteamAPI;
PLUGIN_GLOBALVARS();

#endif