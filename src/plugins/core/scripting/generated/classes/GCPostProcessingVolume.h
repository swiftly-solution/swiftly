class GCPostProcessingVolume;

#ifndef _gccpostprocessingvolume_h
#define _gccpostprocessingvolume_h

#include "../../../scripting.h"




class GCPostProcessingVolume
{
private:
    void *m_ptr;

public:
    GCPostProcessingVolume() {}
    GCPostProcessingVolume(void *ptr) : m_ptr(ptr) {}

    float GetFadeDuration() const { return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flFadeDuration"); }
    void SetFadeDuration(float value) { SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flFadeDuration", false, value); }
    float GetMinLogExposure() const { return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flMinLogExposure"); }
    void SetMinLogExposure(float value) { SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flMinLogExposure", false, value); }
    float GetMaxLogExposure() const { return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flMaxLogExposure"); }
    void SetMaxLogExposure(float value) { SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flMaxLogExposure", false, value); }
    float GetMinExposure() const { return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flMinExposure"); }
    void SetMinExposure(float value) { SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flMinExposure", false, value); }
    float GetMaxExposure() const { return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flMaxExposure"); }
    void SetMaxExposure(float value) { SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flMaxExposure", false, value); }
    float GetExposureCompensation() const { return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flExposureCompensation"); }
    void SetExposureCompensation(float value) { SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flExposureCompensation", false, value); }
    float GetExposureFadeSpeedUp() const { return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flExposureFadeSpeedUp"); }
    void SetExposureFadeSpeedUp(float value) { SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flExposureFadeSpeedUp", false, value); }
    float GetExposureFadeSpeedDown() const { return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flExposureFadeSpeedDown"); }
    void SetExposureFadeSpeedDown(float value) { SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flExposureFadeSpeedDown", false, value); }
    float GetTonemapEVSmoothingRange() const { return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flTonemapEVSmoothingRange"); }
    void SetTonemapEVSmoothingRange(float value) { SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flTonemapEVSmoothingRange", false, value); }
    bool GetMaster() const { return GetSchemaValue<bool>(m_ptr, "CPostProcessingVolume", "m_bMaster"); }
    void SetMaster(bool value) { SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_bMaster", false, value); }
    bool GetExposureControl() const { return GetSchemaValue<bool>(m_ptr, "CPostProcessingVolume", "m_bExposureControl"); }
    void SetExposureControl(bool value) { SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_bExposureControl", false, value); }
    float GetRate() const { return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flRate"); }
    void SetRate(float value) { SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flRate", false, value); }
    float GetTonemapPercentTarget() const { return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flTonemapPercentTarget"); }
    void SetTonemapPercentTarget(float value) { SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flTonemapPercentTarget", false, value); }
    float GetTonemapPercentBrightPixels() const { return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flTonemapPercentBrightPixels"); }
    void SetTonemapPercentBrightPixels(float value) { SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flTonemapPercentBrightPixels", false, value); }
    float GetTonemapMinAvgLum() const { return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flTonemapMinAvgLum"); }
    void SetTonemapMinAvgLum(float value) { SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flTonemapMinAvgLum", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif