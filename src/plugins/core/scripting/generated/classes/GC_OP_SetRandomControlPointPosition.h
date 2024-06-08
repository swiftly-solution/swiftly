class GC_OP_SetRandomControlPointPosition;

#ifndef _gcc_op_setrandomcontrolpointposition_h
#define _gcc_op_setrandomcontrolpointposition_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_SetRandomControlPointPosition
{
private:
    void *m_ptr;

public:
    GC_OP_SetRandomControlPointPosition() {}
    GC_OP_SetRandomControlPointPosition(void *ptr) : m_ptr(ptr) {}

    bool GetUseWorldLocation() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetRandomControlPointPosition", "m_bUseWorldLocation"); }
    void SetUseWorldLocation(bool value) { SetSchemaValue(m_ptr, "C_OP_SetRandomControlPointPosition", "m_bUseWorldLocation", false, value); }
    bool GetOrient() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetRandomControlPointPosition", "m_bOrient"); }
    void SetOrient(bool value) { SetSchemaValue(m_ptr, "C_OP_SetRandomControlPointPosition", "m_bOrient", false, value); }
    int32_t GetCP1() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetRandomControlPointPosition", "m_nCP1"); }
    void SetCP1(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetRandomControlPointPosition", "m_nCP1", false, value); }
    int32_t GetHeadLocation() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetRandomControlPointPosition", "m_nHeadLocation"); }
    void SetHeadLocation(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetRandomControlPointPosition", "m_nHeadLocation", false, value); }
    GCParticleCollectionFloatInput GetReRandomRate() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetRandomControlPointPosition", "m_flReRandomRate"); }
    void SetReRandomRate(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetRandomControlPointPosition", "m_flReRandomRate", false, value); }
    Vector GetCPMinPos() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_SetRandomControlPointPosition", "m_vecCPMinPos"); }
    void SetCPMinPos(Vector value) { SetSchemaValue(m_ptr, "C_OP_SetRandomControlPointPosition", "m_vecCPMinPos", false, value); }
    Vector GetCPMaxPos() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_SetRandomControlPointPosition", "m_vecCPMaxPos"); }
    void SetCPMaxPos(Vector value) { SetSchemaValue(m_ptr, "C_OP_SetRandomControlPointPosition", "m_vecCPMaxPos", false, value); }
    GCParticleCollectionFloatInput GetInterpolation() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetRandomControlPointPosition", "m_flInterpolation"); }
    void SetInterpolation(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetRandomControlPointPosition", "m_flInterpolation", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif