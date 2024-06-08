class GC_OP_SetControlPointFieldToWater;

#ifndef _gcc_op_setcontrolpointfieldtowater_h
#define _gcc_op_setcontrolpointfieldtowater_h

#include "../../../scripting.h"




class GC_OP_SetControlPointFieldToWater
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointFieldToWater() {}
    GC_OP_SetControlPointFieldToWater(void *ptr) : m_ptr(ptr) {}

    int32_t GetSourceCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointFieldToWater", "m_nSourceCP"); }
    void SetSourceCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointFieldToWater", "m_nSourceCP", false, value); }
    int32_t GetDestCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointFieldToWater", "m_nDestCP"); }
    void SetDestCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointFieldToWater", "m_nDestCP", false, value); }
    int32_t GetCPField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointFieldToWater", "m_nCPField"); }
    void SetCPField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointFieldToWater", "m_nCPField", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif