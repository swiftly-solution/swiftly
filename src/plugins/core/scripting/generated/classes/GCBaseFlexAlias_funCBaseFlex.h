class GCBaseFlexAlias_funCBaseFlex;

#ifndef _gccbaseflexalias_funcbaseflex_h
#define _gccbaseflexalias_funcbaseflex_h

#include "../../../scripting.h"




class GCBaseFlexAlias_funCBaseFlex
{
private:
    void *m_ptr;

public:
    GCBaseFlexAlias_funCBaseFlex() {}
    GCBaseFlexAlias_funCBaseFlex(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif