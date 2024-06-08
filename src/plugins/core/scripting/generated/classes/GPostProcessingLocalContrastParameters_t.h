class GPostProcessingLocalContrastParameters_t;

#ifndef _gcpostprocessinglocalcontrastparameters_t_h
#define _gcpostprocessinglocalcontrastparameters_t_h

#include "../../../scripting.h"




class GPostProcessingLocalContrastParameters_t
{
private:
    void *m_ptr;

public:
    GPostProcessingLocalContrastParameters_t() {}
    GPostProcessingLocalContrastParameters_t(void *ptr) : m_ptr(ptr) {}

    float GetLocalContrastStrength() const { return GetSchemaValue<float>(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastStrength"); }
    void SetLocalContrastStrength(float value) { SetSchemaValue(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastStrength", true, value); }
    float GetLocalContrastEdgeStrength() const { return GetSchemaValue<float>(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastEdgeStrength"); }
    void SetLocalContrastEdgeStrength(float value) { SetSchemaValue(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastEdgeStrength", true, value); }
    float GetLocalContrastVignetteStart() const { return GetSchemaValue<float>(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastVignetteStart"); }
    void SetLocalContrastVignetteStart(float value) { SetSchemaValue(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastVignetteStart", true, value); }
    float GetLocalContrastVignetteEnd() const { return GetSchemaValue<float>(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastVignetteEnd"); }
    void SetLocalContrastVignetteEnd(float value) { SetSchemaValue(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastVignetteEnd", true, value); }
    float GetLocalContrastVignetteBlur() const { return GetSchemaValue<float>(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastVignetteBlur"); }
    void SetLocalContrastVignetteBlur(float value) { SetSchemaValue(m_ptr, "PostProcessingLocalContrastParameters_t", "m_flLocalContrastVignetteBlur", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif