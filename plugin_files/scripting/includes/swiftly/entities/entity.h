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

    Entity(const char *clsname = nullptr);
    ~Entity();

    void Spawn();
    void Destroy();
    void AcceptInput(const char *input, const char *activator = nullptr, const char *caller = nullptr, double *value = nullptr);

    void SetModel(const char *model);
    void SetCollisionGroup(CollisionGroup collisionGroup);

    CollisionGroup GetCollisionGroup(uint32_t entityID);

    uint32_t GetEntityID() { return this->entityID; }
};

#endif