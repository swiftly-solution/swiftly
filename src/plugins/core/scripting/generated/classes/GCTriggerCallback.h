class GCTriggerCallback;

#ifndef _gcctriggercallback_h
#define _gcctriggercallback_h

#include "../../../scripting.h"




class GCTriggerCallback
{
private:
    void *m_ptr;

public:
    GCTriggerCallback() {}
    GCTriggerCallback(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif