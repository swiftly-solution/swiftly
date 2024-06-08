class GCSun;

#ifndef _gccsun_h
#define _gccsun_h

#include "../../../scripting.h"




class GCSun
{
private:
    void *m_ptr;

public:
    GCSun() {}
    GCSun(void *ptr) : m_ptr(ptr) {}

    Vector GetDirection() const { return GetSchemaValue<Vector>(m_ptr, "CSun", "m_vDirection"); }
    void SetDirection(Vector value) { SetSchemaValue(m_ptr, "CSun", "m_vDirection", false, value); }
    Color GetOverlay() const { return GetSchemaValue<Color>(m_ptr, "CSun", "m_clrOverlay"); }
    void SetOverlay(Color value) { SetSchemaValue(m_ptr, "CSun", "m_clrOverlay", false, value); }
    CUtlSymbolLarge GetEffectName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSun", "m_iszEffectName"); }
    void SetEffectName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSun", "m_iszEffectName", false, value); }
    CUtlSymbolLarge GetSSEffectName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSun", "m_iszSSEffectName"); }
    void SetSSEffectName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSun", "m_iszSSEffectName", false, value); }
    bool GetOn() const { return GetSchemaValue<bool>(m_ptr, "CSun", "m_bOn"); }
    void SetOn(bool value) { SetSchemaValue(m_ptr, "CSun", "m_bOn", false, value); }
    bool GetBmaxColor() const { return GetSchemaValue<bool>(m_ptr, "CSun", "m_bmaxColor"); }
    void SetBmaxColor(bool value) { SetSchemaValue(m_ptr, "CSun", "m_bmaxColor", false, value); }
    float GetSize() const { return GetSchemaValue<float>(m_ptr, "CSun", "m_flSize"); }
    void SetSize(float value) { SetSchemaValue(m_ptr, "CSun", "m_flSize", false, value); }
    float GetRotation() const { return GetSchemaValue<float>(m_ptr, "CSun", "m_flRotation"); }
    void SetRotation(float value) { SetSchemaValue(m_ptr, "CSun", "m_flRotation", false, value); }
    float GetHazeScale() const { return GetSchemaValue<float>(m_ptr, "CSun", "m_flHazeScale"); }
    void SetHazeScale(float value) { SetSchemaValue(m_ptr, "CSun", "m_flHazeScale", false, value); }
    float GetAlphaHaze() const { return GetSchemaValue<float>(m_ptr, "CSun", "m_flAlphaHaze"); }
    void SetAlphaHaze(float value) { SetSchemaValue(m_ptr, "CSun", "m_flAlphaHaze", false, value); }
    float GetAlphaHdr() const { return GetSchemaValue<float>(m_ptr, "CSun", "m_flAlphaHdr"); }
    void SetAlphaHdr(float value) { SetSchemaValue(m_ptr, "CSun", "m_flAlphaHdr", false, value); }
    float GetAlphaScale() const { return GetSchemaValue<float>(m_ptr, "CSun", "m_flAlphaScale"); }
    void SetAlphaScale(float value) { SetSchemaValue(m_ptr, "CSun", "m_flAlphaScale", false, value); }
    float GetHDRColorScale() const { return GetSchemaValue<float>(m_ptr, "CSun", "m_flHDRColorScale"); }
    void SetHDRColorScale(float value) { SetSchemaValue(m_ptr, "CSun", "m_flHDRColorScale", false, value); }
    float GetFarZScale() const { return GetSchemaValue<float>(m_ptr, "CSun", "m_flFarZScale"); }
    void SetFarZScale(float value) { SetSchemaValue(m_ptr, "CSun", "m_flFarZScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif