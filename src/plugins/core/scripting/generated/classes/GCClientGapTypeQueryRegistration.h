class GCClientGapTypeQueryRegistration;

#ifndef _gccclientgaptypequeryregistration_h
#define _gccclientgaptypequeryregistration_h

#include "../../../scripting.h"




class GCClientGapTypeQueryRegistration
{
private:
    void *m_ptr;

public:
    GCClientGapTypeQueryRegistration() {}
    GCClientGapTypeQueryRegistration(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif