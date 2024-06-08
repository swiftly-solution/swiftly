class GCPrecipitation;

#ifndef _gccprecipitation_h
#define _gccprecipitation_h

#include "../../../scripting.h"




class GCPrecipitation
{
private:
    void *m_ptr;

public:
    GCPrecipitation() {}
    GCPrecipitation(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif