#include "../../../../common.h"
#include "../../../../entities/EntityManager.h"
#include "../../../../player/PlayerManager.h"
#include "../../../../utils/memstr.h"

#include <string>
#include <any>
#include <type_traits>

std::string SerializeData(std::any data);

unsigned int StringToUInt(const char *str)
{
    unsigned int retval;
    try
    {
        retval = (unsigned int)std::strtoul(str, nullptr, 10);
    }
    catch (std::invalid_argument &ex)
    {
        retval = -1;
    }
    catch (std::out_of_range &exr)
    {
        retval = -1;
    }
    return retval;
}

CEntityInstance *FetchInstanceByInput(std::string input)
{
    std::vector<std::string> splittedInput = explode(input, ":");
    if (splittedInput.size() < 1)
        return nullptr;

    if (splittedInput[0] == "entity")
    {
        uint32_t entityid = StringToUInt(splittedInput[1].c_str());
        Entity *entity = g_entityManager->GetEntity(entityid);
        if (entity == nullptr)
            return nullptr;

        return entity->GetEntityInstance();
    }
    else if (splittedInput[0] == "player")
    {
        uint32_t playerid = StringToUInt(splittedInput[1].c_str());
        Player *player = g_playerManager->GetPlayer(playerid);
        if (player == nullptr)
            return nullptr;

        return player->GetPlayerPawn();
    }
    else
        return nullptr;
}

SMM_API uint32_t scripting_Entity_Create(const char *classname)
{
    std::string clsname = classname;
    if (classname == nullptr)
        clsname = "prop_dynamic_override";

    uint32_t entityID = g_entityManager->CreateEntity(classname);
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

    MemStr str(data);
    str.DeleteAfter(500);
    return str.Get();
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

    MemStr str(data);
    str.DeleteAfter(500);
    return str.Get();
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

    MemStr str(data);
    str.DeleteAfter(500);
    return str.Get();
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

SMM_API void scripting_Entity_AcceptInput(uint32_t entityID, const char *input, const char *activator, const char *caller, double *value)
{
    if (entityID == 0 || input == nullptr)
        return;

    Entity *entity = g_entityManager->GetEntity(entityID);
    if (entity == nullptr)
        return;

    CEntityInstance *activatorInstance = nullptr;
    CEntityInstance *callerInstance = nullptr;

    if (activator)
        activatorInstance = FetchInstanceByInput(activator);
    if (caller)
        callerInstance = FetchInstanceByInput(caller);

    entity->AcceptInput(input, activatorInstance, callerInstance, value);
}

SMM_API void scripting_Entity_SetCollisionGroup(uint32_t entityID, Collision_Group_t collisionGroup)
{
    if (entityID == 0)
        return;

    Entity *entity = g_entityManager->GetEntity(entityID);
    if (entity == nullptr)
        return;

    entity->SetCollisionGroup(collisionGroup);
}

SMM_API Collision_Group_t scripting_Entity_GetCollisionGroup(uint32_t entityID)
{
    if (entityID == 0)
        return COLLISION_GROUP_ALWAYS;

    Entity *entity = g_entityManager->GetEntity(entityID);
    if (entity == nullptr)
        return COLLISION_GROUP_ALWAYS;

    return entity->GetCollisionGroup(entityID);
}