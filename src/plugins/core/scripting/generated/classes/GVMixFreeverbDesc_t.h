class GVMixFreeverbDesc_t;

#ifndef _gcvmixfreeverbdesc_t_h
#define _gcvmixfreeverbdesc_t_h

#include "../../../scripting.h"




class GVMixFreeverbDesc_t
{
private:
    void *m_ptr;

public:
    GVMixFreeverbDesc_t() {}
    GVMixFreeverbDesc_t(void *ptr) : m_ptr(ptr) {}

    float GetRoomSize() const { return GetSchemaValue<float>(m_ptr, "VMixFreeverbDesc_t", "m_flRoomSize"); }
    void SetRoomSize(float value) { SetSchemaValue(m_ptr, "VMixFreeverbDesc_t", "m_flRoomSize", true, value); }
    float GetDamp() const { return GetSchemaValue<float>(m_ptr, "VMixFreeverbDesc_t", "m_flDamp"); }
    void SetDamp(float value) { SetSchemaValue(m_ptr, "VMixFreeverbDesc_t", "m_flDamp", true, value); }
    float GetWidth() const { return GetSchemaValue<float>(m_ptr, "VMixFreeverbDesc_t", "m_flWidth"); }
    void SetWidth(float value) { SetSchemaValue(m_ptr, "VMixFreeverbDesc_t", "m_flWidth", true, value); }
    float GetLateReflections() const { return GetSchemaValue<float>(m_ptr, "VMixFreeverbDesc_t", "m_flLateReflections"); }
    void SetLateReflections(float value) { SetSchemaValue(m_ptr, "VMixFreeverbDesc_t", "m_flLateReflections", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif