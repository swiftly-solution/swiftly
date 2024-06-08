class GCFootTrajectory;

#ifndef _gccfoottrajectory_h
#define _gccfoottrajectory_h

#include "../../../scripting.h"




class GCFootTrajectory
{
private:
    void *m_ptr;

public:
    GCFootTrajectory() {}
    GCFootTrajectory(void *ptr) : m_ptr(ptr) {}

    Vector GetOffset() const { return GetSchemaValue<Vector>(m_ptr, "CFootTrajectory", "m_vOffset"); }
    void SetOffset(Vector value) { SetSchemaValue(m_ptr, "CFootTrajectory", "m_vOffset", false, value); }
    float GetRotationOffset() const { return GetSchemaValue<float>(m_ptr, "CFootTrajectory", "m_flRotationOffset"); }
    void SetRotationOffset(float value) { SetSchemaValue(m_ptr, "CFootTrajectory", "m_flRotationOffset", false, value); }
    float GetProgression() const { return GetSchemaValue<float>(m_ptr, "CFootTrajectory", "m_flProgression"); }
    void SetProgression(float value) { SetSchemaValue(m_ptr, "CFootTrajectory", "m_flProgression", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif