class GCStringAnimTag;

#ifndef _gccstringanimtag_h
#define _gccstringanimtag_h

#include "../../../scripting.h"




class GCStringAnimTag
{
private:
    void *m_ptr;

public:
    GCStringAnimTag() {}
    GCStringAnimTag(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif