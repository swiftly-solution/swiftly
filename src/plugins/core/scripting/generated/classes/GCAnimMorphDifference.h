class GCAnimMorphDifference;

#ifndef _gccanimmorphdifference_h
#define _gccanimmorphdifference_h

#include "../../../scripting.h"




class GCAnimMorphDifference
{
private:
    void *m_ptr;

public:
    GCAnimMorphDifference() {}
    GCAnimMorphDifference(void *ptr) : m_ptr(ptr) {}

    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimMorphDifference", "m_name"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CAnimMorphDifference", "m_name", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif