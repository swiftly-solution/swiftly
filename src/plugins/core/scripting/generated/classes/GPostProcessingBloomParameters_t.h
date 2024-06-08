class GPostProcessingBloomParameters_t;

#ifndef _gcpostprocessingbloomparameters_t_h
#define _gcpostprocessingbloomparameters_t_h

#include "../../../scripting.h"

#include "../types/GBloomBlendMode_t.h"


class GPostProcessingBloomParameters_t
{
private:
    void *m_ptr;

public:
    GPostProcessingBloomParameters_t() {}
    GPostProcessingBloomParameters_t(void *ptr) : m_ptr(ptr) {}

    BloomBlendMode_t GetBlendMode() const { return GetSchemaValue<BloomBlendMode_t>(m_ptr, "PostProcessingBloomParameters_t", "m_blendMode"); }
    void SetBlendMode(BloomBlendMode_t value) { SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_blendMode", true, value); }
    float GetBloomStrength() const { return GetSchemaValue<float>(m_ptr, "PostProcessingBloomParameters_t", "m_flBloomStrength"); }
    void SetBloomStrength(float value) { SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_flBloomStrength", true, value); }
    float GetScreenBloomStrength() const { return GetSchemaValue<float>(m_ptr, "PostProcessingBloomParameters_t", "m_flScreenBloomStrength"); }
    void SetScreenBloomStrength(float value) { SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_flScreenBloomStrength", true, value); }
    float GetBlurBloomStrength() const { return GetSchemaValue<float>(m_ptr, "PostProcessingBloomParameters_t", "m_flBlurBloomStrength"); }
    void SetBlurBloomStrength(float value) { SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_flBlurBloomStrength", true, value); }
    float GetBloomThreshold() const { return GetSchemaValue<float>(m_ptr, "PostProcessingBloomParameters_t", "m_flBloomThreshold"); }
    void SetBloomThreshold(float value) { SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_flBloomThreshold", true, value); }
    float GetBloomThresholdWidth() const { return GetSchemaValue<float>(m_ptr, "PostProcessingBloomParameters_t", "m_flBloomThresholdWidth"); }
    void SetBloomThresholdWidth(float value) { SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_flBloomThresholdWidth", true, value); }
    float GetSkyboxBloomStrength() const { return GetSchemaValue<float>(m_ptr, "PostProcessingBloomParameters_t", "m_flSkyboxBloomStrength"); }
    void SetSkyboxBloomStrength(float value) { SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_flSkyboxBloomStrength", true, value); }
    float GetBloomStartValue() const { return GetSchemaValue<float>(m_ptr, "PostProcessingBloomParameters_t", "m_flBloomStartValue"); }
    void SetBloomStartValue(float value) { SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_flBloomStartValue", true, value); }
    std::vector<float> GetBlurWeight() const { float* outValue = GetSchemaValue<float*>(m_ptr, "PostProcessingBloomParameters_t", "m_flBlurWeight"); std::vector<float> ret; for(int i = 0; i < 5; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetBlurWeight(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "PostProcessingBloomParameters_t", "m_flBlurWeight"); for(int i = 0; i < 5; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_flBlurWeight", true, outValue); }
    std::vector<Vector> GetBlurTint() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "PostProcessingBloomParameters_t", "m_vBlurTint"); std::vector<Vector> ret; for(int i = 0; i < 5; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetBlurTint(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "PostProcessingBloomParameters_t", "m_vBlurTint"); for(int i = 0; i < 5; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_vBlurTint", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif