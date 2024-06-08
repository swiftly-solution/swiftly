class GPostProcessingVignetteParameters_t;

#ifndef _gcpostprocessingvignetteparameters_t_h
#define _gcpostprocessingvignetteparameters_t_h

#include "../../../scripting.h"




class GPostProcessingVignetteParameters_t
{
private:
    void *m_ptr;

public:
    GPostProcessingVignetteParameters_t() {}
    GPostProcessingVignetteParameters_t(void *ptr) : m_ptr(ptr) {}

    float GetVignetteStrength() const { return GetSchemaValue<float>(m_ptr, "PostProcessingVignetteParameters_t", "m_flVignetteStrength"); }
    void SetVignetteStrength(float value) { SetSchemaValue(m_ptr, "PostProcessingVignetteParameters_t", "m_flVignetteStrength", true, value); }
    Vector2D GetCenter() const { return GetSchemaValue<Vector2D>(m_ptr, "PostProcessingVignetteParameters_t", "m_vCenter"); }
    void SetCenter(Vector2D value) { SetSchemaValue(m_ptr, "PostProcessingVignetteParameters_t", "m_vCenter", true, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "PostProcessingVignetteParameters_t", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "PostProcessingVignetteParameters_t", "m_flRadius", true, value); }
    float GetRoundness() const { return GetSchemaValue<float>(m_ptr, "PostProcessingVignetteParameters_t", "m_flRoundness"); }
    void SetRoundness(float value) { SetSchemaValue(m_ptr, "PostProcessingVignetteParameters_t", "m_flRoundness", true, value); }
    float GetFeather() const { return GetSchemaValue<float>(m_ptr, "PostProcessingVignetteParameters_t", "m_flFeather"); }
    void SetFeather(float value) { SetSchemaValue(m_ptr, "PostProcessingVignetteParameters_t", "m_flFeather", true, value); }
    Vector GetColorTint() const { return GetSchemaValue<Vector>(m_ptr, "PostProcessingVignetteParameters_t", "m_vColorTint"); }
    void SetColorTint(Vector value) { SetSchemaValue(m_ptr, "PostProcessingVignetteParameters_t", "m_vColorTint", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif