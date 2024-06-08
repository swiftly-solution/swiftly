class GCLogicNPCCounterOBB;

#ifndef _gcclogicnpccounterobb_h
#define _gcclogicnpccounterobb_h

#include "../../../scripting.h"




class GCLogicNPCCounterOBB
{
private:
    void *m_ptr;

public:
    GCLogicNPCCounterOBB() {}
    GCLogicNPCCounterOBB(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif