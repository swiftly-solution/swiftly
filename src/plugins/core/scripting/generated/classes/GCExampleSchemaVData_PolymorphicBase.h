class GCExampleSchemaVData_PolymorphicBase;

#ifndef _gccexampleschemavdata_polymorphicbase_h
#define _gccexampleschemavdata_polymorphicbase_h

#include "../../../scripting.h"




class GCExampleSchemaVData_PolymorphicBase
{
private:
    void *m_ptr;

public:
    GCExampleSchemaVData_PolymorphicBase() {}
    GCExampleSchemaVData_PolymorphicBase(void *ptr) : m_ptr(ptr) {}

    int32_t GetBase() const { return GetSchemaValue<int32_t>(m_ptr, "CExampleSchemaVData_PolymorphicBase", "m_nBase"); }
    void SetBase(int32_t value) { SetSchemaValue(m_ptr, "CExampleSchemaVData_PolymorphicBase", "m_nBase", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif