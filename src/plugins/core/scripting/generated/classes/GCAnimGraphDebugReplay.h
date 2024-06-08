class GCAnimGraphDebugReplay;

#ifndef _gccanimgraphdebugreplay_h
#define _gccanimgraphdebugreplay_h

#include "../../../scripting.h"




class GCAnimGraphDebugReplay
{
private:
    void *m_ptr;

public:
    GCAnimGraphDebugReplay() {}
    GCAnimGraphDebugReplay(void *ptr) : m_ptr(ptr) {}

    CUtlString GetAnimGraphFileName() const { return GetSchemaValue<CUtlString>(m_ptr, "CAnimGraphDebugReplay", "m_animGraphFileName"); }
    void SetAnimGraphFileName(CUtlString value) { SetSchemaValue(m_ptr, "CAnimGraphDebugReplay", "m_animGraphFileName", false, value); }
    int32_t GetStartIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimGraphDebugReplay", "m_startIndex"); }
    void SetStartIndex(int32_t value) { SetSchemaValue(m_ptr, "CAnimGraphDebugReplay", "m_startIndex", false, value); }
    int32_t GetWriteIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimGraphDebugReplay", "m_writeIndex"); }
    void SetWriteIndex(int32_t value) { SetSchemaValue(m_ptr, "CAnimGraphDebugReplay", "m_writeIndex", false, value); }
    int32_t GetFrameCount() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimGraphDebugReplay", "m_frameCount"); }
    void SetFrameCount(int32_t value) { SetSchemaValue(m_ptr, "CAnimGraphDebugReplay", "m_frameCount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif