class GBoneDemoCaptureSettings_t;

#ifndef _gcbonedemocapturesettings_t_h
#define _gcbonedemocapturesettings_t_h

#include "../../../scripting.h"




class GBoneDemoCaptureSettings_t
{
private:
    void *m_ptr;

public:
    GBoneDemoCaptureSettings_t() {}
    GBoneDemoCaptureSettings_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetBoneName() const { return GetSchemaValue<CUtlString>(m_ptr, "BoneDemoCaptureSettings_t", "m_boneName"); }
    void SetBoneName(CUtlString value) { SetSchemaValue(m_ptr, "BoneDemoCaptureSettings_t", "m_boneName", true, value); }
    float GetErrorSplineRotationMax() const { return GetSchemaValue<float>(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorSplineRotationMax"); }
    void SetErrorSplineRotationMax(float value) { SetSchemaValue(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorSplineRotationMax", true, value); }
    float GetErrorSplineTranslationMax() const { return GetSchemaValue<float>(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorSplineTranslationMax"); }
    void SetErrorSplineTranslationMax(float value) { SetSchemaValue(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorSplineTranslationMax", true, value); }
    float GetErrorSplineScaleMax() const { return GetSchemaValue<float>(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorSplineScaleMax"); }
    void SetErrorSplineScaleMax(float value) { SetSchemaValue(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorSplineScaleMax", true, value); }
    float GetErrorQuantizationRotationMax() const { return GetSchemaValue<float>(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorQuantizationRotationMax"); }
    void SetErrorQuantizationRotationMax(float value) { SetSchemaValue(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorQuantizationRotationMax", true, value); }
    float GetErrorQuantizationTranslationMax() const { return GetSchemaValue<float>(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorQuantizationTranslationMax"); }
    void SetErrorQuantizationTranslationMax(float value) { SetSchemaValue(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorQuantizationTranslationMax", true, value); }
    float GetErrorQuantizationScaleMax() const { return GetSchemaValue<float>(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorQuantizationScaleMax"); }
    void SetErrorQuantizationScaleMax(float value) { SetSchemaValue(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorQuantizationScaleMax", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif