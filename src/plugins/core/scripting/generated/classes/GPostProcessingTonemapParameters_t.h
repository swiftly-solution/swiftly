class GPostProcessingTonemapParameters_t;

#ifndef _gcpostprocessingtonemapparameters_t_h
#define _gcpostprocessingtonemapparameters_t_h

#include "../../../scripting.h"




class GPostProcessingTonemapParameters_t
{
private:
    void *m_ptr;

public:
    GPostProcessingTonemapParameters_t() {}
    GPostProcessingTonemapParameters_t(void *ptr) : m_ptr(ptr) {}

    float GetExposureBias() const { return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flExposureBias"); }
    void SetExposureBias(float value) { SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flExposureBias", true, value); }
    float GetShoulderStrength() const { return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flShoulderStrength"); }
    void SetShoulderStrength(float value) { SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flShoulderStrength", true, value); }
    float GetLinearStrength() const { return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flLinearStrength"); }
    void SetLinearStrength(float value) { SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flLinearStrength", true, value); }
    float GetLinearAngle() const { return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flLinearAngle"); }
    void SetLinearAngle(float value) { SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flLinearAngle", true, value); }
    float GetToeStrength() const { return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flToeStrength"); }
    void SetToeStrength(float value) { SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flToeStrength", true, value); }
    float GetToeNum() const { return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flToeNum"); }
    void SetToeNum(float value) { SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flToeNum", true, value); }
    float GetToeDenom() const { return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flToeDenom"); }
    void SetToeDenom(float value) { SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flToeDenom", true, value); }
    float GetWhitePoint() const { return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flWhitePoint"); }
    void SetWhitePoint(float value) { SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flWhitePoint", true, value); }
    float GetLuminanceSource() const { return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flLuminanceSource"); }
    void SetLuminanceSource(float value) { SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flLuminanceSource", true, value); }
    float GetExposureBiasShadows() const { return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flExposureBiasShadows"); }
    void SetExposureBiasShadows(float value) { SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flExposureBiasShadows", true, value); }
    float GetExposureBiasHighlights() const { return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flExposureBiasHighlights"); }
    void SetExposureBiasHighlights(float value) { SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flExposureBiasHighlights", true, value); }
    float GetMinShadowLum() const { return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flMinShadowLum"); }
    void SetMinShadowLum(float value) { SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flMinShadowLum", true, value); }
    float GetMaxShadowLum() const { return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flMaxShadowLum"); }
    void SetMaxShadowLum(float value) { SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flMaxShadowLum", true, value); }
    float GetMinHighlightLum() const { return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flMinHighlightLum"); }
    void SetMinHighlightLum(float value) { SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flMinHighlightLum", true, value); }
    float GetMaxHighlightLum() const { return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flMaxHighlightLum"); }
    void SetMaxHighlightLum(float value) { SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flMaxHighlightLum", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif