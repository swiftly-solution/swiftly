#ifndef _entitymanager_h
#define _entitymanager_h

#include "../common.h"
#include "../sig/Signatures.h"
#include "Entity.h"

#include <string>

class EntityManager
{
public:
    EntityManager() {}

    Entity *CreateEntity(std::string model);
};

extern EntityManager *g_entityManager;

#endif