class GVelocitySampler;

#ifndef _gcvelocitysampler_h
#define _gcvelocitysampler_h

#include "../../../scripting.h"




class GVelocitySampler
{
private:
    void *m_ptr;

public:
    GVelocitySampler() {}
    GVelocitySampler(void *ptr) : m_ptr(ptr) {}

    Vector GetPrevSample() const { return GetSchemaValue<Vector>(m_ptr, "VelocitySampler", "m_prevSample"); }
    void SetPrevSample(Vector value) { SetSchemaValue(m_ptr, "VelocitySampler", "m_prevSample", false, value); }
    float GetIdealSampleRate() const { return GetSchemaValue<float>(m_ptr, "VelocitySampler", "m_fIdealSampleRate"); }
    void SetIdealSampleRate(float value) { SetSchemaValue(m_ptr, "VelocitySampler", "m_fIdealSampleRate", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif