class GCEmptyEntityInstance;

#ifndef _gccemptyentityinstance_h
#define _gccemptyentityinstance_h

#include "../../../scripting.h"




class GCEmptyEntityInstance
{
private:
    void *m_ptr;

public:
    GCEmptyEntityInstance() {}
    GCEmptyEntityInstance(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif