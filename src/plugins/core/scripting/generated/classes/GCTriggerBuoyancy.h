class GCTriggerBuoyancy;

#ifndef _gcctriggerbuoyancy_h
#define _gcctriggerbuoyancy_h

#include "../../../scripting.h"


#include "GCBuoyancyHelper.h"

class GCTriggerBuoyancy
{
private:
    void *m_ptr;

public:
    GCTriggerBuoyancy() {}
    GCTriggerBuoyancy(void *ptr) : m_ptr(ptr) {}

    GCBuoyancyHelper GetBuoyancyHelper() const { return GetSchemaValue<GCBuoyancyHelper>(m_ptr, "CTriggerBuoyancy", "m_BuoyancyHelper"); }
    void SetBuoyancyHelper(GCBuoyancyHelper value) { SetSchemaValue(m_ptr, "CTriggerBuoyancy", "m_BuoyancyHelper", false, value); }
    float GetFluidDensity() const { return GetSchemaValue<float>(m_ptr, "CTriggerBuoyancy", "m_flFluidDensity"); }
    void SetFluidDensity(float value) { SetSchemaValue(m_ptr, "CTriggerBuoyancy", "m_flFluidDensity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif