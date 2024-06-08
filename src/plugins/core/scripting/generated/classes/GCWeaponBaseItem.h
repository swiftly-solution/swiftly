class GCWeaponBaseItem;

#ifndef _gccweaponbaseitem_h
#define _gccweaponbaseitem_h

#include "../../../scripting.h"


#include "GCountdownTimer.h"

class GCWeaponBaseItem
{
private:
    void *m_ptr;

public:
    GCWeaponBaseItem() {}
    GCWeaponBaseItem(void *ptr) : m_ptr(ptr) {}

    GCountdownTimer GetSequenceCompleteTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CWeaponBaseItem", "m_SequenceCompleteTimer"); }
    void SetSequenceCompleteTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CWeaponBaseItem", "m_SequenceCompleteTimer", false, value); }
    bool GetRedraw() const { return GetSchemaValue<bool>(m_ptr, "CWeaponBaseItem", "m_bRedraw"); }
    void SetRedraw(bool value) { SetSchemaValue(m_ptr, "CWeaponBaseItem", "m_bRedraw", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif