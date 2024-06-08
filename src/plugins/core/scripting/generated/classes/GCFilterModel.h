class GCFilterModel;

#ifndef _gccfiltermodel_h
#define _gccfiltermodel_h

#include "../../../scripting.h"




class GCFilterModel
{
private:
    void *m_ptr;

public:
    GCFilterModel() {}
    GCFilterModel(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetFilterModel() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFilterModel", "m_iFilterModel"); }
    void SetFilterModel(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFilterModel", "m_iFilterModel", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif