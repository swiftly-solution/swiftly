class GCCSGameModeRules_Deathmatch;

#ifndef _gcccsgamemoderules_deathmatch_h
#define _gcccsgamemoderules_deathmatch_h

#include "../../../scripting.h"




class GCCSGameModeRules_Deathmatch
{
private:
    void *m_ptr;

public:
    GCCSGameModeRules_Deathmatch() {}
    GCCSGameModeRules_Deathmatch(void *ptr) : m_ptr(ptr) {}

    float GetDMBonusTimeLength() const { return GetSchemaValue<float>(m_ptr, "CCSGameModeRules_Deathmatch", "m_flDMBonusTimeLength"); }
    void SetDMBonusTimeLength(float value) { SetSchemaValue(m_ptr, "CCSGameModeRules_Deathmatch", "m_flDMBonusTimeLength", false, value); }
    CUtlString GetDMBonusWeapon() const { return GetSchemaValue<CUtlString>(m_ptr, "CCSGameModeRules_Deathmatch", "m_sDMBonusWeapon"); }
    void SetDMBonusWeapon(CUtlString value) { SetSchemaValue(m_ptr, "CCSGameModeRules_Deathmatch", "m_sDMBonusWeapon", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif