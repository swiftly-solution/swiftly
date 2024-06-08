class GCSoundEventParameter;

#ifndef _gccsoundeventparameter_h
#define _gccsoundeventparameter_h

#include "../../../scripting.h"




class GCSoundEventParameter
{
private:
    void *m_ptr;

public:
    GCSoundEventParameter() {}
    GCSoundEventParameter(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetParamName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundEventParameter", "m_iszParamName"); }
    void SetParamName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundEventParameter", "m_iszParamName", false, value); }
    float GetFloatValue() const { return GetSchemaValue<float>(m_ptr, "CSoundEventParameter", "m_flFloatValue"); }
    void SetFloatValue(float value) { SetSchemaValue(m_ptr, "CSoundEventParameter", "m_flFloatValue", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif