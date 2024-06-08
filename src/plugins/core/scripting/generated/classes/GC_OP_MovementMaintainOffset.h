class GC_OP_MovementMaintainOffset;

#ifndef _gcc_op_movementmaintainoffset_h
#define _gcc_op_movementmaintainoffset_h

#include "../../../scripting.h"




class GC_OP_MovementMaintainOffset
{
private:
    void *m_ptr;

public:
    GC_OP_MovementMaintainOffset() {}
    GC_OP_MovementMaintainOffset(void *ptr) : m_ptr(ptr) {}

    Vector GetOffset() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_MovementMaintainOffset", "m_vecOffset"); }
    void SetOffset(Vector value) { SetSchemaValue(m_ptr, "C_OP_MovementMaintainOffset", "m_vecOffset", false, value); }
    int32_t GetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MovementMaintainOffset", "m_nCP"); }
    void SetCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MovementMaintainOffset", "m_nCP", false, value); }
    bool GetRadiusScale() const { return GetSchemaValue<bool>(m_ptr, "C_OP_MovementMaintainOffset", "m_bRadiusScale"); }
    void SetRadiusScale(bool value) { SetSchemaValue(m_ptr, "C_OP_MovementMaintainOffset", "m_bRadiusScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif