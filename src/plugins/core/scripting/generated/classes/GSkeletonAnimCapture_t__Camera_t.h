class GSkeletonAnimCapture_t__Camera_t;

#ifndef _gcskeletonanimcapture_t__camera_t_h
#define _gcskeletonanimcapture_t__camera_t_h

#include "../../../scripting.h"




class GSkeletonAnimCapture_t__Camera_t
{
private:
    void *m_ptr;

public:
    GSkeletonAnimCapture_t__Camera_t() {}
    GSkeletonAnimCapture_t__Camera_t(void *ptr) : m_ptr(ptr) {}

    float GetTime() const { return GetSchemaValue<float>(m_ptr, "SkeletonAnimCapture_t__Camera_t", "m_flTime"); }
    void SetTime(float value) { SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__Camera_t", "m_flTime", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif