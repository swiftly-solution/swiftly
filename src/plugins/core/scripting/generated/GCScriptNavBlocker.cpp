#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCScriptNavBlocker::GCScriptNavBlocker(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCScriptNavBlocker::GCScriptNavBlocker(void *ptr) {
    m_ptr = ptr;
}
Vector GCScriptNavBlocker::GetExtent() const {
    return GetSchemaValue<Vector>(m_ptr, "CScriptNavBlocker", "m_vExtent");
}
void GCScriptNavBlocker::SetExtent(Vector value) {
    SetSchemaValue(m_ptr, "CScriptNavBlocker", "m_vExtent", false, value);
}
std::string GCScriptNavBlocker::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCScriptNavBlocker::IsValid() {
    return (m_ptr != nullptr);
}
GCFuncNavBlocker GCScriptNavBlocker::GetParent() const {
    GCFuncNavBlocker value(m_ptr);
    return value;
}
void GCScriptNavBlocker::SetParent(GCFuncNavBlocker value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCScriptNavBlocker(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptNavBlocker>("CScriptNavBlocker")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Extent", &GCScriptNavBlocker::GetExtent, &GCScriptNavBlocker::SetExtent)
        .addProperty("Parent", &GCScriptNavBlocker::GetParent, &GCScriptNavBlocker::SetParent)
        .addFunction("ToPtr", &GCScriptNavBlocker::ToPtr)
        .addFunction("IsValid", &GCScriptNavBlocker::IsValid)
        .endClass();
}