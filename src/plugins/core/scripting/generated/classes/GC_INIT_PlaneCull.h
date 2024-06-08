class GC_INIT_PlaneCull;

#ifndef _gcc_init_planecull_h
#define _gcc_init_planecull_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_INIT_PlaneCull
{
private:
    void *m_ptr;

public:
    GC_INIT_PlaneCull() {}
    GC_INIT_PlaneCull(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_PlaneCull", "m_nControlPoint"); }
    void SetControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_PlaneCull", "m_nControlPoint", false, value); }
    GCParticleCollectionFloatInput GetDistance() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_PlaneCull", "m_flDistance"); }
    void SetDistance(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_PlaneCull", "m_flDistance", false, value); }
    bool GetCullInside() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_PlaneCull", "m_bCullInside"); }
    void SetCullInside(bool value) { SetSchemaValue(m_ptr, "C_INIT_PlaneCull", "m_bCullInside", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif