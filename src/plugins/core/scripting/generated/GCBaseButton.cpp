#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseButton::GCBaseButton(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseButton::GCBaseButton(void *ptr) {
    m_ptr = ptr;
}
QAngle GCBaseButton::GetMoveEntitySpace() const {
    return GetSchemaValue<QAngle>(m_ptr, "CBaseButton", "m_angMoveEntitySpace");
}
void GCBaseButton::SetMoveEntitySpace(QAngle value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_angMoveEntitySpace", false, value);
}
bool GCBaseButton::GetStayPushed() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseButton", "m_fStayPushed");
}
void GCBaseButton::SetStayPushed(bool value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_fStayPushed", false, value);
}
bool GCBaseButton::GetRotating() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseButton", "m_fRotating");
}
void GCBaseButton::SetRotating(bool value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_fRotating", false, value);
}
Glocksound_t GCBaseButton::GetLs() const {
    Glocksound_t value(GetSchemaPtr(m_ptr, "CBaseButton", "m_ls"));
    return value;
}
void GCBaseButton::SetLs(Glocksound_t value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_ls", false, value);
}
std::string GCBaseButton::GetUseSound() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseButton", "m_sUseSound").String();
}
void GCBaseButton::SetUseSound(std::string value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_sUseSound", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBaseButton::GetLockedSound() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseButton", "m_sLockedSound").String();
}
void GCBaseButton::SetLockedSound(std::string value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_sLockedSound", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBaseButton::GetUnlockedSound() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseButton", "m_sUnlockedSound").String();
}
void GCBaseButton::SetUnlockedSound(std::string value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_sUnlockedSound", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBaseButton::GetOverrideAnticipationName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseButton", "m_sOverrideAnticipationName").String();
}
void GCBaseButton::SetOverrideAnticipationName(std::string value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_sOverrideAnticipationName", false, CUtlSymbolLarge(value.c_str()));
}
bool GCBaseButton::GetLocked() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseButton", "m_bLocked");
}
void GCBaseButton::SetLocked(bool value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_bLocked", false, value);
}
bool GCBaseButton::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseButton", "m_bDisabled");
}
void GCBaseButton::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_bDisabled", false, value);
}
float GCBaseButton::GetUseLockedTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseButton", "m_flUseLockedTime");
}
void GCBaseButton::SetUseLockedTime(float value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_flUseLockedTime", false, value);
}
bool GCBaseButton::GetSolidBsp() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseButton", "m_bSolidBsp");
}
void GCBaseButton::SetSolidBsp(bool value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_bSolidBsp", false, value);
}
GCEntityIOOutput GCBaseButton::GetOnDamaged() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseButton", "m_OnDamaged"));
    return value;
}
void GCBaseButton::SetOnDamaged(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_OnDamaged", false, value);
}
GCEntityIOOutput GCBaseButton::GetOnPressed() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseButton", "m_OnPressed"));
    return value;
}
void GCBaseButton::SetOnPressed(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_OnPressed", false, value);
}
GCEntityIOOutput GCBaseButton::GetOnUseLocked() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseButton", "m_OnUseLocked"));
    return value;
}
void GCBaseButton::SetOnUseLocked(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_OnUseLocked", false, value);
}
GCEntityIOOutput GCBaseButton::GetOnIn() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseButton", "m_OnIn"));
    return value;
}
void GCBaseButton::SetOnIn(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_OnIn", false, value);
}
GCEntityIOOutput GCBaseButton::GetOnOut() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseButton", "m_OnOut"));
    return value;
}
void GCBaseButton::SetOnOut(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_OnOut", false, value);
}
int32_t GCBaseButton::GetState() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseButton", "m_nState");
}
void GCBaseButton::SetState(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_nState", false, value);
}
GCEntityInstance GCBaseButton::GetConstraint() const {
    GCEntityInstance value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseButton", "m_hConstraint"));
    return value;
}
void GCBaseButton::SetConstraint(GCEntityInstance* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Constraint' is not possible.\n");
}
GCEntityInstance GCBaseButton::GetConstraintParent() const {
    GCEntityInstance value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseButton", "m_hConstraintParent"));
    return value;
}
void GCBaseButton::SetConstraintParent(GCEntityInstance* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ConstraintParent' is not possible.\n");
}
bool GCBaseButton::GetForceNpcExclude() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseButton", "m_bForceNpcExclude");
}
void GCBaseButton::SetForceNpcExclude(bool value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_bForceNpcExclude", false, value);
}
std::string GCBaseButton::GetGlowEntity() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseButton", "m_sGlowEntity").String();
}
void GCBaseButton::SetGlowEntity(std::string value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_sGlowEntity", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseModelEntity GCBaseButton::GetGlowEntity1() const {
    GCBaseModelEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseButton", "m_glowEntity"));
    return value;
}
void GCBaseButton::SetGlowEntity1(GCBaseModelEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'GlowEntity1' is not possible.\n");
}
bool GCBaseButton::GetUsable() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseButton", "m_usable");
}
void GCBaseButton::SetUsable(bool value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_usable", false, value);
}
std::string GCBaseButton::GetDisplayText() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseButton", "m_szDisplayText").String();
}
void GCBaseButton::SetDisplayText(std::string value) {
    SetSchemaValue(m_ptr, "CBaseButton", "m_szDisplayText", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBaseButton::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseButton::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseToggle GCBaseButton::GetParent() const {
    GCBaseToggle value(m_ptr);
    return value;
}
void GCBaseButton::SetParent(GCBaseToggle value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseButton(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseButton>("CBaseButton")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MoveEntitySpace", &GCBaseButton::GetMoveEntitySpace, &GCBaseButton::SetMoveEntitySpace)
        .addProperty("StayPushed", &GCBaseButton::GetStayPushed, &GCBaseButton::SetStayPushed)
        .addProperty("Rotating", &GCBaseButton::GetRotating, &GCBaseButton::SetRotating)
        .addProperty("Ls", &GCBaseButton::GetLs, &GCBaseButton::SetLs)
        .addProperty("UseSound", &GCBaseButton::GetUseSound, &GCBaseButton::SetUseSound)
        .addProperty("LockedSound", &GCBaseButton::GetLockedSound, &GCBaseButton::SetLockedSound)
        .addProperty("UnlockedSound", &GCBaseButton::GetUnlockedSound, &GCBaseButton::SetUnlockedSound)
        .addProperty("OverrideAnticipationName", &GCBaseButton::GetOverrideAnticipationName, &GCBaseButton::SetOverrideAnticipationName)
        .addProperty("Locked", &GCBaseButton::GetLocked, &GCBaseButton::SetLocked)
        .addProperty("Disabled", &GCBaseButton::GetDisabled, &GCBaseButton::SetDisabled)
        .addProperty("UseLockedTime", &GCBaseButton::GetUseLockedTime, &GCBaseButton::SetUseLockedTime)
        .addProperty("SolidBsp", &GCBaseButton::GetSolidBsp, &GCBaseButton::SetSolidBsp)
        .addProperty("OnDamaged", &GCBaseButton::GetOnDamaged, &GCBaseButton::SetOnDamaged)
        .addProperty("OnPressed", &GCBaseButton::GetOnPressed, &GCBaseButton::SetOnPressed)
        .addProperty("OnUseLocked", &GCBaseButton::GetOnUseLocked, &GCBaseButton::SetOnUseLocked)
        .addProperty("OnIn", &GCBaseButton::GetOnIn, &GCBaseButton::SetOnIn)
        .addProperty("OnOut", &GCBaseButton::GetOnOut, &GCBaseButton::SetOnOut)
        .addProperty("State", &GCBaseButton::GetState, &GCBaseButton::SetState)
        .addProperty("Constraint", &GCBaseButton::GetConstraint, &GCBaseButton::SetConstraint)
        .addProperty("ConstraintParent", &GCBaseButton::GetConstraintParent, &GCBaseButton::SetConstraintParent)
        .addProperty("ForceNpcExclude", &GCBaseButton::GetForceNpcExclude, &GCBaseButton::SetForceNpcExclude)
        .addProperty("GlowEntity", &GCBaseButton::GetGlowEntity, &GCBaseButton::SetGlowEntity)
        .addProperty("GlowEntity1", &GCBaseButton::GetGlowEntity1, &GCBaseButton::SetGlowEntity1)
        .addProperty("Usable", &GCBaseButton::GetUsable, &GCBaseButton::SetUsable)
        .addProperty("DisplayText", &GCBaseButton::GetDisplayText, &GCBaseButton::SetDisplayText)
        .addProperty("Parent", &GCBaseButton::GetParent, &GCBaseButton::SetParent)
        .addFunction("ToPtr", &GCBaseButton::ToPtr)
        .addFunction("IsValid", &GCBaseButton::IsValid)
        .endClass();
}