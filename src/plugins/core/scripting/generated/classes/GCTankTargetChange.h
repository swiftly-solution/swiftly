class GCTankTargetChange;

#ifndef _gcctanktargetchange_h
#define _gcctanktargetchange_h

#include "../../../scripting.h"




class GCTankTargetChange
{
private:
    void *m_ptr;

public:
    GCTankTargetChange() {}
    GCTankTargetChange(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetNewTargetName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTankTargetChange", "m_newTargetName"); }
    void SetNewTargetName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTankTargetChange", "m_newTargetName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif