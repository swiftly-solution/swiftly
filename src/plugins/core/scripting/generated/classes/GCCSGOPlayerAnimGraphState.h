class GCCSGOPlayerAnimGraphState;

#ifndef _gcccsgoplayeranimgraphstate_h
#define _gcccsgoplayeranimgraphstate_h

#include "../../../scripting.h"




class GCCSGOPlayerAnimGraphState
{
private:
    void *m_ptr;

public:
    GCCSGOPlayerAnimGraphState() {}
    GCCSGOPlayerAnimGraphState(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif