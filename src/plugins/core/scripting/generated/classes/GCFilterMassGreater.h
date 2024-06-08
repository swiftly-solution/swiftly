class GCFilterMassGreater;

#ifndef _gccfiltermassgreater_h
#define _gccfiltermassgreater_h

#include "../../../scripting.h"




class GCFilterMassGreater
{
private:
    void *m_ptr;

public:
    GCFilterMassGreater() {}
    GCFilterMassGreater(void *ptr) : m_ptr(ptr) {}

    float GetFilterMass() const { return GetSchemaValue<float>(m_ptr, "CFilterMassGreater", "m_fFilterMass"); }
    void SetFilterMass(float value) { SetSchemaValue(m_ptr, "CFilterMassGreater", "m_fFilterMass", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif