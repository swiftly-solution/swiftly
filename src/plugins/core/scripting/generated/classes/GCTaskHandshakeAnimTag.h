class GCTaskHandshakeAnimTag;

#ifndef _gcctaskhandshakeanimtag_h
#define _gcctaskhandshakeanimtag_h

#include "../../../scripting.h"




class GCTaskHandshakeAnimTag
{
private:
    void *m_ptr;

public:
    GCTaskHandshakeAnimTag() {}
    GCTaskHandshakeAnimTag(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif