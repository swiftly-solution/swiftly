class GCFootstepTableHandle;

#ifndef _gccfootsteptablehandle_h
#define _gccfootsteptablehandle_h

#include "../../../scripting.h"




class GCFootstepTableHandle
{
private:
    void *m_ptr;

public:
    GCFootstepTableHandle() {}
    GCFootstepTableHandle(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif