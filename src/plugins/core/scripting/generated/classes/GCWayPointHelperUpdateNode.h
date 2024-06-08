class GCWayPointHelperUpdateNode;

#ifndef _gccwaypointhelperupdatenode_h
#define _gccwaypointhelperupdatenode_h

#include "../../../scripting.h"




class GCWayPointHelperUpdateNode
{
private:
    void *m_ptr;

public:
    GCWayPointHelperUpdateNode() {}
    GCWayPointHelperUpdateNode(void *ptr) : m_ptr(ptr) {}

    float GetStartCycle() const { return GetSchemaValue<float>(m_ptr, "CWayPointHelperUpdateNode", "m_flStartCycle"); }
    void SetStartCycle(float value) { SetSchemaValue(m_ptr, "CWayPointHelperUpdateNode", "m_flStartCycle", false, value); }
    float GetEndCycle() const { return GetSchemaValue<float>(m_ptr, "CWayPointHelperUpdateNode", "m_flEndCycle"); }
    void SetEndCycle(float value) { SetSchemaValue(m_ptr, "CWayPointHelperUpdateNode", "m_flEndCycle", false, value); }
    bool GetOnlyGoals() const { return GetSchemaValue<bool>(m_ptr, "CWayPointHelperUpdateNode", "m_bOnlyGoals"); }
    void SetOnlyGoals(bool value) { SetSchemaValue(m_ptr, "CWayPointHelperUpdateNode", "m_bOnlyGoals", false, value); }
    bool GetPreventOvershoot() const { return GetSchemaValue<bool>(m_ptr, "CWayPointHelperUpdateNode", "m_bPreventOvershoot"); }
    void SetPreventOvershoot(bool value) { SetSchemaValue(m_ptr, "CWayPointHelperUpdateNode", "m_bPreventOvershoot", false, value); }
    bool GetPreventUndershoot() const { return GetSchemaValue<bool>(m_ptr, "CWayPointHelperUpdateNode", "m_bPreventUndershoot"); }
    void SetPreventUndershoot(bool value) { SetSchemaValue(m_ptr, "CWayPointHelperUpdateNode", "m_bPreventUndershoot", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif