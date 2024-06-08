class GCCSPlace;

#ifndef _gcccsplace_h
#define _gcccsplace_h

#include "../../../scripting.h"




class GCCSPlace
{
private:
    void *m_ptr;

public:
    GCCSPlace() {}
    GCCSPlace(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CCSPlace", "m_name"); }
    void SetName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CCSPlace", "m_name", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif