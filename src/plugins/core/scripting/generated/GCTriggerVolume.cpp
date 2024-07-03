#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerVolume::GCTriggerVolume(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerVolume::GCTriggerVolume(void *ptr) {
    m_ptr = ptr;
}
std::string GCTriggerVolume::GetFilterName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerVolume", "m_iFilterName").String();
}
void GCTriggerVolume::SetFilterName(std::string value) {
    SetSchemaValue(m_ptr, "CTriggerVolume", "m_iFilterName", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseFilter GCTriggerVolume::GetFilter() const {
    GCBaseFilter value(*GetSchemaValuePtr<void*>(m_ptr, "CTriggerVolume", "m_hFilter"));
    return value;
}
void GCTriggerVolume::SetFilter(GCBaseFilter* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Filter' is not possible.\n");
}
std::string GCTriggerVolume::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerVolume::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCTriggerVolume::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCTriggerVolume::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerVolume>("CTriggerVolume")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FilterName", &GCTriggerVolume::GetFilterName, &GCTriggerVolume::SetFilterName)
        .addProperty("Filter", &GCTriggerVolume::GetFilter, &GCTriggerVolume::SetFilter)
        .addProperty("Parent", &GCTriggerVolume::GetParent, &GCTriggerVolume::SetParent)
        .addFunction("ToPtr", &GCTriggerVolume::ToPtr)
        .addFunction("IsValid", &GCTriggerVolume::IsValid)
        .endClass();
}