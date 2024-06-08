class GC_OP_ModelCull;

#ifndef _gcc_op_modelcull_h
#define _gcc_op_modelcull_h

#include "../../../scripting.h"




class GC_OP_ModelCull
{
private:
    void *m_ptr;

public:
    GC_OP_ModelCull() {}
    GC_OP_ModelCull(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ModelCull", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ModelCull", "m_nControlPointNumber", false, value); }
    bool GetBoundBox() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ModelCull", "m_bBoundBox"); }
    void SetBoundBox(bool value) { SetSchemaValue(m_ptr, "C_OP_ModelCull", "m_bBoundBox", false, value); }
    bool GetCullOutside() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ModelCull", "m_bCullOutside"); }
    void SetCullOutside(bool value) { SetSchemaValue(m_ptr, "C_OP_ModelCull", "m_bCullOutside", false, value); }
    bool GetUseBones() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ModelCull", "m_bUseBones"); }
    void SetUseBones(bool value) { SetSchemaValue(m_ptr, "C_OP_ModelCull", "m_bUseBones", false, value); }
    std::string GetHitboxSetName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_ModelCull", "m_HitboxSetName"); }
    void SetHitboxSetName(std::string value) { SetSchemaValue(m_ptr, "C_OP_ModelCull", "m_HitboxSetName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif