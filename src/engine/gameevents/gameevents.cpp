#include "gameevents.h"

#include <utils/common.h>
#include <sdk/game.h>
#include <memory/encoders/json.h>
#include <filesystem/files/files.h>
#include <embedder/src/Embedder.h>
#include <plugins/manager.h>
#include <engine/vgui/vgui.h>
#include <server/player/manager.h>

#include <dynlibutils/module.h>
#include <rapidjson/json.hpp>
#include <any>

#include <stack>

extern std::map<std::string, std::string> gameEventsRegister;

SH_DECL_EXTERN3_void(INetworkServerService, StartupServer, SH_NOATTRIB, 0, const GameSessionConfiguration_t&, ISource2WorldSession*, const char*);

SH_DECL_HOOK2(IGameEventManager2, FireEvent, SH_NOATTRIB, 0, bool, IGameEvent*, bool);
SH_DECL_HOOK2(IGameEventManager2, LoadEventsFromFile, SH_NOATTRIB, 0, int, const char*, bool);
int loadEventFromFileHookID = -1;

DynLibUtils::CModule DetermineModuleByLibrary(std::string library);

std::stack<IGameEvent*> dupEvents;

void EventManager::Initialize()
{
    std::string game_name = GetGameName();

    if (game_name == "unknown")
    {
        PRINT("Unknown game detected, not loading any game events.\n");
        return;
    }

    auto j = encoders::json::FromString(Files::Read("addons/swiftly/gamedata/" + game_name + "/gameevents.json"), "addons/swiftly/gamedata/" + game_name + "/gameevents.json");
    if (!j.IsObject())
        return;

    for (auto it = j.MemberBegin(); it != j.MemberEnd(); ++it)
    {
        std::string eventRawName = it->name.GetString();
        std::string eventProcessedName = it->value.GetString();
        gameEventsRegister.insert({ eventRawName, eventProcessedName });
    }

    PRINTF("Succesfully loaded %lld Game Events from files.\n", gameEventsRegister.size());

    DynLibUtils::CModule servermodule = DetermineModuleByLibrary("server");
    auto CGameEventManagerVTable = servermodule.GetVirtualTableByName("CGameEventManager");
    loadEventFromFileHookID = SH_ADD_DVPHOOK(IGameEventManager2, LoadEventsFromFile, (IGameEventManager2*)((void*)CGameEventManagerVTable), SH_MEMBER(this, &EventManager::LoadEventsFromFile), false);
}

void EventManager::RegisterGameEvents()
{
    PLUGIN_PRINT("Game Events", "Loading game events...\n");
    for (auto it = enqueueListenEvents.begin(); it != enqueueListenEvents.end(); ++it)
    {
        std::string ev = *(it);
        if (!g_gameEventManager->FindListener(this, ev.c_str()))
            g_gameEventManager->AddListener(this, ev.c_str(), true);
    }

    if (!g_gameEventManager->FindListener(this, "player_spawn"))
        g_gameEventManager->AddListener(this, "player_spawn", true);

    PLUGIN_PRINT("Game Events", "Game events have been succesfully loaded.\n");
    loadedGameEvents = true;
}

void EventManager::RegisterGameEventListen(std::string ev_name)
{
    std::string raw_ev = "";

    for (auto it = gameEventsRegister.begin(); it != gameEventsRegister.end(); ++it)
    {
        if (it->second == ev_name)
        {
            raw_ev = it->first;
            break;
        }
    }

    if (raw_ev == "")
        return;

    if (!loadedGameEvents)
    {
        if (enqueueListenEvents.find(raw_ev) == enqueueListenEvents.end())
            enqueueListenEvents.insert(raw_ev);
    }
    else
    {
        if (!g_gameEventManager->FindListener(this, raw_ev.c_str()))
            g_gameEventManager->AddListener(this, raw_ev.c_str(), true);
    }
}

int EventManager::LoadEventsFromFile(const char* filePath, bool searchAll)
{
    if (!g_gameEventManager)
    {
        g_gameEventManager = META_IFACEPTR(IGameEventManager2);

        SH_ADD_HOOK(IGameEventManager2, FireEvent, g_gameEventManager, SH_MEMBER(this, &EventManager::OnFireEvent), false);
        SH_ADD_HOOK(IGameEventManager2, FireEvent, g_gameEventManager, SH_MEMBER(this, &EventManager::OnPostFireEvent), true);
        SH_ADD_HOOK(INetworkServerService, StartupServer, g_pNetworkServerService, SH_MEMBER(this, &EventManager::StartupServer), true);
    }

    RETURN_META_VALUE(MRES_IGNORED, 0);
}

void EventManager::Shutdown()
{
    SH_REMOVE_HOOK(IGameEventManager2, FireEvent, g_gameEventManager, SH_MEMBER(this, &EventManager::OnFireEvent), false);
    SH_REMOVE_HOOK(IGameEventManager2, FireEvent, g_gameEventManager, SH_MEMBER(this, &EventManager::OnPostFireEvent), true);
    SH_REMOVE_HOOK(INetworkServerService, StartupServer, g_pNetworkServerService, SH_MEMBER(this, &EventManager::StartupServer), true);
    SH_REMOVE_HOOK_ID(loadEventFromFileHookID);

    g_gameEventManager->RemoveListener(this);
}

void EventManager::StartupServer(const GameSessionConfiguration_t& config, ISource2WorldSession*, const char*)
{
    RegisterGameEvents();
}

void EventManager::FireGameEvent(IGameEvent* pEvent) {}

bool EventManager::OnFireEvent(IGameEvent* pEvent, bool bDontBroadcast)
{
    if (!pEvent)
    {
        RETURN_META_VALUE(MRES_IGNORED, false);
    }

    std::string eventName = pEvent->GetName();

    bool dontBroadcast = bDontBroadcast;

    std::string prettyEventName = gameEventsRegister[eventName];
    if (!prettyEventName.empty())
    {
        std::map<std::string, std::any> evData = { { "plugin_name", std::string("core") }, { "event_data", pEvent }, { "dontBroadcast", dontBroadcast } };
        auto eventData = new ClassData(evData, "Event", nullptr);

        EventResult result = g_pluginManager.ExecuteEvent("core", prettyEventName, {}, eventData);

        dontBroadcast = eventData->GetDataOr<bool>("dontBroadcast", dontBroadcast);

        delete eventData;

        if (prettyEventName == "OnPlayerSpawn")
        {
            auto slot = pEvent->GetPlayerSlot("userid");
            Player* player = g_playerManager.GetPlayer(slot);
            if (player)
            {
                player->SetFirstSpawn(false);
                // player->EnsureCustomView(1);
            }
        }
        if (result != EventResult::Continue)
        {
            dupEvents.push(g_gameEventManager->DuplicateEvent(pEvent));
            g_gameEventManager->FreeEvent(pEvent);
            RETURN_META_VALUE(MRES_SUPERCEDE, false);
        }
    }

    dupEvents.push(g_gameEventManager->DuplicateEvent(pEvent));

    if (dontBroadcast != bDontBroadcast)
    {
        RETURN_META_VALUE_NEWPARAMS(MRES_IGNORED, true, &IGameEventManager2::FireEvent, (pEvent, dontBroadcast));
    }

    RETURN_META_VALUE(MRES_IGNORED, true);
}

bool EventManager::OnPostFireEvent(IGameEvent* pEvent, bool bDontBroadcast)
{
    if (!pEvent)
    {
        RETURN_META_VALUE(MRES_IGNORED, false);
    }

    IGameEvent* realGameEvent = dupEvents.top();

    std::string eventName = realGameEvent->GetName();

    std::string prettyEventName = gameEventsRegister[eventName];

    if (prettyEventName == "OnRoundStart") {
        g_VGUI.ResetStateOfScreenTexts();

        g_Plugin.RegisterTimeout(100, []() -> void {
            g_VGUI.RegenerateScreenTexts();
        });
    }

    if (!prettyEventName.empty())
    {
        std::map<std::string, std::any> evData = { { "plugin_name", std::string("core") }, { "event_data", realGameEvent }, { "dontBroadcast", bDontBroadcast } };
        auto eventData = new ClassData(evData, "Event", nullptr);

        EventResult result = g_pluginManager.ExecuteEvent("core", string_format("OnPost%s", prettyEventName.substr(2).c_str()), {}, eventData);

        delete eventData;

        if (result != EventResult::Continue) {
            g_gameEventManager->FreeEvent(realGameEvent);
            dupEvents.pop();
            RETURN_META_VALUE(MRES_SUPERCEDE, false);
        }
    }

    g_gameEventManager->FreeEvent(realGameEvent);
    dupEvents.pop();
    RETURN_META_VALUE(MRES_IGNORED, true);
}