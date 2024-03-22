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

class CBasePlayerController;

typedef void (*ClientPrint)(CBasePlayerController *, int, const char *, const char *, const char *, const char *, const char *);

class CBasePlayerController : public Z_CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CBasePlayerController, false)

    SCHEMA_FIELD_OFFSET(uint64, m_steamID, 0)
    SCHEMA_FIELD_OFFSET(CHandle<CBasePlayerPawn>, m_hPawn, 0)
    SCHEMA_FIELD_POINTER_OFFSET(char *, m_iszPlayerName, 0)
    SCHEMA_FIELD_OFFSET(PlayerConnectedState, m_iConnected, 0)
    SCHEMA_FIELD_OFFSET(uint32_t, m_iDesiredFOV, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bAutoKickDisabled, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nAvailableEntitySteadyState, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bGamePaused, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bHasAnySteadyStateEnts, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bIsHLTV, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bIsLowViolence, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bLagCompensation, 0)
    SCHEMA_FIELD_OFFSET(float, m_flLastEntitySteadyState, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nLastLateCommandExecuted, 0)
    SCHEMA_FIELD_OFFSET(float, m_flLastPlayerTalkTime, 0)
    SCHEMA_FIELD_OFFSET(int32_t, m_nLastRealCommandNumberExecuted, 0)
    SCHEMA_FIELD_OFFSET(float, m_fLerpTime, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bPredict, 0)
    SCHEMA_FIELD_OFFSET(uint32_t, m_nTickBase, 0)

    void SendMsg(int destination, const char *message)
    {
        g_Signatures->FetchSignature<ClientPrint>("ClientPrint")(this, destination, message, nullptr, nullptr, nullptr, nullptr);
    }

    void SetPawn(CCSPlayerPawn *pawn)
    {
        g_Signatures->FetchSignature<CBasePlayerController_SetPawn>("CBasePlayerController_SetPawn")(this, pawn, true, false);
    }
};