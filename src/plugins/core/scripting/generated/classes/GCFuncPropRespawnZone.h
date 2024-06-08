class GCFuncPropRespawnZone;

#ifndef _gccfuncproprespawnzone_h
#define _gccfuncproprespawnzone_h

#include "../../../scripting.h"




class GCFuncPropRespawnZone
{
private:
    void *m_ptr;

public:
    GCFuncPropRespawnZone() {}
    GCFuncPropRespawnZone(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif