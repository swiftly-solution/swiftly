class GCPointCameraVFOV;

#ifndef _gccpointcameravfov_h
#define _gccpointcameravfov_h

#include "../../../scripting.h"




class GCPointCameraVFOV
{
private:
    void *m_ptr;

public:
    GCPointCameraVFOV() {}
    GCPointCameraVFOV(void *ptr) : m_ptr(ptr) {}

    float GetVerticalFOV() const { return GetSchemaValue<float>(m_ptr, "CPointCameraVFOV", "m_flVerticalFOV"); }
    void SetVerticalFOV(float value) { SetSchemaValue(m_ptr, "CPointCameraVFOV", "m_flVerticalFOV", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif