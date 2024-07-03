#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayer_WeaponServices::GCPlayer_WeaponServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayer_WeaponServices::GCPlayer_WeaponServices(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCBasePlayerWeapon*> GCPlayer_WeaponServices::GetMyWeapons() const {
    CUtlVector<GCBasePlayerWeapon*>* vec = GetSchemaValue<CUtlVector<GCBasePlayerWeapon*>*>(m_ptr, "CPlayer_WeaponServices", "m_hMyWeapons"); std::vector<GCBasePlayerWeapon*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCPlayer_WeaponServices::SetMyWeapons(std::vector<GCBasePlayerWeapon*> value) {
    SetSchemaValueCUtlVector<GCBasePlayerWeapon*>(m_ptr, "CPlayer_WeaponServices", "m_hMyWeapons", false, value);
}
GCBasePlayerWeapon GCPlayer_WeaponServices::GetActiveWeapon() const {
    GCBasePlayerWeapon value(*GetSchemaValuePtr<void*>(m_ptr, "CPlayer_WeaponServices", "m_hActiveWeapon"));
    return value;
}
void GCPlayer_WeaponServices::SetActiveWeapon(GCBasePlayerWeapon* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ActiveWeapon' is not possible.\n");
}
GCBasePlayerWeapon GCPlayer_WeaponServices::GetLastWeapon() const {
    GCBasePlayerWeapon value(*GetSchemaValuePtr<void*>(m_ptr, "CPlayer_WeaponServices", "m_hLastWeapon"));
    return value;
}
void GCPlayer_WeaponServices::SetLastWeapon(GCBasePlayerWeapon* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'LastWeapon' is not possible.\n");
}
std::vector<uint16_t> GCPlayer_WeaponServices::GetAmmo() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "CPlayer_WeaponServices", "m_iAmmo"); std::vector<uint16_t> ret; for(int i = 0; i < 32; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCPlayer_WeaponServices::SetAmmo(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "CPlayer_WeaponServices", "m_iAmmo"); for(int i = 0; i < 32; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CPlayer_WeaponServices", "m_iAmmo", false, outValue);
}
bool GCPlayer_WeaponServices::GetPreventWeaponPickup() const {
    return GetSchemaValue<bool>(m_ptr, "CPlayer_WeaponServices", "m_bPreventWeaponPickup");
}
void GCPlayer_WeaponServices::SetPreventWeaponPickup(bool value) {
    SetSchemaValue(m_ptr, "CPlayer_WeaponServices", "m_bPreventWeaponPickup", false, value);
}
std::string GCPlayer_WeaponServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayer_WeaponServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerPawnComponent GCPlayer_WeaponServices::GetParent() const {
    GCPlayerPawnComponent value(m_ptr);
    return value;
}
void GCPlayer_WeaponServices::SetParent(GCPlayerPawnComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPlayer_WeaponServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_WeaponServices>("CPlayer_WeaponServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MyWeapons", &GCPlayer_WeaponServices::GetMyWeapons, &GCPlayer_WeaponServices::SetMyWeapons)
        .addProperty("ActiveWeapon", &GCPlayer_WeaponServices::GetActiveWeapon, &GCPlayer_WeaponServices::SetActiveWeapon)
        .addProperty("LastWeapon", &GCPlayer_WeaponServices::GetLastWeapon, &GCPlayer_WeaponServices::SetLastWeapon)
        .addProperty("Ammo", &GCPlayer_WeaponServices::GetAmmo, &GCPlayer_WeaponServices::SetAmmo)
        .addProperty("PreventWeaponPickup", &GCPlayer_WeaponServices::GetPreventWeaponPickup, &GCPlayer_WeaponServices::SetPreventWeaponPickup)
        .addProperty("Parent", &GCPlayer_WeaponServices::GetParent, &GCPlayer_WeaponServices::SetParent)
        .addFunction("ToPtr", &GCPlayer_WeaponServices::ToPtr)
        .addFunction("IsValid", &GCPlayer_WeaponServices::IsValid)
        .endClass();
}