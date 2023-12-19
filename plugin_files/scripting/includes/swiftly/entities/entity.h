#ifndef _swiftly_entities_entity_h
#define _swiftly_entities_entity_h

#include <cstdint>
#include "../swiftly_memory.h"
#include "../types.h"

#include "coords.h"
#include "angles.h"
#include "colors.h"

class Entity
{
private:
    uint32_t entityID = 0;

public:
    ECoords *coords;
    Angles *angles;
    Colors *color;

    Entity();
    ~Entity();

    void Spawn();
    void Destroy();

    void SetModel(const char *model);

    uint32_t GetEntityID() { return this->entityID; }
};

#endif