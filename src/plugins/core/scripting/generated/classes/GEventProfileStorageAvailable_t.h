class GEventProfileStorageAvailable_t;

#ifndef _gceventprofilestorageavailable_t_h
#define _gceventprofilestorageavailable_t_h

#include "../../../scripting.h"




class GEventProfileStorageAvailable_t
{
private:
    void *m_ptr;

public:
    GEventProfileStorageAvailable_t() {}
    GEventProfileStorageAvailable_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetSplitScreenSlot() const { return GetSchemaValue<int32_t>(m_ptr, "EventProfileStorageAvailable_t", "m_nSplitScreenSlot"); }
    void SetSplitScreenSlot(int32_t value) { SetSchemaValue(m_ptr, "EventProfileStorageAvailable_t", "m_nSplitScreenSlot", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif