#ifndef _gameevents_h
#define _gameevents_h

#include "../../common.h"
#include "../../entrypoint.h"
#include <utlvector.h>
#include <set>

typedef void (*FnEventListenerCallback)(IGameEvent* event);

class EventManager : public IGameEventListener2
{
private:
    std::set<std::string> enqueueListenEvents;
    bool loadedGameEvents = false;
public:
    EventManager() = default;
    ~EventManager() = default;

    void Initialize();
    void Shutdown();
    void RegisterGameEvents();
    void RegisterGameEventListen(std::string ev_name);

    void FireGameEvent(IGameEvent* pEvent) override;
    bool OnFireEvent(IGameEvent* pEvent, bool bDontBroadcast);
    bool OnPostFireEvent(IGameEvent* pEvent, bool bDontBroadcast);

    int LoadEventsFromFile(const char* filePath, bool searchAll);
};

extern EventManager* eventManager;

#endif