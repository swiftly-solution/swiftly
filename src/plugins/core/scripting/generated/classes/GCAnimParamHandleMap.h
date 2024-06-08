class GCAnimParamHandleMap;

#ifndef _gccanimparamhandlemap_h
#define _gccanimparamhandlemap_h

#include "../../../scripting.h"




class GCAnimParamHandleMap
{
private:
    void *m_ptr;

public:
    GCAnimParamHandleMap() {}
    GCAnimParamHandleMap(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif