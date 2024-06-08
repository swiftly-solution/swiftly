class GCStopAtGoalUpdateNode;

#ifndef _gccstopatgoalupdatenode_h
#define _gccstopatgoalupdatenode_h

#include "../../../scripting.h"


#include "GCAnimInputDamping.h"

class GCStopAtGoalUpdateNode
{
private:
    void *m_ptr;

public:
    GCStopAtGoalUpdateNode() {}
    GCStopAtGoalUpdateNode(void *ptr) : m_ptr(ptr) {}

    float GetOuterRadius() const { return GetSchemaValue<float>(m_ptr, "CStopAtGoalUpdateNode", "m_flOuterRadius"); }
    void SetOuterRadius(float value) { SetSchemaValue(m_ptr, "CStopAtGoalUpdateNode", "m_flOuterRadius", false, value); }
    float GetInnerRadius() const { return GetSchemaValue<float>(m_ptr, "CStopAtGoalUpdateNode", "m_flInnerRadius"); }
    void SetInnerRadius(float value) { SetSchemaValue(m_ptr, "CStopAtGoalUpdateNode", "m_flInnerRadius", false, value); }
    float GetMaxScale() const { return GetSchemaValue<float>(m_ptr, "CStopAtGoalUpdateNode", "m_flMaxScale"); }
    void SetMaxScale(float value) { SetSchemaValue(m_ptr, "CStopAtGoalUpdateNode", "m_flMaxScale", false, value); }
    float GetMinScale() const { return GetSchemaValue<float>(m_ptr, "CStopAtGoalUpdateNode", "m_flMinScale"); }
    void SetMinScale(float value) { SetSchemaValue(m_ptr, "CStopAtGoalUpdateNode", "m_flMinScale", false, value); }
    GCAnimInputDamping GetDamping() const { return GetSchemaValue<GCAnimInputDamping>(m_ptr, "CStopAtGoalUpdateNode", "m_damping"); }
    void SetDamping(GCAnimInputDamping value) { SetSchemaValue(m_ptr, "CStopAtGoalUpdateNode", "m_damping", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif