class GCTriggerDetectExplosion;

#ifndef _gcctriggerdetectexplosion_h
#define _gcctriggerdetectexplosion_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCTriggerDetectExplosion
{
private:
    void *m_ptr;

public:
    GCTriggerDetectExplosion() {}
    GCTriggerDetectExplosion(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnDetectedExplosion() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTriggerDetectExplosion", "m_OnDetectedExplosion"); }
    void SetOnDetectedExplosion(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTriggerDetectExplosion", "m_OnDetectedExplosion", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif