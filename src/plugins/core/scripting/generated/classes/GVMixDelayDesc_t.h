class GVMixDelayDesc_t;

#ifndef _gcvmixdelaydesc_t_h
#define _gcvmixdelaydesc_t_h

#include "../../../scripting.h"


#include "GVMixFilterDesc_t.h"

class GVMixDelayDesc_t
{
private:
    void *m_ptr;

public:
    GVMixDelayDesc_t() {}
    GVMixDelayDesc_t(void *ptr) : m_ptr(ptr) {}

    GVMixFilterDesc_t GetFeedbackFilter() const { return GetSchemaValue<GVMixFilterDesc_t>(m_ptr, "VMixDelayDesc_t", "m_feedbackFilter"); }
    void SetFeedbackFilter(GVMixFilterDesc_t value) { SetSchemaValue(m_ptr, "VMixDelayDesc_t", "m_feedbackFilter", true, value); }
    bool GetEnableFilter() const { return GetSchemaValue<bool>(m_ptr, "VMixDelayDesc_t", "m_bEnableFilter"); }
    void SetEnableFilter(bool value) { SetSchemaValue(m_ptr, "VMixDelayDesc_t", "m_bEnableFilter", true, value); }
    float GetDelay() const { return GetSchemaValue<float>(m_ptr, "VMixDelayDesc_t", "m_flDelay"); }
    void SetDelay(float value) { SetSchemaValue(m_ptr, "VMixDelayDesc_t", "m_flDelay", true, value); }
    float GetDirectGain() const { return GetSchemaValue<float>(m_ptr, "VMixDelayDesc_t", "m_flDirectGain"); }
    void SetDirectGain(float value) { SetSchemaValue(m_ptr, "VMixDelayDesc_t", "m_flDirectGain", true, value); }
    float GetDelayGain() const { return GetSchemaValue<float>(m_ptr, "VMixDelayDesc_t", "m_flDelayGain"); }
    void SetDelayGain(float value) { SetSchemaValue(m_ptr, "VMixDelayDesc_t", "m_flDelayGain", true, value); }
    float GetFeedbackGain() const { return GetSchemaValue<float>(m_ptr, "VMixDelayDesc_t", "m_flFeedbackGain"); }
    void SetFeedbackGain(float value) { SetSchemaValue(m_ptr, "VMixDelayDesc_t", "m_flFeedbackGain", true, value); }
    float GetWidth() const { return GetSchemaValue<float>(m_ptr, "VMixDelayDesc_t", "m_flWidth"); }
    void SetWidth(float value) { SetSchemaValue(m_ptr, "VMixDelayDesc_t", "m_flWidth", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif