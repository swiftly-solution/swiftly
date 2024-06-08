class GC_OP_ConstrainDistance;

#ifndef _gcc_op_constraindistance_h
#define _gcc_op_constraindistance_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_ConstrainDistance
{
private:
    void *m_ptr;

public:
    GC_OP_ConstrainDistance() {}
    GC_OP_ConstrainDistance(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetMinDistance() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_ConstrainDistance", "m_fMinDistance"); }
    void SetMinDistance(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ConstrainDistance", "m_fMinDistance", false, value); }
    GCParticleCollectionFloatInput GetMaxDistance() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_ConstrainDistance", "m_fMaxDistance"); }
    void SetMaxDistance(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ConstrainDistance", "m_fMaxDistance", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ConstrainDistance", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ConstrainDistance", "m_nControlPointNumber", false, value); }
    Vector GetCenterOffset() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_ConstrainDistance", "m_CenterOffset"); }
    void SetCenterOffset(Vector value) { SetSchemaValue(m_ptr, "C_OP_ConstrainDistance", "m_CenterOffset", false, value); }
    bool GetGlobalCenter() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ConstrainDistance", "m_bGlobalCenter"); }
    void SetGlobalCenter(bool value) { SetSchemaValue(m_ptr, "C_OP_ConstrainDistance", "m_bGlobalCenter", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif