class GCAK47;

#ifndef _gccak47_h
#define _gccak47_h

#include "../../../scripting.h"




class GCAK47
{
private:
    void *m_ptr;

public:
    GCAK47() {}
    GCAK47(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif