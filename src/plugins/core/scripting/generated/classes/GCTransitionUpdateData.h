class GCTransitionUpdateData;

#ifndef _gcctransitionupdatedata_h
#define _gcctransitionupdatedata_h

#include "../../../scripting.h"




class GCTransitionUpdateData
{
private:
    void *m_ptr;

public:
    GCTransitionUpdateData() {}
    GCTransitionUpdateData(void *ptr) : m_ptr(ptr) {}

    uint8_t GetSrcStateIndex() const { return GetSchemaValue<uint8_t>(m_ptr, "CTransitionUpdateData", "m_srcStateIndex"); }
    void SetSrcStateIndex(uint8_t value) { SetSchemaValue(m_ptr, "CTransitionUpdateData", "m_srcStateIndex", false, value); }
    uint8_t GetDestStateIndex() const { return GetSchemaValue<uint8_t>(m_ptr, "CTransitionUpdateData", "m_destStateIndex"); }
    void SetDestStateIndex(uint8_t value) { SetSchemaValue(m_ptr, "CTransitionUpdateData", "m_destStateIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif