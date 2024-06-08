class GC_OP_BoxConstraint;

#ifndef _gcc_op_boxconstraint_h
#define _gcc_op_boxconstraint_h

#include "../../../scripting.h"




class GC_OP_BoxConstraint
{
private:
    void *m_ptr;

public:
    GC_OP_BoxConstraint() {}
    GC_OP_BoxConstraint(void *ptr) : m_ptr(ptr) {}

    int32_t GetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_BoxConstraint", "m_nCP"); }
    void SetCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_BoxConstraint", "m_nCP", false, value); }
    bool GetLocalSpace() const { return GetSchemaValue<bool>(m_ptr, "C_OP_BoxConstraint", "m_bLocalSpace"); }
    void SetLocalSpace(bool value) { SetSchemaValue(m_ptr, "C_OP_BoxConstraint", "m_bLocalSpace", false, value); }
    bool GetAccountForRadius() const { return GetSchemaValue<bool>(m_ptr, "C_OP_BoxConstraint", "m_bAccountForRadius"); }
    void SetAccountForRadius(bool value) { SetSchemaValue(m_ptr, "C_OP_BoxConstraint", "m_bAccountForRadius", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif