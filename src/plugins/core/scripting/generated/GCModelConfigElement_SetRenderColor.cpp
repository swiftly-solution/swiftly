#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCModelConfigElement_SetRenderColor::GCModelConfigElement_SetRenderColor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCModelConfigElement_SetRenderColor::GCModelConfigElement_SetRenderColor(void *ptr) {
    m_ptr = ptr;
}
Color GCModelConfigElement_SetRenderColor::GetColor() const {
    return GetSchemaValue<Color>(m_ptr, "CModelConfigElement_SetRenderColor", "m_Color");
}
void GCModelConfigElement_SetRenderColor::SetColor(Color value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_SetRenderColor", "m_Color", false, value);
}
std::string GCModelConfigElement_SetRenderColor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCModelConfigElement_SetRenderColor::IsValid() {
    return (m_ptr != nullptr);
}
GCModelConfigElement GCModelConfigElement_SetRenderColor::GetParent() const {
    GCModelConfigElement value(m_ptr);
    return value;
}
void GCModelConfigElement_SetRenderColor::SetParent(GCModelConfigElement value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCModelConfigElement_SetRenderColor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_SetRenderColor>("CModelConfigElement_SetRenderColor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Color", &GCModelConfigElement_SetRenderColor::GetColor, &GCModelConfigElement_SetRenderColor::SetColor)
        .addProperty("Parent", &GCModelConfigElement_SetRenderColor::GetParent, &GCModelConfigElement_SetRenderColor::SetParent)
        .addFunction("ToPtr", &GCModelConfigElement_SetRenderColor::ToPtr)
        .addFunction("IsValid", &GCModelConfigElement_SetRenderColor::IsValid)
        .endClass();
}