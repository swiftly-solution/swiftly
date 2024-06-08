class GCLogicAutosave;

#ifndef _gcclogicautosave_h
#define _gcclogicautosave_h

#include "../../../scripting.h"




class GCLogicAutosave
{
private:
    void *m_ptr;

public:
    GCLogicAutosave() {}
    GCLogicAutosave(void *ptr) : m_ptr(ptr) {}

    bool GetForceNewLevelUnit() const { return GetSchemaValue<bool>(m_ptr, "CLogicAutosave", "m_bForceNewLevelUnit"); }
    void SetForceNewLevelUnit(bool value) { SetSchemaValue(m_ptr, "CLogicAutosave", "m_bForceNewLevelUnit", false, value); }
    int32_t GetMinHitPoints() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicAutosave", "m_minHitPoints"); }
    void SetMinHitPoints(int32_t value) { SetSchemaValue(m_ptr, "CLogicAutosave", "m_minHitPoints", false, value); }
    int32_t GetMinHitPointsToCommit() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicAutosave", "m_minHitPointsToCommit"); }
    void SetMinHitPointsToCommit(int32_t value) { SetSchemaValue(m_ptr, "CLogicAutosave", "m_minHitPointsToCommit", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif