#pragma once

#include "../../entrypoint.h"
#include "../schema.h"
#include "../../signatures/Offsets.h"
#include "../../common.h"
#include "globaltypes.h"
#include "CCollisionProperty.h"
#include "ehandle.h"
#include <public/mathlib/vector.h>

#define CS_TEAM_NONE 0
#define CS_TEAM_SPECTATOR 1
#define CS_TEAM_T 2
#define CS_TEAM_CT 3

inline CEntityInstance* UTIL_FindEntityByClassname(CEntityInstance* pStart, const char* name)
{
    extern CEntitySystem* g_pEntitySystem;
    CEntityIdentity* pEntity = pStart ? pStart->m_pEntity->m_pNext : g_pEntitySystem->m_EntityList.m_pFirstActiveEntity;

    for (; pEntity; pEntity = pEntity->m_pNext)
    {
        if (!strcmp(pEntity->m_designerName.String(), name))
            return pEntity->m_pInstance;
    };

    return nullptr;
}

class CEntitySubclassVDataBase
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CEntitySubclassVDataBase, false)
};

class CModelState
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CModelState, true)

    SCHEMA_FIELD_OFFSET(uint64_t, m_MeshGroupMask, 0)
};

class CSkeletonInstance
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CSkeletonInstance, false)

    SCHEMA_FIELD_POINTER_OFFSET(CModelState, m_modelState, 0)
};

class CGameSceneNode
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CGameSceneNode, false)

    SCHEMA_FIELD_OFFSET(CEntityInstance*, m_pOwner, 0);
    SCHEMA_FIELD_OFFSET(CGameSceneNode*, m_pParent, 0);
    SCHEMA_FIELD_OFFSET(CGameSceneNode*, m_pChild, 0);
    SCHEMA_FIELD_OFFSET(CNetworkOriginCellCoordQuantizedVector, m_vecOrigin, 0);
    SCHEMA_FIELD_OFFSET(QAngle, m_angRotation, 0);
    SCHEMA_FIELD_OFFSET(float, m_flScale, 0);
    SCHEMA_FIELD_OFFSET(float, m_flAbsScale, 0);
    SCHEMA_FIELD_OFFSET(Vector, m_vecAbsOrigin, 0);
    SCHEMA_FIELD_OFFSET(QAngle, m_angAbsRotation, 0);
    SCHEMA_FIELD_OFFSET(Vector, m_vRenderOrigin, 0);

    matrix3x4_t EntityToWorldTransform()
    {
        matrix3x4_t mat;

        // issues with this and im tired so hardcoded it
        // AngleMatrix(this->m_angAbsRotation(), this->m_vecAbsOrigin(), mat);

        QAngle angles = this->m_angAbsRotation();
        float sr, sp, sy, cr, cp, cy;
        SinCos(DEG2RAD(angles[YAW]), &sy, &cy);
        SinCos(DEG2RAD(angles[PITCH]), &sp, &cp);
        SinCos(DEG2RAD(angles[ROLL]), &sr, &cr);
        mat[0][0] = cp * cy;
        mat[1][0] = cp * sy;
        mat[2][0] = -sp;

        float crcy = cr * cy;
        float crsy = cr * sy;
        float srcy = sr * cy;
        float srsy = sr * sy;
        mat[0][1] = sp * srcy - crsy;
        mat[1][1] = sp * srsy + crcy;
        mat[2][1] = sr * cp;

        mat[0][2] = (sp * crcy + srsy);
        mat[1][2] = (sp * crsy - srcy);
        mat[2][2] = cr * cp;

        Vector pos = this->m_vecAbsOrigin();
        mat[0][3] = pos.x;
        mat[1][3] = pos.y;
        mat[2][3] = pos.z;

        return mat;
    }

    CSkeletonInstance* GetSkeletonInstance()
    {
        return CALL_VIRTUAL(CSkeletonInstance*, 8, this);
    }
};

class CBodyComponent
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CBodyComponent, false)

    SCHEMA_FIELD_OFFSET(CGameSceneNode*, m_pSceneNode, 0)
};

class CBaseEntity : public CEntityInstance
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CBaseEntity, false)

    SCHEMA_FIELD_OFFSET(CBitVec<64>, m_isSteadyState, 0);
    SCHEMA_FIELD_OFFSET(float, m_lastNetworkChange, 0);
    SCHEMA_FIELD_POINTER_OFFSET(CNetworkTransmitComponent, m_NetworkTransmitComponent, 0);
    SCHEMA_FIELD_OFFSET(int, m_iHealth, 0);
    SCHEMA_FIELD_OFFSET(int, m_iMaxHealth, 0);
    SCHEMA_FIELD_OFFSET(int, m_iTeamNum, 0);
    SCHEMA_FIELD_OFFSET(MoveType_t, m_MoveType, 0);
    SCHEMA_FIELD_OFFSET(uint32, m_spawnflags, 0);
    SCHEMA_FIELD_OFFSET(uint32, m_fFlags, 0);
    SCHEMA_FIELD_OFFSET(LifeState_t, m_lifeState, 0);
    SCHEMA_FIELD_OFFSET(CCollisionProperty*, m_pCollision, 0);
    SCHEMA_FIELD_OFFSET(CBodyComponent*, m_CBodyComponent, 0);
    SCHEMA_FIELD_OFFSET(Vector, m_vecAbsVelocity, 0);
    SCHEMA_FIELD_POINTER_OFFSET(CUtlStringToken, m_nSubclassID, 0);
    SCHEMA_FIELD_OFFSET(CUtlSymbolLarge, m_iGlobalname, 0);
    SCHEMA_FIELD_OFFSET(float, m_flGravityScale, 0);

    int EntityIndex() { return this->m_pEntity->GetRefEHandle().GetEntryIndex(); }
    int entindex() { return m_pEntity->m_EHandle.GetEntryIndex(); }

    void Teleport(Vector* position, QAngle* angles, Vector* velocity)
    {
        static int offset = g_Offsets->GetOffset("CBaseEntity_Teleport");
        CALL_VIRTUAL(void, offset, this, position, angles, velocity);
    }

    void TakeDamage(int damage)
    {
        this->m_iHealth = this->m_iHealth() - damage;
    }

    void DispatchSpawn()
    {
        g_Signatures->FetchSignature<CBaseEntity_DispatchSpawn>("CBaseEntity_DispatchSpawn")(this, nullptr);
    }

    void Despawn()
    {
        g_Signatures->FetchSignature<UTIL_Remove>("UTIL_Remove")(this);
    }

    void AcceptInput(const char* pInputName, CEntityInstance* pActivator = nullptr, CEntityInstance* pCaller = nullptr, const char* value = nullptr, int outputID = 0)
    {
        variant_t variantValue = variant_t(value);
        g_Signatures->FetchSignature<CEntityInstance_AcceptInput>("CEntityInstance_AcceptInput")(this, pInputName, pActivator, pCaller, &variantValue, outputID);
    }

    void EmitSoundFilter(IRecipientFilter& filter, std::string sound_name, int pitch, float volume)
    {
        EmitSound_t params;
        params.m_pSoundName = sound_name.c_str();
        params.m_flVolume = volume;
        params.m_nPitch = pitch;

        g_Signatures->FetchSignature<CBaseEntity_EmitSoundFilter>("CBaseEntity_EmitSoundFilter")(filter, m_pEntity->m_EHandle.GetEntryIndex(), params);
    }

    void CollisionRulesChanged()
    {
        static int offset = g_Offsets->GetOffset("CollisionRulesChanged");
        CALL_VIRTUAL(void, offset, this);
    }

    CEntitySubclassVDataBase* GetVData() { return *(CEntitySubclassVDataBase**)((uint8*)(m_nSubclassID()) + 4); }
};