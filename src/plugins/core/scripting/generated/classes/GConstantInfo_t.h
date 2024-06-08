class GConstantInfo_t;

#ifndef _gcconstantinfo_t_h
#define _gcconstantinfo_t_h

#include "../../../scripting.h"




class GConstantInfo_t
{
private:
    void *m_ptr;

public:
    GConstantInfo_t() {}
    GConstantInfo_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "ConstantInfo_t", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "ConstantInfo_t", "m_name", true, value); }
    CUtlStringToken GetNameToken() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "ConstantInfo_t", "m_nameToken"); }
    void SetNameToken(CUtlStringToken value) { SetSchemaValue(m_ptr, "ConstantInfo_t", "m_nameToken", true, value); }
    float GetValue() const { return GetSchemaValue<float>(m_ptr, "ConstantInfo_t", "m_flValue"); }
    void SetValue(float value) { SetSchemaValue(m_ptr, "ConstantInfo_t", "m_flValue", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif