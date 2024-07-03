#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseIssue::GCBaseIssue(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseIssue::GCBaseIssue(void *ptr) {
    m_ptr = ptr;
}
std::string GCBaseIssue::GetTypeString() const {
    return GetSchemaValuePtr<char>(m_ptr, "CBaseIssue", "m_szTypeString");
}
void GCBaseIssue::SetTypeString(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CBaseIssue", "m_szTypeString", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 64);
}
std::string GCBaseIssue::GetDetailsString() const {
    return GetSchemaValuePtr<char>(m_ptr, "CBaseIssue", "m_szDetailsString");
}
void GCBaseIssue::SetDetailsString(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CBaseIssue", "m_szDetailsString", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 260);
}
int32_t GCBaseIssue::GetNumYesVotes() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseIssue", "m_iNumYesVotes");
}
void GCBaseIssue::SetNumYesVotes(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseIssue", "m_iNumYesVotes", false, value);
}
int32_t GCBaseIssue::GetNumNoVotes() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseIssue", "m_iNumNoVotes");
}
void GCBaseIssue::SetNumNoVotes(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseIssue", "m_iNumNoVotes", false, value);
}
int32_t GCBaseIssue::GetNumPotentialVotes() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseIssue", "m_iNumPotentialVotes");
}
void GCBaseIssue::SetNumPotentialVotes(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseIssue", "m_iNumPotentialVotes", false, value);
}
std::string GCBaseIssue::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseIssue::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCBaseIssue(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseIssue>("CBaseIssue")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TypeString", &GCBaseIssue::GetTypeString, &GCBaseIssue::SetTypeString)
        .addProperty("DetailsString", &GCBaseIssue::GetDetailsString, &GCBaseIssue::SetDetailsString)
        .addProperty("NumYesVotes", &GCBaseIssue::GetNumYesVotes, &GCBaseIssue::SetNumYesVotes)
        .addProperty("NumNoVotes", &GCBaseIssue::GetNumNoVotes, &GCBaseIssue::SetNumNoVotes)
        .addProperty("NumPotentialVotes", &GCBaseIssue::GetNumPotentialVotes, &GCBaseIssue::SetNumPotentialVotes)
        .addFunction("ToPtr", &GCBaseIssue::ToPtr)
        .addFunction("IsValid", &GCBaseIssue::IsValid)
        .endClass();
}