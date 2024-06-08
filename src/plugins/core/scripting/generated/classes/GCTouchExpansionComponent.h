class GCTouchExpansionComponent;

#ifndef _gcctouchexpansioncomponent_h
#define _gcctouchexpansioncomponent_h

#include "../../../scripting.h"




class GCTouchExpansionComponent
{
private:
    void *m_ptr;

public:
    GCTouchExpansionComponent() {}
    GCTouchExpansionComponent(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif