class GCEnvInstructorHint;

#ifndef _gccenvinstructorhint_h
#define _gccenvinstructorhint_h

#include "../../../scripting.h"




class GCEnvInstructorHint
{
private:
    void *m_ptr;

public:
    GCEnvInstructorHint() {}
    GCEnvInstructorHint(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorHint", "m_iszName"); }
    void SetName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iszName", false, value); }
    CUtlSymbolLarge GetReplace_Key() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorHint", "m_iszReplace_Key"); }
    void SetReplace_Key(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iszReplace_Key", false, value); }
    CUtlSymbolLarge GetHintTargetEntity() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorHint", "m_iszHintTargetEntity"); }
    void SetHintTargetEntity(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iszHintTargetEntity", false, value); }
    int32_t GetTimeout() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvInstructorHint", "m_iTimeout"); }
    void SetTimeout(int32_t value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iTimeout", false, value); }
    int32_t GetDisplayLimit() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvInstructorHint", "m_iDisplayLimit"); }
    void SetDisplayLimit(int32_t value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iDisplayLimit", false, value); }
    CUtlSymbolLarge GetIcon_Onscreen() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorHint", "m_iszIcon_Onscreen"); }
    void SetIcon_Onscreen(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iszIcon_Onscreen", false, value); }
    CUtlSymbolLarge GetIcon_Offscreen() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorHint", "m_iszIcon_Offscreen"); }
    void SetIcon_Offscreen(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iszIcon_Offscreen", false, value); }
    CUtlSymbolLarge GetCaption() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorHint", "m_iszCaption"); }
    void SetCaption(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iszCaption", false, value); }
    CUtlSymbolLarge GetActivatorCaption() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorHint", "m_iszActivatorCaption"); }
    void SetActivatorCaption(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iszActivatorCaption", false, value); }
    Color GetColor() const { return GetSchemaValue<Color>(m_ptr, "CEnvInstructorHint", "m_Color"); }
    void SetColor(Color value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_Color", false, value); }
    float GetIconOffset() const { return GetSchemaValue<float>(m_ptr, "CEnvInstructorHint", "m_fIconOffset"); }
    void SetIconOffset(float value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_fIconOffset", false, value); }
    float GetRange() const { return GetSchemaValue<float>(m_ptr, "CEnvInstructorHint", "m_fRange"); }
    void SetRange(float value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_fRange", false, value); }
    uint8_t GetPulseOption() const { return GetSchemaValue<uint8_t>(m_ptr, "CEnvInstructorHint", "m_iPulseOption"); }
    void SetPulseOption(uint8_t value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iPulseOption", false, value); }
    uint8_t GetAlphaOption() const { return GetSchemaValue<uint8_t>(m_ptr, "CEnvInstructorHint", "m_iAlphaOption"); }
    void SetAlphaOption(uint8_t value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iAlphaOption", false, value); }
    uint8_t GetShakeOption() const { return GetSchemaValue<uint8_t>(m_ptr, "CEnvInstructorHint", "m_iShakeOption"); }
    void SetShakeOption(uint8_t value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iShakeOption", false, value); }
    bool GetStatic() const { return GetSchemaValue<bool>(m_ptr, "CEnvInstructorHint", "m_bStatic"); }
    void SetStatic(bool value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_bStatic", false, value); }
    bool GetNoOffscreen() const { return GetSchemaValue<bool>(m_ptr, "CEnvInstructorHint", "m_bNoOffscreen"); }
    void SetNoOffscreen(bool value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_bNoOffscreen", false, value); }
    bool GetForceCaption() const { return GetSchemaValue<bool>(m_ptr, "CEnvInstructorHint", "m_bForceCaption"); }
    void SetForceCaption(bool value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_bForceCaption", false, value); }
    int32_t GetInstanceType() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvInstructorHint", "m_iInstanceType"); }
    void SetInstanceType(int32_t value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iInstanceType", false, value); }
    bool GetSuppressRest() const { return GetSchemaValue<bool>(m_ptr, "CEnvInstructorHint", "m_bSuppressRest"); }
    void SetSuppressRest(bool value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_bSuppressRest", false, value); }
    CUtlSymbolLarge GetBinding() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorHint", "m_iszBinding"); }
    void SetBinding(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iszBinding", false, value); }
    bool GetAllowNoDrawTarget() const { return GetSchemaValue<bool>(m_ptr, "CEnvInstructorHint", "m_bAllowNoDrawTarget"); }
    void SetAllowNoDrawTarget(bool value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_bAllowNoDrawTarget", false, value); }
    bool GetAutoStart() const { return GetSchemaValue<bool>(m_ptr, "CEnvInstructorHint", "m_bAutoStart"); }
    void SetAutoStart(bool value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_bAutoStart", false, value); }
    bool GetLocalPlayerOnly() const { return GetSchemaValue<bool>(m_ptr, "CEnvInstructorHint", "m_bLocalPlayerOnly"); }
    void SetLocalPlayerOnly(bool value) { SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_bLocalPlayerOnly", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif