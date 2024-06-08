class GCMovementHandshakeAnimTag;

#ifndef _gccmovementhandshakeanimtag_h
#define _gccmovementhandshakeanimtag_h

#include "../../../scripting.h"




class GCMovementHandshakeAnimTag
{
private:
    void *m_ptr;

public:
    GCMovementHandshakeAnimTag() {}
    GCMovementHandshakeAnimTag(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif