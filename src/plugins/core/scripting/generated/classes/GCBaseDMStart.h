class GCBaseDMStart;

#ifndef _gccbasedmstart_h
#define _gccbasedmstart_h

#include "../../../scripting.h"




class GCBaseDMStart
{
private:
    void *m_ptr;

public:
    GCBaseDMStart() {}
    GCBaseDMStart(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetMaster() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseDMStart", "m_Master"); }
    void SetMaster(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseDMStart", "m_Master", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif