#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTeam::GCTeam(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTeam::GCTeam(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCBasePlayerController*> GCTeam::GetPlayerControllers() const {
    CUtlVector<GCBasePlayerController*>* vec = GetSchemaValue<CUtlVector<GCBasePlayerController*>*>(m_ptr, "CTeam", "m_aPlayerControllers"); std::vector<GCBasePlayerController*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCTeam::SetPlayerControllers(std::vector<GCBasePlayerController*> value) {
    SetSchemaValueCUtlVector<GCBasePlayerController*>(m_ptr, "CTeam", "m_aPlayerControllers", false, value);
}
std::vector<GCBasePlayerPawn*> GCTeam::GetPlayers() const {
    CUtlVector<GCBasePlayerPawn*>* vec = GetSchemaValue<CUtlVector<GCBasePlayerPawn*>*>(m_ptr, "CTeam", "m_aPlayers"); std::vector<GCBasePlayerPawn*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCTeam::SetPlayers(std::vector<GCBasePlayerPawn*> value) {
    SetSchemaValueCUtlVector<GCBasePlayerPawn*>(m_ptr, "CTeam", "m_aPlayers", false, value);
}
int32_t GCTeam::GetScore() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTeam", "m_iScore");
}
void GCTeam::SetScore(int32_t value) {
    SetSchemaValue(m_ptr, "CTeam", "m_iScore", false, value);
}
std::string GCTeam::GetTeamname() const {
    return GetSchemaValuePtr<char>(m_ptr, "CTeam", "m_szTeamname");
}
void GCTeam::SetTeamname(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CTeam", "m_szTeamname", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 129);
}
std::string GCTeam::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTeam::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCTeam::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCTeam::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTeam(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTeam>("CTeam")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PlayerControllers", &GCTeam::GetPlayerControllers, &GCTeam::SetPlayerControllers)
        .addProperty("Players", &GCTeam::GetPlayers, &GCTeam::SetPlayers)
        .addProperty("Score", &GCTeam::GetScore, &GCTeam::SetScore)
        .addProperty("Teamname", &GCTeam::GetTeamname, &GCTeam::SetTeamname)
        .addProperty("Parent", &GCTeam::GetParent, &GCTeam::SetParent)
        .addFunction("ToPtr", &GCTeam::ToPtr)
        .addFunction("IsValid", &GCTeam::IsValid)
        .endClass();
}