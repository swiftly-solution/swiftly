#pragma once

#include "CBasePlayerController.h"
#include "services.h"

class CCSPlayerController : public CBasePlayerController
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSPlayerController)

    SCHEMA_FIELD_OFFSET(CCSPlayerController_InGameMoneyServices *, m_pInGameMoneyServices, 0)
    SCHEMA_FIELD_OFFSET(CCSPlayerController_ActionTrackingServices *, m_pActionTrackingServices, 0)
    SCHEMA_FIELD_OFFSET(CCSPlayerController_InventoryServices *, m_pInventoryServices, 0)
    SCHEMA_FIELD_OFFSET(bool, m_bPawnIsAlive, 0)
    SCHEMA_FIELD_OFFSET(CHandle<CCSPlayerPawn>, m_hPlayerPawn, 0)
    SCHEMA_FIELD_OFFSET(CHandle<CCSPlayerPawnBase>, m_hObserverPawn, 0)
    SCHEMA_FIELD_OFFSET(CUtlSymbolLarge, m_szClan, 0)
    SCHEMA_FIELD_POINTER_OFFSET(char, m_szClanName, 0)
    SCHEMA_FIELD_OFFSET(int, m_iCompTeammateColor, 0)
    SCHEMA_FIELD_OFFSET(CEntityHandle, m_hDesiredObserverTarget, 0)

    void Respawn()
    {
        CCSPlayerPawn *pawn = m_hPlayerPawn.Get();
        if (!pawn)
            return;

        SetPawn(pawn);
        CALL_VIRTUAL(void, g_Offsets->GetOffset("CCSPlayerController_Respawn"), this);
    }
};
