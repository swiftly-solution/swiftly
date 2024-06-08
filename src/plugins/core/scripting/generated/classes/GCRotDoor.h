class GCRotDoor;

#ifndef _gccrotdoor_h
#define _gccrotdoor_h

#include "../../../scripting.h"




class GCRotDoor
{
private:
    void *m_ptr;

public:
    GCRotDoor() {}
    GCRotDoor(void *ptr) : m_ptr(ptr) {}

    bool GetSolidBsp() const { return GetSchemaValue<bool>(m_ptr, "CRotDoor", "m_bSolidBsp"); }
    void SetSolidBsp(bool value) { SetSchemaValue(m_ptr, "CRotDoor", "m_bSolidBsp", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif