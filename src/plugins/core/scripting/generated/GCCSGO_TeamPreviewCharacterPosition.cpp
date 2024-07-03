#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGO_TeamPreviewCharacterPosition::GCCSGO_TeamPreviewCharacterPosition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGO_TeamPreviewCharacterPosition::GCCSGO_TeamPreviewCharacterPosition(void *ptr) {
    m_ptr = ptr;
}
int32_t GCCSGO_TeamPreviewCharacterPosition::GetVariant() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_nVariant");
}
void GCCSGO_TeamPreviewCharacterPosition::SetVariant(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_nVariant", false, value);
}
int32_t GCCSGO_TeamPreviewCharacterPosition::GetRandom() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_nRandom");
}
void GCCSGO_TeamPreviewCharacterPosition::SetRandom(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_nRandom", false, value);
}
int32_t GCCSGO_TeamPreviewCharacterPosition::GetOrdinal() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_nOrdinal");
}
void GCCSGO_TeamPreviewCharacterPosition::SetOrdinal(int32_t value) {
    SetSchemaValue(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_nOrdinal", false, value);
}
std::string GCCSGO_TeamPreviewCharacterPosition::GetWeaponName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_sWeaponName").Get();
}
void GCCSGO_TeamPreviewCharacterPosition::SetWeaponName(std::string value) {
    SetSchemaValue(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_sWeaponName", false, CUtlString(value.c_str()));
}
uint64_t GCCSGO_TeamPreviewCharacterPosition::GetXuid() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_xuid");
}
void GCCSGO_TeamPreviewCharacterPosition::SetXuid(uint64_t value) {
    SetSchemaValue(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_xuid", false, value);
}
GCEconItemView GCCSGO_TeamPreviewCharacterPosition::GetAgentItem() const {
    GCEconItemView value(GetSchemaPtr(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_agentItem"));
    return value;
}
void GCCSGO_TeamPreviewCharacterPosition::SetAgentItem(GCEconItemView value) {
    SetSchemaValue(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_agentItem", false, value);
}
GCEconItemView GCCSGO_TeamPreviewCharacterPosition::GetGlovesItem() const {
    GCEconItemView value(GetSchemaPtr(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_glovesItem"));
    return value;
}
void GCCSGO_TeamPreviewCharacterPosition::SetGlovesItem(GCEconItemView value) {
    SetSchemaValue(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_glovesItem", false, value);
}
GCEconItemView GCCSGO_TeamPreviewCharacterPosition::GetWeaponItem() const {
    GCEconItemView value(GetSchemaPtr(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_weaponItem"));
    return value;
}
void GCCSGO_TeamPreviewCharacterPosition::SetWeaponItem(GCEconItemView value) {
    SetSchemaValue(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_weaponItem", false, value);
}
std::string GCCSGO_TeamPreviewCharacterPosition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGO_TeamPreviewCharacterPosition::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCCSGO_TeamPreviewCharacterPosition::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCCSGO_TeamPreviewCharacterPosition::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSGO_TeamPreviewCharacterPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_TeamPreviewCharacterPosition>("CCSGO_TeamPreviewCharacterPosition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Variant", &GCCSGO_TeamPreviewCharacterPosition::GetVariant, &GCCSGO_TeamPreviewCharacterPosition::SetVariant)
        .addProperty("Random", &GCCSGO_TeamPreviewCharacterPosition::GetRandom, &GCCSGO_TeamPreviewCharacterPosition::SetRandom)
        .addProperty("Ordinal", &GCCSGO_TeamPreviewCharacterPosition::GetOrdinal, &GCCSGO_TeamPreviewCharacterPosition::SetOrdinal)
        .addProperty("WeaponName", &GCCSGO_TeamPreviewCharacterPosition::GetWeaponName, &GCCSGO_TeamPreviewCharacterPosition::SetWeaponName)
        .addProperty("Xuid", &GCCSGO_TeamPreviewCharacterPosition::GetXuid, &GCCSGO_TeamPreviewCharacterPosition::SetXuid)
        .addProperty("AgentItem", &GCCSGO_TeamPreviewCharacterPosition::GetAgentItem, &GCCSGO_TeamPreviewCharacterPosition::SetAgentItem)
        .addProperty("GlovesItem", &GCCSGO_TeamPreviewCharacterPosition::GetGlovesItem, &GCCSGO_TeamPreviewCharacterPosition::SetGlovesItem)
        .addProperty("WeaponItem", &GCCSGO_TeamPreviewCharacterPosition::GetWeaponItem, &GCCSGO_TeamPreviewCharacterPosition::SetWeaponItem)
        .addProperty("Parent", &GCCSGO_TeamPreviewCharacterPosition::GetParent, &GCCSGO_TeamPreviewCharacterPosition::SetParent)
        .addFunction("ToPtr", &GCCSGO_TeamPreviewCharacterPosition::ToPtr)
        .addFunction("IsValid", &GCCSGO_TeamPreviewCharacterPosition::IsValid)
        .endClass();
}