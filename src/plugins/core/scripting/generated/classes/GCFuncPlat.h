class GCFuncPlat;

#ifndef _gccfuncplat_h
#define _gccfuncplat_h

#include "../../../scripting.h"




class GCFuncPlat
{
private:
    void *m_ptr;

public:
    GCFuncPlat() {}
    GCFuncPlat(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetNoise() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncPlat", "m_sNoise"); }
    void SetNoise(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncPlat", "m_sNoise", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif