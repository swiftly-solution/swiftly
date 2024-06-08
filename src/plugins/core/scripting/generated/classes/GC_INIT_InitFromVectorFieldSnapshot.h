class GC_INIT_InitFromVectorFieldSnapshot;

#ifndef _gcc_init_initfromvectorfieldsnapshot_h
#define _gcc_init_initfromvectorfieldsnapshot_h

#include "../../../scripting.h"


#include "GCPerParticleVecInput.h"

class GC_INIT_InitFromVectorFieldSnapshot
{
private:
    void *m_ptr;

public:
    GC_INIT_InitFromVectorFieldSnapshot() {}
    GC_INIT_InitFromVectorFieldSnapshot(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_InitFromVectorFieldSnapshot", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_InitFromVectorFieldSnapshot", "m_nControlPointNumber", false, value); }
    int32_t GetLocalSpaceCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_InitFromVectorFieldSnapshot", "m_nLocalSpaceCP"); }
    void SetLocalSpaceCP(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_InitFromVectorFieldSnapshot", "m_nLocalSpaceCP", false, value); }
    int32_t GetWeightUpdateCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_InitFromVectorFieldSnapshot", "m_nWeightUpdateCP"); }
    void SetWeightUpdateCP(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_InitFromVectorFieldSnapshot", "m_nWeightUpdateCP", false, value); }
    bool GetUseVerticalVelocity() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitFromVectorFieldSnapshot", "m_bUseVerticalVelocity"); }
    void SetUseVerticalVelocity(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitFromVectorFieldSnapshot", "m_bUseVerticalVelocity", false, value); }
    GCPerParticleVecInput GetScale() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_INIT_InitFromVectorFieldSnapshot", "m_vecScale"); }
    void SetScale(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_INIT_InitFromVectorFieldSnapshot", "m_vecScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif