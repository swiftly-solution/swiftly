class GCEnvHudHint;

#ifndef _gccenvhudhint_h
#define _gccenvhudhint_h

#include "../../../scripting.h"




class GCEnvHudHint
{
private:
    void *m_ptr;

public:
    GCEnvHudHint() {}
    GCEnvHudHint(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetMessage() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvHudHint", "m_iszMessage"); }
    void SetMessage(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvHudHint", "m_iszMessage", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif