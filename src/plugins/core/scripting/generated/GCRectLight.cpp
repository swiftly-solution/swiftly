#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRectLight::GCRectLight(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRectLight::GCRectLight(void *ptr) {
    m_ptr = ptr;
}
bool GCRectLight::GetShowLight() const {
    return GetSchemaValue<bool>(m_ptr, "CRectLight", "m_bShowLight");
}
void GCRectLight::SetShowLight(bool value) {
    SetSchemaValue(m_ptr, "CRectLight", "m_bShowLight", false, value);
}
std::string GCRectLight::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRectLight::IsValid() {
    return (m_ptr != nullptr);
}
GCBarnLight GCRectLight::GetParent() const {
    GCBarnLight value(m_ptr);
    return value;
}
void GCRectLight::SetParent(GCBarnLight value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRectLight(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRectLight>("CRectLight")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ShowLight", &GCRectLight::GetShowLight, &GCRectLight::SetShowLight)
        .addProperty("Parent", &GCRectLight::GetParent, &GCRectLight::SetParent)
        .addFunction("ToPtr", &GCRectLight::ToPtr)
        .addFunction("IsValid", &GCRectLight::IsValid)
        .endClass();
}