#ifndef _swiftly_entities_h
#define _swiftly_entities_h

#include <cstdint>
#include <map>
#include <vector>
#include "entities/entity.h"

class Entities
{
private:
    std::map<uint32_t, Entity *> entities;

public:
    Entities(){};

    Entity *Create(const char *clsname = nullptr);
    Entity *Fetch(uint32_t id);
    void Destroy(uint32_t id);

    std::vector<uint32_t> GetEntityIDs();
    std::vector<Entity *> GetEntities();
};

extern Entities *entities;

#endif