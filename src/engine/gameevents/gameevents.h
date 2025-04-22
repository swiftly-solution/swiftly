#ifndef _engine_gameevents_h
#define _engine_gameevents_h

#include <core/entrypoint.h>
#include <set>
#include <string>

typedef void (*EventListenerCallback)(IGameEvent* event);

class EventManager : public IGameEventListener2
{
private:
    std::set<std::string> enqueueListenEvents;
    bool loadedGameEvents = false;

public:
    void Initialize();
    void Shutdown();
    void RegisterGameEvents();
    void RegisterGameEventListen(std::string ev_name);

    void FireGameEvent(IGameEvent* pEvent) override;
    bool OnFireEvent(IGameEvent* pEvent, bool bDontBroadcast);
    bool OnPostFireEvent(IGameEvent* pEvent, bool bDontBroadcast);

    void StartupServer(const GameSessionConfiguration_t& config, ISource2WorldSession*, const char*);

    int LoadEventsFromFile(const char* filePath, bool searchAll);
};

extern EventManager g_eventManager;

#endif