class GCFilterContext;

#ifndef _gccfiltercontext_h
#define _gccfiltercontext_h

#include "../../../scripting.h"




class GCFilterContext
{
private:
    void *m_ptr;

public:
    GCFilterContext() {}
    GCFilterContext(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetFilterContext() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFilterContext", "m_iFilterContext"); }
    void SetFilterContext(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFilterContext", "m_iFilterContext", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif