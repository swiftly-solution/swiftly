#ifndef _entitymanager_h
#define _entitymanager_h

#include "../common.h"
#include "../sig/Signatures.h"
#include "Entity.h"

#include <map>
#include <string>

class EntityManager
{
private:
    std::map<uint32_t, Entity *> entities;
    uint32_t entityIncrementID = 0;

public:
    EntityManager() {}

    uint32_t CreateEntity(std::string classname);
    Entity *GetEntity(uint32_t id);
    void DestroyEntity(uint32_t id);
};

extern EntityManager *g_entityManager;

#endif