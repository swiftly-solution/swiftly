class GMoodAnimation_t;

#ifndef _gcmoodanimation_t_h
#define _gcmoodanimation_t_h

#include "../../../scripting.h"




class GMoodAnimation_t
{
private:
    void *m_ptr;

public:
    GMoodAnimation_t() {}
    GMoodAnimation_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "MoodAnimation_t", "m_sName"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "MoodAnimation_t", "m_sName", true, value); }
    float GetWeight() const { return GetSchemaValue<float>(m_ptr, "MoodAnimation_t", "m_flWeight"); }
    void SetWeight(float value) { SetSchemaValue(m_ptr, "MoodAnimation_t", "m_flWeight", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif