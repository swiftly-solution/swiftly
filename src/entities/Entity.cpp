#include "Entity.h"

#include <thread>

typedef void *(*UTIL_CreateEntityByName)(const char *, int);

Entity::Entity()
{
    this->worldEntity = reinterpret_cast<CBaseModelEntity *>(g_Signatures->FetchSignature<UTIL_CreateEntityByName>("UTIL_CreateEntityByName")("prop_dynamic_override", -1));
    if (this->worldEntity == nullptr)
        PRINTF("Entity::Entity", "Failed to create entity.\n");
}

Entity::Entity(CEntityInstance *entityInstance)
{
    this->worldEntity = (CBaseModelEntity *)entityInstance;
}

Vector Entity::GetCoords()
{
    return this->worldEntity->m_CBodyComponent->m_pSceneNode->m_vecAbsOrigin();
}

QAngle Entity::GetAngle()
{
    return this->worldEntity->m_CBodyComponent->m_pSceneNode->m_angAbsRotation();
}

void Entity::SetCoords(float x, float y, float z)
{
    Vector vec(x, y, z);

    this->worldEntity->m_CBodyComponent->m_pSceneNode->m_vecAbsOrigin = vec;
}

void Entity::SetAngle(float x, float y, float z)
{
    QAngle angle(x, y, z);
    this->worldEntity->m_CBodyComponent->m_pSceneNode->m_angAbsRotation = angle;
}

void Entity::SetSolidType(SolidType_t solid_type)
{
    this->worldEntity->m_Collision.Get().m_nSolidType = solid_type;
}

void Entity::SetModel(std::string model)
{
    bool hasModel = (g_precacher->HasModelInList(model));
    if (!hasModel)
    {
        g_precacher->AddModel(model);
        PRINTF("Precacher", "Model '%s' was not precached before and it was added to the list.\n", model.c_str());
        PRINT("Precacher", "It may work on the second map change if the model is valid.\n");
    }

    this->model = model;

    if (hasModel && this->spawned)
        this->SetModel(model.c_str());
}

void Entity::Spawn()
{
    if (this->spawned)
        return;

    this->spawned = true;
    this->worldEntity->Spawn();

    CBaseModelEntity *ent = this->worldEntity;
    std::string mod = this->model;

    g_Plugin.NextFrame([ent, mod]() -> void
                       { ent->SetModel(mod.c_str()); });
}

void Entity::Destroy()
{
    this->worldEntity->Despawn();
    this->spawned = false;
}

Color Entity::GetColor()
{
    return this->worldEntity->m_clrRender();
}

void Entity::SetColor(int r, int g, int b, int a)
{
    Color color(r, g, b, a);

    this->worldEntity->m_clrRender = color;
}