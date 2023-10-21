#ifndef _baseEntity_h
#define _baseEntity_h

#include "../common.h"
#include "schemasystem.h"

inline CEntityInstance *UTIL_FindEntityByClassname(CEntityInstance *pStart, const char *name)
{
	extern CEntitySystem *g_pEntitySystem;
	CEntityIdentity *pEntity = pStart ? pStart->m_pEntity->m_pNext : g_pEntitySystem->m_EntityList.m_pFirstActiveEntity;

	for (; pEntity; pEntity = pEntity->m_pNext)
	{
		if (!strcmp(pEntity->m_designerName.String(), name))
			return pEntity->m_pInstance;
	};

	return nullptr;
}

class SC_CBaseEntity : public CBaseEntity
{
public:
	SCHEMA_FIELD(int32_t, CBaseEntity, m_iHealth);
	SCHEMA_FIELD(int32_t, CBaseEntity, m_iMaxHealth);
	SCHEMA_FIELD(LifeState_t, CBaseEntity, m_lifeState);
	SCHEMA_FIELD(uint8_t, CBaseEntity, m_iTeamNum);
	SCHEMA_FIELD(float, CBaseEntity, m_flGravityScale);
};

#endif