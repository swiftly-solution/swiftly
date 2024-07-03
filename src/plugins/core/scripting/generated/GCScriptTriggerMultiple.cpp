#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCScriptTriggerMultiple::GCScriptTriggerMultiple(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCScriptTriggerMultiple::GCScriptTriggerMultiple(void *ptr) {
    m_ptr = ptr;
}
Vector GCScriptTriggerMultiple::GetExtent() const {
    return GetSchemaValue<Vector>(m_ptr, "CScriptTriggerMultiple", "m_vExtent");
}
void GCScriptTriggerMultiple::SetExtent(Vector value) {
    SetSchemaValue(m_ptr, "CScriptTriggerMultiple", "m_vExtent", false, value);
}
std::string GCScriptTriggerMultiple::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCScriptTriggerMultiple::IsValid() {
    return (m_ptr != nullptr);
}
GCTriggerMultiple GCScriptTriggerMultiple::GetParent() const {
    GCTriggerMultiple value(m_ptr);
    return value;
}
void GCScriptTriggerMultiple::SetParent(GCTriggerMultiple value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCScriptTriggerMultiple(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptTriggerMultiple>("CScriptTriggerMultiple")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Extent", &GCScriptTriggerMultiple::GetExtent, &GCScriptTriggerMultiple::SetExtent)
        .addProperty("Parent", &GCScriptTriggerMultiple::GetParent, &GCScriptTriggerMultiple::SetParent)
        .addFunction("ToPtr", &GCScriptTriggerMultiple::ToPtr)
        .addFunction("IsValid", &GCScriptTriggerMultiple::IsValid)
        .endClass();
}