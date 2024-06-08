class GCPrecipitationBlocker;

#ifndef _gccprecipitationblocker_h
#define _gccprecipitationblocker_h

#include "../../../scripting.h"




class GCPrecipitationBlocker
{
private:
    void *m_ptr;

public:
    GCPrecipitationBlocker() {}
    GCPrecipitationBlocker(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif