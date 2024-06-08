class GCAnimReplayFrame;

#ifndef _gccanimreplayframe_h
#define _gccanimreplayframe_h

#include "../../../scripting.h"




class GCAnimReplayFrame
{
private:
    void *m_ptr;

public:
    GCAnimReplayFrame() {}
    GCAnimReplayFrame(void *ptr) : m_ptr(ptr) {}

    float GetTimeStamp() const { return GetSchemaValue<float>(m_ptr, "CAnimReplayFrame", "m_timeStamp"); }
    void SetTimeStamp(float value) { SetSchemaValue(m_ptr, "CAnimReplayFrame", "m_timeStamp", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif