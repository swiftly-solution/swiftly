class GCSharedGapTypeQueryRegistration;

#ifndef _gccsharedgaptypequeryregistration_h
#define _gccsharedgaptypequeryregistration_h

#include "../../../scripting.h"




class GCSharedGapTypeQueryRegistration
{
private:
    void *m_ptr;

public:
    GCSharedGapTypeQueryRegistration() {}
    GCSharedGapTypeQueryRegistration(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif