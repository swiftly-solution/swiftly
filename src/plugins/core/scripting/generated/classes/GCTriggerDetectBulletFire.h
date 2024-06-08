class GCTriggerDetectBulletFire;

#ifndef _gcctriggerdetectbulletfire_h
#define _gcctriggerdetectbulletfire_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCTriggerDetectBulletFire
{
private:
    void *m_ptr;

public:
    GCTriggerDetectBulletFire() {}
    GCTriggerDetectBulletFire(void *ptr) : m_ptr(ptr) {}

    bool GetPlayerFireOnly() const { return GetSchemaValue<bool>(m_ptr, "CTriggerDetectBulletFire", "m_bPlayerFireOnly"); }
    void SetPlayerFireOnly(bool value) { SetSchemaValue(m_ptr, "CTriggerDetectBulletFire", "m_bPlayerFireOnly", false, value); }
    GCEntityIOOutput GetOnDetectedBulletFire() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTriggerDetectBulletFire", "m_OnDetectedBulletFire"); }
    void SetOnDetectedBulletFire(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTriggerDetectBulletFire", "m_OnDetectedBulletFire", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif