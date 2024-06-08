class GC_OP_SDFConstraint;

#ifndef _gcc_op_sdfconstraint_h
#define _gcc_op_sdfconstraint_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_SDFConstraint
{
private:
    void *m_ptr;

public:
    GC_OP_SDFConstraint() {}
    GC_OP_SDFConstraint(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetMinDist() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SDFConstraint", "m_flMinDist"); }
    void SetMinDist(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SDFConstraint", "m_flMinDist", false, value); }
    GCParticleCollectionFloatInput GetMaxDist() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SDFConstraint", "m_flMaxDist"); }
    void SetMaxDist(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SDFConstraint", "m_flMaxDist", false, value); }
    int32_t GetMaxIterations() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SDFConstraint", "m_nMaxIterations"); }
    void SetMaxIterations(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SDFConstraint", "m_nMaxIterations", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif