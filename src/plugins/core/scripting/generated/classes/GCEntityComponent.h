class GCEntityComponent;

#ifndef _gccentitycomponent_h
#define _gccentitycomponent_h

#include "../../../scripting.h"




class GCEntityComponent
{
private:
    void *m_ptr;

public:
    GCEntityComponent() {}
    GCEntityComponent(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif