class GEventPostDataUpdate_t;

#ifndef _gceventpostdataupdate_t_h
#define _gceventpostdataupdate_t_h

#include "../../../scripting.h"




class GEventPostDataUpdate_t
{
private:
    void *m_ptr;

public:
    GEventPostDataUpdate_t() {}
    GEventPostDataUpdate_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetCount() const { return GetSchemaValue<int32_t>(m_ptr, "EventPostDataUpdate_t", "m_nCount"); }
    void SetCount(int32_t value) { SetSchemaValue(m_ptr, "EventPostDataUpdate_t", "m_nCount", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif