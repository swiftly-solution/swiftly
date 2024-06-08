class GCTriggerBombReset;

#ifndef _gcctriggerbombreset_h
#define _gcctriggerbombreset_h

#include "../../../scripting.h"




class GCTriggerBombReset
{
private:
    void *m_ptr;

public:
    GCTriggerBombReset() {}
    GCTriggerBombReset(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif