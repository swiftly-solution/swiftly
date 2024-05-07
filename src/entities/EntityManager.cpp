#include "EntityManager.h"
#include "../sdk/entity/CBaseModelEntity.h"
#include <thread>

uint32_t EntityManager::CreateEntity(std::string classname)
{
    Entity *entity = new Entity(classname);

    if (!starts_with(classname, "player:"))
        entity->SetSolidType(SolidType_t::SOLID_VPHYSICS);

    ++entityIncrementID;
    this->entities.insert(std::make_pair(entityIncrementID, entity));
    return entityIncrementID;
}

Entity *EntityManager::GetEntity(uint32_t id)
{
    if (this->entities.find(id) == this->entities.end())
        return nullptr;

    return this->entities.at(id);
}

void EntityManager::DestroyEntity(uint32_t id)
{
    if (this->entities.find(id) == this->entities.end())
        return;

    Entity *ent = this->entities.at(id);
    delete ent;
    this->entities.erase(id);
}