class GCLogicAchievement;

#ifndef _gcclogicachievement_h
#define _gcclogicachievement_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCLogicAchievement
{
private:
    void *m_ptr;

public:
    GCLogicAchievement() {}
    GCLogicAchievement(void *ptr) : m_ptr(ptr) {}

    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CLogicAchievement", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CLogicAchievement", "m_bDisabled", false, value); }
    CUtlSymbolLarge GetAchievementEventID() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicAchievement", "m_iszAchievementEventID"); }
    void SetAchievementEventID(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicAchievement", "m_iszAchievementEventID", false, value); }
    GCEntityIOOutput GetOnFired() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicAchievement", "m_OnFired"); }
    void SetOnFired(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicAchievement", "m_OnFired", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif