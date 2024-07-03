#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointClientUIDialog::GCPointClientUIDialog(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointClientUIDialog::GCPointClientUIDialog(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCPointClientUIDialog::GetActivator() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPointClientUIDialog", "m_hActivator"));
    return value;
}
void GCPointClientUIDialog::SetActivator(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Activator' is not possible.\n");
}
bool GCPointClientUIDialog::GetStartEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CPointClientUIDialog", "m_bStartEnabled");
}
void GCPointClientUIDialog::SetStartEnabled(bool value) {
    SetSchemaValue(m_ptr, "CPointClientUIDialog", "m_bStartEnabled", false, value);
}
std::string GCPointClientUIDialog::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointClientUIDialog::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseClientUIEntity GCPointClientUIDialog::GetParent() const {
    GCBaseClientUIEntity value(m_ptr);
    return value;
}
void GCPointClientUIDialog::SetParent(GCBaseClientUIEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointClientUIDialog(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointClientUIDialog>("CPointClientUIDialog")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Activator", &GCPointClientUIDialog::GetActivator, &GCPointClientUIDialog::SetActivator)
        .addProperty("StartEnabled", &GCPointClientUIDialog::GetStartEnabled, &GCPointClientUIDialog::SetStartEnabled)
        .addProperty("Parent", &GCPointClientUIDialog::GetParent, &GCPointClientUIDialog::SetParent)
        .addFunction("ToPtr", &GCPointClientUIDialog::ToPtr)
        .addFunction("IsValid", &GCPointClientUIDialog::IsValid)
        .endClass();
}