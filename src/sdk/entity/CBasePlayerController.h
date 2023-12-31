#pragma once

#include "ehandle.h"
#include "CBaseEntity.h"
#include "CCSPlayerPawn.h"

enum class PlayerConnectedState : uint32_t
{
    PlayerNeverConnected = 0xFFFFFFFF,
    PlayerConnected = 0x0,
    PlayerConnecting = 0x1,
    PlayerReconnecting = 0x2,
    PlayerDisconnecting = 0x3,
    PlayerDisconnected = 0x4,
    PlayerReserved = 0x5,
};

class CBasePlayerController : public Z_CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CBasePlayerController, false)

    SCHEMA_FIELD_OFFSET(uint64, m_steamID, 0)
    SCHEMA_FIELD_OFFSET(CHandle<CBasePlayerPawn>, m_hPawn, 0)
    SCHEMA_FIELD_POINTER_OFFSET(char, m_iszPlayerName, 0)
    SCHEMA_FIELD_OFFSET(PlayerConnectedState, m_iConnected, 0)

    void SendMsg(int destination, const char *message)
    {
        g_Signatures->FetchSignature<ClientPrint>("ClientPrint")(this, destination, message, nullptr, nullptr, nullptr, nullptr);
    }
};