#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvFade::GCEnvFade(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvFade::GCEnvFade(void *ptr) {
    m_ptr = ptr;
}
Color GCEnvFade::GetFadeColor() const {
    return GetSchemaValue<Color>(m_ptr, "CEnvFade", "m_fadeColor");
}
void GCEnvFade::SetFadeColor(Color value) {
    SetSchemaValue(m_ptr, "CEnvFade", "m_fadeColor", false, value);
}
float GCEnvFade::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "CEnvFade", "m_Duration");
}
void GCEnvFade::SetDuration(float value) {
    SetSchemaValue(m_ptr, "CEnvFade", "m_Duration", false, value);
}
float GCEnvFade::GetHoldDuration() const {
    return GetSchemaValue<float>(m_ptr, "CEnvFade", "m_HoldDuration");
}
void GCEnvFade::SetHoldDuration(float value) {
    SetSchemaValue(m_ptr, "CEnvFade", "m_HoldDuration", false, value);
}
GCEntityIOOutput GCEnvFade::GetOnBeginFade() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CEnvFade", "m_OnBeginFade"));
    return value;
}
void GCEnvFade::SetOnBeginFade(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CEnvFade", "m_OnBeginFade", false, value);
}
std::string GCEnvFade::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvFade::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCEnvFade::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCEnvFade::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvFade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvFade>("CEnvFade")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FadeColor", &GCEnvFade::GetFadeColor, &GCEnvFade::SetFadeColor)
        .addProperty("Duration", &GCEnvFade::GetDuration, &GCEnvFade::SetDuration)
        .addProperty("HoldDuration", &GCEnvFade::GetHoldDuration, &GCEnvFade::SetHoldDuration)
        .addProperty("OnBeginFade", &GCEnvFade::GetOnBeginFade, &GCEnvFade::SetOnBeginFade)
        .addProperty("Parent", &GCEnvFade::GetParent, &GCEnvFade::SetParent)
        .addFunction("ToPtr", &GCEnvFade::ToPtr)
        .addFunction("IsValid", &GCEnvFade::IsValid)
        .endClass();
}