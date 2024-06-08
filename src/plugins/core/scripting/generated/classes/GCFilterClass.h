class GCFilterClass;

#ifndef _gccfilterclass_h
#define _gccfilterclass_h

#include "../../../scripting.h"




class GCFilterClass
{
private:
    void *m_ptr;

public:
    GCFilterClass() {}
    GCFilterClass(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetFilterClass() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFilterClass", "m_iFilterClass"); }
    void SetFilterClass(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFilterClass", "m_iFilterClass", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif