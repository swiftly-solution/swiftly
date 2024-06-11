#include "../scripting.h"

#include "generated/classes.h"

std::map<CEntityIdentity *, GCEntityInstance *> entityInstanceMapping;

std::vector<GCEntityInstance *> UTIL_FindEntitiesByClassname(const char *name)
{
    extern CEntitySystem *g_pEntitySystem;
    CEntityIdentity *pEntity = g_pEntitySystem->m_EntityList.m_pFirstActiveEntity;
    std::vector<GCEntityInstance *> entities;

    for (; pEntity; pEntity = pEntity->m_pNext)
    {
        if (!strcmp(pEntity->m_designerName.String(), name))
        {
            if (entityInstanceMapping.find(pEntity) == entityInstanceMapping.end())
                entityInstanceMapping.insert({pEntity, new GCEntityInstance((void *)pEntity)});

            entities.push_back(entityInstanceMapping.at(pEntity));
        }
    };

    return entities;
}