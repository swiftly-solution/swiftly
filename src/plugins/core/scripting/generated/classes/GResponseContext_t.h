class GResponseContext_t;

#ifndef _gcresponsecontext_t_h
#define _gcresponsecontext_t_h

#include "../../../scripting.h"




class GResponseContext_t
{
private:
    void *m_ptr;

public:
    GResponseContext_t() {}
    GResponseContext_t(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "ResponseContext_t", "m_iszName"); }
    void SetName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "ResponseContext_t", "m_iszName", true, value); }
    CUtlSymbolLarge GetValue() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "ResponseContext_t", "m_iszValue"); }
    void SetValue(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "ResponseContext_t", "m_iszValue", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif