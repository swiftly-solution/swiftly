#ifndef _gameevents_h
#define _gameevents_h

#include "../common.h"
#include <utlvector.h>

typedef void (*FnEventListenerCallback)(IGameEvent *event);

class CGameEventListener;

extern CUtlVector<CGameEventListener *> g_GameEventListener;

class CGameEventListener : public IGameEventListener2
{
private:
    FnEventListenerCallback callback;
    const char *eventName;

public:
    CGameEventListener(FnEventListenerCallback callback, const char *eventName) : callback(callback), eventName(eventName)
    {
        g_GameEventListener.AddToTail(this);
    }

    void CallEvent(IGameEvent *event)
    {
        callback(event);
    }

    void FireGameEvent(IGameEvent *event) override
    {
        this->CallEvent(event);
    }

    const char *GetName() { return eventName; }
};

void RegisterEventListeners();
void UnregisterEventListeners();

extern IGameEventManager2 *g_gameEventManager;

// Provided from https://github.com/Source2ZE/CS2Fixes/blob/5cb620cc971927a573ed29143178f5e2114ed0c4/src/eventlistener.h#L61-L64
#define GAME_EVENT(_event)                                            \
    void _event##_callback(IGameEvent *);                             \
    CGameEventListener _event##_listener(_event##_callback, #_event); \
    void _event##_callback(IGameEvent *pEvent)

#endif