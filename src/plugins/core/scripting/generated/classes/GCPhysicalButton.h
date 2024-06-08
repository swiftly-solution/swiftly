class GCPhysicalButton;

#ifndef _gccphysicalbutton_h
#define _gccphysicalbutton_h

#include "../../../scripting.h"




class GCPhysicalButton
{
private:
    void *m_ptr;

public:
    GCPhysicalButton() {}
    GCPhysicalButton(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif