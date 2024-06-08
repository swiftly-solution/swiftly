class GCAnimParamHandle;

#ifndef _gccanimparamhandle_h
#define _gccanimparamhandle_h

#include "../../../scripting.h"

#include "../types/GAnimParamType_t.h"


class GCAnimParamHandle
{
private:
    void *m_ptr;

public:
    GCAnimParamHandle() {}
    GCAnimParamHandle(void *ptr) : m_ptr(ptr) {}

    AnimParamType_t GetType() const { return GetSchemaValue<AnimParamType_t>(m_ptr, "CAnimParamHandle", "m_type"); }
    void SetType(AnimParamType_t value) { SetSchemaValue(m_ptr, "CAnimParamHandle", "m_type", false, value); }
    uint8_t GetIndex() const { return GetSchemaValue<uint8_t>(m_ptr, "CAnimParamHandle", "m_index"); }
    void SetIndex(uint8_t value) { SetSchemaValue(m_ptr, "CAnimParamHandle", "m_index", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif