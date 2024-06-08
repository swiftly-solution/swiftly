class GC_OP_SetControlPointPositionToRandomActiveCP;

#ifndef _gcc_op_setcontrolpointpositiontorandomactivecp_h
#define _gcc_op_setcontrolpointpositiontorandomactivecp_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_SetControlPointPositionToRandomActiveCP
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointPositionToRandomActiveCP() {}
    GC_OP_SetControlPointPositionToRandomActiveCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetCP1() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointPositionToRandomActiveCP", "m_nCP1"); }
    void SetCP1(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositionToRandomActiveCP", "m_nCP1", false, value); }
    int32_t GetHeadLocationMin() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointPositionToRandomActiveCP", "m_nHeadLocationMin"); }
    void SetHeadLocationMin(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositionToRandomActiveCP", "m_nHeadLocationMin", false, value); }
    int32_t GetHeadLocationMax() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointPositionToRandomActiveCP", "m_nHeadLocationMax"); }
    void SetHeadLocationMax(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositionToRandomActiveCP", "m_nHeadLocationMax", false, value); }
    GCParticleCollectionFloatInput GetResetRate() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetControlPointPositionToRandomActiveCP", "m_flResetRate"); }
    void SetResetRate(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositionToRandomActiveCP", "m_flResetRate", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif