#ifndef _gameevents_h
#define _gameevents_h

#include "../common.h"
#include "../entrypoint.h"
#include <utlvector.h>

typedef void (*FnEventListenerCallback)(IGameEvent* event);

class EventManager : public IGameEventListener2
{
public:
    EventManager() = default;
    ~EventManager() = default;

    void Initialize();
    void Shutdown();
    void RegisterGameEvents();

    void FireGameEvent(IGameEvent* pEvent) override;
    bool OnFireEvent(IGameEvent* pEvent, bool bDontBroadcast);
    bool OnPostFireEvent(IGameEvent* pEvent, bool bDontBroadcast);

    int LoadEventsFromFile(const char* filePath, bool searchAll);
};

extern EventManager* eventManager;

#endif