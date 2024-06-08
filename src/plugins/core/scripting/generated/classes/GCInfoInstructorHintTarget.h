class GCInfoInstructorHintTarget;

#ifndef _gccinfoinstructorhinttarget_h
#define _gccinfoinstructorhinttarget_h

#include "../../../scripting.h"




class GCInfoInstructorHintTarget
{
private:
    void *m_ptr;

public:
    GCInfoInstructorHintTarget() {}
    GCInfoInstructorHintTarget(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif