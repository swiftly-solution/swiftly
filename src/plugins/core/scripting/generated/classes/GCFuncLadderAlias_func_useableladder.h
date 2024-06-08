class GCFuncLadderAlias_func_useableladder;

#ifndef _gccfuncladderalias_func_useableladder_h
#define _gccfuncladderalias_func_useableladder_h

#include "../../../scripting.h"




class GCFuncLadderAlias_func_useableladder
{
private:
    void *m_ptr;

public:
    GCFuncLadderAlias_func_useableladder() {}
    GCFuncLadderAlias_func_useableladder(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif