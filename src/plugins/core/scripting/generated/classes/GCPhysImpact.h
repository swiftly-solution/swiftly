class GCPhysImpact;

#ifndef _gccphysimpact_h
#define _gccphysimpact_h

#include "../../../scripting.h"




class GCPhysImpact
{
private:
    void *m_ptr;

public:
    GCPhysImpact() {}
    GCPhysImpact(void *ptr) : m_ptr(ptr) {}

    float GetDamage() const { return GetSchemaValue<float>(m_ptr, "CPhysImpact", "m_damage"); }
    void SetDamage(float value) { SetSchemaValue(m_ptr, "CPhysImpact", "m_damage", false, value); }
    float GetDistance() const { return GetSchemaValue<float>(m_ptr, "CPhysImpact", "m_distance"); }
    void SetDistance(float value) { SetSchemaValue(m_ptr, "CPhysImpact", "m_distance", false, value); }
    CUtlSymbolLarge GetDirectionEntityName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysImpact", "m_directionEntityName"); }
    void SetDirectionEntityName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPhysImpact", "m_directionEntityName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif