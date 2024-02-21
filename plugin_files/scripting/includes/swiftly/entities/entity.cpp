#include "entity.h"
#include "../swiftly.h"

typedef uint32_t (*CreateEntity)();
typedef void (*Entity_Spawn)(uint32_t);
typedef void (*Entity_Destroy)(uint32_t);
typedef void (*Entity_SetModel)(uint32_t, const char *);
typedef void (*Entity_AcceptInput)(uint32_t, const char *, const char *, const char *, double *);

Entity::Entity()
{
    void *createEntity = FetchFunctionPtr(nullptr, "scripting_Entity_Create");
    if (createEntity)
        this->entityID = reinterpret_cast<CreateEntity>(createEntity)();
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

    void *spawnEntity = FetchFunctionPtr(nullptr, "scripting_Entity_Spawn");
    if (spawnEntity)
        reinterpret_cast<Entity_Spawn>(spawnEntity)(this->entityID);
    else
        NOT_SUPPORTED("scripting_Entity_Spawn");
}

void Entity::Destroy()
{
    if (this->entityID == 0)
    {
        print("[Swiftly] You can't use %s because the entity couldn't be created.\n", __FUNCTION__);
        return;
    }

    void *destroyEntity = FetchFunctionPtr(nullptr, "scripting_Entity_Destroy");
    if (destroyEntity)
        reinterpret_cast<Entity_Destroy>(destroyEntity)(this->entityID);
    else
        NOT_SUPPORTED("scripting_Entity_Destroy");
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

    void *setModelEntity = FetchFunctionPtr(nullptr, "scripting_Entity_SetModel");
    if (setModelEntity)
        reinterpret_cast<Entity_SetModel>(setModelEntity)(this->entityID, model);
    else
        NOT_SUPPORTED("scripting_Entity_SetModel");
}

void Entity::AcceptInput(const char *input, const char *activator = nullptr, const char *caller = nullptr, double *value = nullptr)
{
    if (this->entityID == 0)
    {
        print("[Swiftly] You can't use %s because the entity couldn't be created.\n", __FUNCTION__);
        return;
    }
    if (input == nullptr)
        return;

    void *acceptInputEntity = FetchFunctionPtr(nullptr, "scripting_Entity_AcceptInput");
    if (acceptInputEntity)
        reinterpret_cast<Entity_AcceptInput>(acceptInputEntity)(this->entityID, input, activator, caller, value);
    else
        NOT_SUPPORTED("scripting_Entity_AcceptInput");
}