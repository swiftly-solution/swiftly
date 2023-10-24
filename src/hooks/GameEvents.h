#ifndef _gameevents_hooks_h
#define _gameevents_hooks_h

#include "../common.h"
struct GameEvent
{
    virtual ~GameEvent() {}
};

struct OnPlayerSpawn : GameEvent
{
    IGameEvent *pEvent;
    OnPlayerSpawn(IGameEvent *pEvent)
    {
        this->pEvent = pEvent;
    };
};

typedef std::multimap<const std::type_info *, const std::function<void(const GameEvent *)>> GameEventMap;

class gameevents
{
public:
    template <typename EventWanted>
    static void on(const std::function<void(const EventWanted *)> &fn)
    {
        gameEventMap.emplace(&typeid(EventWanted), [fn](const GameEvent *e)
                             { fn(static_cast<const EventWanted *>(e)); });
    }

    template <typename EventWanted>
    static void emit(const EventWanted &event)
    {
        auto range = gameEventMap.equal_range(&typeid(event));
        for (auto it = range.first; it != range.second; ++it)
            it->second(&event);
    }
};

extern GameEventMap gameEventMap;

#endif