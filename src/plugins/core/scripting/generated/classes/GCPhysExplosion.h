class GCPhysExplosion;

#ifndef _gccphysexplosion_h
#define _gccphysexplosion_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCPhysExplosion
{
private:
    void *m_ptr;

public:
    GCPhysExplosion() {}
    GCPhysExplosion(void *ptr) : m_ptr(ptr) {}

    bool GetExplodeOnSpawn() const { return GetSchemaValue<bool>(m_ptr, "CPhysExplosion", "m_bExplodeOnSpawn"); }
    void SetExplodeOnSpawn(bool value) { SetSchemaValue(m_ptr, "CPhysExplosion", "m_bExplodeOnSpawn", false, value); }
    float GetMagnitude() const { return GetSchemaValue<float>(m_ptr, "CPhysExplosion", "m_flMagnitude"); }
    void SetMagnitude(float value) { SetSchemaValue(m_ptr, "CPhysExplosion", "m_flMagnitude", false, value); }
    float GetDamage() const { return GetSchemaValue<float>(m_ptr, "CPhysExplosion", "m_flDamage"); }
    void SetDamage(float value) { SetSchemaValue(m_ptr, "CPhysExplosion", "m_flDamage", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CPhysExplosion", "m_radius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CPhysExplosion", "m_radius", false, value); }
    CUtlSymbolLarge GetTargetEntityName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysExplosion", "m_targetEntityName"); }
    void SetTargetEntityName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPhysExplosion", "m_targetEntityName", false, value); }
    float GetInnerRadius() const { return GetSchemaValue<float>(m_ptr, "CPhysExplosion", "m_flInnerRadius"); }
    void SetInnerRadius(float value) { SetSchemaValue(m_ptr, "CPhysExplosion", "m_flInnerRadius", false, value); }
    float GetPushScale() const { return GetSchemaValue<float>(m_ptr, "CPhysExplosion", "m_flPushScale"); }
    void SetPushScale(float value) { SetSchemaValue(m_ptr, "CPhysExplosion", "m_flPushScale", false, value); }
    bool GetConvertToDebrisWhenPossible() const { return GetSchemaValue<bool>(m_ptr, "CPhysExplosion", "m_bConvertToDebrisWhenPossible"); }
    void SetConvertToDebrisWhenPossible(bool value) { SetSchemaValue(m_ptr, "CPhysExplosion", "m_bConvertToDebrisWhenPossible", false, value); }
    GCEntityIOOutput GetOnPushedPlayer() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysExplosion", "m_OnPushedPlayer"); }
    void SetOnPushedPlayer(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysExplosion", "m_OnPushedPlayer", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif