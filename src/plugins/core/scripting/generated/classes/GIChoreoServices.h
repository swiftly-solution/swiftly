class GIChoreoServices;

#ifndef _gcichoreoservices_h
#define _gcichoreoservices_h

#include "../../../scripting.h"




class GIChoreoServices
{
private:
    void *m_ptr;

public:
    GIChoreoServices() {}
    GIChoreoServices(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif