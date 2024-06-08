class GCEmitTagActionUpdater;

#ifndef _gccemittagactionupdater_h
#define _gccemittagactionupdater_h

#include "../../../scripting.h"




class GCEmitTagActionUpdater
{
private:
    void *m_ptr;

public:
    GCEmitTagActionUpdater() {}
    GCEmitTagActionUpdater(void *ptr) : m_ptr(ptr) {}

    int32_t GetTagIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CEmitTagActionUpdater", "m_nTagIndex"); }
    void SetTagIndex(int32_t value) { SetSchemaValue(m_ptr, "CEmitTagActionUpdater", "m_nTagIndex", false, value); }
    bool GetIsZeroDuration() const { return GetSchemaValue<bool>(m_ptr, "CEmitTagActionUpdater", "m_bIsZeroDuration"); }
    void SetIsZeroDuration(bool value) { SetSchemaValue(m_ptr, "CEmitTagActionUpdater", "m_bIsZeroDuration", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif