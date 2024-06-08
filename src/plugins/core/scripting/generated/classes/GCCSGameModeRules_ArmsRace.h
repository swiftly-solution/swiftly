class GCCSGameModeRules_ArmsRace;

#ifndef _gcccsgamemoderules_armsrace_h
#define _gcccsgamemoderules_armsrace_h

#include "../../../scripting.h"




class GCCSGameModeRules_ArmsRace
{
private:
    void *m_ptr;

public:
    GCCSGameModeRules_ArmsRace() {}
    GCCSGameModeRules_ArmsRace(void *ptr) : m_ptr(ptr) {}

    std::vector<CUtlString> GetWeaponSequence() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CCSGameModeRules_ArmsRace", "m_WeaponSequence"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetWeaponSequence(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CCSGameModeRules_ArmsRace", "m_WeaponSequence", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif