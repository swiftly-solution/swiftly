#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSosGroupBranchPattern::GCSosGroupBranchPattern(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSosGroupBranchPattern::GCSosGroupBranchPattern(void *ptr) {
    m_ptr = ptr;
}
bool GCSosGroupBranchPattern::GetMatchEventName() const {
    return GetSchemaValue<bool>(m_ptr, "CSosGroupBranchPattern", "m_bMatchEventName");
}
void GCSosGroupBranchPattern::SetMatchEventName(bool value) {
    SetSchemaValue(m_ptr, "CSosGroupBranchPattern", "m_bMatchEventName", false, value);
}
bool GCSosGroupBranchPattern::GetMatchEventSubString() const {
    return GetSchemaValue<bool>(m_ptr, "CSosGroupBranchPattern", "m_bMatchEventSubString");
}
void GCSosGroupBranchPattern::SetMatchEventSubString(bool value) {
    SetSchemaValue(m_ptr, "CSosGroupBranchPattern", "m_bMatchEventSubString", false, value);
}
bool GCSosGroupBranchPattern::GetMatchEntIndex() const {
    return GetSchemaValue<bool>(m_ptr, "CSosGroupBranchPattern", "m_bMatchEntIndex");
}
void GCSosGroupBranchPattern::SetMatchEntIndex(bool value) {
    SetSchemaValue(m_ptr, "CSosGroupBranchPattern", "m_bMatchEntIndex", false, value);
}
bool GCSosGroupBranchPattern::GetMatchOpvar() const {
    return GetSchemaValue<bool>(m_ptr, "CSosGroupBranchPattern", "m_bMatchOpvar");
}
void GCSosGroupBranchPattern::SetMatchOpvar(bool value) {
    SetSchemaValue(m_ptr, "CSosGroupBranchPattern", "m_bMatchOpvar", false, value);
}
bool GCSosGroupBranchPattern::GetMatchString() const {
    return GetSchemaValue<bool>(m_ptr, "CSosGroupBranchPattern", "m_bMatchString");
}
void GCSosGroupBranchPattern::SetMatchString(bool value) {
    SetSchemaValue(m_ptr, "CSosGroupBranchPattern", "m_bMatchString", false, value);
}
std::string GCSosGroupBranchPattern::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSosGroupBranchPattern::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSosGroupBranchPattern(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupBranchPattern>("CSosGroupBranchPattern")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MatchEventName", &GCSosGroupBranchPattern::GetMatchEventName, &GCSosGroupBranchPattern::SetMatchEventName)
        .addProperty("MatchEventSubString", &GCSosGroupBranchPattern::GetMatchEventSubString, &GCSosGroupBranchPattern::SetMatchEventSubString)
        .addProperty("MatchEntIndex", &GCSosGroupBranchPattern::GetMatchEntIndex, &GCSosGroupBranchPattern::SetMatchEntIndex)
        .addProperty("MatchOpvar", &GCSosGroupBranchPattern::GetMatchOpvar, &GCSosGroupBranchPattern::SetMatchOpvar)
        .addProperty("MatchString", &GCSosGroupBranchPattern::GetMatchString, &GCSosGroupBranchPattern::SetMatchString)
        .addFunction("ToPtr", &GCSosGroupBranchPattern::ToPtr)
        .addFunction("IsValid", &GCSosGroupBranchPattern::IsValid)
        .endClass();
}