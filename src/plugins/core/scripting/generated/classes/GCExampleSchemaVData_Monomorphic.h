class GCExampleSchemaVData_Monomorphic;

#ifndef _gccexampleschemavdata_monomorphic_h
#define _gccexampleschemavdata_monomorphic_h

#include "../../../scripting.h"




class GCExampleSchemaVData_Monomorphic
{
private:
    void *m_ptr;

public:
    GCExampleSchemaVData_Monomorphic() {}
    GCExampleSchemaVData_Monomorphic(void *ptr) : m_ptr(ptr) {}

    int32_t GetExample1() const { return GetSchemaValue<int32_t>(m_ptr, "CExampleSchemaVData_Monomorphic", "m_nExample1"); }
    void SetExample1(int32_t value) { SetSchemaValue(m_ptr, "CExampleSchemaVData_Monomorphic", "m_nExample1", false, value); }
    int32_t GetExample2() const { return GetSchemaValue<int32_t>(m_ptr, "CExampleSchemaVData_Monomorphic", "m_nExample2"); }
    void SetExample2(int32_t value) { SetSchemaValue(m_ptr, "CExampleSchemaVData_Monomorphic", "m_nExample2", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif