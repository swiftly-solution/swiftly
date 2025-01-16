#pragma once

#include "CBaseEntity.h"
#include "CBaseModelEntity.h"
#include "services.h"
#include "../../memory/signatures/Offsets.h"

#include "../../utils/utils.h"
#include "../../common.h"
#include "../../entrypoint.h"

class CBasePlayerPawn : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CBasePlayerPawn)

    SCHEMA_FIELD_OFFSET(CPlayer_MovementServices*, m_pMovementServices, 0);
    SCHEMA_FIELD_OFFSET(CPlayer_WeaponServices*, m_pWeaponServices, 0);
    SCHEMA_FIELD_OFFSET(CCSPlayer_ItemServices*, m_pItemServices, 0);
    // @a.alex1421 - Discord -> Pointed out that m_pObserverServices should be with SCHEMA_FIELD not SCHEMA_FIELD_POINTER
    SCHEMA_FIELD_OFFSET(CPlayer_ObserverServices*, m_pObserverServices, 0);
    SCHEMA_FIELD_OFFSET(CPlayer_CameraServices*, m_pCameraServices, 0);
    SCHEMA_FIELD_OFFSET(CHandle<CBasePlayerController>, m_hController, 0);

    void TakeDamage(int damage)
    {
        if (this->m_iHealth() - damage <= 0)
            this->CommitSuicide(false, true);
        else
            CBaseEntity::TakeDamage(damage);
    }

    void CommitSuicide(bool explode, bool forced)
    {
        static int offset = g_Offsets->GetOffset("CBasePlayerPawn_CommitSuicide");
        CALL_VIRTUAL(void, offset, this, explode, forced);
    }
};