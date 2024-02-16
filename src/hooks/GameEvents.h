#ifndef _gameevents_hooks_h
#define _gameevents_hooks_h

#include "../common.h"
#include <map>
#include <functional>

#define GAMEEVENT_DEFINITION(name) \
    struct name : GameEvent        \
    {                              \
        IGameEvent *pEvent;        \
        name(IGameEvent *pEvent)   \
        {                          \
            this->pEvent = pEvent; \
        }                          \
    }

struct GameEvent
{
    virtual ~GameEvent() {}
};

GAMEEVENT_DEFINITION(OnPlayerSpawn);
GAMEEVENT_DEFINITION(OnRoundPrestart);
GAMEEVENT_DEFINITION(OnRoundPostStart);
GAMEEVENT_DEFINITION(OnRoundStart);
GAMEEVENT_DEFINITION(OnRoundEnd);
GAMEEVENT_DEFINITION(BombBeginPlant);
GAMEEVENT_DEFINITION(BombAbortPlant);
GAMEEVENT_DEFINITION(BombPlanted);
GAMEEVENT_DEFINITION(BombDefused);
GAMEEVENT_DEFINITION(BombExploded);
GAMEEVENT_DEFINITION(BombDropped);
GAMEEVENT_DEFINITION(BombPickup);
GAMEEVENT_DEFINITION(BombBeginDefuse);
GAMEEVENT_DEFINITION(BombAbortDefuse);
GAMEEVENT_DEFINITION(PlayerDeath);
GAMEEVENT_DEFINITION(PlayerHurt);
GAMEEVENT_DEFINITION(PlayerBlind);
GAMEEVENT_DEFINITION(PlayerInfo);
GAMEEVENT_DEFINITION(PlayerFullUpdate);
GAMEEVENT_DEFINITION(ItemPickup);
GAMEEVENT_DEFINITION(EnterBuyzone);
GAMEEVENT_DEFINITION(ExitBuyzone);
GAMEEVENT_DEFINITION(EnterBombzone);
GAMEEVENT_DEFINITION(ExitBombzone);
GAMEEVENT_DEFINITION(PlayerJump);
GAMEEVENT_DEFINITION(PlayerFallDamage);
GAMEEVENT_DEFINITION(ClientFullConnected);

typedef std::multimap<const std::type_info *, const std::function<void(const GameEvent *)>> GameEventMap;

extern GameEventMap gameEventMap;

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

#endif