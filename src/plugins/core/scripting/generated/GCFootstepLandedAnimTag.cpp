#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFootstepLandedAnimTag::GCFootstepLandedAnimTag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFootstepLandedAnimTag::GCFootstepLandedAnimTag(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCFootstepLandedAnimTag::GetFootstepType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CFootstepLandedAnimTag", "m_FootstepType");
}
void GCFootstepLandedAnimTag::SetFootstepType(uint64_t value) {
    SetSchemaValue(m_ptr, "CFootstepLandedAnimTag", "m_FootstepType", false, value);
}
std::string GCFootstepLandedAnimTag::GetOverrideSoundName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CFootstepLandedAnimTag", "m_OverrideSoundName").Get();
}
void GCFootstepLandedAnimTag::SetOverrideSoundName(std::string value) {
    SetSchemaValue(m_ptr, "CFootstepLandedAnimTag", "m_OverrideSoundName", false, CUtlString(value.c_str()));
}
std::string GCFootstepLandedAnimTag::GetDebugAnimSourceString() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CFootstepLandedAnimTag", "m_DebugAnimSourceString").Get();
}
void GCFootstepLandedAnimTag::SetDebugAnimSourceString(std::string value) {
    SetSchemaValue(m_ptr, "CFootstepLandedAnimTag", "m_DebugAnimSourceString", false, CUtlString(value.c_str()));
}
std::string GCFootstepLandedAnimTag::GetBoneName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CFootstepLandedAnimTag", "m_BoneName").Get();
}
void GCFootstepLandedAnimTag::SetBoneName(std::string value) {
    SetSchemaValue(m_ptr, "CFootstepLandedAnimTag", "m_BoneName", false, CUtlString(value.c_str()));
}
std::string GCFootstepLandedAnimTag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFootstepLandedAnimTag::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimTagBase GCFootstepLandedAnimTag::GetParent() const {
    GCAnimTagBase value(m_ptr);
    return value;
}
void GCFootstepLandedAnimTag::SetParent(GCAnimTagBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFootstepLandedAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootstepLandedAnimTag>("CFootstepLandedAnimTag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FootstepType", &GCFootstepLandedAnimTag::GetFootstepType, &GCFootstepLandedAnimTag::SetFootstepType)
        .addProperty("OverrideSoundName", &GCFootstepLandedAnimTag::GetOverrideSoundName, &GCFootstepLandedAnimTag::SetOverrideSoundName)
        .addProperty("DebugAnimSourceString", &GCFootstepLandedAnimTag::GetDebugAnimSourceString, &GCFootstepLandedAnimTag::SetDebugAnimSourceString)
        .addProperty("BoneName", &GCFootstepLandedAnimTag::GetBoneName, &GCFootstepLandedAnimTag::SetBoneName)
        .addProperty("Parent", &GCFootstepLandedAnimTag::GetParent, &GCFootstepLandedAnimTag::SetParent)
        .addFunction("ToPtr", &GCFootstepLandedAnimTag::ToPtr)
        .addFunction("IsValid", &GCFootstepLandedAnimTag::IsValid)
        .endClass();
}