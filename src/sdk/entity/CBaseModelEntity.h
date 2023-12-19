#pragma once

#include "CBaseEntity.h"
#include "globaltypes.h"
#include "../../sig/Signatures.h"
#include "../../precacher/Precacher.h"

class CBaseModelEntity : public Z_CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CBaseModelEntity, false)

    SCHEMA_FIELD_OFFSET(CCollisionProperty, m_Collision, 0)
    SCHEMA_FIELD_OFFSET(CGlowProperty, m_Glow, 0)

    void SetModel(const char *model)
    {
        g_Signatures->FetchSignature<CBaseModelEntity_SetModel>("CBaseModelEntity_SetModel")(this, model);
    }
};