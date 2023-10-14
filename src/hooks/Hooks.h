#ifndef _hooks_h
#define _hooks_h

#include "../common.h"

struct Event
{
    virtual ~Event() {}
};
struct OnClientConnectedEvent : Event
{
    CPlayerSlot *slot;
    const char *pszName;
    uint64 xuid;
    const char *pszNetworkID;
    const char *pszAddress;
    bool bFakePlayer;
    OnClientConnectedEvent(CPlayerSlot *slot, const char *pszName, uint64 xuid, const char *pszNetworkID, const char *pszAddress, bool bFakePlayer)
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

typedef std::multimap<const std::type_info *,
                      const std::function<void(const Event *)>>
    EventMap;

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

extern EventMap eventMap;

#endif