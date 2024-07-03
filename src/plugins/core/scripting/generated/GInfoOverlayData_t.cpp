#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GInfoOverlayData_t::GInfoOverlayData_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GInfoOverlayData_t::GInfoOverlayData_t(void *ptr) {
    m_ptr = ptr;
}
matrix3x4_t GInfoOverlayData_t::GetTransform() const {
    return GetSchemaValue<matrix3x4_t>(m_ptr, "InfoOverlayData_t", "m_transform");
}
void GInfoOverlayData_t::SetTransform(matrix3x4_t value) {
    SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_transform", true, value);
}
float GInfoOverlayData_t::GetWidth() const {
    return GetSchemaValue<float>(m_ptr, "InfoOverlayData_t", "m_flWidth");
}
void GInfoOverlayData_t::SetWidth(float value) {
    SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_flWidth", true, value);
}
float GInfoOverlayData_t::GetHeight() const {
    return GetSchemaValue<float>(m_ptr, "InfoOverlayData_t", "m_flHeight");
}
void GInfoOverlayData_t::SetHeight(float value) {
    SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_flHeight", true, value);
}
float GInfoOverlayData_t::GetDepth() const {
    return GetSchemaValue<float>(m_ptr, "InfoOverlayData_t", "m_flDepth");
}
void GInfoOverlayData_t::SetDepth(float value) {
    SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_flDepth", true, value);
}
Vector2D GInfoOverlayData_t::GetUVStart() const {
    return GetSchemaValue<Vector2D>(m_ptr, "InfoOverlayData_t", "m_vUVStart");
}
void GInfoOverlayData_t::SetUVStart(Vector2D value) {
    SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_vUVStart", true, value);
}
Vector2D GInfoOverlayData_t::GetUVEnd() const {
    return GetSchemaValue<Vector2D>(m_ptr, "InfoOverlayData_t", "m_vUVEnd");
}
void GInfoOverlayData_t::SetUVEnd(Vector2D value) {
    SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_vUVEnd", true, value);
}
int32_t GInfoOverlayData_t::GetRenderOrder() const {
    return GetSchemaValue<int32_t>(m_ptr, "InfoOverlayData_t", "m_nRenderOrder");
}
void GInfoOverlayData_t::SetRenderOrder(int32_t value) {
    SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_nRenderOrder", true, value);
}
Vector4D GInfoOverlayData_t::GetTintColor() const {
    return GetSchemaValue<Vector4D>(m_ptr, "InfoOverlayData_t", "m_vTintColor");
}
void GInfoOverlayData_t::SetTintColor(Vector4D value) {
    SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_vTintColor", true, value);
}
int32_t GInfoOverlayData_t::GetSequenceOverride() const {
    return GetSchemaValue<int32_t>(m_ptr, "InfoOverlayData_t", "m_nSequenceOverride");
}
void GInfoOverlayData_t::SetSequenceOverride(int32_t value) {
    SetSchemaValue(m_ptr, "InfoOverlayData_t", "m_nSequenceOverride", true, value);
}
std::string GInfoOverlayData_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GInfoOverlayData_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassInfoOverlayData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GInfoOverlayData_t>("InfoOverlayData_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Transform", &GInfoOverlayData_t::GetTransform, &GInfoOverlayData_t::SetTransform)
        .addProperty("Width", &GInfoOverlayData_t::GetWidth, &GInfoOverlayData_t::SetWidth)
        .addProperty("Height", &GInfoOverlayData_t::GetHeight, &GInfoOverlayData_t::SetHeight)
        .addProperty("Depth", &GInfoOverlayData_t::GetDepth, &GInfoOverlayData_t::SetDepth)
        .addProperty("UVStart", &GInfoOverlayData_t::GetUVStart, &GInfoOverlayData_t::SetUVStart)
        .addProperty("UVEnd", &GInfoOverlayData_t::GetUVEnd, &GInfoOverlayData_t::SetUVEnd)
        .addProperty("RenderOrder", &GInfoOverlayData_t::GetRenderOrder, &GInfoOverlayData_t::SetRenderOrder)
        .addProperty("TintColor", &GInfoOverlayData_t::GetTintColor, &GInfoOverlayData_t::SetTintColor)
        .addProperty("SequenceOverride", &GInfoOverlayData_t::GetSequenceOverride, &GInfoOverlayData_t::SetSequenceOverride)
        .addFunction("ToPtr", &GInfoOverlayData_t::ToPtr)
        .addFunction("IsValid", &GInfoOverlayData_t::IsValid)
        .endClass();
}