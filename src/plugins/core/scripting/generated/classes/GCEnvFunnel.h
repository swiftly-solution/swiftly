class GCEnvFunnel;

#ifndef _gccenvfunnel_h
#define _gccenvfunnel_h

#include "../../../scripting.h"




class GCEnvFunnel
{
private:
    void *m_ptr;

public:
    GCEnvFunnel() {}
    GCEnvFunnel(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif