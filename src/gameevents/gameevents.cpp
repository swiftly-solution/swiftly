#include "gameevents.h"
#include "GGameEvents.h"
#include "../hooks/FuncHook.h"
#include "../plugins/core/scripting.h"
#include "../plugins/PluginManager.h"
#include "../player/PlayerManager.h"

#include <vector>
#include <msgpack.hpp>
#include <sstream>
#include <map>
#include <stack>

SH_DECL_HOOK2(IGameEventManager2, FireEvent, SH_NOATTRIB, 0, bool, IGameEvent *, bool);
FuncHook<decltype(Hook_CGameEventManager_Init)> TCGameEventManager_Init(Hook_CGameEventManager_Init, "CGameEventManager_Init");

EventManager *eventManager = nullptr;
std::stack<IGameEvent*> dupEvents;

void Hook_CGameEventManager_Init(IGameEventManager2 *pGameEventManager)
{
    g_gameEventManager = pGameEventManager;
    TCGameEventManager_Init(pGameEventManager);

    PLUGIN_PRINT("Game Events", "Loading game events...\n");
    RegisterEventListeners();
    PLUGIN_PRINTF("Game Events", "%d game events have been succesfully loaded.\n", gameEventsRegister.size());
}

void RegisterEventListeners()
{
    if (!g_gameEventManager)
        return;

    if (!eventManager)
        eventManager = new EventManager();

    eventManager->Initialize();
}

void UnregisterEventListeners()
{
    if (!g_gameEventManager)
        return;

    eventManager->Shutdown();
}

void EventManager::Initialize()
{
    SH_ADD_HOOK(IGameEventManager2, FireEvent, g_gameEventManager, SH_MEMBER(this, &EventManager::OnFireEvent), false);
    SH_ADD_HOOK(IGameEventManager2, FireEvent, g_gameEventManager, SH_MEMBER(this, &EventManager::OnPostFireEvent), true);

    for (auto it = gameEventsRegister.begin(); it != gameEventsRegister.end(); ++it)
    {
        if (!g_gameEventManager->FindListener(this, it->first.c_str()))
            g_gameEventManager->AddListener(this, it->first.c_str(), true);
    }
}

void EventManager::Shutdown()
{
    SH_REMOVE_HOOK(IGameEventManager2, FireEvent, g_gameEventManager, SH_MEMBER(this, &EventManager::OnFireEvent), false);
    SH_REMOVE_HOOK(IGameEventManager2, FireEvent, g_gameEventManager, SH_MEMBER(this, &EventManager::OnPostFireEvent), true);

    g_gameEventManager->RemoveListener(this);
}

void EventManager::FireGameEvent(IGameEvent *pEvent) {}

std::string emptyEventData = "";
bool setEmptyEventdata = false;

bool EventManager::OnFireEvent(IGameEvent *pEvent, bool bDontBroadcast)
{
    if (!pEvent)
    {
        RETURN_META_VALUE(MRES_IGNORED, false);
    }

    std::string eventName = pEvent->GetName();

    if (gameEventsRegister.find(eventName) != gameEventsRegister.end())
    {
        std::string prettyEventName = gameEventsRegister.at(eventName);

        if (!setEmptyEventdata)
        {
            setEmptyEventdata = true;

            std::stringstream ss;
            std::vector<msgpack::object> eventData;

            msgpack::pack(ss, eventData);
            emptyEventData = ss.str();
        }

        PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
        EventResult result = g_pluginManager->ExecuteEvent("core", prettyEventName, emptyEventData, event);
        delete event;
        if (prettyEventName == "OnPlayerSpawn")
        {
            auto slot = pEvent->GetPlayerSlot("userid");
            Player *player = g_playerManager->GetPlayer(slot);
            if (player)
                player->SetFirstSpawn(false);
        }
        if (result != EventResult::Continue)
        {
            dupEvents.push(g_gameEventManager->DuplicateEvent(pEvent));
            g_gameEventManager->FreeEvent(pEvent);
            RETURN_META_VALUE(MRES_SUPERCEDE, false);
        }
    }

    dupEvents.push(g_gameEventManager->DuplicateEvent(pEvent));
    RETURN_META_VALUE(MRES_IGNORED, true);
}

bool EventManager::OnPostFireEvent(IGameEvent *pEvent, bool bDontBroadcast)
{
    if (!pEvent)
    {
        RETURN_META_VALUE(MRES_IGNORED, false);
    }

    IGameEvent* realGameEvent = dupEvents.top();

    std::string eventName = realGameEvent->GetName();

    if (gameEventsRegister.find(eventName) != gameEventsRegister.end())
    {
        std::string prettyEventName = gameEventsRegister.at(eventName);

        if (!setEmptyEventdata)
        {
            setEmptyEventdata = true;

            std::stringstream ss;
            std::vector<msgpack::object> eventData;

            msgpack::pack(ss, eventData);
            emptyEventData = ss.str();
        }

        PluginEvent *event = new PluginEvent("core", realGameEvent, nullptr);
        EventResult result = g_pluginManager->ExecuteEvent("core", string_format("OnPost%s", prettyEventName.substr(2).c_str()), emptyEventData, event);
        delete event;

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