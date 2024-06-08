class GCSimpleSimTimer;

#ifndef _gccsimplesimtimer_h
#define _gccsimplesimtimer_h

#include "../../../scripting.h"




class GCSimpleSimTimer
{
private:
    void *m_ptr;

public:
    GCSimpleSimTimer() {}
    GCSimpleSimTimer(void *ptr) : m_ptr(ptr) {}

    WorldGroupId_t GetWorldGroupId() const { return GetSchemaValue<WorldGroupId_t>(m_ptr, "CSimpleSimTimer", "m_nWorldGroupId"); }
    void SetWorldGroupId(WorldGroupId_t value) { SetSchemaValue(m_ptr, "CSimpleSimTimer", "m_nWorldGroupId", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif