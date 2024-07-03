#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSun::GCSun(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSun::GCSun(void *ptr) {
    m_ptr = ptr;
}
Vector GCSun::GetDirection() const {
    return GetSchemaValue<Vector>(m_ptr, "CSun", "m_vDirection");
}
void GCSun::SetDirection(Vector value) {
    SetSchemaValue(m_ptr, "CSun", "m_vDirection", false, value);
}
Color GCSun::GetOverlay() const {
    return GetSchemaValue<Color>(m_ptr, "CSun", "m_clrOverlay");
}
void GCSun::SetOverlay(Color value) {
    SetSchemaValue(m_ptr, "CSun", "m_clrOverlay", false, value);
}
std::string GCSun::GetEffectName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSun", "m_iszEffectName").String();
}
void GCSun::SetEffectName(std::string value) {
    SetSchemaValue(m_ptr, "CSun", "m_iszEffectName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSun::GetSSEffectName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSun", "m_iszSSEffectName").String();
}
void GCSun::SetSSEffectName(std::string value) {
    SetSchemaValue(m_ptr, "CSun", "m_iszSSEffectName", false, CUtlSymbolLarge(value.c_str()));
}
bool GCSun::GetOn() const {
    return GetSchemaValue<bool>(m_ptr, "CSun", "m_bOn");
}
void GCSun::SetOn(bool value) {
    SetSchemaValue(m_ptr, "CSun", "m_bOn", false, value);
}
bool GCSun::GetBmaxColor() const {
    return GetSchemaValue<bool>(m_ptr, "CSun", "m_bmaxColor");
}
void GCSun::SetBmaxColor(bool value) {
    SetSchemaValue(m_ptr, "CSun", "m_bmaxColor", false, value);
}
float GCSun::GetSize() const {
    return GetSchemaValue<float>(m_ptr, "CSun", "m_flSize");
}
void GCSun::SetSize(float value) {
    SetSchemaValue(m_ptr, "CSun", "m_flSize", false, value);
}
float GCSun::GetRotation() const {
    return GetSchemaValue<float>(m_ptr, "CSun", "m_flRotation");
}
void GCSun::SetRotation(float value) {
    SetSchemaValue(m_ptr, "CSun", "m_flRotation", false, value);
}
float GCSun::GetHazeScale() const {
    return GetSchemaValue<float>(m_ptr, "CSun", "m_flHazeScale");
}
void GCSun::SetHazeScale(float value) {
    SetSchemaValue(m_ptr, "CSun", "m_flHazeScale", false, value);
}
float GCSun::GetAlphaHaze() const {
    return GetSchemaValue<float>(m_ptr, "CSun", "m_flAlphaHaze");
}
void GCSun::SetAlphaHaze(float value) {
    SetSchemaValue(m_ptr, "CSun", "m_flAlphaHaze", false, value);
}
float GCSun::GetAlphaHdr() const {
    return GetSchemaValue<float>(m_ptr, "CSun", "m_flAlphaHdr");
}
void GCSun::SetAlphaHdr(float value) {
    SetSchemaValue(m_ptr, "CSun", "m_flAlphaHdr", false, value);
}
float GCSun::GetAlphaScale() const {
    return GetSchemaValue<float>(m_ptr, "CSun", "m_flAlphaScale");
}
void GCSun::SetAlphaScale(float value) {
    SetSchemaValue(m_ptr, "CSun", "m_flAlphaScale", false, value);
}
float GCSun::GetHDRColorScale() const {
    return GetSchemaValue<float>(m_ptr, "CSun", "m_flHDRColorScale");
}
void GCSun::SetHDRColorScale(float value) {
    SetSchemaValue(m_ptr, "CSun", "m_flHDRColorScale", false, value);
}
float GCSun::GetFarZScale() const {
    return GetSchemaValue<float>(m_ptr, "CSun", "m_flFarZScale");
}
void GCSun::SetFarZScale(float value) {
    SetSchemaValue(m_ptr, "CSun", "m_flFarZScale", false, value);
}
std::string GCSun::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSun::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCSun::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCSun::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSun(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSun>("CSun")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Direction", &GCSun::GetDirection, &GCSun::SetDirection)
        .addProperty("Overlay", &GCSun::GetOverlay, &GCSun::SetOverlay)
        .addProperty("EffectName", &GCSun::GetEffectName, &GCSun::SetEffectName)
        .addProperty("SSEffectName", &GCSun::GetSSEffectName, &GCSun::SetSSEffectName)
        .addProperty("On", &GCSun::GetOn, &GCSun::SetOn)
        .addProperty("BmaxColor", &GCSun::GetBmaxColor, &GCSun::SetBmaxColor)
        .addProperty("Size", &GCSun::GetSize, &GCSun::SetSize)
        .addProperty("Rotation", &GCSun::GetRotation, &GCSun::SetRotation)
        .addProperty("HazeScale", &GCSun::GetHazeScale, &GCSun::SetHazeScale)
        .addProperty("AlphaHaze", &GCSun::GetAlphaHaze, &GCSun::SetAlphaHaze)
        .addProperty("AlphaHdr", &GCSun::GetAlphaHdr, &GCSun::SetAlphaHdr)
        .addProperty("AlphaScale", &GCSun::GetAlphaScale, &GCSun::SetAlphaScale)
        .addProperty("HDRColorScale", &GCSun::GetHDRColorScale, &GCSun::SetHDRColorScale)
        .addProperty("FarZScale", &GCSun::GetFarZScale, &GCSun::SetFarZScale)
        .addProperty("Parent", &GCSun::GetParent, &GCSun::SetParent)
        .addFunction("ToPtr", &GCSun::ToPtr)
        .addFunction("IsValid", &GCSun::IsValid)
        .endClass();
}