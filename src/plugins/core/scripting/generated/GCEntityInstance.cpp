#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEntityInstance::GCEntityInstance(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEntityInstance::GCEntityInstance(void *ptr) {
    m_ptr = ptr;
}
std::string GCEntityInstance::GetPrivateVScripts() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEntityInstance", "m_iszPrivateVScripts").String();
}
void GCEntityInstance::SetPrivateVScripts(std::string value) {
    SetSchemaValue(m_ptr, "CEntityInstance", "m_iszPrivateVScripts", false, CUtlSymbolLarge(value.c_str()));
}
GCEntityIdentity GCEntityInstance::GetEntity() const {
    GCEntityIdentity value(*GetSchemaValuePtr<void*>(m_ptr, "CEntityInstance", "m_pEntity"));
    return value;
}
void GCEntityInstance::SetEntity(GCEntityIdentity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Entity' is not possible.\n");
}
GCScriptComponent GCEntityInstance::GetCScriptComponent() const {
    GCScriptComponent value(*GetSchemaValuePtr<void*>(m_ptr, "CEntityInstance", "m_CScriptComponent"));
    return value;
}
void GCEntityInstance::SetCScriptComponent(GCScriptComponent* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'CScriptComponent' is not possible.\n");
}
bool GCEntityInstance::GetVisibleinPVS() const {
    return GetSchemaValue<bool>(m_ptr, "CEntityInstance", "m_bVisibleinPVS");
}
void GCEntityInstance::SetVisibleinPVS(bool value) {
    SetSchemaValue(m_ptr, "CEntityInstance", "m_bVisibleinPVS", false, value);
}
std::string GCEntityInstance::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEntityInstance::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCEntityInstance(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntityInstance>("CEntityInstance")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PrivateVScripts", &GCEntityInstance::GetPrivateVScripts, &GCEntityInstance::SetPrivateVScripts)
        .addProperty("Entity", &GCEntityInstance::GetEntity, &GCEntityInstance::SetEntity)
        .addProperty("CScriptComponent", &GCEntityInstance::GetCScriptComponent, &GCEntityInstance::SetCScriptComponent)
        .addProperty("VisibleinPVS", &GCEntityInstance::GetVisibleinPVS, &GCEntityInstance::SetVisibleinPVS)
        .addFunction("ToPtr", &GCEntityInstance::ToPtr)
        .addFunction("IsValid", &GCEntityInstance::IsValid)
        .endClass();
}