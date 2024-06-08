class GC_INIT_DistanceToNeighborCull;

#ifndef _gcc_init_distancetoneighborcull_h
#define _gcc_init_distancetoneighborcull_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"

class GC_INIT_DistanceToNeighborCull
{
private:
    void *m_ptr;

public:
    GC_INIT_DistanceToNeighborCull() {}
    GC_INIT_DistanceToNeighborCull(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetDistance() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_DistanceToNeighborCull", "m_flDistance"); }
    void SetDistance(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_DistanceToNeighborCull", "m_flDistance", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif