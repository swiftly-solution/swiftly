class GCCSPointScriptExtensions_observer;

#ifndef _gcccspointscriptextensions_observer_h
#define _gcccspointscriptextensions_observer_h

#include "../../../scripting.h"




class GCCSPointScriptExtensions_observer
{
private:
    void *m_ptr;

public:
    GCCSPointScriptExtensions_observer() {}
    GCCSPointScriptExtensions_observer(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif