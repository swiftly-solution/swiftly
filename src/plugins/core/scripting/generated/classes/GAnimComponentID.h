class GAnimComponentID;

#ifndef _gcanimcomponentid_h
#define _gcanimcomponentid_h

#include "../../../scripting.h"




class GAnimComponentID
{
private:
    void *m_ptr;

public:
    GAnimComponentID() {}
    GAnimComponentID(void *ptr) : m_ptr(ptr) {}

    uint32_t GetId() const { return GetSchemaValue<uint32_t>(m_ptr, "AnimComponentID", "m_id"); }
    void SetId(uint32_t value) { SetSchemaValue(m_ptr, "AnimComponentID", "m_id", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif