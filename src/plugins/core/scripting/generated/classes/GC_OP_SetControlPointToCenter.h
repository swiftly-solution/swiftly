class GC_OP_SetControlPointToCenter;

#ifndef _gcc_op_setcontrolpointtocenter_h
#define _gcc_op_setcontrolpointtocenter_h

#include "../../../scripting.h"

#include "../types/GParticleParentSetMode_t.h"


class GC_OP_SetControlPointToCenter
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointToCenter() {}
    GC_OP_SetControlPointToCenter(void *ptr) : m_ptr(ptr) {}

    int32_t GetCP1() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointToCenter", "m_nCP1"); }
    void SetCP1(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToCenter", "m_nCP1", false, value); }
    Vector GetCP1Pos() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_SetControlPointToCenter", "m_vecCP1Pos"); }
    void SetCP1Pos(Vector value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToCenter", "m_vecCP1Pos", false, value); }
    ParticleParentSetMode_t GetSetParent() const { return GetSchemaValue<ParticleParentSetMode_t>(m_ptr, "C_OP_SetControlPointToCenter", "m_nSetParent"); }
    void SetSetParent(ParticleParentSetMode_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToCenter", "m_nSetParent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif