#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCScriptComponent::GCScriptComponent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCScriptComponent::GCScriptComponent(void *ptr) {
    m_ptr = ptr;
}
std::string GCScriptComponent::GetScriptClassName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptComponent", "m_scriptClassName").String();
}
void GCScriptComponent::SetScriptClassName(std::string value) {
    SetSchemaValue(m_ptr, "CScriptComponent", "m_scriptClassName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCScriptComponent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCScriptComponent::IsValid() {
    return (m_ptr != nullptr);
}
GCEntityComponent GCScriptComponent::GetParent() const {
    GCEntityComponent value(m_ptr);
    return value;
}
void GCScriptComponent::SetParent(GCEntityComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCScriptComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptComponent>("CScriptComponent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ScriptClassName", &GCScriptComponent::GetScriptClassName, &GCScriptComponent::SetScriptClassName)
        .addProperty("Parent", &GCScriptComponent::GetParent, &GCScriptComponent::SetParent)
        .addFunction("ToPtr", &GCScriptComponent::ToPtr)
        .addFunction("IsValid", &GCScriptComponent::IsValid)
        .endClass();
}