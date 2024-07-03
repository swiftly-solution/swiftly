#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSeqSeqDescFlag::GCSeqSeqDescFlag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSeqSeqDescFlag::GCSeqSeqDescFlag(void *ptr) {
    m_ptr = ptr;
}
bool GCSeqSeqDescFlag::GetLooping() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bLooping");
}
void GCSeqSeqDescFlag::SetLooping(bool value) {
    SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bLooping", false, value);
}
bool GCSeqSeqDescFlag::GetSnap() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bSnap");
}
void GCSeqSeqDescFlag::SetSnap(bool value) {
    SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bSnap", false, value);
}
bool GCSeqSeqDescFlag::GetAutoplay() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bAutoplay");
}
void GCSeqSeqDescFlag::SetAutoplay(bool value) {
    SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bAutoplay", false, value);
}
bool GCSeqSeqDescFlag::GetPost() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bPost");
}
void GCSeqSeqDescFlag::SetPost(bool value) {
    SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bPost", false, value);
}
bool GCSeqSeqDescFlag::GetHidden() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bHidden");
}
void GCSeqSeqDescFlag::SetHidden(bool value) {
    SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bHidden", false, value);
}
bool GCSeqSeqDescFlag::GetMulti() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bMulti");
}
void GCSeqSeqDescFlag::SetMulti(bool value) {
    SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bMulti", false, value);
}
bool GCSeqSeqDescFlag::GetLegacyDelta() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bLegacyDelta");
}
void GCSeqSeqDescFlag::SetLegacyDelta(bool value) {
    SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bLegacyDelta", false, value);
}
bool GCSeqSeqDescFlag::GetLegacyWorldspace() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bLegacyWorldspace");
}
void GCSeqSeqDescFlag::SetLegacyWorldspace(bool value) {
    SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bLegacyWorldspace", false, value);
}
bool GCSeqSeqDescFlag::GetLegacyCyclepose() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bLegacyCyclepose");
}
void GCSeqSeqDescFlag::SetLegacyCyclepose(bool value) {
    SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bLegacyCyclepose", false, value);
}
bool GCSeqSeqDescFlag::GetLegacyRealtime() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bLegacyRealtime");
}
void GCSeqSeqDescFlag::SetLegacyRealtime(bool value) {
    SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bLegacyRealtime", false, value);
}
bool GCSeqSeqDescFlag::GetModelDoc() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqSeqDescFlag", "m_bModelDoc");
}
void GCSeqSeqDescFlag::SetModelDoc(bool value) {
    SetSchemaValue(m_ptr, "CSeqSeqDescFlag", "m_bModelDoc", false, value);
}
std::string GCSeqSeqDescFlag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSeqSeqDescFlag::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSeqSeqDescFlag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqSeqDescFlag>("CSeqSeqDescFlag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Looping", &GCSeqSeqDescFlag::GetLooping, &GCSeqSeqDescFlag::SetLooping)
        .addProperty("Snap", &GCSeqSeqDescFlag::GetSnap, &GCSeqSeqDescFlag::SetSnap)
        .addProperty("Autoplay", &GCSeqSeqDescFlag::GetAutoplay, &GCSeqSeqDescFlag::SetAutoplay)
        .addProperty("Post", &GCSeqSeqDescFlag::GetPost, &GCSeqSeqDescFlag::SetPost)
        .addProperty("Hidden", &GCSeqSeqDescFlag::GetHidden, &GCSeqSeqDescFlag::SetHidden)
        .addProperty("Multi", &GCSeqSeqDescFlag::GetMulti, &GCSeqSeqDescFlag::SetMulti)
        .addProperty("LegacyDelta", &GCSeqSeqDescFlag::GetLegacyDelta, &GCSeqSeqDescFlag::SetLegacyDelta)
        .addProperty("LegacyWorldspace", &GCSeqSeqDescFlag::GetLegacyWorldspace, &GCSeqSeqDescFlag::SetLegacyWorldspace)
        .addProperty("LegacyCyclepose", &GCSeqSeqDescFlag::GetLegacyCyclepose, &GCSeqSeqDescFlag::SetLegacyCyclepose)
        .addProperty("LegacyRealtime", &GCSeqSeqDescFlag::GetLegacyRealtime, &GCSeqSeqDescFlag::SetLegacyRealtime)
        .addProperty("ModelDoc", &GCSeqSeqDescFlag::GetModelDoc, &GCSeqSeqDescFlag::SetModelDoc)
        .addFunction("ToPtr", &GCSeqSeqDescFlag::ToPtr)
        .addFunction("IsValid", &GCSeqSeqDescFlag::IsValid)
        .endClass();
}