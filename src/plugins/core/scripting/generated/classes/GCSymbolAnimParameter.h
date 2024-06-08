class GCSymbolAnimParameter;

#ifndef _gccsymbolanimparameter_h
#define _gccsymbolanimparameter_h

#include "../../../scripting.h"




class GCSymbolAnimParameter
{
private:
    void *m_ptr;

public:
    GCSymbolAnimParameter() {}
    GCSymbolAnimParameter(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif