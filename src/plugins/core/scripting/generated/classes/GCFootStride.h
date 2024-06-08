class GCFootStride;

#ifndef _gccfootstride_h
#define _gccfootstride_h

#include "../../../scripting.h"


#include "GCFootCycle.h"
#include "GCFootCycleDefinition.h"
#include "GCFootTrajectories.h"

class GCFootStride
{
private:
    void *m_ptr;

public:
    GCFootStride() {}
    GCFootStride(void *ptr) : m_ptr(ptr) {}

    GCFootCycleDefinition GetDefinition() const { return GetSchemaValue<GCFootCycleDefinition>(m_ptr, "CFootStride", "m_definition"); }
    void SetDefinition(GCFootCycleDefinition value) { SetSchemaValue(m_ptr, "CFootStride", "m_definition", false, value); }
    GCFootTrajectories GetTrajectories() const { return GetSchemaValue<GCFootTrajectories>(m_ptr, "CFootStride", "m_trajectories"); }
    void SetTrajectories(GCFootTrajectories value) { SetSchemaValue(m_ptr, "CFootStride", "m_trajectories", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif