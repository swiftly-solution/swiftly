class GCBtActionParachutePositioning;

#ifndef _gccbtactionparachutepositioning_h
#define _gccbtactionparachutepositioning_h

#include "../../../scripting.h"


#include "GCountdownTimer.h"

class GCBtActionParachutePositioning
{
private:
    void *m_ptr;

public:
    GCBtActionParachutePositioning() {}
    GCBtActionParachutePositioning(void *ptr) : m_ptr(ptr) {}

    GCountdownTimer GetActionTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CBtActionParachutePositioning", "m_ActionTimer"); }
    void SetActionTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CBtActionParachutePositioning", "m_ActionTimer", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif