#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Gfogplayerparams_t::Gfogplayerparams_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Gfogplayerparams_t::Gfogplayerparams_t(void *ptr) {
    m_ptr = ptr;
}
GCFogController Gfogplayerparams_t::GetCtrl() const {
    GCFogController value(*GetSchemaValuePtr<void*>(m_ptr, "fogplayerparams_t", "m_hCtrl"));
    return value;
}
void Gfogplayerparams_t::SetCtrl(GCFogController* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Ctrl' is not possible.\n");
}
float Gfogplayerparams_t::GetTransitionTime() const {
    return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flTransitionTime");
}
void Gfogplayerparams_t::SetTransitionTime(float value) {
    SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flTransitionTime", true, value);
}
Color Gfogplayerparams_t::GetOldColor() const {
    return GetSchemaValue<Color>(m_ptr, "fogplayerparams_t", "m_OldColor");
}
void Gfogplayerparams_t::SetOldColor(Color value) {
    SetSchemaValue(m_ptr, "fogplayerparams_t", "m_OldColor", true, value);
}
float Gfogplayerparams_t::GetOldStart() const {
    return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flOldStart");
}
void Gfogplayerparams_t::SetOldStart(float value) {
    SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flOldStart", true, value);
}
float Gfogplayerparams_t::GetOldEnd() const {
    return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flOldEnd");
}
void Gfogplayerparams_t::SetOldEnd(float value) {
    SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flOldEnd", true, value);
}
float Gfogplayerparams_t::GetOldMaxDensity() const {
    return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flOldMaxDensity");
}
void Gfogplayerparams_t::SetOldMaxDensity(float value) {
    SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flOldMaxDensity", true, value);
}
float Gfogplayerparams_t::GetOldHDRColorScale() const {
    return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flOldHDRColorScale");
}
void Gfogplayerparams_t::SetOldHDRColorScale(float value) {
    SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flOldHDRColorScale", true, value);
}
float Gfogplayerparams_t::GetOldFarZ() const {
    return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flOldFarZ");
}
void Gfogplayerparams_t::SetOldFarZ(float value) {
    SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flOldFarZ", true, value);
}
Color Gfogplayerparams_t::GetNewColor() const {
    return GetSchemaValue<Color>(m_ptr, "fogplayerparams_t", "m_NewColor");
}
void Gfogplayerparams_t::SetNewColor(Color value) {
    SetSchemaValue(m_ptr, "fogplayerparams_t", "m_NewColor", true, value);
}
float Gfogplayerparams_t::GetNewStart() const {
    return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flNewStart");
}
void Gfogplayerparams_t::SetNewStart(float value) {
    SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flNewStart", true, value);
}
float Gfogplayerparams_t::GetNewEnd() const {
    return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flNewEnd");
}
void Gfogplayerparams_t::SetNewEnd(float value) {
    SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flNewEnd", true, value);
}
float Gfogplayerparams_t::GetNewMaxDensity() const {
    return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flNewMaxDensity");
}
void Gfogplayerparams_t::SetNewMaxDensity(float value) {
    SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flNewMaxDensity", true, value);
}
float Gfogplayerparams_t::GetNewHDRColorScale() const {
    return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flNewHDRColorScale");
}
void Gfogplayerparams_t::SetNewHDRColorScale(float value) {
    SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flNewHDRColorScale", true, value);
}
float Gfogplayerparams_t::GetNewFarZ() const {
    return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flNewFarZ");
}
void Gfogplayerparams_t::SetNewFarZ(float value) {
    SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flNewFarZ", true, value);
}
std::string Gfogplayerparams_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Gfogplayerparams_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassfogplayerparams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gfogplayerparams_t>("fogplayerparams_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Ctrl", &Gfogplayerparams_t::GetCtrl, &Gfogplayerparams_t::SetCtrl)
        .addProperty("TransitionTime", &Gfogplayerparams_t::GetTransitionTime, &Gfogplayerparams_t::SetTransitionTime)
        .addProperty("OldColor", &Gfogplayerparams_t::GetOldColor, &Gfogplayerparams_t::SetOldColor)
        .addProperty("OldStart", &Gfogplayerparams_t::GetOldStart, &Gfogplayerparams_t::SetOldStart)
        .addProperty("OldEnd", &Gfogplayerparams_t::GetOldEnd, &Gfogplayerparams_t::SetOldEnd)
        .addProperty("OldMaxDensity", &Gfogplayerparams_t::GetOldMaxDensity, &Gfogplayerparams_t::SetOldMaxDensity)
        .addProperty("OldHDRColorScale", &Gfogplayerparams_t::GetOldHDRColorScale, &Gfogplayerparams_t::SetOldHDRColorScale)
        .addProperty("OldFarZ", &Gfogplayerparams_t::GetOldFarZ, &Gfogplayerparams_t::SetOldFarZ)
        .addProperty("NewColor", &Gfogplayerparams_t::GetNewColor, &Gfogplayerparams_t::SetNewColor)
        .addProperty("NewStart", &Gfogplayerparams_t::GetNewStart, &Gfogplayerparams_t::SetNewStart)
        .addProperty("NewEnd", &Gfogplayerparams_t::GetNewEnd, &Gfogplayerparams_t::SetNewEnd)
        .addProperty("NewMaxDensity", &Gfogplayerparams_t::GetNewMaxDensity, &Gfogplayerparams_t::SetNewMaxDensity)
        .addProperty("NewHDRColorScale", &Gfogplayerparams_t::GetNewHDRColorScale, &Gfogplayerparams_t::SetNewHDRColorScale)
        .addProperty("NewFarZ", &Gfogplayerparams_t::GetNewFarZ, &Gfogplayerparams_t::SetNewFarZ)
        .addFunction("ToPtr", &Gfogplayerparams_t::ToPtr)
        .addFunction("IsValid", &Gfogplayerparams_t::IsValid)
        .endClass();
}