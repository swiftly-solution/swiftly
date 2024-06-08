class GCSpinUpdateBase;

#ifndef _gccspinupdatebase_h
#define _gccspinupdatebase_h

#include "../../../scripting.h"




class GCSpinUpdateBase
{
private:
    void *m_ptr;

public:
    GCSpinUpdateBase() {}
    GCSpinUpdateBase(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif