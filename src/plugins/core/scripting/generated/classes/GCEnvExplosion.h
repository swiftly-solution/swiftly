class GCEnvExplosion;

#ifndef _gccenvexplosion_h
#define _gccenvexplosion_h

#include "../../../scripting.h"

#include "../types/GClass_T.h"
#include "GCBaseEntity.h"

class GCEnvExplosion
{
private:
    void *m_ptr;

public:
    GCEnvExplosion() {}
    GCEnvExplosion(void *ptr) : m_ptr(ptr) {}

    int32_t GetMagnitude() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvExplosion", "m_iMagnitude"); }
    void SetMagnitude(int32_t value) { SetSchemaValue(m_ptr, "CEnvExplosion", "m_iMagnitude", false, value); }
    float GetPlayerDamage() const { return GetSchemaValue<float>(m_ptr, "CEnvExplosion", "m_flPlayerDamage"); }
    void SetPlayerDamage(float value) { SetSchemaValue(m_ptr, "CEnvExplosion", "m_flPlayerDamage", false, value); }
    int32_t GetRadiusOverride() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvExplosion", "m_iRadiusOverride"); }
    void SetRadiusOverride(int32_t value) { SetSchemaValue(m_ptr, "CEnvExplosion", "m_iRadiusOverride", false, value); }
    float GetInnerRadius() const { return GetSchemaValue<float>(m_ptr, "CEnvExplosion", "m_flInnerRadius"); }
    void SetInnerRadius(float value) { SetSchemaValue(m_ptr, "CEnvExplosion", "m_flInnerRadius", false, value); }
    int32_t GetSpriteScale() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvExplosion", "m_spriteScale"); }
    void SetSpriteScale(int32_t value) { SetSchemaValue(m_ptr, "CEnvExplosion", "m_spriteScale", false, value); }
    float GetDamageForce() const { return GetSchemaValue<float>(m_ptr, "CEnvExplosion", "m_flDamageForce"); }
    void SetDamageForce(float value) { SetSchemaValue(m_ptr, "CEnvExplosion", "m_flDamageForce", false, value); }
    GCBaseEntity* GetInflictor() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CEnvExplosion", "m_hInflictor"); }
    void SetInflictor(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Inflictor' is not possible.\n"); }
    int32_t GetCustomDamageType() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvExplosion", "m_iCustomDamageType"); }
    void SetCustomDamageType(int32_t value) { SetSchemaValue(m_ptr, "CEnvExplosion", "m_iCustomDamageType", false, value); }
    CUtlSymbolLarge GetExplosionType() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvExplosion", "m_iszExplosionType"); }
    void SetExplosionType(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvExplosion", "m_iszExplosionType", false, value); }
    CUtlSymbolLarge GetCustomEffectName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvExplosion", "m_iszCustomEffectName"); }
    void SetCustomEffectName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvExplosion", "m_iszCustomEffectName", false, value); }
    CUtlSymbolLarge GetCustomSoundName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvExplosion", "m_iszCustomSoundName"); }
    void SetCustomSoundName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvExplosion", "m_iszCustomSoundName", false, value); }
    Class_T GetClassIgnore() const { return GetSchemaValue<Class_T>(m_ptr, "CEnvExplosion", "m_iClassIgnore"); }
    void SetClassIgnore(Class_T value) { SetSchemaValue(m_ptr, "CEnvExplosion", "m_iClassIgnore", false, value); }
    Class_T GetClassIgnore2() const { return GetSchemaValue<Class_T>(m_ptr, "CEnvExplosion", "m_iClassIgnore2"); }
    void SetClassIgnore2(Class_T value) { SetSchemaValue(m_ptr, "CEnvExplosion", "m_iClassIgnore2", false, value); }
    CUtlSymbolLarge GetEntityIgnoreName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvExplosion", "m_iszEntityIgnoreName"); }
    void SetEntityIgnoreName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvExplosion", "m_iszEntityIgnoreName", false, value); }
    GCBaseEntity* GetEntityIgnore() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CEnvExplosion", "m_hEntityIgnore"); }
    void SetEntityIgnore(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'EntityIgnore' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif