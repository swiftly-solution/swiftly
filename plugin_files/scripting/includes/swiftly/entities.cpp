#include "entities.h"

Entity *Entities::Create(const char *clsname)
{
    Entity *entity = new Entity(clsname);
    this->entities.insert(std::make_pair(entity->GetEntityID(), entity));
    return entity;
}

Entity *Entities::Fetch(uint32_t id)
{
    if (this->entities.find(id) == this->entities.end())
        return nullptr;

    return this->entities.at(id);
}

void Entities::Destroy(uint32_t id)
{
    if (this->entities.find(id) == this->entities.end())
        return;

    Entity *entity = this->entities.at(id);
    entity->Destroy();
    delete entity;
    this->entities.erase(id);
}

std::vector<uint32_t> Entities::GetEntityIDs()
{
    std::vector<uint32_t> ids;
    for (std::map<uint32_t, Entity *>::iterator it = this->entities.begin(); it != this->entities.end(); ++it)
        ids.push_back(it->first);

    return ids;
}

std::vector<Entity *> Entities::GetEntities()
{
    std::vector<Entity *> ent;
    for (std::map<uint32_t, Entity *>::iterator it = this->entities.begin(); it != this->entities.end(); ++it)
        ent.push_back(it->second);

    return ent;
}
