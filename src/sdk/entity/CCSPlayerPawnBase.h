#pragma once
#include "CBasePlayerPawn.h"
#include "../schema/schema.h"
#include "CBaseViewModel.h"

class CCSPlayerController;

class CCSPlayerPawnBase : public CBasePlayerPawn
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSPlayerPawnBase)

    SCHEMA_FIELD_OFFSET(int, m_ArmorValue, 0);
    SCHEMA_FIELD_OFFSET(float, m_flFlashDuration, 0);
    SCHEMA_FIELD_OFFSET(float, m_flVelocityModifier, 0);
    SCHEMA_FIELD_OFFSET(QAngle, m_angEyeAngles, 0);
    SCHEMA_FIELD_OFFSET(CHandle<CCSPlayerController>, m_hOriginalController, 0);
    SCHEMA_FIELD_OFFSET(CCSPlayer_ViewModelServices*, m_pViewModelServices, 0);
};