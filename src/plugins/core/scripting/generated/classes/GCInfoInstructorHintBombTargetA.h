class GCInfoInstructorHintBombTargetA;

#ifndef _gccinfoinstructorhintbombtargeta_h
#define _gccinfoinstructorhintbombtargeta_h

#include "../../../scripting.h"




class GCInfoInstructorHintBombTargetA
{
private:
    void *m_ptr;

public:
    GCInfoInstructorHintBombTargetA() {}
    GCInfoInstructorHintBombTargetA(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif