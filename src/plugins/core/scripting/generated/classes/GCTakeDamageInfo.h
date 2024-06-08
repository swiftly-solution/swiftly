class GCTakeDamageInfo;

#ifndef _gcctakedamageinfo_h
#define _gcctakedamageinfo_h

#include "../../../scripting.h"

#include "../types/GTakeDamageFlags_t.h"
#include "GCBaseEntity.h"

class GCTakeDamageInfo
{
private:
    void *m_ptr;

public:
    GCTakeDamageInfo() {}
    GCTakeDamageInfo(void *ptr) : m_ptr(ptr) {}

    Vector GetDamageForce() const { return GetSchemaValue<Vector>(m_ptr, "CTakeDamageInfo", "m_vecDamageForce"); }
    void SetDamageForce(Vector value) { SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_vecDamageForce", false, value); }
    Vector GetDamagePosition() const { return GetSchemaValue<Vector>(m_ptr, "CTakeDamageInfo", "m_vecDamagePosition"); }
    void SetDamagePosition(Vector value) { SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_vecDamagePosition", false, value); }
    Vector GetReportedPosition() const { return GetSchemaValue<Vector>(m_ptr, "CTakeDamageInfo", "m_vecReportedPosition"); }
    void SetReportedPosition(Vector value) { SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_vecReportedPosition", false, value); }
    Vector GetDamageDirection() const { return GetSchemaValue<Vector>(m_ptr, "CTakeDamageInfo", "m_vecDamageDirection"); }
    void SetDamageDirection(Vector value) { SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_vecDamageDirection", false, value); }
    GCBaseEntity* GetInflictor() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CTakeDamageInfo", "m_hInflictor"); }
    void SetInflictor(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Inflictor' is not possible.\n"); }
    GCBaseEntity* GetAttacker() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CTakeDamageInfo", "m_hAttacker"); }
    void SetAttacker(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Attacker' is not possible.\n"); }
    GCBaseEntity* GetAbility() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CTakeDamageInfo", "m_hAbility"); }
    void SetAbility(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Ability' is not possible.\n"); }
    float GetDamage() const { return GetSchemaValue<float>(m_ptr, "CTakeDamageInfo", "m_flDamage"); }
    void SetDamage(float value) { SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_flDamage", false, value); }
    float GetTotalledDamage() const { return GetSchemaValue<float>(m_ptr, "CTakeDamageInfo", "m_flTotalledDamage"); }
    void SetTotalledDamage(float value) { SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_flTotalledDamage", false, value); }
    int32_t GetBitsDamageType() const { return GetSchemaValue<int32_t>(m_ptr, "CTakeDamageInfo", "m_bitsDamageType"); }
    void SetBitsDamageType(int32_t value) { SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_bitsDamageType", false, value); }
    int32_t GetDamageCustom() const { return GetSchemaValue<int32_t>(m_ptr, "CTakeDamageInfo", "m_iDamageCustom"); }
    void SetDamageCustom(int32_t value) { SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_iDamageCustom", false, value); }
    uint8_t GetAmmoType() const { return GetSchemaValue<uint8_t>(m_ptr, "CTakeDamageInfo", "m_iAmmoType"); }
    void SetAmmoType(uint8_t value) { SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_iAmmoType", false, value); }
    float GetOriginalDamage() const { return GetSchemaValue<float>(m_ptr, "CTakeDamageInfo", "m_flOriginalDamage"); }
    void SetOriginalDamage(float value) { SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_flOriginalDamage", false, value); }
    bool GetShouldBleed() const { return GetSchemaValue<bool>(m_ptr, "CTakeDamageInfo", "m_bShouldBleed"); }
    void SetShouldBleed(bool value) { SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_bShouldBleed", false, value); }
    bool GetShouldSpark() const { return GetSchemaValue<bool>(m_ptr, "CTakeDamageInfo", "m_bShouldSpark"); }
    void SetShouldSpark(bool value) { SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_bShouldSpark", false, value); }
    TakeDamageFlags_t GetDamageFlags() const { return GetSchemaValue<TakeDamageFlags_t>(m_ptr, "CTakeDamageInfo", "m_nDamageFlags"); }
    void SetDamageFlags(TakeDamageFlags_t value) { SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_nDamageFlags", false, value); }
    int32_t GetNumObjectsPenetrated() const { return GetSchemaValue<int32_t>(m_ptr, "CTakeDamageInfo", "m_nNumObjectsPenetrated"); }
    void SetNumObjectsPenetrated(int32_t value) { SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_nNumObjectsPenetrated", false, value); }
    bool GetInTakeDamageFlow() const { return GetSchemaValue<bool>(m_ptr, "CTakeDamageInfo", "m_bInTakeDamageFlow"); }
    void SetInTakeDamageFlow(bool value) { SetSchemaValue(m_ptr, "CTakeDamageInfo", "m_bInTakeDamageFlow", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif