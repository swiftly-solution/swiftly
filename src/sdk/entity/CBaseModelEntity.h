#pragma once

#include "CBaseEntity.h"
#include "globaltypes.h"
#include "../../signatures/Signatures.h"
#include "../../precacher/precacher.h"

class CBaseModelEntity;

typedef void (*CBaseModelEntity_SetModel)(CBaseModelEntity*, const char*);

class CBaseModelEntity : public Z_CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CBaseModelEntity, false)

    SCHEMA_FIELD_OFFSET(CCollisionProperty, m_Collision, 0)
    SCHEMA_FIELD_OFFSET(CGlowProperty, m_Glow, 0)
    SCHEMA_FIELD_OFFSET(Color, m_clrRender, 0)

    void SetModel(const char* model)
    {
        bool hasModel = (g_precacher->HasModelInList(model));
        if (!hasModel)
        {
            g_precacher->AddModel(model);
            PLUGIN_PRINTF("Precacher", "Model '%s' was not precached before and it was added to the list.\n", model);
            PLUGIN_PRINTF("Precacher", "It may work on the second map change if the model is valid.\n");
        }

        g_Signatures->FetchSignature<CBaseModelEntity_SetModel>("CBaseModelEntity_SetModel")(this, model);
    }

    void SetSolidType(SolidType_t type)
    {
        this->m_Collision.Get().m_nSolidType = type;
    }
};