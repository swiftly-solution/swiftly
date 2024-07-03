#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCScriptTriggerPush::GCScriptTriggerPush(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCScriptTriggerPush::GCScriptTriggerPush(void *ptr) {
    m_ptr = ptr;
}
Vector GCScriptTriggerPush::GetExtent() const {
    return GetSchemaValue<Vector>(m_ptr, "CScriptTriggerPush", "m_vExtent");
}
void GCScriptTriggerPush::SetExtent(Vector value) {
    SetSchemaValue(m_ptr, "CScriptTriggerPush", "m_vExtent", false, value);
}
std::string GCScriptTriggerPush::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCScriptTriggerPush::IsValid() {
    return (m_ptr != nullptr);
}
GCTriggerPush GCScriptTriggerPush::GetParent() const {
    GCTriggerPush value(m_ptr);
    return value;
}
void GCScriptTriggerPush::SetParent(GCTriggerPush value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCScriptTriggerPush(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptTriggerPush>("CScriptTriggerPush")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Extent", &GCScriptTriggerPush::GetExtent, &GCScriptTriggerPush::SetExtent)
        .addProperty("Parent", &GCScriptTriggerPush::GetParent, &GCScriptTriggerPush::SetParent)
        .addFunction("ToPtr", &GCScriptTriggerPush::ToPtr)
        .addFunction("IsValid", &GCScriptTriggerPush::IsValid)
        .endClass();
}