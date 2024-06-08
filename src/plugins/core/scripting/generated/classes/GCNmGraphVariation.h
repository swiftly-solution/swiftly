class GCNmGraphVariation;

#ifndef _gccnmgraphvariation_h
#define _gccnmgraphvariation_h

#include "../../../scripting.h"




class GCNmGraphVariation
{
private:
    void *m_ptr;

public:
    GCNmGraphVariation() {}
    GCNmGraphVariation(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif