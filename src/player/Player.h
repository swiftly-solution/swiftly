#ifndef _player_h
#define _player_h

#include "../common.h"
#include "../sdk/CBasePlayerController.h"
#include "../sdk/CBasePlayerPawn.h"
#include <ctime>

class Player
{
private:
    CPlayerSlot slot;
    bool isFakeClient;
    bool isAuthenticated;
    bool isConnected;
    int eHandleId = -1;
    std::time_t connectTime;

public:
    Player(bool m_isFakeClient, CPlayerSlot m_slot) : isFakeClient(m_isFakeClient), slot(m_slot), connectTime(std::time(0)) {}

    ~Player()
    {
        this->isFakeClient = true;
        this->isAuthenticated = false;
    }

    inline bool IsFakeClient() { return this->isFakeClient; };
    inline bool IsAuthenticated() { return this->isAuthenticated; };
    inline CPlayerSlot *GetSlot() { return &this->slot; };
    inline void SetEHandlerIdx(int eHandleId) { this->eHandleId = eHandleId; };
    inline int GetEHandlerIdx() { return this->eHandleId; };
    inline uint32 GetConnectedTime() { return (std::time(0) - this->connectTime); };

    inline void SetConnected(bool connected) { this->isConnected = connected; };
    inline bool IsConnected() { return this->isConnected; };

    void Authenticate();

    CBasePlayerController *GetController();
    CBasePlayerPawn *GetPawn();
};

#endif