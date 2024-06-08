class GCAttributeManager__cached_attribute_float_t;

#ifndef _gccattributemanager__cached_attribute_float_t_h
#define _gccattributemanager__cached_attribute_float_t_h

#include "../../../scripting.h"




class GCAttributeManager__cached_attribute_float_t
{
private:
    void *m_ptr;

public:
    GCAttributeManager__cached_attribute_float_t() {}
    GCAttributeManager__cached_attribute_float_t(void *ptr) : m_ptr(ptr) {}

    float GetIn() const { return GetSchemaValue<float>(m_ptr, "CAttributeManager__cached_attribute_float_t", "flIn"); }
    void SetIn(float value) { SetSchemaValue(m_ptr, "CAttributeManager__cached_attribute_float_t", "flIn", true, value); }
    CUtlSymbolLarge GetAttribHook() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CAttributeManager__cached_attribute_float_t", "iAttribHook"); }
    void SetAttribHook(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CAttributeManager__cached_attribute_float_t", "iAttribHook", true, value); }
    float GetOut() const { return GetSchemaValue<float>(m_ptr, "CAttributeManager__cached_attribute_float_t", "flOut"); }
    void SetOut(float value) { SetSchemaValue(m_ptr, "CAttributeManager__cached_attribute_float_t", "flOut", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif