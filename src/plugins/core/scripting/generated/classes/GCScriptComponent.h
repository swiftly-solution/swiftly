class GCScriptComponent;

#ifndef _gccscriptcomponent_h
#define _gccscriptcomponent_h

#include "../../../scripting.h"




class GCScriptComponent
{
private:
    void *m_ptr;

public:
    GCScriptComponent() {}
    GCScriptComponent(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetScriptClassName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptComponent", "m_scriptClassName"); }
    void SetScriptClassName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CScriptComponent", "m_scriptClassName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif