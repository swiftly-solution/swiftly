class GCLogicActiveAutosave;

#ifndef _gcclogicactiveautosave_h
#define _gcclogicactiveautosave_h

#include "../../../scripting.h"




class GCLogicActiveAutosave
{
private:
    void *m_ptr;

public:
    GCLogicActiveAutosave() {}
    GCLogicActiveAutosave(void *ptr) : m_ptr(ptr) {}

    int32_t GetTriggerHitPoints() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicActiveAutosave", "m_TriggerHitPoints"); }
    void SetTriggerHitPoints(int32_t value) { SetSchemaValue(m_ptr, "CLogicActiveAutosave", "m_TriggerHitPoints", false, value); }
    float GetTimeToTrigger() const { return GetSchemaValue<float>(m_ptr, "CLogicActiveAutosave", "m_flTimeToTrigger"); }
    void SetTimeToTrigger(float value) { SetSchemaValue(m_ptr, "CLogicActiveAutosave", "m_flTimeToTrigger", false, value); }
    float GetDangerousTime() const { return GetSchemaValue<float>(m_ptr, "CLogicActiveAutosave", "m_flDangerousTime"); }
    void SetDangerousTime(float value) { SetSchemaValue(m_ptr, "CLogicActiveAutosave", "m_flDangerousTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif