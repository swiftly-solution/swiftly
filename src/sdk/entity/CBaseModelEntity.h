#pragma once

#include "CBaseEntity.h"
#include "globaltypes.h"
#include "../../memory/signatures/Signatures.h"
#include "../../entitysystem/precacher/precacher.h"

class CBaseModelEntity;

class CBaseModelEntity : public CBaseEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CBaseModelEntity)

    SCHEMA_FIELD_POINTER_OFFSET(CCollisionProperty, m_Collision, 0);
    SCHEMA_FIELD_OFFSET(CGlowProperty, m_Glow, 0);
    SCHEMA_FIELD_OFFSET(Color, m_clrRender, 0);

    void SetModel(const char* model)
    {
        bool hasModel = (g_precacher->HasModelInList(model));
        if (!hasModel)
        {
            g_precacher->AddModel(model);
            PLUGIN_PRINTF("Precacher", "Model '%s' was not precached before and it was added to the list.\n", model);
            PLUGIN_PRINTF("Precacher", "It may work on the second map change if the model is valid.\n");
        }

        g_Signatures->FetchSignature<CBaseModelEntity_SetModel_t>("CBaseModelEntity_SetModel")(this, model);
    }

    void SetBodygroup(const char* str, uint64_t val)
    {
        g_Signatures->FetchSignature<CBaseModelEntity_SetBodygroup_t>("CBaseModelEntity_SetBodygroup")(this, str, val);
    }

    void SetSolidType(SolidType_t type)
    {
        this->m_Collision->m_nSolidType = type;
        CollisionRulesChanged();
    }
};