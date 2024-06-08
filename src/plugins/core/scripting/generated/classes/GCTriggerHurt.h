class GCTriggerHurt;

#ifndef _gcctriggerhurt_h
#define _gcctriggerhurt_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCTriggerHurt
{
private:
    void *m_ptr;

public:
    GCTriggerHurt() {}
    GCTriggerHurt(void *ptr) : m_ptr(ptr) {}

    float GetOriginalDamage() const { return GetSchemaValue<float>(m_ptr, "CTriggerHurt", "m_flOriginalDamage"); }
    void SetOriginalDamage(float value) { SetSchemaValue(m_ptr, "CTriggerHurt", "m_flOriginalDamage", false, value); }
    float GetDamage() const { return GetSchemaValue<float>(m_ptr, "CTriggerHurt", "m_flDamage"); }
    void SetDamage(float value) { SetSchemaValue(m_ptr, "CTriggerHurt", "m_flDamage", false, value); }
    float GetDamageCap() const { return GetSchemaValue<float>(m_ptr, "CTriggerHurt", "m_flDamageCap"); }
    void SetDamageCap(float value) { SetSchemaValue(m_ptr, "CTriggerHurt", "m_flDamageCap", false, value); }
    float GetForgivenessDelay() const { return GetSchemaValue<float>(m_ptr, "CTriggerHurt", "m_flForgivenessDelay"); }
    void SetForgivenessDelay(float value) { SetSchemaValue(m_ptr, "CTriggerHurt", "m_flForgivenessDelay", false, value); }
    int32_t GetBitsDamageInflict() const { return GetSchemaValue<int32_t>(m_ptr, "CTriggerHurt", "m_bitsDamageInflict"); }
    void SetBitsDamageInflict(int32_t value) { SetSchemaValue(m_ptr, "CTriggerHurt", "m_bitsDamageInflict", false, value); }
    int32_t GetDamageModel() const { return GetSchemaValue<int32_t>(m_ptr, "CTriggerHurt", "m_damageModel"); }
    void SetDamageModel(int32_t value) { SetSchemaValue(m_ptr, "CTriggerHurt", "m_damageModel", false, value); }
    bool GetNoDmgForce() const { return GetSchemaValue<bool>(m_ptr, "CTriggerHurt", "m_bNoDmgForce"); }
    void SetNoDmgForce(bool value) { SetSchemaValue(m_ptr, "CTriggerHurt", "m_bNoDmgForce", false, value); }
    Vector GetDamageForce() const { return GetSchemaValue<Vector>(m_ptr, "CTriggerHurt", "m_vDamageForce"); }
    void SetDamageForce(Vector value) { SetSchemaValue(m_ptr, "CTriggerHurt", "m_vDamageForce", false, value); }
    bool GetThinkAlways() const { return GetSchemaValue<bool>(m_ptr, "CTriggerHurt", "m_thinkAlways"); }
    void SetThinkAlways(bool value) { SetSchemaValue(m_ptr, "CTriggerHurt", "m_thinkAlways", false, value); }
    float GetHurtThinkPeriod() const { return GetSchemaValue<float>(m_ptr, "CTriggerHurt", "m_hurtThinkPeriod"); }
    void SetHurtThinkPeriod(float value) { SetSchemaValue(m_ptr, "CTriggerHurt", "m_hurtThinkPeriod", false, value); }
    GCEntityIOOutput GetOnHurt() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTriggerHurt", "m_OnHurt"); }
    void SetOnHurt(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTriggerHurt", "m_OnHurt", false, value); }
    GCEntityIOOutput GetOnHurtPlayer() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTriggerHurt", "m_OnHurtPlayer"); }
    void SetOnHurtPlayer(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTriggerHurt", "m_OnHurtPlayer", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif