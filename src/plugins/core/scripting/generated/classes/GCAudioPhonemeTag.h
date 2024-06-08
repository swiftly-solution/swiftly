class GCAudioPhonemeTag;

#ifndef _gccaudiophonemetag_h
#define _gccaudiophonemetag_h

#include "../../../scripting.h"




class GCAudioPhonemeTag
{
private:
    void *m_ptr;

public:
    GCAudioPhonemeTag() {}
    GCAudioPhonemeTag(void *ptr) : m_ptr(ptr) {}

    float GetStartTime() const { return GetSchemaValue<float>(m_ptr, "CAudioPhonemeTag", "m_flStartTime"); }
    void SetStartTime(float value) { SetSchemaValue(m_ptr, "CAudioPhonemeTag", "m_flStartTime", false, value); }
    float GetEndTime() const { return GetSchemaValue<float>(m_ptr, "CAudioPhonemeTag", "m_flEndTime"); }
    void SetEndTime(float value) { SetSchemaValue(m_ptr, "CAudioPhonemeTag", "m_flEndTime", false, value); }
    int32_t GetPhonemeCode() const { return GetSchemaValue<int32_t>(m_ptr, "CAudioPhonemeTag", "m_nPhonemeCode"); }
    void SetPhonemeCode(int32_t value) { SetSchemaValue(m_ptr, "CAudioPhonemeTag", "m_nPhonemeCode", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif