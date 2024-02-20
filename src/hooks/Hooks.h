#ifndef _hooks_h
#define _hooks_h

#include "../common.h"
#include <map>
#include <functional>

class CBasePlayerWeapon;

struct Event
{
    virtual ~Event() {}
};

struct OnClientActive : Event
{
    CPlayerSlot *slot;
    bool bLoadGame;
    const char *pszName;
    uint64 xuid;
    OnClientActive(CPlayerSlot *slot, bool bLoadGame, const char *pszName, uint64 xuid)
    {
        this->slot = slot;
        this->bLoadGame = bLoadGame;
        this->pszName = pszName;
        this->xuid = xuid;
    }
};

struct OnClientSettingsChanged : Event
{
    CPlayerSlot *slot;
    OnClientSettingsChanged(CPlayerSlot *slot)
    {
        this->slot = slot;
    }
};

struct OnGameFrame : Event
{
    bool simulating;
    bool bFirstTick;
    bool bLastTick;
    OnGameFrame(bool simulating, bool bFirstTick, bool bLastTick)
    {
        this->simulating = simulating;
        this->bFirstTick = bFirstTick;
        this->bLastTick = bLastTick;
    }
};

struct OnClientDisconnect : Event
{
    CPlayerSlot *slot;
    int reason;
    const char *pszName;
    uint64 xuid;
    const char *pszNetworkID;
    OnClientDisconnect(CPlayerSlot *slot, int reason, const char *pszName, uint64 xuid, const char *pszNetworkID)
    {
        this->slot = slot;
        this->reason = reason;
        this->pszName = pszName;
        this->xuid = xuid;
        this->pszNetworkID = pszNetworkID;
    }
};

struct OnClientConnect : Event
{
    CPlayerSlot *slot;
    const char *pszName;
    uint64 xuid;
    const char *pszNetworkID;
    bool unk1;
    CBufferString *pRejectReason;
    OnClientConnect(CPlayerSlot *slot, const char *pszName, uint64 xuid, const char *pszNetworkID, bool unk1, CBufferString *pRejectReason)
    {
        this->slot = slot;
        this->pszName = pszName;
        this->xuid = xuid;
        this->pszNetworkID = pszNetworkID;
        this->unk1 = unk1;
        this->pRejectReason = pRejectReason;
    }
};

struct OnMapLoad : Event
{
    const char *map;

    OnMapLoad(const char *map)
    {
        this->map = map;
    }
};

struct OnMapUnload : Event
{
    const char *map;

    OnMapUnload(const char *map)
    {
        this->map = map;
    }
};

struct OnWeaponSpawned : Event
{
    CBasePlayerWeapon *pEntity;

    OnWeaponSpawned(CBasePlayerWeapon *pEntity)
    {
        this->pEntity = pEntity;
    }
};

struct OnClientKeyStateChange : Event
{
    CPlayerSlot *slot;
    char const *button;
    bool pressed;
    OnClientKeyStateChange(CPlayerSlot *slot, char const *button, bool pressed)
    {
        this->slot = slot;
        this->button = button;
        this->pressed = pressed;
    };
};

struct OnClientExecuteCommand : Event
{
    CPlayerSlot *slot;
    const char *command;
    OnClientExecuteCommand(CPlayerSlot *slot, char const *command)
    {
        this->slot = slot;
        this->command = command;
    };
};

struct OnClientCommand : Event
{
    CPlayerSlot *slot;
    const char *command;
    OnClientCommand(CPlayerSlot *slot, char const *command)
    {
        this->slot = slot;
        this->command = command;
    };
};

typedef std::multimap<const std::type_info *, const std::function<void(const Event *)>>
    EventMap;

extern EventMap eventMap;

class hooks
{
public:
    template <typename EventWanted>
    static void on(const std::function<void(const EventWanted *)> &fn)
    {
        eventMap.emplace(&typeid(EventWanted), [fn](const Event *e)
                         { fn(static_cast<const EventWanted *>(e)); });
    }

    template <typename EventWanted>
    static void emit(const EventWanted &event)
    {
        auto range = eventMap.equal_range(&typeid(event));
        for (auto it = range.first; it != range.second; ++it)
            it->second(&event);
    }
};

#endif