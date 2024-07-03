#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlatTrigger::GCPlatTrigger(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlatTrigger::GCPlatTrigger(void *ptr) {
    m_ptr = ptr;
}
GCFuncPlat GCPlatTrigger::GetPlatform() const {
    GCFuncPlat value(*GetSchemaValuePtr<void*>(m_ptr, "CPlatTrigger", "m_pPlatform"));
    return value;
}
void GCPlatTrigger::SetPlatform(GCFuncPlat* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Platform' is not possible.\n");
}
std::string GCPlatTrigger::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlatTrigger::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCPlatTrigger::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCPlatTrigger::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPlatTrigger(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlatTrigger>("CPlatTrigger")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Platform", &GCPlatTrigger::GetPlatform, &GCPlatTrigger::SetPlatform)
        .addProperty("Parent", &GCPlatTrigger::GetParent, &GCPlatTrigger::SetParent)
        .addFunction("ToPtr", &GCPlatTrigger::ToPtr)
        .addFunction("IsValid", &GCPlatTrigger::IsValid)
        .endClass();
}