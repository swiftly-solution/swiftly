class GC_INIT_StatusEffect;

#ifndef _gcc_init_statuseffect_h
#define _gcc_init_statuseffect_h

#include "../../../scripting.h"

#include "../types/GDetail2Combo_t.h"


class GC_INIT_StatusEffect
{
private:
    void *m_ptr;

public:
    GC_INIT_StatusEffect() {}
    GC_INIT_StatusEffect(void *ptr) : m_ptr(ptr) {}

    Detail2Combo_t GetDetail2Combo() const { return GetSchemaValue<Detail2Combo_t>(m_ptr, "C_INIT_StatusEffect", "m_nDetail2Combo"); }
    void SetDetail2Combo(Detail2Combo_t value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_nDetail2Combo", false, value); }
    float GetDetail2Rotation() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffect", "m_flDetail2Rotation"); }
    void SetDetail2Rotation(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_flDetail2Rotation", false, value); }
    float GetDetail2Scale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffect", "m_flDetail2Scale"); }
    void SetDetail2Scale(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_flDetail2Scale", false, value); }
    float GetDetail2BlendFactor() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffect", "m_flDetail2BlendFactor"); }
    void SetDetail2BlendFactor(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_flDetail2BlendFactor", false, value); }
    float GetColorWarpIntensity() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffect", "m_flColorWarpIntensity"); }
    void SetColorWarpIntensity(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_flColorWarpIntensity", false, value); }
    float GetDiffuseWarpBlendToFull() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffect", "m_flDiffuseWarpBlendToFull"); }
    void SetDiffuseWarpBlendToFull(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_flDiffuseWarpBlendToFull", false, value); }
    float GetEnvMapIntensity() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffect", "m_flEnvMapIntensity"); }
    void SetEnvMapIntensity(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_flEnvMapIntensity", false, value); }
    float GetAmbientScale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffect", "m_flAmbientScale"); }
    void SetAmbientScale(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_flAmbientScale", false, value); }
    Color GetSpecularColor() const { return GetSchemaValue<Color>(m_ptr, "C_INIT_StatusEffect", "m_specularColor"); }
    void SetSpecularColor(Color value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_specularColor", false, value); }
    float GetSpecularScale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffect", "m_flSpecularScale"); }
    void SetSpecularScale(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_flSpecularScale", false, value); }
    float GetSpecularExponent() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffect", "m_flSpecularExponent"); }
    void SetSpecularExponent(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_flSpecularExponent", false, value); }
    float GetSpecularExponentBlendToFull() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffect", "m_flSpecularExponentBlendToFull"); }
    void SetSpecularExponentBlendToFull(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_flSpecularExponentBlendToFull", false, value); }
    float GetSpecularBlendToFull() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffect", "m_flSpecularBlendToFull"); }
    void SetSpecularBlendToFull(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_flSpecularBlendToFull", false, value); }
    Color GetRimLightColor() const { return GetSchemaValue<Color>(m_ptr, "C_INIT_StatusEffect", "m_rimLightColor"); }
    void SetRimLightColor(Color value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_rimLightColor", false, value); }
    float GetRimLightScale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffect", "m_flRimLightScale"); }
    void SetRimLightScale(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_flRimLightScale", false, value); }
    float GetReflectionsTintByBaseBlendToNone() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffect", "m_flReflectionsTintByBaseBlendToNone"); }
    void SetReflectionsTintByBaseBlendToNone(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_flReflectionsTintByBaseBlendToNone", false, value); }
    float GetMetalnessBlendToFull() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffect", "m_flMetalnessBlendToFull"); }
    void SetMetalnessBlendToFull(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_flMetalnessBlendToFull", false, value); }
    float GetSelfIllumBlendToFull() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffect", "m_flSelfIllumBlendToFull"); }
    void SetSelfIllumBlendToFull(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffect", "m_flSelfIllumBlendToFull", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif