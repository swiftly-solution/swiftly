#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSeqAutoLayerFlag::GCSeqAutoLayerFlag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSeqAutoLayerFlag::GCSeqAutoLayerFlag(void *ptr) {
    m_ptr = ptr;
}
bool GCSeqAutoLayerFlag::GetPost() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqAutoLayerFlag", "m_bPost");
}
void GCSeqAutoLayerFlag::SetPost(bool value) {
    SetSchemaValue(m_ptr, "CSeqAutoLayerFlag", "m_bPost", false, value);
}
bool GCSeqAutoLayerFlag::GetSpline() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqAutoLayerFlag", "m_bSpline");
}
void GCSeqAutoLayerFlag::SetSpline(bool value) {
    SetSchemaValue(m_ptr, "CSeqAutoLayerFlag", "m_bSpline", false, value);
}
bool GCSeqAutoLayerFlag::GetXFade() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqAutoLayerFlag", "m_bXFade");
}
void GCSeqAutoLayerFlag::SetXFade(bool value) {
    SetSchemaValue(m_ptr, "CSeqAutoLayerFlag", "m_bXFade", false, value);
}
bool GCSeqAutoLayerFlag::GetNoBlend() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqAutoLayerFlag", "m_bNoBlend");
}
void GCSeqAutoLayerFlag::SetNoBlend(bool value) {
    SetSchemaValue(m_ptr, "CSeqAutoLayerFlag", "m_bNoBlend", false, value);
}
bool GCSeqAutoLayerFlag::GetLocal() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqAutoLayerFlag", "m_bLocal");
}
void GCSeqAutoLayerFlag::SetLocal(bool value) {
    SetSchemaValue(m_ptr, "CSeqAutoLayerFlag", "m_bLocal", false, value);
}
bool GCSeqAutoLayerFlag::GetPose() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqAutoLayerFlag", "m_bPose");
}
void GCSeqAutoLayerFlag::SetPose(bool value) {
    SetSchemaValue(m_ptr, "CSeqAutoLayerFlag", "m_bPose", false, value);
}
bool GCSeqAutoLayerFlag::GetFetchFrame() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqAutoLayerFlag", "m_bFetchFrame");
}
void GCSeqAutoLayerFlag::SetFetchFrame(bool value) {
    SetSchemaValue(m_ptr, "CSeqAutoLayerFlag", "m_bFetchFrame", false, value);
}
bool GCSeqAutoLayerFlag::GetSubtract() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqAutoLayerFlag", "m_bSubtract");
}
void GCSeqAutoLayerFlag::SetSubtract(bool value) {
    SetSchemaValue(m_ptr, "CSeqAutoLayerFlag", "m_bSubtract", false, value);
}
std::string GCSeqAutoLayerFlag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSeqAutoLayerFlag::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSeqAutoLayerFlag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqAutoLayerFlag>("CSeqAutoLayerFlag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Post", &GCSeqAutoLayerFlag::GetPost, &GCSeqAutoLayerFlag::SetPost)
        .addProperty("Spline", &GCSeqAutoLayerFlag::GetSpline, &GCSeqAutoLayerFlag::SetSpline)
        .addProperty("XFade", &GCSeqAutoLayerFlag::GetXFade, &GCSeqAutoLayerFlag::SetXFade)
        .addProperty("NoBlend", &GCSeqAutoLayerFlag::GetNoBlend, &GCSeqAutoLayerFlag::SetNoBlend)
        .addProperty("Local", &GCSeqAutoLayerFlag::GetLocal, &GCSeqAutoLayerFlag::SetLocal)
        .addProperty("Pose", &GCSeqAutoLayerFlag::GetPose, &GCSeqAutoLayerFlag::SetPose)
        .addProperty("FetchFrame", &GCSeqAutoLayerFlag::GetFetchFrame, &GCSeqAutoLayerFlag::SetFetchFrame)
        .addProperty("Subtract", &GCSeqAutoLayerFlag::GetSubtract, &GCSeqAutoLayerFlag::SetSubtract)
        .addFunction("ToPtr", &GCSeqAutoLayerFlag::ToPtr)
        .addFunction("IsValid", &GCSeqAutoLayerFlag::IsValid)
        .endClass();
}