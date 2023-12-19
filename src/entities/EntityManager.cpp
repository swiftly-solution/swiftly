#include "EntityManager.h"
#include "../sdk/entity/CBaseModelEntity.h"
#include <thread>

Entity *EntityManager::CreateEntity(std::string model)
{
    Entity *entity = new Entity();

    entity->SetCoords(1266.753906f, -158.130188f, -167.968750f);
    entity->SetAngle(0.0f, 180.0f, 0.0f);
    entity->SetSolidType(SolidType_t::SOLID_VPHYSICS);

    entity->SetModel(model.c_str());
    entity->Spawn();

    return entity;
}