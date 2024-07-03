#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoDynamicShadowHint::GCInfoDynamicShadowHint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoDynamicShadowHint::GCInfoDynamicShadowHint(void *ptr) {
    m_ptr = ptr;
}
bool GCInfoDynamicShadowHint::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CInfoDynamicShadowHint", "m_bDisabled");
}
void GCInfoDynamicShadowHint::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CInfoDynamicShadowHint", "m_bDisabled", false, value);
}
float GCInfoDynamicShadowHint::GetRange() const {
    return GetSchemaValue<float>(m_ptr, "CInfoDynamicShadowHint", "m_flRange");
}
void GCInfoDynamicShadowHint::SetRange(float value) {
    SetSchemaValue(m_ptr, "CInfoDynamicShadowHint", "m_flRange", false, value);
}
int32_t GCInfoDynamicShadowHint::GetImportance() const {
    return GetSchemaValue<int32_t>(m_ptr, "CInfoDynamicShadowHint", "m_nImportance");
}
void GCInfoDynamicShadowHint::SetImportance(int32_t value) {
    SetSchemaValue(m_ptr, "CInfoDynamicShadowHint", "m_nImportance", false, value);
}
int32_t GCInfoDynamicShadowHint::GetLightChoice() const {
    return GetSchemaValue<int32_t>(m_ptr, "CInfoDynamicShadowHint", "m_nLightChoice");
}
void GCInfoDynamicShadowHint::SetLightChoice(int32_t value) {
    SetSchemaValue(m_ptr, "CInfoDynamicShadowHint", "m_nLightChoice", false, value);
}
GCBaseEntity GCInfoDynamicShadowHint::GetLight() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CInfoDynamicShadowHint", "m_hLight"));
    return value;
}
void GCInfoDynamicShadowHint::SetLight(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Light' is not possible.\n");
}
std::string GCInfoDynamicShadowHint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoDynamicShadowHint::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCInfoDynamicShadowHint::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCInfoDynamicShadowHint::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoDynamicShadowHint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoDynamicShadowHint>("CInfoDynamicShadowHint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disabled", &GCInfoDynamicShadowHint::GetDisabled, &GCInfoDynamicShadowHint::SetDisabled)
        .addProperty("Range", &GCInfoDynamicShadowHint::GetRange, &GCInfoDynamicShadowHint::SetRange)
        .addProperty("Importance", &GCInfoDynamicShadowHint::GetImportance, &GCInfoDynamicShadowHint::SetImportance)
        .addProperty("LightChoice", &GCInfoDynamicShadowHint::GetLightChoice, &GCInfoDynamicShadowHint::SetLightChoice)
        .addProperty("Light", &GCInfoDynamicShadowHint::GetLight, &GCInfoDynamicShadowHint::SetLight)
        .addProperty("Parent", &GCInfoDynamicShadowHint::GetParent, &GCInfoDynamicShadowHint::SetParent)
        .addFunction("ToPtr", &GCInfoDynamicShadowHint::ToPtr)
        .addFunction("IsValid", &GCInfoDynamicShadowHint::IsValid)
        .endClass();
}