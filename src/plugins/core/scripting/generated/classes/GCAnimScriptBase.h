class GCAnimScriptBase;

#ifndef _gccanimscriptbase_h
#define _gccanimscriptbase_h

#include "../../../scripting.h"




class GCAnimScriptBase
{
private:
    void *m_ptr;

public:
    GCAnimScriptBase() {}
    GCAnimScriptBase(void *ptr) : m_ptr(ptr) {}

    bool GetIsValid() const { return GetSchemaValue<bool>(m_ptr, "CAnimScriptBase", "m_bIsValid"); }
    void SetIsValid(bool value) { SetSchemaValue(m_ptr, "CAnimScriptBase", "m_bIsValid", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif