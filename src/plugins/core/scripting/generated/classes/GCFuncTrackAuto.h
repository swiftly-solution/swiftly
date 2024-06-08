class GCFuncTrackAuto;

#ifndef _gccfunctrackauto_h
#define _gccfunctrackauto_h

#include "../../../scripting.h"




class GCFuncTrackAuto
{
private:
    void *m_ptr;

public:
    GCFuncTrackAuto() {}
    GCFuncTrackAuto(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif