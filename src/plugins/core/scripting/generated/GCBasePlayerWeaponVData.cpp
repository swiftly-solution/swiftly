#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBasePlayerWeaponVData::GCBasePlayerWeaponVData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBasePlayerWeaponVData::GCBasePlayerWeaponVData(void *ptr) {
    m_ptr = ptr;
}
bool GCBasePlayerWeaponVData::GetBuiltRightHanded() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePlayerWeaponVData", "m_bBuiltRightHanded");
}
void GCBasePlayerWeaponVData::SetBuiltRightHanded(bool value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_bBuiltRightHanded", false, value);
}
bool GCBasePlayerWeaponVData::GetAllowFlipping() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePlayerWeaponVData", "m_bAllowFlipping");
}
void GCBasePlayerWeaponVData::SetAllowFlipping(bool value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_bAllowFlipping", false, value);
}
std::string GCBasePlayerWeaponVData::GetMuzzleAttachment() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBasePlayerWeaponVData", "m_sMuzzleAttachment").Get();
}
void GCBasePlayerWeaponVData::SetMuzzleAttachment(std::string value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_sMuzzleAttachment", false, CUtlString(value.c_str()));
}
uint64_t GCBasePlayerWeaponVData::GetFlags() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBasePlayerWeaponVData", "m_iFlags");
}
void GCBasePlayerWeaponVData::SetFlags(uint64_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iFlags", false, value);
}
uint8_t GCBasePlayerWeaponVData::GetPrimaryAmmoType() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CBasePlayerWeaponVData", "m_nPrimaryAmmoType");
}
void GCBasePlayerWeaponVData::SetPrimaryAmmoType(uint8_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_nPrimaryAmmoType", false, value);
}
uint8_t GCBasePlayerWeaponVData::GetSecondaryAmmoType() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CBasePlayerWeaponVData", "m_nSecondaryAmmoType");
}
void GCBasePlayerWeaponVData::SetSecondaryAmmoType(uint8_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_nSecondaryAmmoType", false, value);
}
int32_t GCBasePlayerWeaponVData::GetMaxClip1() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeaponVData", "m_iMaxClip1");
}
void GCBasePlayerWeaponVData::SetMaxClip1(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iMaxClip1", false, value);
}
int32_t GCBasePlayerWeaponVData::GetMaxClip2() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeaponVData", "m_iMaxClip2");
}
void GCBasePlayerWeaponVData::SetMaxClip2(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iMaxClip2", false, value);
}
int32_t GCBasePlayerWeaponVData::GetDefaultClip1() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeaponVData", "m_iDefaultClip1");
}
void GCBasePlayerWeaponVData::SetDefaultClip1(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iDefaultClip1", false, value);
}
int32_t GCBasePlayerWeaponVData::GetDefaultClip2() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeaponVData", "m_iDefaultClip2");
}
void GCBasePlayerWeaponVData::SetDefaultClip2(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iDefaultClip2", false, value);
}
int32_t GCBasePlayerWeaponVData::GetWeight() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeaponVData", "m_iWeight");
}
void GCBasePlayerWeaponVData::SetWeight(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iWeight", false, value);
}
bool GCBasePlayerWeaponVData::GetAutoSwitchTo() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePlayerWeaponVData", "m_bAutoSwitchTo");
}
void GCBasePlayerWeaponVData::SetAutoSwitchTo(bool value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_bAutoSwitchTo", false, value);
}
bool GCBasePlayerWeaponVData::GetAutoSwitchFrom() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePlayerWeaponVData", "m_bAutoSwitchFrom");
}
void GCBasePlayerWeaponVData::SetAutoSwitchFrom(bool value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_bAutoSwitchFrom", false, value);
}
uint64_t GCBasePlayerWeaponVData::GetRumbleEffect() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBasePlayerWeaponVData", "m_iRumbleEffect");
}
void GCBasePlayerWeaponVData::SetRumbleEffect(uint64_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iRumbleEffect", false, value);
}
bool GCBasePlayerWeaponVData::GetLinkedCooldowns() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePlayerWeaponVData", "m_bLinkedCooldowns");
}
void GCBasePlayerWeaponVData::SetLinkedCooldowns(bool value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_bLinkedCooldowns", false, value);
}
int32_t GCBasePlayerWeaponVData::GetSlot() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeaponVData", "m_iSlot");
}
void GCBasePlayerWeaponVData::SetSlot(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iSlot", false, value);
}
int32_t GCBasePlayerWeaponVData::GetPosition() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeaponVData", "m_iPosition");
}
void GCBasePlayerWeaponVData::SetPosition(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iPosition", false, value);
}
std::string GCBasePlayerWeaponVData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBasePlayerWeaponVData::IsValid() {
    return (m_ptr != nullptr);
}
GCEntitySubclassVDataBase GCBasePlayerWeaponVData::GetParent() const {
    GCEntitySubclassVDataBase value(m_ptr);
    return value;
}
void GCBasePlayerWeaponVData::SetParent(GCEntitySubclassVDataBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBasePlayerWeaponVData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBasePlayerWeaponVData>("CBasePlayerWeaponVData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BuiltRightHanded", &GCBasePlayerWeaponVData::GetBuiltRightHanded, &GCBasePlayerWeaponVData::SetBuiltRightHanded)
        .addProperty("AllowFlipping", &GCBasePlayerWeaponVData::GetAllowFlipping, &GCBasePlayerWeaponVData::SetAllowFlipping)
        .addProperty("MuzzleAttachment", &GCBasePlayerWeaponVData::GetMuzzleAttachment, &GCBasePlayerWeaponVData::SetMuzzleAttachment)
        .addProperty("Flags", &GCBasePlayerWeaponVData::GetFlags, &GCBasePlayerWeaponVData::SetFlags)
        .addProperty("PrimaryAmmoType", &GCBasePlayerWeaponVData::GetPrimaryAmmoType, &GCBasePlayerWeaponVData::SetPrimaryAmmoType)
        .addProperty("SecondaryAmmoType", &GCBasePlayerWeaponVData::GetSecondaryAmmoType, &GCBasePlayerWeaponVData::SetSecondaryAmmoType)
        .addProperty("MaxClip1", &GCBasePlayerWeaponVData::GetMaxClip1, &GCBasePlayerWeaponVData::SetMaxClip1)
        .addProperty("MaxClip2", &GCBasePlayerWeaponVData::GetMaxClip2, &GCBasePlayerWeaponVData::SetMaxClip2)
        .addProperty("DefaultClip1", &GCBasePlayerWeaponVData::GetDefaultClip1, &GCBasePlayerWeaponVData::SetDefaultClip1)
        .addProperty("DefaultClip2", &GCBasePlayerWeaponVData::GetDefaultClip2, &GCBasePlayerWeaponVData::SetDefaultClip2)
        .addProperty("Weight", &GCBasePlayerWeaponVData::GetWeight, &GCBasePlayerWeaponVData::SetWeight)
        .addProperty("AutoSwitchTo", &GCBasePlayerWeaponVData::GetAutoSwitchTo, &GCBasePlayerWeaponVData::SetAutoSwitchTo)
        .addProperty("AutoSwitchFrom", &GCBasePlayerWeaponVData::GetAutoSwitchFrom, &GCBasePlayerWeaponVData::SetAutoSwitchFrom)
        .addProperty("RumbleEffect", &GCBasePlayerWeaponVData::GetRumbleEffect, &GCBasePlayerWeaponVData::SetRumbleEffect)
        .addProperty("LinkedCooldowns", &GCBasePlayerWeaponVData::GetLinkedCooldowns, &GCBasePlayerWeaponVData::SetLinkedCooldowns)
        .addProperty("Slot", &GCBasePlayerWeaponVData::GetSlot, &GCBasePlayerWeaponVData::SetSlot)
        .addProperty("Position", &GCBasePlayerWeaponVData::GetPosition, &GCBasePlayerWeaponVData::SetPosition)
        .addProperty("Parent", &GCBasePlayerWeaponVData::GetParent, &GCBasePlayerWeaponVData::SetParent)
        .addFunction("ToPtr", &GCBasePlayerWeaponVData::ToPtr)
        .addFunction("IsValid", &GCBasePlayerWeaponVData::IsValid)
        .endClass();
}