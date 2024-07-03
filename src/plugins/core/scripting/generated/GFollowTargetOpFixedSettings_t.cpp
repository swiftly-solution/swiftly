#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFollowTargetOpFixedSettings_t::GFollowTargetOpFixedSettings_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFollowTargetOpFixedSettings_t::GFollowTargetOpFixedSettings_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GFollowTargetOpFixedSettings_t::GetBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "FollowTargetOpFixedSettings_t", "m_boneIndex");
}
void GFollowTargetOpFixedSettings_t::SetBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "FollowTargetOpFixedSettings_t", "m_boneIndex", true, value);
}
bool GFollowTargetOpFixedSettings_t::GetBoneTarget() const {
    return GetSchemaValue<bool>(m_ptr, "FollowTargetOpFixedSettings_t", "m_bBoneTarget");
}
void GFollowTargetOpFixedSettings_t::SetBoneTarget(bool value) {
    SetSchemaValue(m_ptr, "FollowTargetOpFixedSettings_t", "m_bBoneTarget", true, value);
}
int32_t GFollowTargetOpFixedSettings_t::GetBoneTargetIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "FollowTargetOpFixedSettings_t", "m_boneTargetIndex");
}
void GFollowTargetOpFixedSettings_t::SetBoneTargetIndex(int32_t value) {
    SetSchemaValue(m_ptr, "FollowTargetOpFixedSettings_t", "m_boneTargetIndex", true, value);
}
bool GFollowTargetOpFixedSettings_t::GetWorldCoodinateTarget() const {
    return GetSchemaValue<bool>(m_ptr, "FollowTargetOpFixedSettings_t", "m_bWorldCoodinateTarget");
}
void GFollowTargetOpFixedSettings_t::SetWorldCoodinateTarget(bool value) {
    SetSchemaValue(m_ptr, "FollowTargetOpFixedSettings_t", "m_bWorldCoodinateTarget", true, value);
}
bool GFollowTargetOpFixedSettings_t::GetMatchTargetOrientation() const {
    return GetSchemaValue<bool>(m_ptr, "FollowTargetOpFixedSettings_t", "m_bMatchTargetOrientation");
}
void GFollowTargetOpFixedSettings_t::SetMatchTargetOrientation(bool value) {
    SetSchemaValue(m_ptr, "FollowTargetOpFixedSettings_t", "m_bMatchTargetOrientation", true, value);
}
std::string GFollowTargetOpFixedSettings_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFollowTargetOpFixedSettings_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFollowTargetOpFixedSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFollowTargetOpFixedSettings_t>("FollowTargetOpFixedSettings_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BoneIndex", &GFollowTargetOpFixedSettings_t::GetBoneIndex, &GFollowTargetOpFixedSettings_t::SetBoneIndex)
        .addProperty("BoneTarget", &GFollowTargetOpFixedSettings_t::GetBoneTarget, &GFollowTargetOpFixedSettings_t::SetBoneTarget)
        .addProperty("BoneTargetIndex", &GFollowTargetOpFixedSettings_t::GetBoneTargetIndex, &GFollowTargetOpFixedSettings_t::SetBoneTargetIndex)
        .addProperty("WorldCoodinateTarget", &GFollowTargetOpFixedSettings_t::GetWorldCoodinateTarget, &GFollowTargetOpFixedSettings_t::SetWorldCoodinateTarget)
        .addProperty("MatchTargetOrientation", &GFollowTargetOpFixedSettings_t::GetMatchTargetOrientation, &GFollowTargetOpFixedSettings_t::SetMatchTargetOrientation)
        .addFunction("ToPtr", &GFollowTargetOpFixedSettings_t::ToPtr)
        .addFunction("IsValid", &GFollowTargetOpFixedSettings_t::IsValid)
        .endClass();
}