class GCFuncWallToggle;

#ifndef _gccfuncwalltoggle_h
#define _gccfuncwalltoggle_h

#include "../../../scripting.h"




class GCFuncWallToggle
{
private:
    void *m_ptr;

public:
    GCFuncWallToggle() {}
    GCFuncWallToggle(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif