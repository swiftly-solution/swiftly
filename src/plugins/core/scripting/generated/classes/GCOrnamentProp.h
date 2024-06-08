class GCOrnamentProp;

#ifndef _gccornamentprop_h
#define _gccornamentprop_h

#include "../../../scripting.h"




class GCOrnamentProp
{
private:
    void *m_ptr;

public:
    GCOrnamentProp() {}
    GCOrnamentProp(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetInitialOwner() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "COrnamentProp", "m_initialOwner"); }
    void SetInitialOwner(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "COrnamentProp", "m_initialOwner", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif