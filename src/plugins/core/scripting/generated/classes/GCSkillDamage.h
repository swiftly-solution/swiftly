class GCSkillDamage;

#ifndef _gccskilldamage_h
#define _gccskilldamage_h

#include "../../../scripting.h"


#include "GCSkillFloat.h"

class GCSkillDamage
{
private:
    void *m_ptr;

public:
    GCSkillDamage() {}
    GCSkillDamage(void *ptr) : m_ptr(ptr) {}

    GCSkillFloat GetDamage() const { return GetSchemaValue<GCSkillFloat>(m_ptr, "CSkillDamage", "m_flDamage"); }
    void SetDamage(GCSkillFloat value) { SetSchemaValue(m_ptr, "CSkillDamage", "m_flDamage", false, value); }
    float GetNPCDamageScalarVsNPC() const { return GetSchemaValue<float>(m_ptr, "CSkillDamage", "m_flNPCDamageScalarVsNPC"); }
    void SetNPCDamageScalarVsNPC(float value) { SetSchemaValue(m_ptr, "CSkillDamage", "m_flNPCDamageScalarVsNPC", false, value); }
    float GetPhysicsForceDamage() const { return GetSchemaValue<float>(m_ptr, "CSkillDamage", "m_flPhysicsForceDamage"); }
    void SetPhysicsForceDamage(float value) { SetSchemaValue(m_ptr, "CSkillDamage", "m_flPhysicsForceDamage", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif