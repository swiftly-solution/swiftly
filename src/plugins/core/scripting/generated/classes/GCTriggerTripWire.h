class GCTriggerTripWire;

#ifndef _gcctriggertripwire_h
#define _gcctriggertripwire_h

#include "../../../scripting.h"




class GCTriggerTripWire
{
private:
    void *m_ptr;

public:
    GCTriggerTripWire() {}
    GCTriggerTripWire(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif