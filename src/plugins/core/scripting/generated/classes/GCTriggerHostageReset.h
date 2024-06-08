class GCTriggerHostageReset;

#ifndef _gcctriggerhostagereset_h
#define _gcctriggerhostagereset_h

#include "../../../scripting.h"




class GCTriggerHostageReset
{
private:
    void *m_ptr;

public:
    GCTriggerHostageReset() {}
    GCTriggerHostageReset(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif