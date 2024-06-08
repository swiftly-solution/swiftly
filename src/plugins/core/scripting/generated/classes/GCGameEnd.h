class GCGameEnd;

#ifndef _gccgameend_h
#define _gccgameend_h

#include "../../../scripting.h"




class GCGameEnd
{
private:
    void *m_ptr;

public:
    GCGameEnd() {}
    GCGameEnd(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif