class GCTonemapController2;

#ifndef _gcctonemapcontroller2_h
#define _gcctonemapcontroller2_h

#include "../../../scripting.h"




class GCTonemapController2
{
private:
    void *m_ptr;

public:
    GCTonemapController2() {}
    GCTonemapController2(void *ptr) : m_ptr(ptr) {}

    float GetAutoExposureMin() const { return GetSchemaValue<float>(m_ptr, "CTonemapController2", "m_flAutoExposureMin"); }
    void SetAutoExposureMin(float value) { SetSchemaValue(m_ptr, "CTonemapController2", "m_flAutoExposureMin", false, value); }
    float GetAutoExposureMax() const { return GetSchemaValue<float>(m_ptr, "CTonemapController2", "m_flAutoExposureMax"); }
    void SetAutoExposureMax(float value) { SetSchemaValue(m_ptr, "CTonemapController2", "m_flAutoExposureMax", false, value); }
    float GetTonemapPercentTarget() const { return GetSchemaValue<float>(m_ptr, "CTonemapController2", "m_flTonemapPercentTarget"); }
    void SetTonemapPercentTarget(float value) { SetSchemaValue(m_ptr, "CTonemapController2", "m_flTonemapPercentTarget", false, value); }
    float GetTonemapPercentBrightPixels() const { return GetSchemaValue<float>(m_ptr, "CTonemapController2", "m_flTonemapPercentBrightPixels"); }
    void SetTonemapPercentBrightPixels(float value) { SetSchemaValue(m_ptr, "CTonemapController2", "m_flTonemapPercentBrightPixels", false, value); }
    float GetTonemapMinAvgLum() const { return GetSchemaValue<float>(m_ptr, "CTonemapController2", "m_flTonemapMinAvgLum"); }
    void SetTonemapMinAvgLum(float value) { SetSchemaValue(m_ptr, "CTonemapController2", "m_flTonemapMinAvgLum", false, value); }
    float GetExposureAdaptationSpeedUp() const { return GetSchemaValue<float>(m_ptr, "CTonemapController2", "m_flExposureAdaptationSpeedUp"); }
    void SetExposureAdaptationSpeedUp(float value) { SetSchemaValue(m_ptr, "CTonemapController2", "m_flExposureAdaptationSpeedUp", false, value); }
    float GetExposureAdaptationSpeedDown() const { return GetSchemaValue<float>(m_ptr, "CTonemapController2", "m_flExposureAdaptationSpeedDown"); }
    void SetExposureAdaptationSpeedDown(float value) { SetSchemaValue(m_ptr, "CTonemapController2", "m_flExposureAdaptationSpeedDown", false, value); }
    float GetTonemapEVSmoothingRange() const { return GetSchemaValue<float>(m_ptr, "CTonemapController2", "m_flTonemapEVSmoothingRange"); }
    void SetTonemapEVSmoothingRange(float value) { SetSchemaValue(m_ptr, "CTonemapController2", "m_flTonemapEVSmoothingRange", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif