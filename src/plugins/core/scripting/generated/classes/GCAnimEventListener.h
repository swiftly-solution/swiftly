class GCAnimEventListener;

#ifndef _gccanimeventlistener_h
#define _gccanimeventlistener_h

#include "../../../scripting.h"




class GCAnimEventListener
{
private:
    void *m_ptr;

public:
    GCAnimEventListener() {}
    GCAnimEventListener(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif