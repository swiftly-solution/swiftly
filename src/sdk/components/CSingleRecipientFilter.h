#include <public/irecipientfilter.h>

#define INVALID_PLAYER_SLOT_INDEX -1
#define INVALID_PLAYER_SLOT CPlayerSlot( INVALID_PLAYER_SLOT_INDEX )

class CRecipientFilter : public IRecipientFilter
{
public:
    CRecipientFilter(NetChannelBufType_t nBufType = BUF_RELIABLE, bool bInitMessage = false) : m_nBufType(nBufType), m_bInitMessage(bInitMessage) {}

    CRecipientFilter(IRecipientFilter* source, CPlayerSlot exceptSlot = INVALID_PLAYER_SLOT)
    {
        m_Recipients = source->GetRecipients();
        m_nBufType = source->GetNetworkBufType();
        m_bInitMessage = source->IsInitMessage();

        if (exceptSlot != INVALID_PLAYER_SLOT)
        {
            m_Recipients.Clear(exceptSlot.Get());
        }
    }

    ~CRecipientFilter() override {}

    NetChannelBufType_t GetNetworkBufType(void) const override
    {
        return m_nBufType;
    }

    bool IsInitMessage(void) const override
    {
        return m_bInitMessage;
    }

    const CPlayerBitVec& GetRecipients() const override { return m_Recipients; }

    void AddRecipient(CPlayerSlot slot)
    {
        int id = slot.Get();
        if (id >= 0 && id < ABSOLUTE_PLAYER_LIMIT)
        {
            m_Recipients.Set(id);
        }
    }

    void AddAllPlayers()
    {
        m_Recipients.ClearAll();

        for (int i = 0; i <= engine->GetServerGlobals()->maxClients; i++)
            if (engine->IsClientFullyAuthenticated(i))
                AddRecipient(i);
    }

    void RemoveRecipient(CPlayerSlot slot)
    {
        int id = slot.Get();
        if (id >= 0 && id < ABSOLUTE_PLAYER_LIMIT)
        {
            m_Recipients.Clear(id);
        }
    }

private:
    // Can't copy this unless we explicitly do it!
    CRecipientFilter(CRecipientFilter const& source)
    {
        Assert(0);
    }

    NetChannelBufType_t m_nBufType;
    bool m_bInitMessage;
    CPlayerBitVec m_Recipients;
};

class CBroadcastRecipientFilter : public CRecipientFilter
{
public:
    CBroadcastRecipientFilter(void)
    {
        AddAllPlayers();
    }
};

class CSingleRecipientFilter : public CRecipientFilter
{
public:
    CSingleRecipientFilter(int iRecipient, bool bReliable = true, bool bInitMessage = false) : m_bReliable(bReliable), m_bInitMessage(bInitMessage)
    {
        AddRecipient(CPlayerSlot(iRecipient));
    }

    ~CSingleRecipientFilter() override {}

    bool IsReliable(void) const { return m_bReliable; }

    bool IsInitMessage(void) const override { return m_bInitMessage; }

    NetChannelBufType_t GetNetworkBufType(void) const override { return m_bReliable ? BUF_RELIABLE : BUF_UNRELIABLE; }

private:
    bool m_bReliable;
    bool m_bInitMessage;
};
