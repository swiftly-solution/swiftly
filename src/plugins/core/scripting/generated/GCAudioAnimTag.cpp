#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAudioAnimTag::GCAudioAnimTag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAudioAnimTag::GCAudioAnimTag(void *ptr) {
    m_ptr = ptr;
}
std::string GCAudioAnimTag::GetClipName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CAudioAnimTag", "m_clipName").Get();
}
void GCAudioAnimTag::SetClipName(std::string value) {
    SetSchemaValue(m_ptr, "CAudioAnimTag", "m_clipName", false, CUtlString(value.c_str()));
}
std::string GCAudioAnimTag::GetAttachmentName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CAudioAnimTag", "m_attachmentName").Get();
}
void GCAudioAnimTag::SetAttachmentName(std::string value) {
    SetSchemaValue(m_ptr, "CAudioAnimTag", "m_attachmentName", false, CUtlString(value.c_str()));
}
float GCAudioAnimTag::GetVolume() const {
    return GetSchemaValue<float>(m_ptr, "CAudioAnimTag", "m_flVolume");
}
void GCAudioAnimTag::SetVolume(float value) {
    SetSchemaValue(m_ptr, "CAudioAnimTag", "m_flVolume", false, value);
}
bool GCAudioAnimTag::GetStopWhenTagEnds() const {
    return GetSchemaValue<bool>(m_ptr, "CAudioAnimTag", "m_bStopWhenTagEnds");
}
void GCAudioAnimTag::SetStopWhenTagEnds(bool value) {
    SetSchemaValue(m_ptr, "CAudioAnimTag", "m_bStopWhenTagEnds", false, value);
}
bool GCAudioAnimTag::GetStopWhenGraphEnds() const {
    return GetSchemaValue<bool>(m_ptr, "CAudioAnimTag", "m_bStopWhenGraphEnds");
}
void GCAudioAnimTag::SetStopWhenGraphEnds(bool value) {
    SetSchemaValue(m_ptr, "CAudioAnimTag", "m_bStopWhenGraphEnds", false, value);
}
bool GCAudioAnimTag::GetPlayOnServer() const {
    return GetSchemaValue<bool>(m_ptr, "CAudioAnimTag", "m_bPlayOnServer");
}
void GCAudioAnimTag::SetPlayOnServer(bool value) {
    SetSchemaValue(m_ptr, "CAudioAnimTag", "m_bPlayOnServer", false, value);
}
bool GCAudioAnimTag::GetPlayOnClient() const {
    return GetSchemaValue<bool>(m_ptr, "CAudioAnimTag", "m_bPlayOnClient");
}
void GCAudioAnimTag::SetPlayOnClient(bool value) {
    SetSchemaValue(m_ptr, "CAudioAnimTag", "m_bPlayOnClient", false, value);
}
std::string GCAudioAnimTag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAudioAnimTag::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimTagBase GCAudioAnimTag::GetParent() const {
    GCAnimTagBase value(m_ptr);
    return value;
}
void GCAudioAnimTag::SetParent(GCAnimTagBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAudioAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAudioAnimTag>("CAudioAnimTag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ClipName", &GCAudioAnimTag::GetClipName, &GCAudioAnimTag::SetClipName)
        .addProperty("AttachmentName", &GCAudioAnimTag::GetAttachmentName, &GCAudioAnimTag::SetAttachmentName)
        .addProperty("Volume", &GCAudioAnimTag::GetVolume, &GCAudioAnimTag::SetVolume)
        .addProperty("StopWhenTagEnds", &GCAudioAnimTag::GetStopWhenTagEnds, &GCAudioAnimTag::SetStopWhenTagEnds)
        .addProperty("StopWhenGraphEnds", &GCAudioAnimTag::GetStopWhenGraphEnds, &GCAudioAnimTag::SetStopWhenGraphEnds)
        .addProperty("PlayOnServer", &GCAudioAnimTag::GetPlayOnServer, &GCAudioAnimTag::SetPlayOnServer)
        .addProperty("PlayOnClient", &GCAudioAnimTag::GetPlayOnClient, &GCAudioAnimTag::SetPlayOnClient)
        .addProperty("Parent", &GCAudioAnimTag::GetParent, &GCAudioAnimTag::SetParent)
        .addFunction("ToPtr", &GCAudioAnimTag::ToPtr)
        .addFunction("IsValid", &GCAudioAnimTag::IsValid)
        .endClass();
}