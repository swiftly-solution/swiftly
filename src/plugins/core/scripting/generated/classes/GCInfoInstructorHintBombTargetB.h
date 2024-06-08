class GCInfoInstructorHintBombTargetB;

#ifndef _gccinfoinstructorhintbombtargetb_h
#define _gccinfoinstructorhintbombtargetb_h

#include "../../../scripting.h"




class GCInfoInstructorHintBombTargetB
{
private:
    void *m_ptr;

public:
    GCInfoInstructorHintBombTargetB() {}
    GCInfoInstructorHintBombTargetB(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif