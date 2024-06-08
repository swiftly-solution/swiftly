class GCHostageExpresserShim;

#ifndef _gcchostageexpressershim_h
#define _gcchostageexpressershim_h

#include "../../../scripting.h"


#include "GCAI_Expresser.h"

class GCHostageExpresserShim
{
private:
    void *m_ptr;

public:
    GCHostageExpresserShim() {}
    GCHostageExpresserShim(void *ptr) : m_ptr(ptr) {}

    GCAI_Expresser* GetExpresser() const { return GetSchemaValue<GCAI_Expresser*>(m_ptr, "CHostageExpresserShim", "m_pExpresser"); }
    void SetExpresser(GCAI_Expresser* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Expresser' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif