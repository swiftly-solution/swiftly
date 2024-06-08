class GCTurnHelperUpdateNode;

#ifndef _gccturnhelperupdatenode_h
#define _gccturnhelperupdatenode_h

#include "../../../scripting.h"

#include "../types/GAnimValueSource.h"


class GCTurnHelperUpdateNode
{
private:
    void *m_ptr;

public:
    GCTurnHelperUpdateNode() {}
    GCTurnHelperUpdateNode(void *ptr) : m_ptr(ptr) {}

    AnimValueSource GetFacingTarget() const { return GetSchemaValue<AnimValueSource>(m_ptr, "CTurnHelperUpdateNode", "m_facingTarget"); }
    void SetFacingTarget(AnimValueSource value) { SetSchemaValue(m_ptr, "CTurnHelperUpdateNode", "m_facingTarget", false, value); }
    float GetTurnStartTimeOffset() const { return GetSchemaValue<float>(m_ptr, "CTurnHelperUpdateNode", "m_turnStartTimeOffset"); }
    void SetTurnStartTimeOffset(float value) { SetSchemaValue(m_ptr, "CTurnHelperUpdateNode", "m_turnStartTimeOffset", false, value); }
    float GetTurnDuration() const { return GetSchemaValue<float>(m_ptr, "CTurnHelperUpdateNode", "m_turnDuration"); }
    void SetTurnDuration(float value) { SetSchemaValue(m_ptr, "CTurnHelperUpdateNode", "m_turnDuration", false, value); }
    bool GetMatchChildDuration() const { return GetSchemaValue<bool>(m_ptr, "CTurnHelperUpdateNode", "m_bMatchChildDuration"); }
    void SetMatchChildDuration(bool value) { SetSchemaValue(m_ptr, "CTurnHelperUpdateNode", "m_bMatchChildDuration", false, value); }
    float GetManualTurnOffset() const { return GetSchemaValue<float>(m_ptr, "CTurnHelperUpdateNode", "m_manualTurnOffset"); }
    void SetManualTurnOffset(float value) { SetSchemaValue(m_ptr, "CTurnHelperUpdateNode", "m_manualTurnOffset", false, value); }
    bool GetUseManualTurnOffset() const { return GetSchemaValue<bool>(m_ptr, "CTurnHelperUpdateNode", "m_bUseManualTurnOffset"); }
    void SetUseManualTurnOffset(bool value) { SetSchemaValue(m_ptr, "CTurnHelperUpdateNode", "m_bUseManualTurnOffset", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif