class GPointCameraSettings_t;

#ifndef _gcpointcamerasettings_t_h
#define _gcpointcamerasettings_t_h

#include "../../../scripting.h"




class GPointCameraSettings_t
{
private:
    void *m_ptr;

public:
    GPointCameraSettings_t() {}
    GPointCameraSettings_t(void *ptr) : m_ptr(ptr) {}

    float GetNearBlurryDistance() const { return GetSchemaValue<float>(m_ptr, "PointCameraSettings_t", "m_flNearBlurryDistance"); }
    void SetNearBlurryDistance(float value) { SetSchemaValue(m_ptr, "PointCameraSettings_t", "m_flNearBlurryDistance", true, value); }
    float GetNearCrispDistance() const { return GetSchemaValue<float>(m_ptr, "PointCameraSettings_t", "m_flNearCrispDistance"); }
    void SetNearCrispDistance(float value) { SetSchemaValue(m_ptr, "PointCameraSettings_t", "m_flNearCrispDistance", true, value); }
    float GetFarCrispDistance() const { return GetSchemaValue<float>(m_ptr, "PointCameraSettings_t", "m_flFarCrispDistance"); }
    void SetFarCrispDistance(float value) { SetSchemaValue(m_ptr, "PointCameraSettings_t", "m_flFarCrispDistance", true, value); }
    float GetFarBlurryDistance() const { return GetSchemaValue<float>(m_ptr, "PointCameraSettings_t", "m_flFarBlurryDistance"); }
    void SetFarBlurryDistance(float value) { SetSchemaValue(m_ptr, "PointCameraSettings_t", "m_flFarBlurryDistance", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif