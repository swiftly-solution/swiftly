class GCTestDomainDerived_Cursor;

#ifndef _gcctestdomainderived_cursor_h
#define _gcctestdomainderived_cursor_h

#include "../../../scripting.h"




class GCTestDomainDerived_Cursor
{
private:
    void *m_ptr;

public:
    GCTestDomainDerived_Cursor() {}
    GCTestDomainDerived_Cursor(void *ptr) : m_ptr(ptr) {}

    int32_t GetCursorValueA() const { return GetSchemaValue<int32_t>(m_ptr, "CTestDomainDerived_Cursor", "m_nCursorValueA"); }
    void SetCursorValueA(int32_t value) { SetSchemaValue(m_ptr, "CTestDomainDerived_Cursor", "m_nCursorValueA", false, value); }
    int32_t GetCursorValueB() const { return GetSchemaValue<int32_t>(m_ptr, "CTestDomainDerived_Cursor", "m_nCursorValueB"); }
    void SetCursorValueB(int32_t value) { SetSchemaValue(m_ptr, "CTestDomainDerived_Cursor", "m_nCursorValueB", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif