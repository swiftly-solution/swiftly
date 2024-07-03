#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCScriptTriggerHurt::GCScriptTriggerHurt(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCScriptTriggerHurt::GCScriptTriggerHurt(void *ptr) {
    m_ptr = ptr;
}
Vector GCScriptTriggerHurt::GetExtent() const {
    return GetSchemaValue<Vector>(m_ptr, "CScriptTriggerHurt", "m_vExtent");
}
void GCScriptTriggerHurt::SetExtent(Vector value) {
    SetSchemaValue(m_ptr, "CScriptTriggerHurt", "m_vExtent", false, value);
}
std::string GCScriptTriggerHurt::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCScriptTriggerHurt::IsValid() {
    return (m_ptr != nullptr);
}
GCTriggerHurt GCScriptTriggerHurt::GetParent() const {
    GCTriggerHurt value(m_ptr);
    return value;
}
void GCScriptTriggerHurt::SetParent(GCTriggerHurt value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCScriptTriggerHurt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptTriggerHurt>("CScriptTriggerHurt")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Extent", &GCScriptTriggerHurt::GetExtent, &GCScriptTriggerHurt::SetExtent)
        .addProperty("Parent", &GCScriptTriggerHurt::GetParent, &GCScriptTriggerHurt::SetParent)
        .addFunction("ToPtr", &GCScriptTriggerHurt::ToPtr)
        .addFunction("IsValid", &GCScriptTriggerHurt::IsValid)
        .endClass();
}