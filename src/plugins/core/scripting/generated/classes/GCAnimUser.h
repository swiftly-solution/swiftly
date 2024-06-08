class GCAnimUser;

#ifndef _gccanimuser_h
#define _gccanimuser_h

#include "../../../scripting.h"




class GCAnimUser
{
private:
    void *m_ptr;

public:
    GCAnimUser() {}
    GCAnimUser(void *ptr) : m_ptr(ptr) {}

    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimUser", "m_name"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CAnimUser", "m_name", false, value); }
    int32_t GetType() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimUser", "m_nType"); }
    void SetType(int32_t value) { SetSchemaValue(m_ptr, "CAnimUser", "m_nType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif