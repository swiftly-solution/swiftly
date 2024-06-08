class GCLogicDistanceAutosave;

#ifndef _gcclogicdistanceautosave_h
#define _gcclogicdistanceautosave_h

#include "../../../scripting.h"




class GCLogicDistanceAutosave
{
private:
    void *m_ptr;

public:
    GCLogicDistanceAutosave() {}
    GCLogicDistanceAutosave(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetTargetEntity() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicDistanceAutosave", "m_iszTargetEntity"); }
    void SetTargetEntity(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicDistanceAutosave", "m_iszTargetEntity", false, value); }
    float GetDistanceToPlayer() const { return GetSchemaValue<float>(m_ptr, "CLogicDistanceAutosave", "m_flDistanceToPlayer"); }
    void SetDistanceToPlayer(float value) { SetSchemaValue(m_ptr, "CLogicDistanceAutosave", "m_flDistanceToPlayer", false, value); }
    bool GetForceNewLevelUnit() const { return GetSchemaValue<bool>(m_ptr, "CLogicDistanceAutosave", "m_bForceNewLevelUnit"); }
    void SetForceNewLevelUnit(bool value) { SetSchemaValue(m_ptr, "CLogicDistanceAutosave", "m_bForceNewLevelUnit", false, value); }
    bool GetCheckCough() const { return GetSchemaValue<bool>(m_ptr, "CLogicDistanceAutosave", "m_bCheckCough"); }
    void SetCheckCough(bool value) { SetSchemaValue(m_ptr, "CLogicDistanceAutosave", "m_bCheckCough", false, value); }
    bool GetThinkDangerous() const { return GetSchemaValue<bool>(m_ptr, "CLogicDistanceAutosave", "m_bThinkDangerous"); }
    void SetThinkDangerous(bool value) { SetSchemaValue(m_ptr, "CLogicDistanceAutosave", "m_bThinkDangerous", false, value); }
    float GetDangerousTime() const { return GetSchemaValue<float>(m_ptr, "CLogicDistanceAutosave", "m_flDangerousTime"); }
    void SetDangerousTime(float value) { SetSchemaValue(m_ptr, "CLogicDistanceAutosave", "m_flDangerousTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif