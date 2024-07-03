#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointWorldText::GCPointWorldText(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointWorldText::GCPointWorldText(void *ptr) {
    m_ptr = ptr;
}
std::string GCPointWorldText::GetMessageText() const {
    return GetSchemaValuePtr<char>(m_ptr, "CPointWorldText", "m_messageText");
}
void GCPointWorldText::SetMessageText(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CPointWorldText", "m_messageText", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 512);
}
std::string GCPointWorldText::GetFontName() const {
    return GetSchemaValuePtr<char>(m_ptr, "CPointWorldText", "m_FontName");
}
void GCPointWorldText::SetFontName(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CPointWorldText", "m_FontName", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 64);
}
bool GCPointWorldText::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CPointWorldText", "m_bEnabled");
}
void GCPointWorldText::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CPointWorldText", "m_bEnabled", false, value);
}
bool GCPointWorldText::GetFullbright() const {
    return GetSchemaValue<bool>(m_ptr, "CPointWorldText", "m_bFullbright");
}
void GCPointWorldText::SetFullbright(bool value) {
    SetSchemaValue(m_ptr, "CPointWorldText", "m_bFullbright", false, value);
}
float GCPointWorldText::GetWorldUnitsPerPx() const {
    return GetSchemaValue<float>(m_ptr, "CPointWorldText", "m_flWorldUnitsPerPx");
}
void GCPointWorldText::SetWorldUnitsPerPx(float value) {
    SetSchemaValue(m_ptr, "CPointWorldText", "m_flWorldUnitsPerPx", false, value);
}
float GCPointWorldText::GetFontSize() const {
    return GetSchemaValue<float>(m_ptr, "CPointWorldText", "m_flFontSize");
}
void GCPointWorldText::SetFontSize(float value) {
    SetSchemaValue(m_ptr, "CPointWorldText", "m_flFontSize", false, value);
}
float GCPointWorldText::GetDepthOffset() const {
    return GetSchemaValue<float>(m_ptr, "CPointWorldText", "m_flDepthOffset");
}
void GCPointWorldText::SetDepthOffset(float value) {
    SetSchemaValue(m_ptr, "CPointWorldText", "m_flDepthOffset", false, value);
}
Color GCPointWorldText::GetColor() const {
    return GetSchemaValue<Color>(m_ptr, "CPointWorldText", "m_Color");
}
void GCPointWorldText::SetColor(Color value) {
    SetSchemaValue(m_ptr, "CPointWorldText", "m_Color", false, value);
}
uint64_t GCPointWorldText::GetJustifyHorizontal() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPointWorldText", "m_nJustifyHorizontal");
}
void GCPointWorldText::SetJustifyHorizontal(uint64_t value) {
    SetSchemaValue(m_ptr, "CPointWorldText", "m_nJustifyHorizontal", false, value);
}
uint64_t GCPointWorldText::GetJustifyVertical() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPointWorldText", "m_nJustifyVertical");
}
void GCPointWorldText::SetJustifyVertical(uint64_t value) {
    SetSchemaValue(m_ptr, "CPointWorldText", "m_nJustifyVertical", false, value);
}
uint64_t GCPointWorldText::GetReorientMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPointWorldText", "m_nReorientMode");
}
void GCPointWorldText::SetReorientMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CPointWorldText", "m_nReorientMode", false, value);
}
std::string GCPointWorldText::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointWorldText::IsValid() {
    return (m_ptr != nullptr);
}
GCModelPointEntity GCPointWorldText::GetParent() const {
    GCModelPointEntity value(m_ptr);
    return value;
}
void GCPointWorldText::SetParent(GCModelPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointWorldText(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointWorldText>("CPointWorldText")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MessageText", &GCPointWorldText::GetMessageText, &GCPointWorldText::SetMessageText)
        .addProperty("FontName", &GCPointWorldText::GetFontName, &GCPointWorldText::SetFontName)
        .addProperty("Enabled", &GCPointWorldText::GetEnabled, &GCPointWorldText::SetEnabled)
        .addProperty("Fullbright", &GCPointWorldText::GetFullbright, &GCPointWorldText::SetFullbright)
        .addProperty("WorldUnitsPerPx", &GCPointWorldText::GetWorldUnitsPerPx, &GCPointWorldText::SetWorldUnitsPerPx)
        .addProperty("FontSize", &GCPointWorldText::GetFontSize, &GCPointWorldText::SetFontSize)
        .addProperty("DepthOffset", &GCPointWorldText::GetDepthOffset, &GCPointWorldText::SetDepthOffset)
        .addProperty("Color", &GCPointWorldText::GetColor, &GCPointWorldText::SetColor)
        .addProperty("JustifyHorizontal", &GCPointWorldText::GetJustifyHorizontal, &GCPointWorldText::SetJustifyHorizontal)
        .addProperty("JustifyVertical", &GCPointWorldText::GetJustifyVertical, &GCPointWorldText::SetJustifyVertical)
        .addProperty("ReorientMode", &GCPointWorldText::GetReorientMode, &GCPointWorldText::SetReorientMode)
        .addProperty("Parent", &GCPointWorldText::GetParent, &GCPointWorldText::SetParent)
        .addFunction("ToPtr", &GCPointWorldText::ToPtr)
        .addFunction("IsValid", &GCPointWorldText::IsValid)
        .endClass();
}