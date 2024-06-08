class GCBaseCombatCharacter;

#ifndef _gccbasecombatcharacter_h
#define _gccbasecombatcharacter_h

#include "../../../scripting.h"

#include "../types/GHitGroup_t.h"
#include "../types/GHull_t.h"
#include "GCEconWearable.h"

class GCBaseCombatCharacter
{
private:
    void *m_ptr;

public:
    GCBaseCombatCharacter() {}
    GCBaseCombatCharacter(void *ptr) : m_ptr(ptr) {}

    bool GetForceServerRagdoll() const { return GetSchemaValue<bool>(m_ptr, "CBaseCombatCharacter", "m_bForceServerRagdoll"); }
    void SetForceServerRagdoll(bool value) { SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_bForceServerRagdoll", false, value); }
    GCEconWearable* GetMyWearables() const { return GetSchemaValue<GCEconWearable*>(m_ptr, "CBaseCombatCharacter", "m_hMyWearables"); }
    void SetMyWearables(GCEconWearable* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'MyWearables' is not possible.\n"); }
    float GetFieldOfView() const { return GetSchemaValue<float>(m_ptr, "CBaseCombatCharacter", "m_flFieldOfView"); }
    void SetFieldOfView(float value) { SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_flFieldOfView", false, value); }
    float GetImpactEnergyScale() const { return GetSchemaValue<float>(m_ptr, "CBaseCombatCharacter", "m_impactEnergyScale"); }
    void SetImpactEnergyScale(float value) { SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_impactEnergyScale", false, value); }
    HitGroup_t GetLastHitGroup() const { return GetSchemaValue<HitGroup_t>(m_ptr, "CBaseCombatCharacter", "m_LastHitGroup"); }
    void SetLastHitGroup(HitGroup_t value) { SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_LastHitGroup", false, value); }
    bool GetApplyStressDamage() const { return GetSchemaValue<bool>(m_ptr, "CBaseCombatCharacter", "m_bApplyStressDamage"); }
    void SetApplyStressDamage(bool value) { SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_bApplyStressDamage", false, value); }
    int32_t GetDamageCount() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseCombatCharacter", "m_iDamageCount"); }
    void SetDamageCount(int32_t value) { SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_iDamageCount", false, value); }
    CUtlSymbolLarge GetStrRelationships() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseCombatCharacter", "m_strRelationships"); }
    void SetStrRelationships(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_strRelationships", false, value); }
    Hull_t GetHull() const { return GetSchemaValue<Hull_t>(m_ptr, "CBaseCombatCharacter", "m_eHull"); }
    void SetHull(Hull_t value) { SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_eHull", false, value); }
    uint32_t GetNavHullIdx() const { return GetSchemaValue<uint32_t>(m_ptr, "CBaseCombatCharacter", "m_nNavHullIdx"); }
    void SetNavHullIdx(uint32_t value) { SetSchemaValue(m_ptr, "CBaseCombatCharacter", "m_nNavHullIdx", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif