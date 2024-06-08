class GModelConfigHandle_t;

#ifndef _gcmodelconfighandle_t_h
#define _gcmodelconfighandle_t_h

#include "../../../scripting.h"




class GModelConfigHandle_t
{
private:
    void *m_ptr;

public:
    GModelConfigHandle_t() {}
    GModelConfigHandle_t(void *ptr) : m_ptr(ptr) {}

    uint32_t GetValue() const { return GetSchemaValue<uint32_t>(m_ptr, "ModelConfigHandle_t", "m_Value"); }
    void SetValue(uint32_t value) { SetSchemaValue(m_ptr, "ModelConfigHandle_t", "m_Value", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif