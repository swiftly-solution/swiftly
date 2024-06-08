class GHitReactFixedSettings_t;

#ifndef _gchitreactfixedsettings_t_h
#define _gchitreactfixedsettings_t_h

#include "../../../scripting.h"




class GHitReactFixedSettings_t
{
private:
    void *m_ptr;

public:
    GHitReactFixedSettings_t() {}
    GHitReactFixedSettings_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetWeightListIndex() const { return GetSchemaValue<int32_t>(m_ptr, "HitReactFixedSettings_t", "m_nWeightListIndex"); }
    void SetWeightListIndex(int32_t value) { SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_nWeightListIndex", true, value); }
    int32_t GetEffectedBoneCount() const { return GetSchemaValue<int32_t>(m_ptr, "HitReactFixedSettings_t", "m_nEffectedBoneCount"); }
    void SetEffectedBoneCount(int32_t value) { SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_nEffectedBoneCount", true, value); }
    float GetMaxImpactForce() const { return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flMaxImpactForce"); }
    void SetMaxImpactForce(float value) { SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flMaxImpactForce", true, value); }
    float GetMinImpactForce() const { return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flMinImpactForce"); }
    void SetMinImpactForce(float value) { SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flMinImpactForce", true, value); }
    float GetWhipImpactScale() const { return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flWhipImpactScale"); }
    void SetWhipImpactScale(float value) { SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flWhipImpactScale", true, value); }
    float GetCounterRotationScale() const { return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flCounterRotationScale"); }
    void SetCounterRotationScale(float value) { SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flCounterRotationScale", true, value); }
    float GetDistanceFadeScale() const { return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flDistanceFadeScale"); }
    void SetDistanceFadeScale(float value) { SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flDistanceFadeScale", true, value); }
    float GetPropagationScale() const { return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flPropagationScale"); }
    void SetPropagationScale(float value) { SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flPropagationScale", true, value); }
    float GetWhipDelay() const { return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flWhipDelay"); }
    void SetWhipDelay(float value) { SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flWhipDelay", true, value); }
    float GetSpringStrength() const { return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flSpringStrength"); }
    void SetSpringStrength(float value) { SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flSpringStrength", true, value); }
    float GetWhipSpringStrength() const { return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flWhipSpringStrength"); }
    void SetWhipSpringStrength(float value) { SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flWhipSpringStrength", true, value); }
    float GetMaxAngleRadians() const { return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flMaxAngleRadians"); }
    void SetMaxAngleRadians(float value) { SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flMaxAngleRadians", true, value); }
    int32_t GetHipBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "HitReactFixedSettings_t", "m_nHipBoneIndex"); }
    void SetHipBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_nHipBoneIndex", true, value); }
    float GetHipBoneTranslationScale() const { return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flHipBoneTranslationScale"); }
    void SetHipBoneTranslationScale(float value) { SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flHipBoneTranslationScale", true, value); }
    float GetHipDipSpringStrength() const { return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flHipDipSpringStrength"); }
    void SetHipDipSpringStrength(float value) { SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flHipDipSpringStrength", true, value); }
    float GetHipDipImpactScale() const { return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flHipDipImpactScale"); }
    void SetHipDipImpactScale(float value) { SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flHipDipImpactScale", true, value); }
    float GetHipDipDelay() const { return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flHipDipDelay"); }
    void SetHipDipDelay(float value) { SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flHipDipDelay", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif