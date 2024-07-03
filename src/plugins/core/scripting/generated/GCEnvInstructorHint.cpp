#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvInstructorHint::GCEnvInstructorHint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvInstructorHint::GCEnvInstructorHint(void *ptr) {
    m_ptr = ptr;
}
std::string GCEnvInstructorHint::GetName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorHint", "m_iszName").String();
}
void GCEnvInstructorHint::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iszName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCEnvInstructorHint::GetReplace_Key() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorHint", "m_iszReplace_Key").String();
}
void GCEnvInstructorHint::SetReplace_Key(std::string value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iszReplace_Key", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCEnvInstructorHint::GetHintTargetEntity() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorHint", "m_iszHintTargetEntity").String();
}
void GCEnvInstructorHint::SetHintTargetEntity(std::string value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iszHintTargetEntity", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCEnvInstructorHint::GetTimeout() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvInstructorHint", "m_iTimeout");
}
void GCEnvInstructorHint::SetTimeout(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iTimeout", false, value);
}
int32_t GCEnvInstructorHint::GetDisplayLimit() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvInstructorHint", "m_iDisplayLimit");
}
void GCEnvInstructorHint::SetDisplayLimit(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iDisplayLimit", false, value);
}
std::string GCEnvInstructorHint::GetIcon_Onscreen() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorHint", "m_iszIcon_Onscreen").String();
}
void GCEnvInstructorHint::SetIcon_Onscreen(std::string value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iszIcon_Onscreen", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCEnvInstructorHint::GetIcon_Offscreen() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorHint", "m_iszIcon_Offscreen").String();
}
void GCEnvInstructorHint::SetIcon_Offscreen(std::string value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iszIcon_Offscreen", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCEnvInstructorHint::GetCaption() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorHint", "m_iszCaption").String();
}
void GCEnvInstructorHint::SetCaption(std::string value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iszCaption", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCEnvInstructorHint::GetActivatorCaption() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorHint", "m_iszActivatorCaption").String();
}
void GCEnvInstructorHint::SetActivatorCaption(std::string value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iszActivatorCaption", false, CUtlSymbolLarge(value.c_str()));
}
Color GCEnvInstructorHint::GetColor() const {
    return GetSchemaValue<Color>(m_ptr, "CEnvInstructorHint", "m_Color");
}
void GCEnvInstructorHint::SetColor(Color value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_Color", false, value);
}
float GCEnvInstructorHint::GetIconOffset() const {
    return GetSchemaValue<float>(m_ptr, "CEnvInstructorHint", "m_fIconOffset");
}
void GCEnvInstructorHint::SetIconOffset(float value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_fIconOffset", false, value);
}
float GCEnvInstructorHint::GetRange() const {
    return GetSchemaValue<float>(m_ptr, "CEnvInstructorHint", "m_fRange");
}
void GCEnvInstructorHint::SetRange(float value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_fRange", false, value);
}
uint8_t GCEnvInstructorHint::GetPulseOption() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CEnvInstructorHint", "m_iPulseOption");
}
void GCEnvInstructorHint::SetPulseOption(uint8_t value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iPulseOption", false, value);
}
uint8_t GCEnvInstructorHint::GetAlphaOption() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CEnvInstructorHint", "m_iAlphaOption");
}
void GCEnvInstructorHint::SetAlphaOption(uint8_t value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iAlphaOption", false, value);
}
uint8_t GCEnvInstructorHint::GetShakeOption() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CEnvInstructorHint", "m_iShakeOption");
}
void GCEnvInstructorHint::SetShakeOption(uint8_t value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iShakeOption", false, value);
}
bool GCEnvInstructorHint::GetStatic() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvInstructorHint", "m_bStatic");
}
void GCEnvInstructorHint::SetStatic(bool value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_bStatic", false, value);
}
bool GCEnvInstructorHint::GetNoOffscreen() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvInstructorHint", "m_bNoOffscreen");
}
void GCEnvInstructorHint::SetNoOffscreen(bool value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_bNoOffscreen", false, value);
}
bool GCEnvInstructorHint::GetForceCaption() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvInstructorHint", "m_bForceCaption");
}
void GCEnvInstructorHint::SetForceCaption(bool value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_bForceCaption", false, value);
}
int32_t GCEnvInstructorHint::GetInstanceType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvInstructorHint", "m_iInstanceType");
}
void GCEnvInstructorHint::SetInstanceType(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iInstanceType", false, value);
}
bool GCEnvInstructorHint::GetSuppressRest() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvInstructorHint", "m_bSuppressRest");
}
void GCEnvInstructorHint::SetSuppressRest(bool value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_bSuppressRest", false, value);
}
std::string GCEnvInstructorHint::GetBinding() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorHint", "m_iszBinding").String();
}
void GCEnvInstructorHint::SetBinding(std::string value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_iszBinding", false, CUtlSymbolLarge(value.c_str()));
}
bool GCEnvInstructorHint::GetAllowNoDrawTarget() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvInstructorHint", "m_bAllowNoDrawTarget");
}
void GCEnvInstructorHint::SetAllowNoDrawTarget(bool value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_bAllowNoDrawTarget", false, value);
}
bool GCEnvInstructorHint::GetAutoStart() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvInstructorHint", "m_bAutoStart");
}
void GCEnvInstructorHint::SetAutoStart(bool value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_bAutoStart", false, value);
}
bool GCEnvInstructorHint::GetLocalPlayerOnly() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvInstructorHint", "m_bLocalPlayerOnly");
}
void GCEnvInstructorHint::SetLocalPlayerOnly(bool value) {
    SetSchemaValue(m_ptr, "CEnvInstructorHint", "m_bLocalPlayerOnly", false, value);
}
std::string GCEnvInstructorHint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvInstructorHint::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCEnvInstructorHint::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCEnvInstructorHint::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvInstructorHint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvInstructorHint>("CEnvInstructorHint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCEnvInstructorHint::GetName, &GCEnvInstructorHint::SetName)
        .addProperty("Replace_Key", &GCEnvInstructorHint::GetReplace_Key, &GCEnvInstructorHint::SetReplace_Key)
        .addProperty("HintTargetEntity", &GCEnvInstructorHint::GetHintTargetEntity, &GCEnvInstructorHint::SetHintTargetEntity)
        .addProperty("Timeout", &GCEnvInstructorHint::GetTimeout, &GCEnvInstructorHint::SetTimeout)
        .addProperty("DisplayLimit", &GCEnvInstructorHint::GetDisplayLimit, &GCEnvInstructorHint::SetDisplayLimit)
        .addProperty("Icon_Onscreen", &GCEnvInstructorHint::GetIcon_Onscreen, &GCEnvInstructorHint::SetIcon_Onscreen)
        .addProperty("Icon_Offscreen", &GCEnvInstructorHint::GetIcon_Offscreen, &GCEnvInstructorHint::SetIcon_Offscreen)
        .addProperty("Caption", &GCEnvInstructorHint::GetCaption, &GCEnvInstructorHint::SetCaption)
        .addProperty("ActivatorCaption", &GCEnvInstructorHint::GetActivatorCaption, &GCEnvInstructorHint::SetActivatorCaption)
        .addProperty("Color", &GCEnvInstructorHint::GetColor, &GCEnvInstructorHint::SetColor)
        .addProperty("IconOffset", &GCEnvInstructorHint::GetIconOffset, &GCEnvInstructorHint::SetIconOffset)
        .addProperty("Range", &GCEnvInstructorHint::GetRange, &GCEnvInstructorHint::SetRange)
        .addProperty("PulseOption", &GCEnvInstructorHint::GetPulseOption, &GCEnvInstructorHint::SetPulseOption)
        .addProperty("AlphaOption", &GCEnvInstructorHint::GetAlphaOption, &GCEnvInstructorHint::SetAlphaOption)
        .addProperty("ShakeOption", &GCEnvInstructorHint::GetShakeOption, &GCEnvInstructorHint::SetShakeOption)
        .addProperty("Static", &GCEnvInstructorHint::GetStatic, &GCEnvInstructorHint::SetStatic)
        .addProperty("NoOffscreen", &GCEnvInstructorHint::GetNoOffscreen, &GCEnvInstructorHint::SetNoOffscreen)
        .addProperty("ForceCaption", &GCEnvInstructorHint::GetForceCaption, &GCEnvInstructorHint::SetForceCaption)
        .addProperty("InstanceType", &GCEnvInstructorHint::GetInstanceType, &GCEnvInstructorHint::SetInstanceType)
        .addProperty("SuppressRest", &GCEnvInstructorHint::GetSuppressRest, &GCEnvInstructorHint::SetSuppressRest)
        .addProperty("Binding", &GCEnvInstructorHint::GetBinding, &GCEnvInstructorHint::SetBinding)
        .addProperty("AllowNoDrawTarget", &GCEnvInstructorHint::GetAllowNoDrawTarget, &GCEnvInstructorHint::SetAllowNoDrawTarget)
        .addProperty("AutoStart", &GCEnvInstructorHint::GetAutoStart, &GCEnvInstructorHint::SetAutoStart)
        .addProperty("LocalPlayerOnly", &GCEnvInstructorHint::GetLocalPlayerOnly, &GCEnvInstructorHint::SetLocalPlayerOnly)
        .addProperty("Parent", &GCEnvInstructorHint::GetParent, &GCEnvInstructorHint::SetParent)
        .addFunction("ToPtr", &GCEnvInstructorHint::ToPtr)
        .addFunction("IsValid", &GCEnvInstructorHint::IsValid)
        .endClass();
}