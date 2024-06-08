class GCAnimUserDifference;

#ifndef _gccanimuserdifference_h
#define _gccanimuserdifference_h

#include "../../../scripting.h"




class GCAnimUserDifference
{
private:
    void *m_ptr;

public:
    GCAnimUserDifference() {}
    GCAnimUserDifference(void *ptr) : m_ptr(ptr) {}

    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimUserDifference", "m_name"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CAnimUserDifference", "m_name", false, value); }
    int32_t GetType() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimUserDifference", "m_nType"); }
    void SetType(int32_t value) { SetSchemaValue(m_ptr, "CAnimUserDifference", "m_nType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif