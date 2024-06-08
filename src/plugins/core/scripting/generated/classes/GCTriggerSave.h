class GCTriggerSave;

#ifndef _gcctriggersave_h
#define _gcctriggersave_h

#include "../../../scripting.h"




class GCTriggerSave
{
private:
    void *m_ptr;

public:
    GCTriggerSave() {}
    GCTriggerSave(void *ptr) : m_ptr(ptr) {}

    bool GetForceNewLevelUnit() const { return GetSchemaValue<bool>(m_ptr, "CTriggerSave", "m_bForceNewLevelUnit"); }
    void SetForceNewLevelUnit(bool value) { SetSchemaValue(m_ptr, "CTriggerSave", "m_bForceNewLevelUnit", false, value); }
    float GetDangerousTimer() const { return GetSchemaValue<float>(m_ptr, "CTriggerSave", "m_fDangerousTimer"); }
    void SetDangerousTimer(float value) { SetSchemaValue(m_ptr, "CTriggerSave", "m_fDangerousTimer", false, value); }
    int32_t GetMinHitPoints() const { return GetSchemaValue<int32_t>(m_ptr, "CTriggerSave", "m_minHitPoints"); }
    void SetMinHitPoints(int32_t value) { SetSchemaValue(m_ptr, "CTriggerSave", "m_minHitPoints", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif