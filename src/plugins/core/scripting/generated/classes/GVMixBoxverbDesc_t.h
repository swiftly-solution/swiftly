class GVMixBoxverbDesc_t;

#ifndef _gcvmixboxverbdesc_t_h
#define _gcvmixboxverbdesc_t_h

#include "../../../scripting.h"


#include "GVMixFilterDesc_t.h"

class GVMixBoxverbDesc_t
{
private:
    void *m_ptr;

public:
    GVMixBoxverbDesc_t() {}
    GVMixBoxverbDesc_t(void *ptr) : m_ptr(ptr) {}

    float GetSizeMax() const { return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flSizeMax"); }
    void SetSizeMax(float value) { SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flSizeMax", true, value); }
    float GetSizeMin() const { return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flSizeMin"); }
    void SetSizeMin(float value) { SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flSizeMin", true, value); }
    float GetComplexity() const { return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flComplexity"); }
    void SetComplexity(float value) { SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flComplexity", true, value); }
    float GetDiffusion() const { return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flDiffusion"); }
    void SetDiffusion(float value) { SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flDiffusion", true, value); }
    float GetModDepth() const { return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flModDepth"); }
    void SetModDepth(float value) { SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flModDepth", true, value); }
    float GetModRate() const { return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flModRate"); }
    void SetModRate(float value) { SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flModRate", true, value); }
    bool GetParallel() const { return GetSchemaValue<bool>(m_ptr, "VMixBoxverbDesc_t", "m_bParallel"); }
    void SetParallel(bool value) { SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_bParallel", true, value); }
    GVMixFilterDesc_t GetFilterType() const { return GetSchemaValue<GVMixFilterDesc_t>(m_ptr, "VMixBoxverbDesc_t", "m_filterType"); }
    void SetFilterType(GVMixFilterDesc_t value) { SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_filterType", true, value); }
    float GetWidth() const { return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flWidth"); }
    void SetWidth(float value) { SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flWidth", true, value); }
    float GetHeight() const { return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flHeight"); }
    void SetHeight(float value) { SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flHeight", true, value); }
    float GetDepth() const { return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flDepth"); }
    void SetDepth(float value) { SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flDepth", true, value); }
    float GetFeedbackScale() const { return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flFeedbackScale"); }
    void SetFeedbackScale(float value) { SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flFeedbackScale", true, value); }
    float GetFeedbackWidth() const { return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flFeedbackWidth"); }
    void SetFeedbackWidth(float value) { SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flFeedbackWidth", true, value); }
    float GetFeedbackHeight() const { return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flFeedbackHeight"); }
    void SetFeedbackHeight(float value) { SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flFeedbackHeight", true, value); }
    float GetFeedbackDepth() const { return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flFeedbackDepth"); }
    void SetFeedbackDepth(float value) { SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flFeedbackDepth", true, value); }
    float GetOutputGain() const { return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flOutputGain"); }
    void SetOutputGain(float value) { SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flOutputGain", true, value); }
    float GetTaps() const { return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flTaps"); }
    void SetTaps(float value) { SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flTaps", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif