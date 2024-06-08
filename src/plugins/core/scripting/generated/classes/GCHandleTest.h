class GCHandleTest;

#ifndef _gcchandletest_h
#define _gcchandletest_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCHandleTest
{
private:
    void *m_ptr;

public:
    GCHandleTest() {}
    GCHandleTest(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetHandle() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CHandleTest", "m_Handle"); }
    void SetHandle(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Handle' is not possible.\n"); }
    bool GetSendHandle() const { return GetSchemaValue<bool>(m_ptr, "CHandleTest", "m_bSendHandle"); }
    void SetSendHandle(bool value) { SetSchemaValue(m_ptr, "CHandleTest", "m_bSendHandle", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif