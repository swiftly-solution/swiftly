class GCTriggerGravity;

#ifndef _gcctriggergravity_h
#define _gcctriggergravity_h

#include "../../../scripting.h"




class GCTriggerGravity
{
private:
    void *m_ptr;

public:
    GCTriggerGravity() {}
    GCTriggerGravity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif