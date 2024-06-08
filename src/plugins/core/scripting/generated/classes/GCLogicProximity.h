class GCLogicProximity;

#ifndef _gcclogicproximity_h
#define _gcclogicproximity_h

#include "../../../scripting.h"




class GCLogicProximity
{
private:
    void *m_ptr;

public:
    GCLogicProximity() {}
    GCLogicProximity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif