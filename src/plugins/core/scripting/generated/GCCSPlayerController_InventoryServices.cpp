#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayerController_InventoryServices::GCCSPlayerController_InventoryServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayerController_InventoryServices::GCCSPlayerController_InventoryServices(void *ptr) {
    m_ptr = ptr;
}
uint16_t GCCSPlayerController_InventoryServices::GetMusicID() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CCSPlayerController_InventoryServices", "m_unMusicID");
}
void GCCSPlayerController_InventoryServices::SetMusicID(uint16_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController_InventoryServices", "m_unMusicID", false, value);
}
std::vector<MedalRank_t> GCCSPlayerController_InventoryServices::GetRank() const {
    MedalRank_t* outValue = GetSchemaValue<MedalRank_t*>(m_ptr, "CCSPlayerController_InventoryServices", "m_rank"); std::vector<MedalRank_t> ret; for(int i = 0; i < 6; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSPlayerController_InventoryServices::SetRank(std::vector<MedalRank_t> value) {
    MedalRank_t* outValue = GetSchemaValue<MedalRank_t*>(m_ptr, "CCSPlayerController_InventoryServices", "m_rank"); for(int i = 0; i < 6; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerController_InventoryServices", "m_rank", false, outValue);
}
int32_t GCCSPlayerController_InventoryServices::GetPersonaDataPublicLevel() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicLevel");
}
void GCCSPlayerController_InventoryServices::SetPersonaDataPublicLevel(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicLevel", false, value);
}
int32_t GCCSPlayerController_InventoryServices::GetPersonaDataPublicCommendsLeader() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicCommendsLeader");
}
void GCCSPlayerController_InventoryServices::SetPersonaDataPublicCommendsLeader(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicCommendsLeader", false, value);
}
int32_t GCCSPlayerController_InventoryServices::GetPersonaDataPublicCommendsTeacher() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicCommendsTeacher");
}
void GCCSPlayerController_InventoryServices::SetPersonaDataPublicCommendsTeacher(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicCommendsTeacher", false, value);
}
int32_t GCCSPlayerController_InventoryServices::GetPersonaDataPublicCommendsFriendly() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicCommendsFriendly");
}
void GCCSPlayerController_InventoryServices::SetPersonaDataPublicCommendsFriendly(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicCommendsFriendly", false, value);
}
int32_t GCCSPlayerController_InventoryServices::GetPersonaDataXpTrailLevel() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataXpTrailLevel");
}
void GCCSPlayerController_InventoryServices::SetPersonaDataXpTrailLevel(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataXpTrailLevel", false, value);
}
std::vector<uint32_t> GCCSPlayerController_InventoryServices::GetEquippedPlayerSprayIDs() const {
    uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CCSPlayerController_InventoryServices", "m_unEquippedPlayerSprayIDs"); std::vector<uint32_t> ret; for(int i = 0; i < 1; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSPlayerController_InventoryServices::SetEquippedPlayerSprayIDs(std::vector<uint32_t> value) {
    uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CCSPlayerController_InventoryServices", "m_unEquippedPlayerSprayIDs"); for(int i = 0; i < 1; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerController_InventoryServices", "m_unEquippedPlayerSprayIDs", false, outValue);
}
std::vector<GServerAuthoritativeWeaponSlot_t> GCCSPlayerController_InventoryServices::GetServerAuthoritativeWeaponSlots() const {
    CUtlVector<GServerAuthoritativeWeaponSlot_t>* vec = GetSchemaValue<CUtlVector<GServerAuthoritativeWeaponSlot_t>*>(m_ptr, "CCSPlayerController_InventoryServices", "m_vecServerAuthoritativeWeaponSlots"); std::vector<GServerAuthoritativeWeaponSlot_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCCSPlayerController_InventoryServices::SetServerAuthoritativeWeaponSlots(std::vector<GServerAuthoritativeWeaponSlot_t> value) {
    SetSchemaValueCUtlVector<GServerAuthoritativeWeaponSlot_t>(m_ptr, "CCSPlayerController_InventoryServices", "m_vecServerAuthoritativeWeaponSlots", false, value);
}
std::string GCCSPlayerController_InventoryServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayerController_InventoryServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerControllerComponent GCCSPlayerController_InventoryServices::GetParent() const {
    GCPlayerControllerComponent value(m_ptr);
    return value;
}
void GCCSPlayerController_InventoryServices::SetParent(GCPlayerControllerComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayerController_InventoryServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayerController_InventoryServices>("CCSPlayerController_InventoryServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MusicID", &GCCSPlayerController_InventoryServices::GetMusicID, &GCCSPlayerController_InventoryServices::SetMusicID)
        .addProperty("Rank", &GCCSPlayerController_InventoryServices::GetRank, &GCCSPlayerController_InventoryServices::SetRank)
        .addProperty("PersonaDataPublicLevel", &GCCSPlayerController_InventoryServices::GetPersonaDataPublicLevel, &GCCSPlayerController_InventoryServices::SetPersonaDataPublicLevel)
        .addProperty("PersonaDataPublicCommendsLeader", &GCCSPlayerController_InventoryServices::GetPersonaDataPublicCommendsLeader, &GCCSPlayerController_InventoryServices::SetPersonaDataPublicCommendsLeader)
        .addProperty("PersonaDataPublicCommendsTeacher", &GCCSPlayerController_InventoryServices::GetPersonaDataPublicCommendsTeacher, &GCCSPlayerController_InventoryServices::SetPersonaDataPublicCommendsTeacher)
        .addProperty("PersonaDataPublicCommendsFriendly", &GCCSPlayerController_InventoryServices::GetPersonaDataPublicCommendsFriendly, &GCCSPlayerController_InventoryServices::SetPersonaDataPublicCommendsFriendly)
        .addProperty("PersonaDataXpTrailLevel", &GCCSPlayerController_InventoryServices::GetPersonaDataXpTrailLevel, &GCCSPlayerController_InventoryServices::SetPersonaDataXpTrailLevel)
        .addProperty("EquippedPlayerSprayIDs", &GCCSPlayerController_InventoryServices::GetEquippedPlayerSprayIDs, &GCCSPlayerController_InventoryServices::SetEquippedPlayerSprayIDs)
        .addProperty("ServerAuthoritativeWeaponSlots", &GCCSPlayerController_InventoryServices::GetServerAuthoritativeWeaponSlots, &GCCSPlayerController_InventoryServices::SetServerAuthoritativeWeaponSlots)
        .addProperty("Parent", &GCCSPlayerController_InventoryServices::GetParent, &GCCSPlayerController_InventoryServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayerController_InventoryServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayerController_InventoryServices::IsValid)
        .endClass();
}