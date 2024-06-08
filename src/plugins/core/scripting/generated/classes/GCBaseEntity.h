class GCBaseEntity;

#ifndef _gccbaseentity_h
#define _gccbaseentity_h

#include "../../../scripting.h"

#include "../types/GTakeDamageFlags_t.h"
#include "../types/GBloodType.h"
#include "GCBodyComponent.h"
#include "GCNetworkTransmitComponent.h"
#include "Gthinkfunc_t.h"
#include "GResponseContext_t.h"
#include "GCBaseFilter.h"
#include "GCEntityIOOutput.h"
#include "GCNetworkVelocityVector.h"
#include "GCCollisionProperty.h"
#include "GCBaseEntity.h"

class GCBaseEntity
{
private:
    void *m_ptr;

public:
    GCBaseEntity() {}
    GCBaseEntity(void *ptr) : m_ptr(ptr) {}

    GCBodyComponent* GetCBodyComponent() const { return GetSchemaValue<GCBodyComponent*>(m_ptr, "CBaseEntity", "m_CBodyComponent"); }
    void SetCBodyComponent(GCBodyComponent* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'CBodyComponent' is not possible.\n"); }
    GCNetworkTransmitComponent GetNetworkTransmitComponent() const { return GetSchemaValue<GCNetworkTransmitComponent>(m_ptr, "CBaseEntity", "m_NetworkTransmitComponent"); }
    void SetNetworkTransmitComponent(GCNetworkTransmitComponent value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_NetworkTransmitComponent", false, value); }
    std::vector<Gthinkfunc_t> GetThinkFunctions() const { CUtlVector<Gthinkfunc_t>* vec = GetSchemaValue<CUtlVector<Gthinkfunc_t>*>(m_ptr, "CBaseEntity", "m_aThinkFunctions"); std::vector<Gthinkfunc_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetThinkFunctions(std::vector<Gthinkfunc_t> value) { SetSchemaValueCUtlVector<Gthinkfunc_t>(m_ptr, "CBaseEntity", "m_aThinkFunctions", false, value); }
    int32_t GetCurrentThinkContext() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_iCurrentThinkContext"); }
    void SetCurrentThinkContext(int32_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_iCurrentThinkContext", false, value); }
    bool GetDisabledContextThinks() const { return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bDisabledContextThinks"); }
    void SetDisabledContextThinks(bool value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_bDisabledContextThinks", false, value); }
    float GetLastNetworkChange() const { return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_lastNetworkChange"); }
    void SetLastNetworkChange(float value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_lastNetworkChange", false, value); }
    std::vector<GResponseContext_t> GetResponseContexts() const { CUtlVector<GResponseContext_t>* vec = GetSchemaValue<CUtlVector<GResponseContext_t>*>(m_ptr, "CBaseEntity", "m_ResponseContexts"); std::vector<GResponseContext_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetResponseContexts(std::vector<GResponseContext_t> value) { SetSchemaValueCUtlVector<GResponseContext_t>(m_ptr, "CBaseEntity", "m_ResponseContexts", false, value); }
    CUtlSymbolLarge GetResponseContext() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseEntity", "m_iszResponseContext"); }
    void SetResponseContext(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_iszResponseContext", false, value); }
    int32_t GetHealth() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_iHealth"); }
    void SetHealth(int32_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_iHealth", false, value); }
    int32_t GetMaxHealth() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_iMaxHealth"); }
    void SetMaxHealth(int32_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_iMaxHealth", false, value); }
    uint8_t GetLifeState() const { return GetSchemaValue<uint8_t>(m_ptr, "CBaseEntity", "m_lifeState"); }
    void SetLifeState(uint8_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_lifeState", false, value); }
    float GetDamageAccumulator() const { return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flDamageAccumulator"); }
    void SetDamageAccumulator(float value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_flDamageAccumulator", false, value); }
    bool GetTakesDamage() const { return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bTakesDamage"); }
    void SetTakesDamage(bool value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_bTakesDamage", false, value); }
    TakeDamageFlags_t GetTakeDamageFlags() const { return GetSchemaValue<TakeDamageFlags_t>(m_ptr, "CBaseEntity", "m_nTakeDamageFlags"); }
    void SetTakeDamageFlags(TakeDamageFlags_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_nTakeDamageFlags", false, value); }
    bool GetIsPlatform() const { return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bIsPlatform"); }
    void SetIsPlatform(bool value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_bIsPlatform", false, value); }
    MoveCollide_t GetMoveCollide() const { return GetSchemaValue<MoveCollide_t>(m_ptr, "CBaseEntity", "m_MoveCollide"); }
    void SetMoveCollide(MoveCollide_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_MoveCollide", false, value); }
    MoveType_t GetMoveType() const { return GetSchemaValue<MoveType_t>(m_ptr, "CBaseEntity", "m_MoveType"); }
    void SetMoveType(MoveType_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_MoveType", false, value); }
    MoveType_t GetActualMoveType() const { return GetSchemaValue<MoveType_t>(m_ptr, "CBaseEntity", "m_nActualMoveType"); }
    void SetActualMoveType(MoveType_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_nActualMoveType", false, value); }
    uint8_t GetWaterTouch() const { return GetSchemaValue<uint8_t>(m_ptr, "CBaseEntity", "m_nWaterTouch"); }
    void SetWaterTouch(uint8_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_nWaterTouch", false, value); }
    uint8_t GetSlimeTouch() const { return GetSchemaValue<uint8_t>(m_ptr, "CBaseEntity", "m_nSlimeTouch"); }
    void SetSlimeTouch(uint8_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_nSlimeTouch", false, value); }
    bool GetRestoreInHierarchy() const { return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bRestoreInHierarchy"); }
    void SetRestoreInHierarchy(bool value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_bRestoreInHierarchy", false, value); }
    CUtlSymbolLarge GetTarget() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseEntity", "m_target"); }
    void SetTarget(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_target", false, value); }
    GCBaseFilter* GetDamageFilter() const { return GetSchemaValue<GCBaseFilter*>(m_ptr, "CBaseEntity", "m_hDamageFilter"); }
    void SetDamageFilter(GCBaseFilter* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'DamageFilter' is not possible.\n"); }
    CUtlSymbolLarge GetDamageFilterName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseEntity", "m_iszDamageFilterName"); }
    void SetDamageFilterName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_iszDamageFilterName", false, value); }
    float GetMoveDoneTime() const { return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flMoveDoneTime"); }
    void SetMoveDoneTime(float value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_flMoveDoneTime", false, value); }
    CUtlStringToken GetSubclassID() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "CBaseEntity", "m_nSubclassID"); }
    void SetSubclassID(CUtlStringToken value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_nSubclassID", false, value); }
    float GetAnimTime() const { return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flAnimTime"); }
    void SetAnimTime(float value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_flAnimTime", false, value); }
    float GetSimulationTime() const { return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flSimulationTime"); }
    void SetSimulationTime(float value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_flSimulationTime", false, value); }
    bool GetClientSideRagdoll() const { return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bClientSideRagdoll"); }
    void SetClientSideRagdoll(bool value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_bClientSideRagdoll", false, value); }
    uint8_t GetInterpolationFrame() const { return GetSchemaValue<uint8_t>(m_ptr, "CBaseEntity", "m_ubInterpolationFrame"); }
    void SetInterpolationFrame(uint8_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_ubInterpolationFrame", false, value); }
    Vector GetPrevVPhysicsUpdatePos() const { return GetSchemaValue<Vector>(m_ptr, "CBaseEntity", "m_vPrevVPhysicsUpdatePos"); }
    void SetPrevVPhysicsUpdatePos(Vector value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_vPrevVPhysicsUpdatePos", false, value); }
    uint8_t GetTeamNum() const { return GetSchemaValue<uint8_t>(m_ptr, "CBaseEntity", "m_iTeamNum"); }
    void SetTeamNum(uint8_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_iTeamNum", false, value); }
    CUtlSymbolLarge GetGlobalname() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseEntity", "m_iGlobalname"); }
    void SetGlobalname(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_iGlobalname", false, value); }
    int32_t GetSentToClients() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_iSentToClients"); }
    void SetSentToClients(int32_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_iSentToClients", false, value); }
    float GetSpeed() const { return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flSpeed"); }
    void SetSpeed(float value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_flSpeed", false, value); }
    CUtlString GetUniqueHammerID() const { return GetSchemaValue<CUtlString>(m_ptr, "CBaseEntity", "m_sUniqueHammerID"); }
    void SetUniqueHammerID(CUtlString value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_sUniqueHammerID", false, value); }
    uint32_t GetSpawnflags() const { return GetSchemaValue<uint32_t>(m_ptr, "CBaseEntity", "m_spawnflags"); }
    void SetSpawnflags(uint32_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_spawnflags", false, value); }
    int32_t GetSimulationTick() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_nSimulationTick"); }
    void SetSimulationTick(int32_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_nSimulationTick", false, value); }
    GCEntityIOOutput GetOnKilled() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseEntity", "m_OnKilled"); }
    void SetOnKilled(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_OnKilled", false, value); }
    uint32_t GetFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "CBaseEntity", "m_fFlags"); }
    void SetFlags(uint32_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_fFlags", false, value); }
    Vector GetAbsVelocity() const { return GetSchemaValue<Vector>(m_ptr, "CBaseEntity", "m_vecAbsVelocity"); }
    void SetAbsVelocity(Vector value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_vecAbsVelocity", false, value); }
    GCNetworkVelocityVector GetVelocity() const { return GetSchemaValue<GCNetworkVelocityVector>(m_ptr, "CBaseEntity", "m_vecVelocity"); }
    void SetVelocity(GCNetworkVelocityVector value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_vecVelocity", false, value); }
    Vector GetBaseVelocity() const { return GetSchemaValue<Vector>(m_ptr, "CBaseEntity", "m_vecBaseVelocity"); }
    void SetBaseVelocity(Vector value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_vecBaseVelocity", false, value); }
    int32_t GetPushEnumCount() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_nPushEnumCount"); }
    void SetPushEnumCount(int32_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_nPushEnumCount", false, value); }
    GCCollisionProperty* GetCollision() const { return GetSchemaValue<GCCollisionProperty*>(m_ptr, "CBaseEntity", "m_pCollision"); }
    void SetCollision(GCCollisionProperty* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Collision' is not possible.\n"); }
    GCBaseEntity* GetEffectEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CBaseEntity", "m_hEffectEntity"); }
    void SetEffectEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'EffectEntity' is not possible.\n"); }
    GCBaseEntity* GetOwnerEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CBaseEntity", "m_hOwnerEntity"); }
    void SetOwnerEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'OwnerEntity' is not possible.\n"); }
    uint32_t GetEffects() const { return GetSchemaValue<uint32_t>(m_ptr, "CBaseEntity", "m_fEffects"); }
    void SetEffects(uint32_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_fEffects", false, value); }
    GCBaseEntity* GetGroundEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CBaseEntity", "m_hGroundEntity"); }
    void SetGroundEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'GroundEntity' is not possible.\n"); }
    int32_t GetGroundBodyIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_nGroundBodyIndex"); }
    void SetGroundBodyIndex(int32_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_nGroundBodyIndex", false, value); }
    float GetFriction() const { return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flFriction"); }
    void SetFriction(float value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_flFriction", false, value); }
    float GetElasticity() const { return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flElasticity"); }
    void SetElasticity(float value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_flElasticity", false, value); }
    float GetGravityScale() const { return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flGravityScale"); }
    void SetGravityScale(float value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_flGravityScale", false, value); }
    float GetTimeScale() const { return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flTimeScale"); }
    void SetTimeScale(float value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_flTimeScale", false, value); }
    float GetWaterLevel() const { return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flWaterLevel"); }
    void SetWaterLevel(float value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_flWaterLevel", false, value); }
    bool GetAnimatedEveryTick() const { return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bAnimatedEveryTick"); }
    void SetAnimatedEveryTick(bool value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_bAnimatedEveryTick", false, value); }
    bool GetDisableLowViolence() const { return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bDisableLowViolence"); }
    void SetDisableLowViolence(bool value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_bDisableLowViolence", false, value); }
    uint8_t GetWaterType() const { return GetSchemaValue<uint8_t>(m_ptr, "CBaseEntity", "m_nWaterType"); }
    void SetWaterType(uint8_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_nWaterType", false, value); }
    int32_t GetEFlags() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_iEFlags"); }
    void SetEFlags(int32_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_iEFlags", false, value); }
    GCEntityIOOutput GetOnUser1() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseEntity", "m_OnUser1"); }
    void SetOnUser1(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_OnUser1", false, value); }
    GCEntityIOOutput GetOnUser2() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseEntity", "m_OnUser2"); }
    void SetOnUser2(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_OnUser2", false, value); }
    GCEntityIOOutput GetOnUser3() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseEntity", "m_OnUser3"); }
    void SetOnUser3(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_OnUser3", false, value); }
    GCEntityIOOutput GetOnUser4() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseEntity", "m_OnUser4"); }
    void SetOnUser4(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_OnUser4", false, value); }
    int32_t GetInitialTeamNum() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseEntity", "m_iInitialTeamNum"); }
    void SetInitialTeamNum(int32_t value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_iInitialTeamNum", false, value); }
    QAngle GetAngVelocity() const { return GetSchemaValue<QAngle>(m_ptr, "CBaseEntity", "m_vecAngVelocity"); }
    void SetAngVelocity(QAngle value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_vecAngVelocity", false, value); }
    bool GetNetworkQuantizeOriginAndAngles() const { return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bNetworkQuantizeOriginAndAngles"); }
    void SetNetworkQuantizeOriginAndAngles(bool value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_bNetworkQuantizeOriginAndAngles", false, value); }
    bool GetLagCompensate() const { return GetSchemaValue<bool>(m_ptr, "CBaseEntity", "m_bLagCompensate"); }
    void SetLagCompensate(bool value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_bLagCompensate", false, value); }
    float GetOverriddenFriction() const { return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flOverriddenFriction"); }
    void SetOverriddenFriction(float value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_flOverriddenFriction", false, value); }
    GCBaseEntity* GetBlocker() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CBaseEntity", "m_pBlocker"); }
    void SetBlocker(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Blocker' is not possible.\n"); }
    float GetLocalTime() const { return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flLocalTime"); }
    void SetLocalTime(float value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_flLocalTime", false, value); }
    float GetVPhysicsUpdateLocalTime() const { return GetSchemaValue<float>(m_ptr, "CBaseEntity", "m_flVPhysicsUpdateLocalTime"); }
    void SetVPhysicsUpdateLocalTime(float value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_flVPhysicsUpdateLocalTime", false, value); }
    BloodType GetBloodType() const { return GetSchemaValue<BloodType>(m_ptr, "CBaseEntity", "m_nBloodType"); }
    void SetBloodType(BloodType value) { SetSchemaValue(m_ptr, "CBaseEntity", "m_nBloodType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif