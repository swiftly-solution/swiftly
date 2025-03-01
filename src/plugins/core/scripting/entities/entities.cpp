#include "../../scripting.h"

std::vector<SDKBaseClass> UTIL_FindEntitiesByClassname(std::string name)
{
    extern CEntitySystem* g_pEntitySystem;
    CEntityIdentity* pEntity = g_pEntitySystem->m_EntityList.m_pFirstActiveEntity;
    std::vector<SDKBaseClass> entities;

    for (; pEntity; pEntity = pEntity->m_pNext)
        if (pEntity->m_designerName.String() == name)
            entities.push_back(SDKBaseClass((void*)(pEntity->m_pInstance), "CEntityInstance"));

    return entities;
}

SDKBaseClass CreateEntityByName(std::string className)
{
    CEntityIdentity* entityPtr = reinterpret_cast<CEntityIdentity*>(g_Signatures->FetchSignature<UTIL_CreateEntityByName>("UTIL_CreateEntityByName")(className.c_str(), -1));

    return SDKBaseClass(entityPtr, "CEntityInstance");;
}