class GVMixSubgraphSwitchDesc_t;

#ifndef _gcvmixsubgraphswitchdesc_t_h
#define _gcvmixsubgraphswitchdesc_t_h

#include "../../../scripting.h"

#include "../types/GVMixSubgraphSwitchInterpolationType_t.h"


class GVMixSubgraphSwitchDesc_t
{
private:
    void *m_ptr;

public:
    GVMixSubgraphSwitchDesc_t() {}
    GVMixSubgraphSwitchDesc_t(void *ptr) : m_ptr(ptr) {}

    VMixSubgraphSwitchInterpolationType_t GetInterpolationMode() const { return GetSchemaValue<VMixSubgraphSwitchInterpolationType_t>(m_ptr, "VMixSubgraphSwitchDesc_t", "m_interpolationMode"); }
    void SetInterpolationMode(VMixSubgraphSwitchInterpolationType_t value) { SetSchemaValue(m_ptr, "VMixSubgraphSwitchDesc_t", "m_interpolationMode", true, value); }
    bool GetOnlyTailsOnFadeOut() const { return GetSchemaValue<bool>(m_ptr, "VMixSubgraphSwitchDesc_t", "m_bOnlyTailsOnFadeOut"); }
    void SetOnlyTailsOnFadeOut(bool value) { SetSchemaValue(m_ptr, "VMixSubgraphSwitchDesc_t", "m_bOnlyTailsOnFadeOut", true, value); }
    float GetInterpolationTime() const { return GetSchemaValue<float>(m_ptr, "VMixSubgraphSwitchDesc_t", "m_flInterpolationTime"); }
    void SetInterpolationTime(float value) { SetSchemaValue(m_ptr, "VMixSubgraphSwitchDesc_t", "m_flInterpolationTime", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif