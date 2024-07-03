#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSosGroupMatchPattern::GCSosGroupMatchPattern(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSosGroupMatchPattern::GCSosGroupMatchPattern(void *ptr) {
    m_ptr = ptr;
}
std::string GCSosGroupMatchPattern::GetMatchSoundEventName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupMatchPattern", "m_matchSoundEventName").Get();
}
void GCSosGroupMatchPattern::SetMatchSoundEventName(std::string value) {
    SetSchemaValue(m_ptr, "CSosGroupMatchPattern", "m_matchSoundEventName", false, CUtlString(value.c_str()));
}
std::string GCSosGroupMatchPattern::GetMatchSoundEventSubString() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupMatchPattern", "m_matchSoundEventSubString").Get();
}
void GCSosGroupMatchPattern::SetMatchSoundEventSubString(std::string value) {
    SetSchemaValue(m_ptr, "CSosGroupMatchPattern", "m_matchSoundEventSubString", false, CUtlString(value.c_str()));
}
float GCSosGroupMatchPattern::GetEntIndex() const {
    return GetSchemaValue<float>(m_ptr, "CSosGroupMatchPattern", "m_flEntIndex");
}
void GCSosGroupMatchPattern::SetEntIndex(float value) {
    SetSchemaValue(m_ptr, "CSosGroupMatchPattern", "m_flEntIndex", false, value);
}
float GCSosGroupMatchPattern::GetOpvar() const {
    return GetSchemaValue<float>(m_ptr, "CSosGroupMatchPattern", "m_flOpvar");
}
void GCSosGroupMatchPattern::SetOpvar(float value) {
    SetSchemaValue(m_ptr, "CSosGroupMatchPattern", "m_flOpvar", false, value);
}
std::string GCSosGroupMatchPattern::GetOpvarString() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupMatchPattern", "m_opvarString").Get();
}
void GCSosGroupMatchPattern::SetOpvarString(std::string value) {
    SetSchemaValue(m_ptr, "CSosGroupMatchPattern", "m_opvarString", false, CUtlString(value.c_str()));
}
std::string GCSosGroupMatchPattern::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSosGroupMatchPattern::IsValid() {
    return (m_ptr != nullptr);
}
GCSosGroupBranchPattern GCSosGroupMatchPattern::GetParent() const {
    GCSosGroupBranchPattern value(m_ptr);
    return value;
}
void GCSosGroupMatchPattern::SetParent(GCSosGroupBranchPattern value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSosGroupMatchPattern(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupMatchPattern>("CSosGroupMatchPattern")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MatchSoundEventName", &GCSosGroupMatchPattern::GetMatchSoundEventName, &GCSosGroupMatchPattern::SetMatchSoundEventName)
        .addProperty("MatchSoundEventSubString", &GCSosGroupMatchPattern::GetMatchSoundEventSubString, &GCSosGroupMatchPattern::SetMatchSoundEventSubString)
        .addProperty("EntIndex", &GCSosGroupMatchPattern::GetEntIndex, &GCSosGroupMatchPattern::SetEntIndex)
        .addProperty("Opvar", &GCSosGroupMatchPattern::GetOpvar, &GCSosGroupMatchPattern::SetOpvar)
        .addProperty("OpvarString", &GCSosGroupMatchPattern::GetOpvarString, &GCSosGroupMatchPattern::SetOpvarString)
        .addProperty("Parent", &GCSosGroupMatchPattern::GetParent, &GCSosGroupMatchPattern::SetParent)
        .addFunction("ToPtr", &GCSosGroupMatchPattern::ToPtr)
        .addFunction("IsValid", &GCSosGroupMatchPattern::IsValid)
        .endClass();
}