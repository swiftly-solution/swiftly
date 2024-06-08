class GC_OP_UpdateLightSource;

#ifndef _gcc_op_updatelightsource_h
#define _gcc_op_updatelightsource_h

#include "../../../scripting.h"




class GC_OP_UpdateLightSource
{
private:
    void *m_ptr;

public:
    GC_OP_UpdateLightSource() {}
    GC_OP_UpdateLightSource(void *ptr) : m_ptr(ptr) {}

    Color GetColorTint() const { return GetSchemaValue<Color>(m_ptr, "C_OP_UpdateLightSource", "m_vColorTint"); }
    void SetColorTint(Color value) { SetSchemaValue(m_ptr, "C_OP_UpdateLightSource", "m_vColorTint", false, value); }
    float GetBrightnessScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_UpdateLightSource", "m_flBrightnessScale"); }
    void SetBrightnessScale(float value) { SetSchemaValue(m_ptr, "C_OP_UpdateLightSource", "m_flBrightnessScale", false, value); }
    float GetRadiusScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_UpdateLightSource", "m_flRadiusScale"); }
    void SetRadiusScale(float value) { SetSchemaValue(m_ptr, "C_OP_UpdateLightSource", "m_flRadiusScale", false, value); }
    float GetMinimumLightingRadius() const { return GetSchemaValue<float>(m_ptr, "C_OP_UpdateLightSource", "m_flMinimumLightingRadius"); }
    void SetMinimumLightingRadius(float value) { SetSchemaValue(m_ptr, "C_OP_UpdateLightSource", "m_flMinimumLightingRadius", false, value); }
    float GetMaximumLightingRadius() const { return GetSchemaValue<float>(m_ptr, "C_OP_UpdateLightSource", "m_flMaximumLightingRadius"); }
    void SetMaximumLightingRadius(float value) { SetSchemaValue(m_ptr, "C_OP_UpdateLightSource", "m_flMaximumLightingRadius", false, value); }
    float GetPositionDampingConstant() const { return GetSchemaValue<float>(m_ptr, "C_OP_UpdateLightSource", "m_flPositionDampingConstant"); }
    void SetPositionDampingConstant(float value) { SetSchemaValue(m_ptr, "C_OP_UpdateLightSource", "m_flPositionDampingConstant", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif