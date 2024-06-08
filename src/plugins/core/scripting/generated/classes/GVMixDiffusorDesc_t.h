class GVMixDiffusorDesc_t;

#ifndef _gcvmixdiffusordesc_t_h
#define _gcvmixdiffusordesc_t_h

#include "../../../scripting.h"




class GVMixDiffusorDesc_t
{
private:
    void *m_ptr;

public:
    GVMixDiffusorDesc_t() {}
    GVMixDiffusorDesc_t(void *ptr) : m_ptr(ptr) {}

    float GetSize() const { return GetSchemaValue<float>(m_ptr, "VMixDiffusorDesc_t", "m_flSize"); }
    void SetSize(float value) { SetSchemaValue(m_ptr, "VMixDiffusorDesc_t", "m_flSize", true, value); }
    float GetComplexity() const { return GetSchemaValue<float>(m_ptr, "VMixDiffusorDesc_t", "m_flComplexity"); }
    void SetComplexity(float value) { SetSchemaValue(m_ptr, "VMixDiffusorDesc_t", "m_flComplexity", true, value); }
    float GetFeedback() const { return GetSchemaValue<float>(m_ptr, "VMixDiffusorDesc_t", "m_flFeedback"); }
    void SetFeedback(float value) { SetSchemaValue(m_ptr, "VMixDiffusorDesc_t", "m_flFeedback", true, value); }
    float GetOutputGain() const { return GetSchemaValue<float>(m_ptr, "VMixDiffusorDesc_t", "m_flOutputGain"); }
    void SetOutputGain(float value) { SetSchemaValue(m_ptr, "VMixDiffusorDesc_t", "m_flOutputGain", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif