#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCScriptTriggerOnce::GCScriptTriggerOnce(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCScriptTriggerOnce::GCScriptTriggerOnce(void *ptr) {
    m_ptr = ptr;
}
Vector GCScriptTriggerOnce::GetExtent() const {
    return GetSchemaValue<Vector>(m_ptr, "CScriptTriggerOnce", "m_vExtent");
}
void GCScriptTriggerOnce::SetExtent(Vector value) {
    SetSchemaValue(m_ptr, "CScriptTriggerOnce", "m_vExtent", false, value);
}
std::string GCScriptTriggerOnce::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCScriptTriggerOnce::IsValid() {
    return (m_ptr != nullptr);
}
GCTriggerOnce GCScriptTriggerOnce::GetParent() const {
    GCTriggerOnce value(m_ptr);
    return value;
}
void GCScriptTriggerOnce::SetParent(GCTriggerOnce value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCScriptTriggerOnce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptTriggerOnce>("CScriptTriggerOnce")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Extent", &GCScriptTriggerOnce::GetExtent, &GCScriptTriggerOnce::SetExtent)
        .addProperty("Parent", &GCScriptTriggerOnce::GetParent, &GCScriptTriggerOnce::SetParent)
        .addFunction("ToPtr", &GCScriptTriggerOnce::ToPtr)
        .addFunction("IsValid", &GCScriptTriggerOnce::IsValid)
        .endClass();
}