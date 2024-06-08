class GCNmSyncTrack__Event_t;

#ifndef _gccnmsynctrack__event_t_h
#define _gccnmsynctrack__event_t_h

#include "../../../scripting.h"


#include "GNmPercent_t.h"

class GCNmSyncTrack__Event_t
{
private:
    void *m_ptr;

public:
    GCNmSyncTrack__Event_t() {}
    GCNmSyncTrack__Event_t(void *ptr) : m_ptr(ptr) {}

    GNmPercent_t GetStartTime() const { return GetSchemaValue<GNmPercent_t>(m_ptr, "CNmSyncTrack__Event_t", "m_startTime"); }
    void SetStartTime(GNmPercent_t value) { SetSchemaValue(m_ptr, "CNmSyncTrack__Event_t", "m_startTime", true, value); }
    GNmPercent_t GetDuration() const { return GetSchemaValue<GNmPercent_t>(m_ptr, "CNmSyncTrack__Event_t", "m_duration"); }
    void SetDuration(GNmPercent_t value) { SetSchemaValue(m_ptr, "CNmSyncTrack__Event_t", "m_duration", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif