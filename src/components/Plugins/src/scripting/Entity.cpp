#include "../../../../common.h"
#include "../../../../entities/EntityManager.h"

#include <string>
#include <any>
#include <type_traits>

std::string SerializeData(std::any data);

SMM_API uint32_t scripting_Entity_Create()
{
    uint32_t entityID = g_entityManager->CreateEntity();
    return entityID;
}

SMM_API void scripting_Entity_Spawn(uint32_t entityID)
{
    if (entityID == 0)
        return;

    Entity *entity = g_entityManager->GetEntity(entityID);
    if (entity == nullptr)
        return;

    entity->Spawn();
}

SMM_API void scripting_Entity_Destroy(uint32_t entityID)
{
    if (entityID == 0)
        return;

    Entity *entity = g_entityManager->GetEntity(entityID);
    if (entity == nullptr)
        return;

    entity->Destroy();
}

SMM_API void scripting_Entity_SetModel(uint32_t entityID, const char *model)
{
    if (entityID == 0 || model == nullptr)
        return;

    Entity *entity = g_entityManager->GetEntity(entityID);
    if (entity == nullptr)
        return;

    entity->SetModel(model);
}

SMM_API const char *scripting_Entity_GetCoords(uint32_t entityID)
{
    if (entityID == 0)
        return "";

    Entity *entity = g_entityManager->GetEntity(entityID);
    if (entity == nullptr)
        return "";

    std::string data = SerializeData(entity->GetCoords());

    char *result = new char[data.size() + 1];
    strcpy(result, data.c_str());
    return result;
}

SMM_API void scripting_Entity_SetCoords(uint32_t entityID, float x, float y, float z)
{
    if (entityID == 0)
        return;

    Entity *entity = g_entityManager->GetEntity(entityID);
    if (entity == nullptr)
        return;

    entity->SetCoords(x, y, z);
}

SMM_API const char *scripting_Entity_GetAngles(uint32_t entityID)
{
    if (entityID == 0)
        return "";

    Entity *entity = g_entityManager->GetEntity(entityID);
    if (entity == nullptr)
        return "";

    std::string data = SerializeData(entity->GetAngle());

    char *result = new char[data.size() + 1];
    strcpy(result, data.c_str());
    return result;
}

SMM_API void scripting_Entity_SetAngles(uint32_t entityID, float x, float y, float z)
{
    if (entityID == 0)
        return;

    Entity *entity = g_entityManager->GetEntity(entityID);
    if (entity == nullptr)
        return;

    entity->SetAngle(x, y, z);
}

SMM_API const char *scripting_Entity_GetColors(uint32_t entityID)
{
    if (entityID == 0)
        return "";

    Entity *entity = g_entityManager->GetEntity(entityID);
    if (entity == nullptr)
        return "";

    std::string data = SerializeData(entity->GetColor());

    char *result = new char[data.size() + 1];
    strcpy(result, data.c_str());
    return result;
}

SMM_API void scripting_Entity_SetColors(uint32_t entityID, int r, int g, int b, int a)
{
    if (entityID == 0)
        return;

    Entity *entity = g_entityManager->GetEntity(entityID);
    if (entity == nullptr)
        return;

    entity->SetColor(r, g, b, a);
}