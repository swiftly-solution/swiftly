class GCStopwatchBase;

#ifndef _gccstopwatchbase_h
#define _gccstopwatchbase_h

#include "../../../scripting.h"




class GCStopwatchBase
{
private:
    void *m_ptr;

public:
    GCStopwatchBase() {}
    GCStopwatchBase(void *ptr) : m_ptr(ptr) {}

    bool GetIsRunning() const { return GetSchemaValue<bool>(m_ptr, "CStopwatchBase", "m_fIsRunning"); }
    void SetIsRunning(bool value) { SetSchemaValue(m_ptr, "CStopwatchBase", "m_fIsRunning", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif