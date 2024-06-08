class GCNmIDEvent;

#ifndef _gccnmidevent_h
#define _gccnmidevent_h

#include "../../../scripting.h"




class GCNmIDEvent
{
private:
    void *m_ptr;

public:
    GCNmIDEvent() {}
    GCNmIDEvent(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif