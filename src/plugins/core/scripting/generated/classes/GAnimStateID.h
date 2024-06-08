class GAnimStateID;

#ifndef _gcanimstateid_h
#define _gcanimstateid_h

#include "../../../scripting.h"




class GAnimStateID
{
private:
    void *m_ptr;

public:
    GAnimStateID() {}
    GAnimStateID(void *ptr) : m_ptr(ptr) {}

    uint32_t GetId() const { return GetSchemaValue<uint32_t>(m_ptr, "AnimStateID", "m_id"); }
    void SetId(uint32_t value) { SetSchemaValue(m_ptr, "AnimStateID", "m_id", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif