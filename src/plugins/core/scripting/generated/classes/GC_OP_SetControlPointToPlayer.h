class GC_OP_SetControlPointToPlayer;

#ifndef _gcc_op_setcontrolpointtoplayer_h
#define _gcc_op_setcontrolpointtoplayer_h

#include "../../../scripting.h"




class GC_OP_SetControlPointToPlayer
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointToPlayer() {}
    GC_OP_SetControlPointToPlayer(void *ptr) : m_ptr(ptr) {}

    int32_t GetCP1() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointToPlayer", "m_nCP1"); }
    void SetCP1(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToPlayer", "m_nCP1", false, value); }
    Vector GetCP1Pos() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_SetControlPointToPlayer", "m_vecCP1Pos"); }
    void SetCP1Pos(Vector value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToPlayer", "m_vecCP1Pos", false, value); }
    bool GetOrientToEyes() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointToPlayer", "m_bOrientToEyes"); }
    void SetOrientToEyes(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToPlayer", "m_bOrientToEyes", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif