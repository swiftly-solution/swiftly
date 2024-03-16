#include "entity.h"
#include "../swiftly.h"

typedef uint32_t (*CreateEntity)(const char *);
typedef void (*Entity_Spawn)(uint32_t);
typedef void (*Entity_Destroy)(uint32_t);
typedef void (*Entity_SetModel)(uint32_t, const char *);
typedef void (*Entity_AcceptInput)(uint32_t, const char *, const char *, const char *, double *);
typedef void (*Entity_CollisionGroup)(uint32_t, int);

Entity::Entity(const char *clsname)
{
    void *createEntity = FetchFunctionPtr(nullptr, "scripting_Entity_Create");
    if (createEntity)
        this->entityID = reinterpret_cast<CreateEntity>(createEntity)(clsname);
    else
        NOT_SUPPORTED("scripting_Entity_Create");

    this->coords = new ECoords(this->entityID);
    this->angles = new Angles(this->entityID);
    this->color = new Colors(this->entityID);
}

Entity::~Entity()
{
    delete this->coords;
    delete this->angles;
    delete this->color;
}

void Entity::Spawn()
{
    if (this->entityID == 0)
    {
        print("[Swiftly] You can't use %s because the entity couldn't be created.\n", __FUNCTION__);
        return;
    }

    REGISTER_METHOD_VOID(scripting_Entity_Spawn, this->entityID);
}

void Entity::Destroy()
{
    if (this->entityID == 0)
    {
        print("[Swiftly] You can't use %s because the entity couldn't be created.\n", __FUNCTION__);
        return;
    }

    REGISTER_METHOD_VOID(scripting_Entity_Destroy, this->entityID);
}

void Entity::SetModel(const char *model)
{
    if (this->entityID == 0)
    {
        print("[Swiftly] You can't use %s because the entity couldn't be created.\n", __FUNCTION__);
        return;
    }
    if (model == nullptr)
        return;

    REGISTER_METHOD_VOID(scripting_Entity_SetModel, this->entityID, model);
}

void Entity::AcceptInput(const char *input, const char *activator, const char *caller, double *value)
{
    if (this->entityID == 0)
    {
        print("[Swiftly] You can't use %s because the entity couldn't be created.\n", __FUNCTION__);
        return;
    }
    if (input == nullptr)
        return;

    REGISTER_METHOD_VOID(scripting_Entity_AcceptInput, this->entityID, input, activator, caller, value);
}

void Entity::SetCollisionGroup(CollisionGroup collisionGroup)
{
    if (this->entityID == 0)
    {
        print("[Swiftly] You can't use %s because the entity couldn't be created.\n", __FUNCTION__);
        return;
    }

    REGISTER_METHOD_VOID(scripting_Entity_SetCollisionGroup, this->entityID, collisionGroup);
}