class GCDSPMixgroupModifier;

#ifndef _gccdspmixgroupmodifier_h
#define _gccdspmixgroupmodifier_h

#include "../../../scripting.h"




class GCDSPMixgroupModifier
{
private:
    void *m_ptr;

public:
    GCDSPMixgroupModifier() {}
    GCDSPMixgroupModifier(void *ptr) : m_ptr(ptr) {}

    CUtlString GetMixgroup() const { return GetSchemaValue<CUtlString>(m_ptr, "CDSPMixgroupModifier", "m_mixgroup"); }
    void SetMixgroup(CUtlString value) { SetSchemaValue(m_ptr, "CDSPMixgroupModifier", "m_mixgroup", false, value); }
    float GetModifier() const { return GetSchemaValue<float>(m_ptr, "CDSPMixgroupModifier", "m_flModifier"); }
    void SetModifier(float value) { SetSchemaValue(m_ptr, "CDSPMixgroupModifier", "m_flModifier", false, value); }
    float GetModifierMin() const { return GetSchemaValue<float>(m_ptr, "CDSPMixgroupModifier", "m_flModifierMin"); }
    void SetModifierMin(float value) { SetSchemaValue(m_ptr, "CDSPMixgroupModifier", "m_flModifierMin", false, value); }
    float GetSourceModifier() const { return GetSchemaValue<float>(m_ptr, "CDSPMixgroupModifier", "m_flSourceModifier"); }
    void SetSourceModifier(float value) { SetSchemaValue(m_ptr, "CDSPMixgroupModifier", "m_flSourceModifier", false, value); }
    float GetSourceModifierMin() const { return GetSchemaValue<float>(m_ptr, "CDSPMixgroupModifier", "m_flSourceModifierMin"); }
    void SetSourceModifierMin(float value) { SetSchemaValue(m_ptr, "CDSPMixgroupModifier", "m_flSourceModifierMin", false, value); }
    float GetListenerReverbModifierWhenSourceReverbIsActive() const { return GetSchemaValue<float>(m_ptr, "CDSPMixgroupModifier", "m_flListenerReverbModifierWhenSourceReverbIsActive"); }
    void SetListenerReverbModifierWhenSourceReverbIsActive(float value) { SetSchemaValue(m_ptr, "CDSPMixgroupModifier", "m_flListenerReverbModifierWhenSourceReverbIsActive", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif