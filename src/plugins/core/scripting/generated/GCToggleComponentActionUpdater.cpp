#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCToggleComponentActionUpdater::GCToggleComponentActionUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCToggleComponentActionUpdater::GCToggleComponentActionUpdater(void *ptr) {
    m_ptr = ptr;
}
GAnimComponentID GCToggleComponentActionUpdater::GetComponentID() const {
    GAnimComponentID value(GetSchemaPtr(m_ptr, "CToggleComponentActionUpdater", "m_componentID"));
    return value;
}
void GCToggleComponentActionUpdater::SetComponentID(GAnimComponentID value) {
    SetSchemaValue(m_ptr, "CToggleComponentActionUpdater", "m_componentID", false, value);
}
bool GCToggleComponentActionUpdater::GetSetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CToggleComponentActionUpdater", "m_bSetEnabled");
}
void GCToggleComponentActionUpdater::SetSetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CToggleComponentActionUpdater", "m_bSetEnabled", false, value);
}
std::string GCToggleComponentActionUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCToggleComponentActionUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimActionUpdater GCToggleComponentActionUpdater::GetParent() const {
    GCAnimActionUpdater value(m_ptr);
    return value;
}
void GCToggleComponentActionUpdater::SetParent(GCAnimActionUpdater value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCToggleComponentActionUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCToggleComponentActionUpdater>("CToggleComponentActionUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ComponentID", &GCToggleComponentActionUpdater::GetComponentID, &GCToggleComponentActionUpdater::SetComponentID)
        .addProperty("SetEnabled", &GCToggleComponentActionUpdater::GetSetEnabled, &GCToggleComponentActionUpdater::SetSetEnabled)
        .addProperty("Parent", &GCToggleComponentActionUpdater::GetParent, &GCToggleComponentActionUpdater::SetParent)
        .addFunction("ToPtr", &GCToggleComponentActionUpdater::ToPtr)
        .addFunction("IsValid", &GCToggleComponentActionUpdater::IsValid)
        .endClass();
}