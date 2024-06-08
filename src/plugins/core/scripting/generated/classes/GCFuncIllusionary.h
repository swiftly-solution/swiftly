class GCFuncIllusionary;

#ifndef _gccfuncillusionary_h
#define _gccfuncillusionary_h

#include "../../../scripting.h"




class GCFuncIllusionary
{
private:
    void *m_ptr;

public:
    GCFuncIllusionary() {}
    GCFuncIllusionary(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif