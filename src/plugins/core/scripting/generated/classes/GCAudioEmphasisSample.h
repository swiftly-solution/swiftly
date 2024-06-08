class GCAudioEmphasisSample;

#ifndef _gccaudioemphasissample_h
#define _gccaudioemphasissample_h

#include "../../../scripting.h"




class GCAudioEmphasisSample
{
private:
    void *m_ptr;

public:
    GCAudioEmphasisSample() {}
    GCAudioEmphasisSample(void *ptr) : m_ptr(ptr) {}

    float GetTime() const { return GetSchemaValue<float>(m_ptr, "CAudioEmphasisSample", "m_flTime"); }
    void SetTime(float value) { SetSchemaValue(m_ptr, "CAudioEmphasisSample", "m_flTime", false, value); }
    float GetValue() const { return GetSchemaValue<float>(m_ptr, "CAudioEmphasisSample", "m_flValue"); }
    void SetValue(float value) { SetSchemaValue(m_ptr, "CAudioEmphasisSample", "m_flValue", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif