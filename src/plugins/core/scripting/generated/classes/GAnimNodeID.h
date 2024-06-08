class GAnimNodeID;

#ifndef _gcanimnodeid_h
#define _gcanimnodeid_h

#include "../../../scripting.h"




class GAnimNodeID
{
private:
    void *m_ptr;

public:
    GAnimNodeID() {}
    GAnimNodeID(void *ptr) : m_ptr(ptr) {}

    uint32_t GetId() const { return GetSchemaValue<uint32_t>(m_ptr, "AnimNodeID", "m_id"); }
    void SetId(uint32_t value) { SetSchemaValue(m_ptr, "AnimNodeID", "m_id", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif