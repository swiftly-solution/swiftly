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
                entityInstanceMapping.insert({pEntity, new GCEntityInstance((void *)(pEntity->m_pInstance))});

            entities.push_back(entityInstanceMapping.at(pEntity));
        }
    };

    return entities;
}

GCEntityInstance *CreateEntityByName(const char *name)
{
    std::string className = (!name ? "prop_dynamic_override" : name);

    CEntityIdentity *entityPtr = reinterpret_cast<CEntityIdentity *>(g_Signatures->FetchSignature<UTIL_CreateEntityByName>("UTIL_CreateEntityByName")(className.c_str(), -1));

    GCEntityInstance *instance = new GCEntityInstance(entityPtr);
    if (entityInstanceMapping.find(entityPtr) == entityInstanceMapping.end())
        entityInstanceMapping.insert({entityPtr, instance});

    return instance;
}