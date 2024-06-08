class GCTriggerActiveWeaponDetect;

#ifndef _gcctriggeractiveweapondetect_h
#define _gcctriggeractiveweapondetect_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCTriggerActiveWeaponDetect
{
private:
    void *m_ptr;

public:
    GCTriggerActiveWeaponDetect() {}
    GCTriggerActiveWeaponDetect(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnTouchedActiveWeapon() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTriggerActiveWeaponDetect", "m_OnTouchedActiveWeapon"); }
    void SetOnTouchedActiveWeapon(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTriggerActiveWeaponDetect", "m_OnTouchedActiveWeapon", false, value); }
    CUtlSymbolLarge GetWeaponClassName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerActiveWeaponDetect", "m_iszWeaponClassName"); }
    void SetWeaponClassName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTriggerActiveWeaponDetect", "m_iszWeaponClassName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif