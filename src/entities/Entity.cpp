#include "Entity.h"

Entity::Entity()
{
    this->worldEntity = reinterpret_cast<CBaseModelEntity *>(g_Signatures->FetchSignature<UTIL_CreateEntityByName>("UTIL_CreateEntityByName")("prop_dynamic_override", -1));
    if (this->worldEntity == nullptr)
        PRINTF("Entity::Entity", "Failed to create entity.\n");
}

Vector Entity::GetCoords()
{
    return this->worldEntity->m_CBodyComponent->m_pSceneNode->m_vecAbsOrigin();
}

void Entity::SetCoords(float x, float y, float z)
{
    Vector vec(x, y, z);

    this->worldEntity->m_CBodyComponent->m_pSceneNode->m_vecAbsOrigin = vec;
}

void Entity::SetSolidType(SolidType_t solid_type)
{
    this->worldEntity->m_Collision.Get().m_nSolidType = solid_type;
}

void Entity::SetModel(std::string model)
{
    this->worldEntity->SetModel(model.c_str());
}

void Entity::Spawn()
{
    this->worldEntity->Spawn();
}
