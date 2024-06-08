class GC_OP_SetSimulationRate;

#ifndef _gcc_op_setsimulationrate_h
#define _gcc_op_setsimulationrate_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_SetSimulationRate
{
private:
    void *m_ptr;

public:
    GC_OP_SetSimulationRate() {}
    GC_OP_SetSimulationRate(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetSimulationScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetSimulationRate", "m_flSimulationScale"); }
    void SetSimulationScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetSimulationRate", "m_flSimulationScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif