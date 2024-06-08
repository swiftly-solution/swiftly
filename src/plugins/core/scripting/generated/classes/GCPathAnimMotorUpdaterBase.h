class GCPathAnimMotorUpdaterBase;

#ifndef _gccpathanimmotorupdaterbase_h
#define _gccpathanimmotorupdaterbase_h

#include "../../../scripting.h"




class GCPathAnimMotorUpdaterBase
{
private:
    void *m_ptr;

public:
    GCPathAnimMotorUpdaterBase() {}
    GCPathAnimMotorUpdaterBase(void *ptr) : m_ptr(ptr) {}

    bool GetLockToPath() const { return GetSchemaValue<bool>(m_ptr, "CPathAnimMotorUpdaterBase", "m_bLockToPath"); }
    void SetLockToPath(bool value) { SetSchemaValue(m_ptr, "CPathAnimMotorUpdaterBase", "m_bLockToPath", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif