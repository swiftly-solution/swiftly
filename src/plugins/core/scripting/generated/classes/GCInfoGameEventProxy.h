class GCInfoGameEventProxy;

#ifndef _gccinfogameeventproxy_h
#define _gccinfogameeventproxy_h

#include "../../../scripting.h"




class GCInfoGameEventProxy
{
private:
    void *m_ptr;

public:
    GCInfoGameEventProxy() {}
    GCInfoGameEventProxy(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetEventName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoGameEventProxy", "m_iszEventName"); }
    void SetEventName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CInfoGameEventProxy", "m_iszEventName", false, value); }
    float GetRange() const { return GetSchemaValue<float>(m_ptr, "CInfoGameEventProxy", "m_flRange"); }
    void SetRange(float value) { SetSchemaValue(m_ptr, "CInfoGameEventProxy", "m_flRange", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif