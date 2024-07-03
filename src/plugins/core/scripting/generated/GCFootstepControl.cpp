#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFootstepControl::GCFootstepControl(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFootstepControl::GCFootstepControl(void *ptr) {
    m_ptr = ptr;
}
std::string GCFootstepControl::GetSource() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFootstepControl", "m_source").String();
}
void GCFootstepControl::SetSource(std::string value) {
    SetSchemaValue(m_ptr, "CFootstepControl", "m_source", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFootstepControl::GetDestination() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFootstepControl", "m_destination").String();
}
void GCFootstepControl::SetDestination(std::string value) {
    SetSchemaValue(m_ptr, "CFootstepControl", "m_destination", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFootstepControl::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFootstepControl::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCFootstepControl::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCFootstepControl::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFootstepControl(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootstepControl>("CFootstepControl")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Source", &GCFootstepControl::GetSource, &GCFootstepControl::SetSource)
        .addProperty("Destination", &GCFootstepControl::GetDestination, &GCFootstepControl::SetDestination)
        .addProperty("Parent", &GCFootstepControl::GetParent, &GCFootstepControl::SetParent)
        .addFunction("ToPtr", &GCFootstepControl::ToPtr)
        .addFunction("IsValid", &GCFootstepControl::IsValid)
        .endClass();
}