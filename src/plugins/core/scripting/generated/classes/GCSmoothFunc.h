class GCSmoothFunc;

#ifndef _gccsmoothfunc_h
#define _gccsmoothfunc_h

#include "../../../scripting.h"




class GCSmoothFunc
{
private:
    void *m_ptr;

public:
    GCSmoothFunc() {}
    GCSmoothFunc(void *ptr) : m_ptr(ptr) {}

    float GetSmoothAmplitude() const { return GetSchemaValue<float>(m_ptr, "CSmoothFunc", "m_flSmoothAmplitude"); }
    void SetSmoothAmplitude(float value) { SetSchemaValue(m_ptr, "CSmoothFunc", "m_flSmoothAmplitude", false, value); }
    float GetSmoothBias() const { return GetSchemaValue<float>(m_ptr, "CSmoothFunc", "m_flSmoothBias"); }
    void SetSmoothBias(float value) { SetSchemaValue(m_ptr, "CSmoothFunc", "m_flSmoothBias", false, value); }
    float GetSmoothDuration() const { return GetSchemaValue<float>(m_ptr, "CSmoothFunc", "m_flSmoothDuration"); }
    void SetSmoothDuration(float value) { SetSchemaValue(m_ptr, "CSmoothFunc", "m_flSmoothDuration", false, value); }
    float GetSmoothRemainingTime() const { return GetSchemaValue<float>(m_ptr, "CSmoothFunc", "m_flSmoothRemainingTime"); }
    void SetSmoothRemainingTime(float value) { SetSchemaValue(m_ptr, "CSmoothFunc", "m_flSmoothRemainingTime", false, value); }
    int32_t GetSmoothDir() const { return GetSchemaValue<int32_t>(m_ptr, "CSmoothFunc", "m_nSmoothDir"); }
    void SetSmoothDir(int32_t value) { SetSchemaValue(m_ptr, "CSmoothFunc", "m_nSmoothDir", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif