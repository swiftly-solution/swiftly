class GC_OP_SetControlPointToHMD;

#ifndef _gcc_op_setcontrolpointtohmd_h
#define _gcc_op_setcontrolpointtohmd_h

#include "../../../scripting.h"




class GC_OP_SetControlPointToHMD
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointToHMD() {}
    GC_OP_SetControlPointToHMD(void *ptr) : m_ptr(ptr) {}

    int32_t GetCP1() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointToHMD", "m_nCP1"); }
    void SetCP1(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToHMD", "m_nCP1", false, value); }
    Vector GetCP1Pos() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_SetControlPointToHMD", "m_vecCP1Pos"); }
    void SetCP1Pos(Vector value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToHMD", "m_vecCP1Pos", false, value); }
    bool GetOrientToHMD() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointToHMD", "m_bOrientToHMD"); }
    void SetOrientToHMD(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToHMD", "m_bOrientToHMD", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif