class GC_OP_BasicMovement;

#ifndef _gcc_op_basicmovement_h
#define _gcc_op_basicmovement_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"
#include "GCParticleMassCalculationParameters.h"

class GC_OP_BasicMovement
{
private:
    void *m_ptr;

public:
    GC_OP_BasicMovement() {}
    GC_OP_BasicMovement(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetDrag() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_BasicMovement", "m_fDrag"); }
    void SetDrag(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_BasicMovement", "m_fDrag", false, value); }
    GCParticleMassCalculationParameters GetMassControls() const { return GetSchemaValue<GCParticleMassCalculationParameters>(m_ptr, "C_OP_BasicMovement", "m_massControls"); }
    void SetMassControls(GCParticleMassCalculationParameters value) { SetSchemaValue(m_ptr, "C_OP_BasicMovement", "m_massControls", false, value); }
    int32_t GetMaxConstraintPasses() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_BasicMovement", "m_nMaxConstraintPasses"); }
    void SetMaxConstraintPasses(int32_t value) { SetSchemaValue(m_ptr, "C_OP_BasicMovement", "m_nMaxConstraintPasses", false, value); }
    bool GetUseNewCode() const { return GetSchemaValue<bool>(m_ptr, "C_OP_BasicMovement", "m_bUseNewCode"); }
    void SetUseNewCode(bool value) { SetSchemaValue(m_ptr, "C_OP_BasicMovement", "m_bUseNewCode", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif