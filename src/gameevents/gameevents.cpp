#include "gameevents.h"
#include "GGameEvents.h"
#include "../hooks/FuncHook.h"
#include "../plugins/core/scripting.h"
#include "../plugins/PluginManager.h"

#include <vector>
#include <msgpack.hpp>
#include <sstream>

SH_DECL_HOOK2(IGameEventManager2, FireEvent, SH_NOATTRIB, 0, bool, IGameEvent *, bool);
FuncHook<decltype(Hook_CGameEventManager_Init)> TCGameEventManager_Init(Hook_CGameEventManager_Init, "CGameEventManager_Init");

EventManager *eventManager = nullptr;

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

    for (auto it = gameEventsRegister.begin(); it != gameEventsRegister.end(); ++it)
    {
        if (!g_gameEventManager->FindListener(this, it->first.c_str()))
            g_gameEventManager->AddListener(this, it->first.c_str(), true);
    }
}

void EventManager::Shutdown()
{
    SH_REMOVE_HOOK(IGameEventManager2, FireEvent, g_gameEventManager, SH_MEMBER(this, &EventManager::OnFireEvent), false);

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
        if (result != EventResult::Continue)
        {
            g_gameEventManager->FreeEvent(pEvent);
            RETURN_META_VALUE(MRES_SUPERCEDE, false);
        }
    }

    RETURN_META_VALUE(MRES_IGNORED, true);
}