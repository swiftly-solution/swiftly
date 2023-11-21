#pragma once

#include "CBaseEntity.h"
#include "CBaseModelEntity.h"
#include "services.h"

class CBasePlayerPawn : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CBasePlayerPawn, false)

    SCHEMA_FIELD_OFFSET(CPlayer_MovementServices *, m_pMovementServices, 0)
    SCHEMA_FIELD_OFFSET(unsigned short *, m_pWeaponServices, 0)
    SCHEMA_FIELD_OFFSET(CCSPlayer_ItemServices *, m_pItemServices, 0)
    SCHEMA_FIELD_OFFSET(CHandle<CBasePlayerController>, m_hController, 0)
};