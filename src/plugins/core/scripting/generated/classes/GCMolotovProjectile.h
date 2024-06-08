class GCMolotovProjectile;

#ifndef _gccmolotovprojectile_h
#define _gccmolotovprojectile_h

#include "../../../scripting.h"


#include "GIntervalTimer.h"

class GCMolotovProjectile
{
private:
    void *m_ptr;

public:
    GCMolotovProjectile() {}
    GCMolotovProjectile(void *ptr) : m_ptr(ptr) {}

    bool GetIsIncGrenade() const { return GetSchemaValue<bool>(m_ptr, "CMolotovProjectile", "m_bIsIncGrenade"); }
    void SetIsIncGrenade(bool value) { SetSchemaValue(m_ptr, "CMolotovProjectile", "m_bIsIncGrenade", false, value); }
    bool GetDetonated() const { return GetSchemaValue<bool>(m_ptr, "CMolotovProjectile", "m_bDetonated"); }
    void SetDetonated(bool value) { SetSchemaValue(m_ptr, "CMolotovProjectile", "m_bDetonated", false, value); }
    GIntervalTimer GetStillTimer() const { return GetSchemaValue<GIntervalTimer>(m_ptr, "CMolotovProjectile", "m_stillTimer"); }
    void SetStillTimer(GIntervalTimer value) { SetSchemaValue(m_ptr, "CMolotovProjectile", "m_stillTimer", false, value); }
    bool GetHasBouncedOffPlayer() const { return GetSchemaValue<bool>(m_ptr, "CMolotovProjectile", "m_bHasBouncedOffPlayer"); }
    void SetHasBouncedOffPlayer(bool value) { SetSchemaValue(m_ptr, "CMolotovProjectile", "m_bHasBouncedOffPlayer", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif