class GCNmSyncTrack;

#ifndef _gccnmsynctrack_h
#define _gccnmsynctrack_h

#include "../../../scripting.h"




class GCNmSyncTrack
{
private:
    void *m_ptr;

public:
    GCNmSyncTrack() {}
    GCNmSyncTrack(void *ptr) : m_ptr(ptr) {}

    int32_t GetStartEventOffset() const { return GetSchemaValue<int32_t>(m_ptr, "CNmSyncTrack", "m_nStartEventOffset"); }
    void SetStartEventOffset(int32_t value) { SetSchemaValue(m_ptr, "CNmSyncTrack", "m_nStartEventOffset", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif