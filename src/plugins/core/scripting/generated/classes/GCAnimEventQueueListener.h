class GCAnimEventQueueListener;

#ifndef _gccanimeventqueuelistener_h
#define _gccanimeventqueuelistener_h

#include "../../../scripting.h"




class GCAnimEventQueueListener
{
private:
    void *m_ptr;

public:
    GCAnimEventQueueListener() {}
    GCAnimEventQueueListener(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif