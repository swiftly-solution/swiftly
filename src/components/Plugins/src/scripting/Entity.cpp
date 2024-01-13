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

Vector scripting_Entity_GetCoordsRaw(uint32_t entityID)
{
    Vector vec(0.0f, 0.0f, 0.0f);
    if (entityID == 0)
        return vec;
    Entity *entity = g_entityManager->GetEntity(entityID);
    if (entity == nullptr)
        return vec;

    return entity->GetCoords();
}

SMM_API const char *scripting_Entity_GetCoords(uint32_t entityID)
{
    std::string data = SerializeData(scripting_Entity_GetCoordsRaw(entityID));

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

QAngle scripting_Entity_GetAnglesRaw(uint32_t entityID)
{
    QAngle angle(0.0f, 0.0f, 0.0f);

    if (entityID == 0)
        return angle;
    Entity *entity = g_entityManager->GetEntity(entityID);
    if (entity == nullptr)
        return angle;

    return entity->GetAngle();
}

SMM_API const char *scripting_Entity_GetAngles(uint32_t entityID)
{
    std::string data = SerializeData(scripting_Entity_GetAnglesRaw(entityID));

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

Color scripting_Entity_GetColorsRaw(uint32_t entityID)
{
    Color color(0, 0, 0, 0);

    if (entityID == 0)
        return color;

    Entity *entity = g_entityManager->GetEntity(entityID);
    if (!entity)
        return color;

    return entity->GetColor();
}

SMM_API const char *scripting_Entity_GetColors(uint32_t entityID)
{
    std::string data = SerializeData(scripting_Entity_GetColorsRaw(entityID));

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