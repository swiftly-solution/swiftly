class GCPropDoorRotatingBreakable;

#ifndef _gccpropdoorrotatingbreakable_h
#define _gccpropdoorrotatingbreakable_h

#include "../../../scripting.h"




class GCPropDoorRotatingBreakable
{
private:
    void *m_ptr;

public:
    GCPropDoorRotatingBreakable() {}
    GCPropDoorRotatingBreakable(void *ptr) : m_ptr(ptr) {}

    bool GetBreakable() const { return GetSchemaValue<bool>(m_ptr, "CPropDoorRotatingBreakable", "m_bBreakable"); }
    void SetBreakable(bool value) { SetSchemaValue(m_ptr, "CPropDoorRotatingBreakable", "m_bBreakable", false, value); }
    bool GetIsAbleToCloseAreaPortals() const { return GetSchemaValue<bool>(m_ptr, "CPropDoorRotatingBreakable", "m_isAbleToCloseAreaPortals"); }
    void SetIsAbleToCloseAreaPortals(bool value) { SetSchemaValue(m_ptr, "CPropDoorRotatingBreakable", "m_isAbleToCloseAreaPortals", false, value); }
    int32_t GetCurrentDamageState() const { return GetSchemaValue<int32_t>(m_ptr, "CPropDoorRotatingBreakable", "m_currentDamageState"); }
    void SetCurrentDamageState(int32_t value) { SetSchemaValue(m_ptr, "CPropDoorRotatingBreakable", "m_currentDamageState", false, value); }
    std::vector<CUtlSymbolLarge> GetDamageStates() const { CUtlVector<CUtlSymbolLarge>* vec = GetSchemaValue<CUtlVector<CUtlSymbolLarge>*>(m_ptr, "CPropDoorRotatingBreakable", "m_damageStates"); std::vector<CUtlSymbolLarge> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetDamageStates(std::vector<CUtlSymbolLarge> value) { SetSchemaValueCUtlVector<CUtlSymbolLarge>(m_ptr, "CPropDoorRotatingBreakable", "m_damageStates", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif