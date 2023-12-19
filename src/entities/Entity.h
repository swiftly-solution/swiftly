#ifndef _entity_h
#define _entity_h

#include "../common.h"
#include "../sig/Signatures.h"
#include <public/mathlib/vector.h>
#include "../sdk/entity/CBaseModelEntity.h"

class Entity
{
private:
    CBaseModelEntity *worldEntity = nullptr;

public:
    Entity();

    Vector GetCoords();
    QAngle GetAngle();

    void SetCoords(float x, float y, float z);
    void SetAngle(float x, float y, float z);

    void SetModel(std::string model);

    void Spawn();
    void Destroy();

    void SetSolidType(SolidType_t solid_type);
};

#endif