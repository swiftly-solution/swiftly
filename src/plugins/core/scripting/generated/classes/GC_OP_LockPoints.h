class GC_OP_LockPoints;

#ifndef _gcc_op_lockpoints_h
#define _gcc_op_lockpoints_h

#include "../../../scripting.h"




class GC_OP_LockPoints
{
private:
    void *m_ptr;

public:
    GC_OP_LockPoints() {}
    GC_OP_LockPoints(void *ptr) : m_ptr(ptr) {}

    int32_t GetMinCol() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_LockPoints", "m_nMinCol"); }
    void SetMinCol(int32_t value) { SetSchemaValue(m_ptr, "C_OP_LockPoints", "m_nMinCol", false, value); }
    int32_t GetMaxCol() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_LockPoints", "m_nMaxCol"); }
    void SetMaxCol(int32_t value) { SetSchemaValue(m_ptr, "C_OP_LockPoints", "m_nMaxCol", false, value); }
    int32_t GetMinRow() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_LockPoints", "m_nMinRow"); }
    void SetMinRow(int32_t value) { SetSchemaValue(m_ptr, "C_OP_LockPoints", "m_nMinRow", false, value); }
    int32_t GetMaxRow() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_LockPoints", "m_nMaxRow"); }
    void SetMaxRow(int32_t value) { SetSchemaValue(m_ptr, "C_OP_LockPoints", "m_nMaxRow", false, value); }
    int32_t GetControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_LockPoints", "m_nControlPoint"); }
    void SetControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_LockPoints", "m_nControlPoint", false, value); }
    float GetBlendValue() const { return GetSchemaValue<float>(m_ptr, "C_OP_LockPoints", "m_flBlendValue"); }
    void SetBlendValue(float value) { SetSchemaValue(m_ptr, "C_OP_LockPoints", "m_flBlendValue", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif