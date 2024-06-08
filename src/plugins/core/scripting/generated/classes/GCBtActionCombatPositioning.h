class GCBtActionCombatPositioning;

#ifndef _gccbtactioncombatpositioning_h
#define _gccbtactioncombatpositioning_h

#include "../../../scripting.h"


#include "GCountdownTimer.h"

class GCBtActionCombatPositioning
{
private:
    void *m_ptr;

public:
    GCBtActionCombatPositioning() {}
    GCBtActionCombatPositioning(void *ptr) : m_ptr(ptr) {}

    CUtlString GetSensorInputKey() const { return GetSchemaValue<CUtlString>(m_ptr, "CBtActionCombatPositioning", "m_szSensorInputKey"); }
    void SetSensorInputKey(CUtlString value) { SetSchemaValue(m_ptr, "CBtActionCombatPositioning", "m_szSensorInputKey", false, value); }
    CUtlString GetIsAttackingKey() const { return GetSchemaValue<CUtlString>(m_ptr, "CBtActionCombatPositioning", "m_szIsAttackingKey"); }
    void SetIsAttackingKey(CUtlString value) { SetSchemaValue(m_ptr, "CBtActionCombatPositioning", "m_szIsAttackingKey", false, value); }
    GCountdownTimer GetActionTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CBtActionCombatPositioning", "m_ActionTimer"); }
    void SetActionTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CBtActionCombatPositioning", "m_ActionTimer", false, value); }
    bool GetCrouching() const { return GetSchemaValue<bool>(m_ptr, "CBtActionCombatPositioning", "m_bCrouching"); }
    void SetCrouching(bool value) { SetSchemaValue(m_ptr, "CBtActionCombatPositioning", "m_bCrouching", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif