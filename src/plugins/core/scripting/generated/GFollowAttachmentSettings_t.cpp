#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFollowAttachmentSettings_t::GFollowAttachmentSettings_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFollowAttachmentSettings_t::GFollowAttachmentSettings_t(void *ptr) {
    m_ptr = ptr;
}
GCAnimAttachment GFollowAttachmentSettings_t::GetAttachment() const {
    GCAnimAttachment value(GetSchemaPtr(m_ptr, "FollowAttachmentSettings_t", "m_attachment"));
    return value;
}
void GFollowAttachmentSettings_t::SetAttachment(GCAnimAttachment value) {
    SetSchemaValue(m_ptr, "FollowAttachmentSettings_t", "m_attachment", true, value);
}
int32_t GFollowAttachmentSettings_t::GetBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "FollowAttachmentSettings_t", "m_boneIndex");
}
void GFollowAttachmentSettings_t::SetBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "FollowAttachmentSettings_t", "m_boneIndex", true, value);
}
bool GFollowAttachmentSettings_t::GetMatchTranslation() const {
    return GetSchemaValue<bool>(m_ptr, "FollowAttachmentSettings_t", "m_bMatchTranslation");
}
void GFollowAttachmentSettings_t::SetMatchTranslation(bool value) {
    SetSchemaValue(m_ptr, "FollowAttachmentSettings_t", "m_bMatchTranslation", true, value);
}
bool GFollowAttachmentSettings_t::GetMatchRotation() const {
    return GetSchemaValue<bool>(m_ptr, "FollowAttachmentSettings_t", "m_bMatchRotation");
}
void GFollowAttachmentSettings_t::SetMatchRotation(bool value) {
    SetSchemaValue(m_ptr, "FollowAttachmentSettings_t", "m_bMatchRotation", true, value);
}
std::string GFollowAttachmentSettings_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFollowAttachmentSettings_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFollowAttachmentSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFollowAttachmentSettings_t>("FollowAttachmentSettings_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Attachment", &GFollowAttachmentSettings_t::GetAttachment, &GFollowAttachmentSettings_t::SetAttachment)
        .addProperty("BoneIndex", &GFollowAttachmentSettings_t::GetBoneIndex, &GFollowAttachmentSettings_t::SetBoneIndex)
        .addProperty("MatchTranslation", &GFollowAttachmentSettings_t::GetMatchTranslation, &GFollowAttachmentSettings_t::SetMatchTranslation)
        .addProperty("MatchRotation", &GFollowAttachmentSettings_t::GetMatchRotation, &GFollowAttachmentSettings_t::SetMatchRotation)
        .addFunction("ToPtr", &GFollowAttachmentSettings_t::ToPtr)
        .addFunction("IsValid", &GFollowAttachmentSettings_t::IsValid)
        .endClass();
}