class GVMixEffectChainDesc_t;

#ifndef _gcvmixeffectchaindesc_t_h
#define _gcvmixeffectchaindesc_t_h

#include "../../../scripting.h"




class GVMixEffectChainDesc_t
{
private:
    void *m_ptr;

public:
    GVMixEffectChainDesc_t() {}
    GVMixEffectChainDesc_t(void *ptr) : m_ptr(ptr) {}

    float GetCrossfadeTime() const { return GetSchemaValue<float>(m_ptr, "VMixEffectChainDesc_t", "m_flCrossfadeTime"); }
    void SetCrossfadeTime(float value) { SetSchemaValue(m_ptr, "VMixEffectChainDesc_t", "m_flCrossfadeTime", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif