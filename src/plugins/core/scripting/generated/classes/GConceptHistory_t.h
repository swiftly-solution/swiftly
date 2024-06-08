class GConceptHistory_t;

#ifndef _gcconcepthistory_t_h
#define _gcconcepthistory_t_h

#include "../../../scripting.h"




class GConceptHistory_t
{
private:
    void *m_ptr;

public:
    GConceptHistory_t() {}
    GConceptHistory_t(void *ptr) : m_ptr(ptr) {}

    float GetTimeSpoken() const { return GetSchemaValue<float>(m_ptr, "ConceptHistory_t", "timeSpoken"); }
    void SetTimeSpoken(float value) { SetSchemaValue(m_ptr, "ConceptHistory_t", "timeSpoken", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif