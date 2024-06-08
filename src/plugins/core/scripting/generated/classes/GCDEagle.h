class GCDEagle;

#ifndef _gccdeagle_h
#define _gccdeagle_h

#include "../../../scripting.h"




class GCDEagle
{
private:
    void *m_ptr;

public:
    GCDEagle() {}
    GCDEagle(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif