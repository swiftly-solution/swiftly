class GCRagdollProp;

#ifndef _gccragdollprop_h
#define _gccragdollprop_h

#include "../../../scripting.h"


#include "Gragdoll_t.h"
#include "GCBaseEntity.h"
#include "GCBasePlayerPawn.h"

class GCRagdollProp
{
private:
    void *m_ptr;

public:
    GCRagdollProp() {}
    GCRagdollProp(void *ptr) : m_ptr(ptr) {}

    Gragdoll_t GetRagdoll() const { return GetSchemaValue<Gragdoll_t>(m_ptr, "CRagdollProp", "m_ragdoll"); }
    void SetRagdoll(Gragdoll_t value) { SetSchemaValue(m_ptr, "CRagdollProp", "m_ragdoll", false, value); }
    bool GetStartDisabled() const { return GetSchemaValue<bool>(m_ptr, "CRagdollProp", "m_bStartDisabled"); }
    void SetStartDisabled(bool value) { SetSchemaValue(m_ptr, "CRagdollProp", "m_bStartDisabled", false, value); }
    std::vector<Vector> GetRagPos() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CRagdollProp", "m_ragPos"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRagPos(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "CRagdollProp", "m_ragPos", false, value); }
    std::vector<QAngle> GetRagAngles() const { CUtlVector<QAngle>* vec = GetSchemaValue<CUtlVector<QAngle>*>(m_ptr, "CRagdollProp", "m_ragAngles"); std::vector<QAngle> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRagAngles(std::vector<QAngle> value) { SetSchemaValueCUtlVector<QAngle>(m_ptr, "CRagdollProp", "m_ragAngles", false, value); }
    GCBaseEntity* GetRagdollSource() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CRagdollProp", "m_hRagdollSource"); }
    void SetRagdollSource(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'RagdollSource' is not possible.\n"); }
    uint32_t GetLastUpdateTickCount() const { return GetSchemaValue<uint32_t>(m_ptr, "CRagdollProp", "m_lastUpdateTickCount"); }
    void SetLastUpdateTickCount(uint32_t value) { SetSchemaValue(m_ptr, "CRagdollProp", "m_lastUpdateTickCount", false, value); }
    bool GetAllAsleep() const { return GetSchemaValue<bool>(m_ptr, "CRagdollProp", "m_allAsleep"); }
    void SetAllAsleep(bool value) { SetSchemaValue(m_ptr, "CRagdollProp", "m_allAsleep", false, value); }
    bool GetFirstCollisionAfterLaunch() const { return GetSchemaValue<bool>(m_ptr, "CRagdollProp", "m_bFirstCollisionAfterLaunch"); }
    void SetFirstCollisionAfterLaunch(bool value) { SetSchemaValue(m_ptr, "CRagdollProp", "m_bFirstCollisionAfterLaunch", false, value); }
    GCBaseEntity* GetDamageEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CRagdollProp", "m_hDamageEntity"); }
    void SetDamageEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'DamageEntity' is not possible.\n"); }
    GCBaseEntity* GetKiller() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CRagdollProp", "m_hKiller"); }
    void SetKiller(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Killer' is not possible.\n"); }
    GCBasePlayerPawn* GetPhysicsAttacker() const { return GetSchemaValue<GCBasePlayerPawn*>(m_ptr, "CRagdollProp", "m_hPhysicsAttacker"); }
    void SetPhysicsAttacker(GCBasePlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PhysicsAttacker' is not possible.\n"); }
    float GetFadeTime() const { return GetSchemaValue<float>(m_ptr, "CRagdollProp", "m_flFadeTime"); }
    void SetFadeTime(float value) { SetSchemaValue(m_ptr, "CRagdollProp", "m_flFadeTime", false, value); }
    Vector GetLastOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CRagdollProp", "m_vecLastOrigin"); }
    void SetLastOrigin(Vector value) { SetSchemaValue(m_ptr, "CRagdollProp", "m_vecLastOrigin", false, value); }
    CUtlSymbolLarge GetStrOriginClassName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CRagdollProp", "m_strOriginClassName"); }
    void SetStrOriginClassName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CRagdollProp", "m_strOriginClassName", false, value); }
    CUtlSymbolLarge GetStrSourceClassName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CRagdollProp", "m_strSourceClassName"); }
    void SetStrSourceClassName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CRagdollProp", "m_strSourceClassName", false, value); }
    bool GetHasBeenPhysgunned() const { return GetSchemaValue<bool>(m_ptr, "CRagdollProp", "m_bHasBeenPhysgunned"); }
    void SetHasBeenPhysgunned(bool value) { SetSchemaValue(m_ptr, "CRagdollProp", "m_bHasBeenPhysgunned", false, value); }
    bool GetShouldTeleportPhysics() const { return GetSchemaValue<bool>(m_ptr, "CRagdollProp", "m_bShouldTeleportPhysics"); }
    void SetShouldTeleportPhysics(bool value) { SetSchemaValue(m_ptr, "CRagdollProp", "m_bShouldTeleportPhysics", false, value); }
    float GetBlendWeight() const { return GetSchemaValue<float>(m_ptr, "CRagdollProp", "m_flBlendWeight"); }
    void SetBlendWeight(float value) { SetSchemaValue(m_ptr, "CRagdollProp", "m_flBlendWeight", false, value); }
    float GetDefaultFadeScale() const { return GetSchemaValue<float>(m_ptr, "CRagdollProp", "m_flDefaultFadeScale"); }
    void SetDefaultFadeScale(float value) { SetSchemaValue(m_ptr, "CRagdollProp", "m_flDefaultFadeScale", false, value); }
    std::vector<Vector> GetRagdollMins() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CRagdollProp", "m_ragdollMins"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRagdollMins(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "CRagdollProp", "m_ragdollMins", false, value); }
    std::vector<Vector> GetRagdollMaxs() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CRagdollProp", "m_ragdollMaxs"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRagdollMaxs(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "CRagdollProp", "m_ragdollMaxs", false, value); }
    bool GetShouldDeleteActivationRecord() const { return GetSchemaValue<bool>(m_ptr, "CRagdollProp", "m_bShouldDeleteActivationRecord"); }
    void SetShouldDeleteActivationRecord(bool value) { SetSchemaValue(m_ptr, "CRagdollProp", "m_bShouldDeleteActivationRecord", false, value); }
    bool GetValidatePoweredRagdollPose() const { return GetSchemaValue<bool>(m_ptr, "CRagdollProp", "m_bValidatePoweredRagdollPose"); }
    void SetValidatePoweredRagdollPose(bool value) { SetSchemaValue(m_ptr, "CRagdollProp", "m_bValidatePoweredRagdollPose", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif