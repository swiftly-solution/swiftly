class GCExampleSchemaVData_PolymorphicDerivedB;

#ifndef _gccexampleschemavdata_polymorphicderivedb_h
#define _gccexampleschemavdata_polymorphicderivedb_h

#include "../../../scripting.h"




class GCExampleSchemaVData_PolymorphicDerivedB
{
private:
    void *m_ptr;

public:
    GCExampleSchemaVData_PolymorphicDerivedB() {}
    GCExampleSchemaVData_PolymorphicDerivedB(void *ptr) : m_ptr(ptr) {}

    int32_t GetDerivedB() const { return GetSchemaValue<int32_t>(m_ptr, "CExampleSchemaVData_PolymorphicDerivedB", "m_nDerivedB"); }
    void SetDerivedB(int32_t value) { SetSchemaValue(m_ptr, "CExampleSchemaVData_PolymorphicDerivedB", "m_nDerivedB", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif