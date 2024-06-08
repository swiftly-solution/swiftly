class GNmSyncTrackTimeRange_t;

#ifndef _gcnmsynctracktimerange_t_h
#define _gcnmsynctracktimerange_t_h

#include "../../../scripting.h"


#include "GNmSyncTrackTime_t.h"

class GNmSyncTrackTimeRange_t
{
private:
    void *m_ptr;

public:
    GNmSyncTrackTimeRange_t() {}
    GNmSyncTrackTimeRange_t(void *ptr) : m_ptr(ptr) {}

    GNmSyncTrackTime_t GetStartTime() const { return GetSchemaValue<GNmSyncTrackTime_t>(m_ptr, "NmSyncTrackTimeRange_t", "m_startTime"); }
    void SetStartTime(GNmSyncTrackTime_t value) { SetSchemaValue(m_ptr, "NmSyncTrackTimeRange_t", "m_startTime", true, value); }
    GNmSyncTrackTime_t GetEndTime() const { return GetSchemaValue<GNmSyncTrackTime_t>(m_ptr, "NmSyncTrackTimeRange_t", "m_endTime"); }
    void SetEndTime(GNmSyncTrackTime_t value) { SetSchemaValue(m_ptr, "NmSyncTrackTimeRange_t", "m_endTime", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif