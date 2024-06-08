class GCDebugHistory;

#ifndef _gccdebughistory_h
#define _gccdebughistory_h

#include "../../../scripting.h"




class GCDebugHistory
{
private:
    void *m_ptr;

public:
    GCDebugHistory() {}
    GCDebugHistory(void *ptr) : m_ptr(ptr) {}

    int32_t GetNpcEvents() const { return GetSchemaValue<int32_t>(m_ptr, "CDebugHistory", "m_nNpcEvents"); }
    void SetNpcEvents(int32_t value) { SetSchemaValue(m_ptr, "CDebugHistory", "m_nNpcEvents", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif