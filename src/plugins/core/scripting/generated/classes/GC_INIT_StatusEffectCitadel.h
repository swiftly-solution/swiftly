class GC_INIT_StatusEffectCitadel;

#ifndef _gcc_init_statuseffectcitadel_h
#define _gcc_init_statuseffectcitadel_h

#include "../../../scripting.h"

#include "../types/GDetailCombo_t.h"


class GC_INIT_StatusEffectCitadel
{
private:
    void *m_ptr;

public:
    GC_INIT_StatusEffectCitadel() {}
    GC_INIT_StatusEffectCitadel(void *ptr) : m_ptr(ptr) {}

    float GetSFXColorWarpAmount() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXColorWarpAmount"); }
    void SetSFXColorWarpAmount(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXColorWarpAmount", false, value); }
    float GetSFXNormalAmount() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXNormalAmount"); }
    void SetSFXNormalAmount(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXNormalAmount", false, value); }
    float GetSFXMetalnessAmount() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXMetalnessAmount"); }
    void SetSFXMetalnessAmount(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXMetalnessAmount", false, value); }
    float GetSFXRoughnessAmount() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXRoughnessAmount"); }
    void SetSFXRoughnessAmount(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXRoughnessAmount", false, value); }
    float GetSFXSelfIllumAmount() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSelfIllumAmount"); }
    void SetSFXSelfIllumAmount(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSelfIllumAmount", false, value); }
    float GetSFXSScale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSScale"); }
    void SetSFXSScale(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSScale", false, value); }
    float GetSFXSScrollX() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSScrollX"); }
    void SetSFXSScrollX(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSScrollX", false, value); }
    float GetSFXSScrollY() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSScrollY"); }
    void SetSFXSScrollY(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSScrollY", false, value); }
    float GetSFXSScrollZ() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSScrollZ"); }
    void SetSFXSScrollZ(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSScrollZ", false, value); }
    float GetSFXSOffsetX() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSOffsetX"); }
    void SetSFXSOffsetX(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSOffsetX", false, value); }
    float GetSFXSOffsetY() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSOffsetY"); }
    void SetSFXSOffsetY(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSOffsetY", false, value); }
    float GetSFXSOffsetZ() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSOffsetZ"); }
    void SetSFXSOffsetZ(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSOffsetZ", false, value); }
    DetailCombo_t GetDetailCombo() const { return GetSchemaValue<DetailCombo_t>(m_ptr, "C_INIT_StatusEffectCitadel", "m_nDetailCombo"); }
    void SetDetailCombo(DetailCombo_t value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_nDetailCombo", false, value); }
    float GetSFXSDetailAmount() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSDetailAmount"); }
    void SetSFXSDetailAmount(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSDetailAmount", false, value); }
    float GetSFXSDetailScale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSDetailScale"); }
    void SetSFXSDetailScale(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSDetailScale", false, value); }
    float GetSFXSDetailScrollX() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSDetailScrollX"); }
    void SetSFXSDetailScrollX(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSDetailScrollX", false, value); }
    float GetSFXSDetailScrollY() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSDetailScrollY"); }
    void SetSFXSDetailScrollY(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSDetailScrollY", false, value); }
    float GetSFXSDetailScrollZ() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSDetailScrollZ"); }
    void SetSFXSDetailScrollZ(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSDetailScrollZ", false, value); }
    float GetSFXSUseModelUVs() const { return GetSchemaValue<float>(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSUseModelUVs"); }
    void SetSFXSUseModelUVs(float value) { SetSchemaValue(m_ptr, "C_INIT_StatusEffectCitadel", "m_flSFXSUseModelUVs", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif