class GVMixEnvelopeDesc_t;

#ifndef _gcvmixenvelopedesc_t_h
#define _gcvmixenvelopedesc_t_h

#include "../../../scripting.h"




class GVMixEnvelopeDesc_t
{
private:
    void *m_ptr;

public:
    GVMixEnvelopeDesc_t() {}
    GVMixEnvelopeDesc_t(void *ptr) : m_ptr(ptr) {}

    float GetAttackTimeMS() const { return GetSchemaValue<float>(m_ptr, "VMixEnvelopeDesc_t", "m_flAttackTimeMS"); }
    void SetAttackTimeMS(float value) { SetSchemaValue(m_ptr, "VMixEnvelopeDesc_t", "m_flAttackTimeMS", true, value); }
    float GetHoldTimeMS() const { return GetSchemaValue<float>(m_ptr, "VMixEnvelopeDesc_t", "m_flHoldTimeMS"); }
    void SetHoldTimeMS(float value) { SetSchemaValue(m_ptr, "VMixEnvelopeDesc_t", "m_flHoldTimeMS", true, value); }
    float GetReleaseTimeMS() const { return GetSchemaValue<float>(m_ptr, "VMixEnvelopeDesc_t", "m_flReleaseTimeMS"); }
    void SetReleaseTimeMS(float value) { SetSchemaValue(m_ptr, "VMixEnvelopeDesc_t", "m_flReleaseTimeMS", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif