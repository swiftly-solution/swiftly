class GCExampleSchemaVData_PolymorphicDerivedA;

#ifndef _gccexampleschemavdata_polymorphicderiveda_h
#define _gccexampleschemavdata_polymorphicderiveda_h

#include "../../../scripting.h"




class GCExampleSchemaVData_PolymorphicDerivedA
{
private:
    void *m_ptr;

public:
    GCExampleSchemaVData_PolymorphicDerivedA() {}
    GCExampleSchemaVData_PolymorphicDerivedA(void *ptr) : m_ptr(ptr) {}

    int32_t GetDerivedA() const { return GetSchemaValue<int32_t>(m_ptr, "CExampleSchemaVData_PolymorphicDerivedA", "m_nDerivedA"); }
    void SetDerivedA(int32_t value) { SetSchemaValue(m_ptr, "CExampleSchemaVData_PolymorphicDerivedA", "m_nDerivedA", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif