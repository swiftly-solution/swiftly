class GAnimTagID;

#ifndef _gcanimtagid_h
#define _gcanimtagid_h

#include "../../../scripting.h"




class GAnimTagID
{
private:
    void *m_ptr;

public:
    GAnimTagID() {}
    GAnimTagID(void *ptr) : m_ptr(ptr) {}

    uint32_t GetId() const { return GetSchemaValue<uint32_t>(m_ptr, "AnimTagID", "m_id"); }
    void SetId(uint32_t value) { SetSchemaValue(m_ptr, "AnimTagID", "m_id", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif