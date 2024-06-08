class GAnimParamID;

#ifndef _gcanimparamid_h
#define _gcanimparamid_h

#include "../../../scripting.h"




class GAnimParamID
{
private:
    void *m_ptr;

public:
    GAnimParamID() {}
    GAnimParamID(void *ptr) : m_ptr(ptr) {}

    uint32_t GetId() const { return GetSchemaValue<uint32_t>(m_ptr, "AnimParamID", "m_id"); }
    void SetId(uint32_t value) { SetSchemaValue(m_ptr, "AnimParamID", "m_id", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif