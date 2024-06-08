class GCEnableMotionFixup;

#ifndef _gccenablemotionfixup_h
#define _gccenablemotionfixup_h

#include "../../../scripting.h"




class GCEnableMotionFixup
{
private:
    void *m_ptr;

public:
    GCEnableMotionFixup() {}
    GCEnableMotionFixup(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif