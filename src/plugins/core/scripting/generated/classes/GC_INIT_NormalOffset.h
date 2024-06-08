class GC_INIT_NormalOffset;

#ifndef _gcc_init_normaloffset_h
#define _gcc_init_normaloffset_h

#include "../../../scripting.h"




class GC_INIT_NormalOffset
{
private:
    void *m_ptr;

public:
    GC_INIT_NormalOffset() {}
    GC_INIT_NormalOffset(void *ptr) : m_ptr(ptr) {}

    Vector GetOffsetMin() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_NormalOffset", "m_OffsetMin"); }
    void SetOffsetMin(Vector value) { SetSchemaValue(m_ptr, "C_INIT_NormalOffset", "m_OffsetMin", false, value); }
    Vector GetOffsetMax() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_NormalOffset", "m_OffsetMax"); }
    void SetOffsetMax(Vector value) { SetSchemaValue(m_ptr, "C_INIT_NormalOffset", "m_OffsetMax", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_NormalOffset", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_NormalOffset", "m_nControlPointNumber", false, value); }
    bool GetLocalCoords() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_NormalOffset", "m_bLocalCoords"); }
    void SetLocalCoords(bool value) { SetSchemaValue(m_ptr, "C_INIT_NormalOffset", "m_bLocalCoords", false, value); }
    bool GetNormalize() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_NormalOffset", "m_bNormalize"); }
    void SetNormalize(bool value) { SetSchemaValue(m_ptr, "C_INIT_NormalOffset", "m_bNormalize", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif