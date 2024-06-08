class GCTaskStatusAnimTag;

#ifndef _gcctaskstatusanimtag_h
#define _gcctaskstatusanimtag_h

#include "../../../scripting.h"




class GCTaskStatusAnimTag
{
private:
    void *m_ptr;

public:
    GCTaskStatusAnimTag() {}
    GCTaskStatusAnimTag(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif