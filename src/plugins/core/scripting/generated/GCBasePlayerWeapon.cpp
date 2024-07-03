#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBasePlayerWeapon::GCBasePlayerWeapon(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBasePlayerWeapon::GCBasePlayerWeapon(void *ptr) {
    m_ptr = ptr;
}
int32 GCBasePlayerWeapon::GetNextPrimaryAttackTick() const {
    return GetSchemaValue<int32>(m_ptr, "CBasePlayerWeapon", "m_nNextPrimaryAttackTick");
}
void GCBasePlayerWeapon::SetNextPrimaryAttackTick(int32 value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeapon", "m_nNextPrimaryAttackTick", false, value);
}
float GCBasePlayerWeapon::GetNextPrimaryAttackTickRatio() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlayerWeapon", "m_flNextPrimaryAttackTickRatio");
}
void GCBasePlayerWeapon::SetNextPrimaryAttackTickRatio(float value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeapon", "m_flNextPrimaryAttackTickRatio", false, value);
}
int32 GCBasePlayerWeapon::GetNextSecondaryAttackTick() const {
    return GetSchemaValue<int32>(m_ptr, "CBasePlayerWeapon", "m_nNextSecondaryAttackTick");
}
void GCBasePlayerWeapon::SetNextSecondaryAttackTick(int32 value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeapon", "m_nNextSecondaryAttackTick", false, value);
}
float GCBasePlayerWeapon::GetNextSecondaryAttackTickRatio() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlayerWeapon", "m_flNextSecondaryAttackTickRatio");
}
void GCBasePlayerWeapon::SetNextSecondaryAttackTickRatio(float value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeapon", "m_flNextSecondaryAttackTickRatio", false, value);
}
int32_t GCBasePlayerWeapon::GetClip1() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeapon", "m_iClip1");
}
void GCBasePlayerWeapon::SetClip1(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeapon", "m_iClip1", false, value);
}
int32_t GCBasePlayerWeapon::GetClip2() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeapon", "m_iClip2");
}
void GCBasePlayerWeapon::SetClip2(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeapon", "m_iClip2", false, value);
}
std::vector<int32_t> GCBasePlayerWeapon::GetReserveAmmo() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CBasePlayerWeapon", "m_pReserveAmmo"); std::vector<int32_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCBasePlayerWeapon::SetReserveAmmo(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CBasePlayerWeapon", "m_pReserveAmmo"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CBasePlayerWeapon", "m_pReserveAmmo", false, outValue);
}
GCEntityIOOutput GCBasePlayerWeapon::GetOnPlayerUse() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBasePlayerWeapon", "m_OnPlayerUse"));
    return value;
}
void GCBasePlayerWeapon::SetOnPlayerUse(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBasePlayerWeapon", "m_OnPlayerUse", false, value);
}
std::string GCBasePlayerWeapon::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBasePlayerWeapon::IsValid() {
    return (m_ptr != nullptr);
}
GCEconEntity GCBasePlayerWeapon::GetParent() const {
    GCEconEntity value(m_ptr);
    return value;
}
void GCBasePlayerWeapon::SetParent(GCEconEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBasePlayerWeapon(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBasePlayerWeapon>("CBasePlayerWeapon")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NextPrimaryAttackTick", &GCBasePlayerWeapon::GetNextPrimaryAttackTick, &GCBasePlayerWeapon::SetNextPrimaryAttackTick)
        .addProperty("NextPrimaryAttackTickRatio", &GCBasePlayerWeapon::GetNextPrimaryAttackTickRatio, &GCBasePlayerWeapon::SetNextPrimaryAttackTickRatio)
        .addProperty("NextSecondaryAttackTick", &GCBasePlayerWeapon::GetNextSecondaryAttackTick, &GCBasePlayerWeapon::SetNextSecondaryAttackTick)
        .addProperty("NextSecondaryAttackTickRatio", &GCBasePlayerWeapon::GetNextSecondaryAttackTickRatio, &GCBasePlayerWeapon::SetNextSecondaryAttackTickRatio)
        .addProperty("Clip1", &GCBasePlayerWeapon::GetClip1, &GCBasePlayerWeapon::SetClip1)
        .addProperty("Clip2", &GCBasePlayerWeapon::GetClip2, &GCBasePlayerWeapon::SetClip2)
        .addProperty("ReserveAmmo", &GCBasePlayerWeapon::GetReserveAmmo, &GCBasePlayerWeapon::SetReserveAmmo)
        .addProperty("OnPlayerUse", &GCBasePlayerWeapon::GetOnPlayerUse, &GCBasePlayerWeapon::SetOnPlayerUse)
        .addProperty("Parent", &GCBasePlayerWeapon::GetParent, &GCBasePlayerWeapon::SetParent)
        .addFunction("ToPtr", &GCBasePlayerWeapon::ToPtr)
        .addFunction("IsValid", &GCBasePlayerWeapon::IsValid)
        .endClass();
}