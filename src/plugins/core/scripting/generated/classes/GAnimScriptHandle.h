class GAnimScriptHandle;

#ifndef _gcanimscripthandle_h
#define _gcanimscripthandle_h

#include "../../../scripting.h"




class GAnimScriptHandle
{
private:
    void *m_ptr;

public:
    GAnimScriptHandle() {}
    GAnimScriptHandle(void *ptr) : m_ptr(ptr) {}

    uint32_t GetId() const { return GetSchemaValue<uint32_t>(m_ptr, "AnimScriptHandle", "m_id"); }
    void SetId(uint32_t value) { SetSchemaValue(m_ptr, "AnimScriptHandle", "m_id", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif