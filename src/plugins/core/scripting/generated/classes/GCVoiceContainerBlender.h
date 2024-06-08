class GCVoiceContainerBlender;

#ifndef _gccvoicecontainerblender_h
#define _gccvoicecontainerblender_h

#include "../../../scripting.h"




class GCVoiceContainerBlender
{
private:
    void *m_ptr;

public:
    GCVoiceContainerBlender() {}
    GCVoiceContainerBlender(void *ptr) : m_ptr(ptr) {}

    float GetBlendFactor() const { return GetSchemaValue<float>(m_ptr, "CVoiceContainerBlender", "m_flBlendFactor"); }
    void SetBlendFactor(float value) { SetSchemaValue(m_ptr, "CVoiceContainerBlender", "m_flBlendFactor", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif