class GVMixModDelayDesc_t;

#ifndef _gcvmixmoddelaydesc_t_h
#define _gcvmixmoddelaydesc_t_h

#include "../../../scripting.h"


#include "GVMixFilterDesc_t.h"

class GVMixModDelayDesc_t
{
private:
    void *m_ptr;

public:
    GVMixModDelayDesc_t() {}
    GVMixModDelayDesc_t(void *ptr) : m_ptr(ptr) {}

    GVMixFilterDesc_t GetFeedbackFilter() const { return GetSchemaValue<GVMixFilterDesc_t>(m_ptr, "VMixModDelayDesc_t", "m_feedbackFilter"); }
    void SetFeedbackFilter(GVMixFilterDesc_t value) { SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_feedbackFilter", true, value); }
    bool GetPhaseInvert() const { return GetSchemaValue<bool>(m_ptr, "VMixModDelayDesc_t", "m_bPhaseInvert"); }
    void SetPhaseInvert(bool value) { SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_bPhaseInvert", true, value); }
    float GetGlideTime() const { return GetSchemaValue<float>(m_ptr, "VMixModDelayDesc_t", "m_flGlideTime"); }
    void SetGlideTime(float value) { SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_flGlideTime", true, value); }
    float GetDelay() const { return GetSchemaValue<float>(m_ptr, "VMixModDelayDesc_t", "m_flDelay"); }
    void SetDelay(float value) { SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_flDelay", true, value); }
    float GetOutputGain() const { return GetSchemaValue<float>(m_ptr, "VMixModDelayDesc_t", "m_flOutputGain"); }
    void SetOutputGain(float value) { SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_flOutputGain", true, value); }
    float GetFeedbackGain() const { return GetSchemaValue<float>(m_ptr, "VMixModDelayDesc_t", "m_flFeedbackGain"); }
    void SetFeedbackGain(float value) { SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_flFeedbackGain", true, value); }
    float GetModRate() const { return GetSchemaValue<float>(m_ptr, "VMixModDelayDesc_t", "m_flModRate"); }
    void SetModRate(float value) { SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_flModRate", true, value); }
    float GetModDepth() const { return GetSchemaValue<float>(m_ptr, "VMixModDelayDesc_t", "m_flModDepth"); }
    void SetModDepth(float value) { SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_flModDepth", true, value); }
    bool GetApplyAntialiasing() const { return GetSchemaValue<bool>(m_ptr, "VMixModDelayDesc_t", "m_bApplyAntialiasing"); }
    void SetApplyAntialiasing(bool value) { SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_bApplyAntialiasing", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif