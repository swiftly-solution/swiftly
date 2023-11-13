#ifndef _hooks_h
#define _hooks_h

#include "../common.h"
#include <map>
#include <functional>

struct Event
{
    virtual ~Event() {}
};
struct OnClientConnected : Event
{
    CPlayerSlot *slot;
    const char *pszName;
    uint64 xuid;
    const char *pszNetworkID;
    const char *pszAddress;
    bool bFakePlayer;
    OnClientConnected(CPlayerSlot *slot, const char *pszName, uint64 xuid, const char *pszNetworkID, const char *pszAddress, bool bFakePlayer)
    {
        this->slot = slot;
        this->pszName = pszName;
        this->xuid = xuid;
        this->pszNetworkID = pszNetworkID;
        this->pszAddress = pszAddress;
        this->bFakePlayer = bFakePlayer;
    };
};

struct OnClientCommand : Event
{
    CPlayerSlot *slot;
    const CCommand *args;
    OnClientCommand(CPlayerSlot *slot, const CCommand *args)
    {
        this->slot = slot;
        this->args = args;
    };
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

struct OnClientPutInServer : Event
{
    CPlayerSlot *slot;
    char const *pszName;
    int type;
    uint64 xuid;
    OnClientPutInServer(CPlayerSlot *slot, char const *pszName, int type, uint64 xuid)
    {
        this->slot = slot;
        this->pszName = pszName;
        this->type = type;
        this->xuid = xuid;
    };
};

struct OnPlayerRegistered : Event
{
    CPlayerSlot *slot;
    OnPlayerRegistered(CPlayerSlot *slot)
    {
        this->slot = slot;
    }
};

typedef std::multimap<const std::type_info *, const std::function<void(const Event *)>> EventMap;

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