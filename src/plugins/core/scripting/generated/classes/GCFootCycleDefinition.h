class GCFootCycleDefinition;

#ifndef _gccfootcycledefinition_h
#define _gccfootcycledefinition_h

#include "../../../scripting.h"


#include "GCAnimCycle.h"
#include "GCFootCycle.h"

class GCFootCycleDefinition
{
private:
    void *m_ptr;

public:
    GCFootCycleDefinition() {}
    GCFootCycleDefinition(void *ptr) : m_ptr(ptr) {}

    Vector GetStancePositionMS() const { return GetSchemaValue<Vector>(m_ptr, "CFootCycleDefinition", "m_vStancePositionMS"); }
    void SetStancePositionMS(Vector value) { SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_vStancePositionMS", false, value); }
    Vector GetMidpointPositionMS() const { return GetSchemaValue<Vector>(m_ptr, "CFootCycleDefinition", "m_vMidpointPositionMS"); }
    void SetMidpointPositionMS(Vector value) { SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_vMidpointPositionMS", false, value); }
    float GetStanceDirectionMS() const { return GetSchemaValue<float>(m_ptr, "CFootCycleDefinition", "m_flStanceDirectionMS"); }
    void SetStanceDirectionMS(float value) { SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_flStanceDirectionMS", false, value); }
    Vector GetToStrideStartPos() const { return GetSchemaValue<Vector>(m_ptr, "CFootCycleDefinition", "m_vToStrideStartPos"); }
    void SetToStrideStartPos(Vector value) { SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_vToStrideStartPos", false, value); }
    GCAnimCycle GetStanceCycle() const { return GetSchemaValue<GCAnimCycle>(m_ptr, "CFootCycleDefinition", "m_stanceCycle"); }
    void SetStanceCycle(GCAnimCycle value) { SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_stanceCycle", false, value); }
    GCFootCycle GetFootLiftCycle() const { return GetSchemaValue<GCFootCycle>(m_ptr, "CFootCycleDefinition", "m_footLiftCycle"); }
    void SetFootLiftCycle(GCFootCycle value) { SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_footLiftCycle", false, value); }
    GCFootCycle GetFootOffCycle() const { return GetSchemaValue<GCFootCycle>(m_ptr, "CFootCycleDefinition", "m_footOffCycle"); }
    void SetFootOffCycle(GCFootCycle value) { SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_footOffCycle", false, value); }
    GCFootCycle GetFootStrikeCycle() const { return GetSchemaValue<GCFootCycle>(m_ptr, "CFootCycleDefinition", "m_footStrikeCycle"); }
    void SetFootStrikeCycle(GCFootCycle value) { SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_footStrikeCycle", false, value); }
    GCFootCycle GetFootLandCycle() const { return GetSchemaValue<GCFootCycle>(m_ptr, "CFootCycleDefinition", "m_footLandCycle"); }
    void SetFootLandCycle(GCFootCycle value) { SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_footLandCycle", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif