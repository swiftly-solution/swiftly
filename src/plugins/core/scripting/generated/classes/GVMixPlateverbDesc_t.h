class GVMixPlateverbDesc_t;

#ifndef _gcvmixplateverbdesc_t_h
#define _gcvmixplateverbdesc_t_h

#include "../../../scripting.h"




class GVMixPlateverbDesc_t
{
private:
    void *m_ptr;

public:
    GVMixPlateverbDesc_t() {}
    GVMixPlateverbDesc_t(void *ptr) : m_ptr(ptr) {}

    float GetPrefilter() const { return GetSchemaValue<float>(m_ptr, "VMixPlateverbDesc_t", "m_flPrefilter"); }
    void SetPrefilter(float value) { SetSchemaValue(m_ptr, "VMixPlateverbDesc_t", "m_flPrefilter", true, value); }
    float GetInputDiffusion1() const { return GetSchemaValue<float>(m_ptr, "VMixPlateverbDesc_t", "m_flInputDiffusion1"); }
    void SetInputDiffusion1(float value) { SetSchemaValue(m_ptr, "VMixPlateverbDesc_t", "m_flInputDiffusion1", true, value); }
    float GetInputDiffusion2() const { return GetSchemaValue<float>(m_ptr, "VMixPlateverbDesc_t", "m_flInputDiffusion2"); }
    void SetInputDiffusion2(float value) { SetSchemaValue(m_ptr, "VMixPlateverbDesc_t", "m_flInputDiffusion2", true, value); }
    float GetDecay() const { return GetSchemaValue<float>(m_ptr, "VMixPlateverbDesc_t", "m_flDecay"); }
    void SetDecay(float value) { SetSchemaValue(m_ptr, "VMixPlateverbDesc_t", "m_flDecay", true, value); }
    float GetDamp() const { return GetSchemaValue<float>(m_ptr, "VMixPlateverbDesc_t", "m_flDamp"); }
    void SetDamp(float value) { SetSchemaValue(m_ptr, "VMixPlateverbDesc_t", "m_flDamp", true, value); }
    float GetFeedbackDiffusion1() const { return GetSchemaValue<float>(m_ptr, "VMixPlateverbDesc_t", "m_flFeedbackDiffusion1"); }
    void SetFeedbackDiffusion1(float value) { SetSchemaValue(m_ptr, "VMixPlateverbDesc_t", "m_flFeedbackDiffusion1", true, value); }
    float GetFeedbackDiffusion2() const { return GetSchemaValue<float>(m_ptr, "VMixPlateverbDesc_t", "m_flFeedbackDiffusion2"); }
    void SetFeedbackDiffusion2(float value) { SetSchemaValue(m_ptr, "VMixPlateverbDesc_t", "m_flFeedbackDiffusion2", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif