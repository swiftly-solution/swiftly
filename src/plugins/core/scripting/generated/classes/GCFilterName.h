class GCFilterName;

#ifndef _gccfiltername_h
#define _gccfiltername_h

#include "../../../scripting.h"




class GCFilterName
{
private:
    void *m_ptr;

public:
    GCFilterName() {}
    GCFilterName(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetFilterName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFilterName", "m_iFilterName"); }
    void SetFilterName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFilterName", "m_iFilterName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif