class GCInfoInstructorHintHostageRescueZone;

#ifndef _gccinfoinstructorhinthostagerescuezone_h
#define _gccinfoinstructorhinthostagerescuezone_h

#include "../../../scripting.h"




class GCInfoInstructorHintHostageRescueZone
{
private:
    void *m_ptr;

public:
    GCInfoInstructorHintHostageRescueZone() {}
    GCInfoInstructorHintHostageRescueZone(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif