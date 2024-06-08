class GC_OP_SetControlPointToHand;

#ifndef _gcc_op_setcontrolpointtohand_h
#define _gcc_op_setcontrolpointtohand_h

#include "../../../scripting.h"




class GC_OP_SetControlPointToHand
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointToHand() {}
    GC_OP_SetControlPointToHand(void *ptr) : m_ptr(ptr) {}

    int32_t GetCP1() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointToHand", "m_nCP1"); }
    void SetCP1(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToHand", "m_nCP1", false, value); }
    int32_t GetHand() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointToHand", "m_nHand"); }
    void SetHand(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToHand", "m_nHand", false, value); }
    Vector GetCP1Pos() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_SetControlPointToHand", "m_vecCP1Pos"); }
    void SetCP1Pos(Vector value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToHand", "m_vecCP1Pos", false, value); }
    bool GetOrientToHand() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointToHand", "m_bOrientToHand"); }
    void SetOrientToHand(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToHand", "m_bOrientToHand", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif