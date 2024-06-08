class GCPoseHandle;

#ifndef _gccposehandle_h
#define _gccposehandle_h

#include "../../../scripting.h"

#include "../types/GPoseType_t.h"


class GCPoseHandle
{
private:
    void *m_ptr;

public:
    GCPoseHandle() {}
    GCPoseHandle(void *ptr) : m_ptr(ptr) {}

    uint16_t GetIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "CPoseHandle", "m_nIndex"); }
    void SetIndex(uint16_t value) { SetSchemaValue(m_ptr, "CPoseHandle", "m_nIndex", false, value); }
    PoseType_t GetType() const { return GetSchemaValue<PoseType_t>(m_ptr, "CPoseHandle", "m_eType"); }
    void SetType(PoseType_t value) { SetSchemaValue(m_ptr, "CPoseHandle", "m_eType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif