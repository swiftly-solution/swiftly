class GNmSyncTrackTime_t;

#ifndef _gcnmsynctracktime_t_h
#define _gcnmsynctracktime_t_h

#include "../../../scripting.h"


#include "GNmPercent_t.h"

class GNmSyncTrackTime_t
{
private:
    void *m_ptr;

public:
    GNmSyncTrackTime_t() {}
    GNmSyncTrackTime_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetEventIdx() const { return GetSchemaValue<int32_t>(m_ptr, "NmSyncTrackTime_t", "m_nEventIdx"); }
    void SetEventIdx(int32_t value) { SetSchemaValue(m_ptr, "NmSyncTrackTime_t", "m_nEventIdx", true, value); }
    GNmPercent_t GetPercentageThrough() const { return GetSchemaValue<GNmPercent_t>(m_ptr, "NmSyncTrackTime_t", "m_percentageThrough"); }
    void SetPercentageThrough(GNmPercent_t value) { SetSchemaValue(m_ptr, "NmSyncTrackTime_t", "m_percentageThrough", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif