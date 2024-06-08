class GCNmSyncTrack__EventMarker_t;

#ifndef _gccnmsynctrack__eventmarker_t_h
#define _gccnmsynctrack__eventmarker_t_h

#include "../../../scripting.h"


#include "GNmPercent_t.h"

class GCNmSyncTrack__EventMarker_t
{
private:
    void *m_ptr;

public:
    GCNmSyncTrack__EventMarker_t() {}
    GCNmSyncTrack__EventMarker_t(void *ptr) : m_ptr(ptr) {}

    GNmPercent_t GetStartTime() const { return GetSchemaValue<GNmPercent_t>(m_ptr, "CNmSyncTrack__EventMarker_t", "m_startTime"); }
    void SetStartTime(GNmPercent_t value) { SetSchemaValue(m_ptr, "CNmSyncTrack__EventMarker_t", "m_startTime", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif