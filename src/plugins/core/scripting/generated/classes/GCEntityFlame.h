class GCEntityFlame;

#ifndef _gccentityflame_h
#define _gccentityflame_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCEntityFlame
{
private:
    void *m_ptr;

public:
    GCEntityFlame() {}
    GCEntityFlame(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetEntAttached() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CEntityFlame", "m_hEntAttached"); }
    void SetEntAttached(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'EntAttached' is not possible.\n"); }
    bool GetCheapEffect() const { return GetSchemaValue<bool>(m_ptr, "CEntityFlame", "m_bCheapEffect"); }
    void SetCheapEffect(bool value) { SetSchemaValue(m_ptr, "CEntityFlame", "m_bCheapEffect", false, value); }
    float GetSize() const { return GetSchemaValue<float>(m_ptr, "CEntityFlame", "m_flSize"); }
    void SetSize(float value) { SetSchemaValue(m_ptr, "CEntityFlame", "m_flSize", false, value); }
    bool GetUseHitboxes() const { return GetSchemaValue<bool>(m_ptr, "CEntityFlame", "m_bUseHitboxes"); }
    void SetUseHitboxes(bool value) { SetSchemaValue(m_ptr, "CEntityFlame", "m_bUseHitboxes", false, value); }
    int32_t GetNumHitboxFires() const { return GetSchemaValue<int32_t>(m_ptr, "CEntityFlame", "m_iNumHitboxFires"); }
    void SetNumHitboxFires(int32_t value) { SetSchemaValue(m_ptr, "CEntityFlame", "m_iNumHitboxFires", false, value); }
    float GetHitboxFireScale() const { return GetSchemaValue<float>(m_ptr, "CEntityFlame", "m_flHitboxFireScale"); }
    void SetHitboxFireScale(float value) { SetSchemaValue(m_ptr, "CEntityFlame", "m_flHitboxFireScale", false, value); }
    GCBaseEntity* GetAttacker() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CEntityFlame", "m_hAttacker"); }
    void SetAttacker(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Attacker' is not possible.\n"); }
    int32_t GetDangerSound() const { return GetSchemaValue<int32_t>(m_ptr, "CEntityFlame", "m_iDangerSound"); }
    void SetDangerSound(int32_t value) { SetSchemaValue(m_ptr, "CEntityFlame", "m_iDangerSound", false, value); }
    float GetDirectDamagePerSecond() const { return GetSchemaValue<float>(m_ptr, "CEntityFlame", "m_flDirectDamagePerSecond"); }
    void SetDirectDamagePerSecond(float value) { SetSchemaValue(m_ptr, "CEntityFlame", "m_flDirectDamagePerSecond", false, value); }
    int32_t GetCustomDamageType() const { return GetSchemaValue<int32_t>(m_ptr, "CEntityFlame", "m_iCustomDamageType"); }
    void SetCustomDamageType(int32_t value) { SetSchemaValue(m_ptr, "CEntityFlame", "m_iCustomDamageType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif