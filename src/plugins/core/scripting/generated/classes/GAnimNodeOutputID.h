class GAnimNodeOutputID;

#ifndef _gcanimnodeoutputid_h
#define _gcanimnodeoutputid_h

#include "../../../scripting.h"




class GAnimNodeOutputID
{
private:
    void *m_ptr;

public:
    GAnimNodeOutputID() {}
    GAnimNodeOutputID(void *ptr) : m_ptr(ptr) {}

    uint32_t GetId() const { return GetSchemaValue<uint32_t>(m_ptr, "AnimNodeOutputID", "m_id"); }
    void SetId(uint32_t value) { SetSchemaValue(m_ptr, "AnimNodeOutputID", "m_id", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif