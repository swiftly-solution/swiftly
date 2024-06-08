class GCGameRulesProxy;

#ifndef _gccgamerulesproxy_h
#define _gccgamerulesproxy_h

#include "../../../scripting.h"




class GCGameRulesProxy
{
private:
    void *m_ptr;

public:
    GCGameRulesProxy() {}
    GCGameRulesProxy(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif