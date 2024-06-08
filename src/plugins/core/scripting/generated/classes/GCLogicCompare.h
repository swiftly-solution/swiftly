class GCLogicCompare;

#ifndef _gcclogiccompare_h
#define _gcclogiccompare_h

#include "../../../scripting.h"




class GCLogicCompare
{
private:
    void *m_ptr;

public:
    GCLogicCompare() {}
    GCLogicCompare(void *ptr) : m_ptr(ptr) {}

    float GetInValue() const { return GetSchemaValue<float>(m_ptr, "CLogicCompare", "m_flInValue"); }
    void SetInValue(float value) { SetSchemaValue(m_ptr, "CLogicCompare", "m_flInValue", false, value); }
    float GetCompareValue() const { return GetSchemaValue<float>(m_ptr, "CLogicCompare", "m_flCompareValue"); }
    void SetCompareValue(float value) { SetSchemaValue(m_ptr, "CLogicCompare", "m_flCompareValue", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif