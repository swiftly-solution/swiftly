#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSeqAutoLayer::GCSeqAutoLayer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSeqAutoLayer::GCSeqAutoLayer(void *ptr) {
    m_ptr = ptr;
}
int16_t GCSeqAutoLayer::GetLocalReference() const {
    return GetSchemaValue<int16_t>(m_ptr, "CSeqAutoLayer", "m_nLocalReference");
}
void GCSeqAutoLayer::SetLocalReference(int16_t value) {
    SetSchemaValue(m_ptr, "CSeqAutoLayer", "m_nLocalReference", false, value);
}
int16_t GCSeqAutoLayer::GetLocalPose() const {
    return GetSchemaValue<int16_t>(m_ptr, "CSeqAutoLayer", "m_nLocalPose");
}
void GCSeqAutoLayer::SetLocalPose(int16_t value) {
    SetSchemaValue(m_ptr, "CSeqAutoLayer", "m_nLocalPose", false, value);
}
GCSeqAutoLayerFlag GCSeqAutoLayer::GetFlags() const {
    GCSeqAutoLayerFlag value(GetSchemaPtr(m_ptr, "CSeqAutoLayer", "m_flags"));
    return value;
}
void GCSeqAutoLayer::SetFlags(GCSeqAutoLayerFlag value) {
    SetSchemaValue(m_ptr, "CSeqAutoLayer", "m_flags", false, value);
}
float GCSeqAutoLayer::GetStart() const {
    return GetSchemaValue<float>(m_ptr, "CSeqAutoLayer", "m_start");
}
void GCSeqAutoLayer::SetStart(float value) {
    SetSchemaValue(m_ptr, "CSeqAutoLayer", "m_start", false, value);
}
float GCSeqAutoLayer::GetPeak() const {
    return GetSchemaValue<float>(m_ptr, "CSeqAutoLayer", "m_peak");
}
void GCSeqAutoLayer::SetPeak(float value) {
    SetSchemaValue(m_ptr, "CSeqAutoLayer", "m_peak", false, value);
}
float GCSeqAutoLayer::GetTail() const {
    return GetSchemaValue<float>(m_ptr, "CSeqAutoLayer", "m_tail");
}
void GCSeqAutoLayer::SetTail(float value) {
    SetSchemaValue(m_ptr, "CSeqAutoLayer", "m_tail", false, value);
}
float GCSeqAutoLayer::GetEnd() const {
    return GetSchemaValue<float>(m_ptr, "CSeqAutoLayer", "m_end");
}
void GCSeqAutoLayer::SetEnd(float value) {
    SetSchemaValue(m_ptr, "CSeqAutoLayer", "m_end", false, value);
}
std::string GCSeqAutoLayer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSeqAutoLayer::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSeqAutoLayer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqAutoLayer>("CSeqAutoLayer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LocalReference", &GCSeqAutoLayer::GetLocalReference, &GCSeqAutoLayer::SetLocalReference)
        .addProperty("LocalPose", &GCSeqAutoLayer::GetLocalPose, &GCSeqAutoLayer::SetLocalPose)
        .addProperty("Flags", &GCSeqAutoLayer::GetFlags, &GCSeqAutoLayer::SetFlags)
        .addProperty("Start", &GCSeqAutoLayer::GetStart, &GCSeqAutoLayer::SetStart)
        .addProperty("Peak", &GCSeqAutoLayer::GetPeak, &GCSeqAutoLayer::SetPeak)
        .addProperty("Tail", &GCSeqAutoLayer::GetTail, &GCSeqAutoLayer::SetTail)
        .addProperty("End", &GCSeqAutoLayer::GetEnd, &GCSeqAutoLayer::SetEnd)
        .addFunction("ToPtr", &GCSeqAutoLayer::ToPtr)
        .addFunction("IsValid", &GCSeqAutoLayer::IsValid)
        .endClass();
}