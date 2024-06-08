class GEventPreDataUpdate_t;

#ifndef _gceventpredataupdate_t_h
#define _gceventpredataupdate_t_h

#include "../../../scripting.h"




class GEventPreDataUpdate_t
{
private:
    void *m_ptr;

public:
    GEventPreDataUpdate_t() {}
    GEventPreDataUpdate_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetCount() const { return GetSchemaValue<int32_t>(m_ptr, "EventPreDataUpdate_t", "m_nCount"); }
    void SetCount(int32_t value) { SetSchemaValue(m_ptr, "EventPreDataUpdate_t", "m_nCount", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif