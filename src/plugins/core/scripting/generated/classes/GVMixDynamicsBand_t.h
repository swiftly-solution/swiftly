class GVMixDynamicsBand_t;

#ifndef _gcvmixdynamicsband_t_h
#define _gcvmixdynamicsband_t_h

#include "../../../scripting.h"




class GVMixDynamicsBand_t
{
private:
    void *m_ptr;

public:
    GVMixDynamicsBand_t() {}
    GVMixDynamicsBand_t(void *ptr) : m_ptr(ptr) {}

    float GetFldbGainInput() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsBand_t", "m_fldbGainInput"); }
    void SetFldbGainInput(float value) { SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_fldbGainInput", true, value); }
    float GetFldbGainOutput() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsBand_t", "m_fldbGainOutput"); }
    void SetFldbGainOutput(float value) { SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_fldbGainOutput", true, value); }
    float GetFldbThresholdBelow() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsBand_t", "m_fldbThresholdBelow"); }
    void SetFldbThresholdBelow(float value) { SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_fldbThresholdBelow", true, value); }
    float GetFldbThresholdAbove() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsBand_t", "m_fldbThresholdAbove"); }
    void SetFldbThresholdAbove(float value) { SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_fldbThresholdAbove", true, value); }
    float GetRatioBelow() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsBand_t", "m_flRatioBelow"); }
    void SetRatioBelow(float value) { SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_flRatioBelow", true, value); }
    float GetRatioAbove() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsBand_t", "m_flRatioAbove"); }
    void SetRatioAbove(float value) { SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_flRatioAbove", true, value); }
    float GetAttackTimeMS() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsBand_t", "m_flAttackTimeMS"); }
    void SetAttackTimeMS(float value) { SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_flAttackTimeMS", true, value); }
    float GetReleaseTimeMS() const { return GetSchemaValue<float>(m_ptr, "VMixDynamicsBand_t", "m_flReleaseTimeMS"); }
    void SetReleaseTimeMS(float value) { SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_flReleaseTimeMS", true, value); }
    bool GetEnable() const { return GetSchemaValue<bool>(m_ptr, "VMixDynamicsBand_t", "m_bEnable"); }
    void SetEnable(bool value) { SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_bEnable", true, value); }
    bool GetSolo() const { return GetSchemaValue<bool>(m_ptr, "VMixDynamicsBand_t", "m_bSolo"); }
    void SetSolo(bool value) { SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_bSolo", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif