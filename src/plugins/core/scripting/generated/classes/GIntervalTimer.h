class GIntervalTimer;

#ifndef _gcintervaltimer_h
#define _gcintervaltimer_h

#include "../../../scripting.h"




class GIntervalTimer
{
private:
    void *m_ptr;

public:
    GIntervalTimer() {}
    GIntervalTimer(void *ptr) : m_ptr(ptr) {}

    WorldGroupId_t GetWorldGroupId() const { return GetSchemaValue<WorldGroupId_t>(m_ptr, "IntervalTimer", "m_nWorldGroupId"); }
    void SetWorldGroupId(WorldGroupId_t value) { SetSchemaValue(m_ptr, "IntervalTimer", "m_nWorldGroupId", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif