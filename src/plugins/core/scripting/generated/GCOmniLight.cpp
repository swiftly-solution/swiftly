#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCOmniLight::GCOmniLight(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCOmniLight::GCOmniLight(void *ptr) {
    m_ptr = ptr;
}
float GCOmniLight::GetInnerAngle() const {
    return GetSchemaValue<float>(m_ptr, "COmniLight", "m_flInnerAngle");
}
void GCOmniLight::SetInnerAngle(float value) {
    SetSchemaValue(m_ptr, "COmniLight", "m_flInnerAngle", false, value);
}
float GCOmniLight::GetOuterAngle() const {
    return GetSchemaValue<float>(m_ptr, "COmniLight", "m_flOuterAngle");
}
void GCOmniLight::SetOuterAngle(float value) {
    SetSchemaValue(m_ptr, "COmniLight", "m_flOuterAngle", false, value);
}
bool GCOmniLight::GetShowLight() const {
    return GetSchemaValue<bool>(m_ptr, "COmniLight", "m_bShowLight");
}
void GCOmniLight::SetShowLight(bool value) {
    SetSchemaValue(m_ptr, "COmniLight", "m_bShowLight", false, value);
}
std::string GCOmniLight::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCOmniLight::IsValid() {
    return (m_ptr != nullptr);
}
GCBarnLight GCOmniLight::GetParent() const {
    GCBarnLight value(m_ptr);
    return value;
}
void GCOmniLight::SetParent(GCBarnLight value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCOmniLight(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCOmniLight>("COmniLight")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InnerAngle", &GCOmniLight::GetInnerAngle, &GCOmniLight::SetInnerAngle)
        .addProperty("OuterAngle", &GCOmniLight::GetOuterAngle, &GCOmniLight::SetOuterAngle)
        .addProperty("ShowLight", &GCOmniLight::GetShowLight, &GCOmniLight::SetShowLight)
        .addProperty("Parent", &GCOmniLight::GetParent, &GCOmniLight::SetParent)
        .addFunction("ToPtr", &GCOmniLight::ToPtr)
        .addFunction("IsValid", &GCOmniLight::IsValid)
        .endClass();
}