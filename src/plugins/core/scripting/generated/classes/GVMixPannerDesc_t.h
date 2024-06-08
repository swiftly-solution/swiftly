class GVMixPannerDesc_t;

#ifndef _gcvmixpannerdesc_t_h
#define _gcvmixpannerdesc_t_h

#include "../../../scripting.h"

#include "../types/GVMixPannerType_t.h"


class GVMixPannerDesc_t
{
private:
    void *m_ptr;

public:
    GVMixPannerDesc_t() {}
    GVMixPannerDesc_t(void *ptr) : m_ptr(ptr) {}

    VMixPannerType_t GetType() const { return GetSchemaValue<VMixPannerType_t>(m_ptr, "VMixPannerDesc_t", "m_type"); }
    void SetType(VMixPannerType_t value) { SetSchemaValue(m_ptr, "VMixPannerDesc_t", "m_type", true, value); }
    float GetStrength() const { return GetSchemaValue<float>(m_ptr, "VMixPannerDesc_t", "m_flStrength"); }
    void SetStrength(float value) { SetSchemaValue(m_ptr, "VMixPannerDesc_t", "m_flStrength", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif