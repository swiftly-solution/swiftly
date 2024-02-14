#pragma once

#include "CBasePlayerPawn.h"

class CCSPlayerPawn : public CBasePlayerPawn
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSPlayerPawn, false)

    SCHEMA_FIELD_OFFSET(CCSPlayer_ActionTrackingServices *, m_pActionTrackingServices, 0)
    SCHEMA_FIELD_POINTER_OFFSET(CEconItemView, m_EconGloves, 0)
};