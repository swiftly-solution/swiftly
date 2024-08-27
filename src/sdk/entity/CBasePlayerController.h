#pragma once

#include "ehandle.h"
#include "CBaseEntity.h"
#include "CCSPlayerPawn.h"
#include "CRecipientFilters.h"
#include "usermessages.pb.h"

enum class CPlayerConnectedState : uint32_t
{
    PlayerNeverConnected = 0xFFFFFFFF,
    PlayerConnected = 0x0,
    PlayerConnecting = 0x1,
    PlayerReconnecting = 0x2,
    PlayerDisconnecting = 0x3,
    PlayerDisconnected = 0x4,
    PlayerReserved = 0x5,
};

class CBasePlayerController;

class CBasePlayerController : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CBasePlayerController, false)

    SCHEMA_FIELD_OFFSET(uint64, m_steamID, 0);
    SCHEMA_FIELD_OFFSET(CHandle<CBasePlayerPawn>, m_hPawn, 0);
    SCHEMA_FIELD_POINTER_OFFSET(char, m_iszPlayerName, 0);
    SCHEMA_FIELD_OFFSET(CPlayerConnectedState, m_iConnected, 0);
    SCHEMA_FIELD_OFFSET(uint32_t, m_iDesiredFOV, 0);
    SCHEMA_FIELD_OFFSET(bool, m_bIsHLTV, 0);

    int GetPlayerSlot() { return entindex() - 1; }

    void SendMsg(int destination, const char* message)
    {
        INetworkMessageInternal* pNetMsg = g_pNetworkMessages->FindNetworkMessagePartial("TextMsg");
        auto data = pNetMsg->AllocateMessage()->ToPB<CUserMessageTextMsg>();

        data->set_dest(destination);
        data->add_param(message);

        CSingleRecipientFilter filter(this->GetPlayerSlot());
        g_pGameEventSystem->PostEventAbstract(-1, false, &filter, pNetMsg, data, 0);

        delete data;
    }

    void SetPawn(CCSPlayerPawn* pawn)
    {
        g_Signatures->FetchSignature<CBasePlayerController_SetPawn>("CBasePlayerController_SetPawn")(this, pawn, true, false);
    }
};