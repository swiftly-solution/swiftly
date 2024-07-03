#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTonemapTrigger::GCTonemapTrigger(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTonemapTrigger::GCTonemapTrigger(void *ptr) {
    m_ptr = ptr;
}
std::string GCTonemapTrigger::GetTonemapControllerName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTonemapTrigger", "m_tonemapControllerName").String();
}
void GCTonemapTrigger::SetTonemapControllerName(std::string value) {
    SetSchemaValue(m_ptr, "CTonemapTrigger", "m_tonemapControllerName", false, CUtlSymbolLarge(value.c_str()));
}
GCEntityInstance GCTonemapTrigger::GetTonemapController() const {
    GCEntityInstance value(*GetSchemaValuePtr<void*>(m_ptr, "CTonemapTrigger", "m_hTonemapController"));
    return value;
}
void GCTonemapTrigger::SetTonemapController(GCEntityInstance* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'TonemapController' is not possible.\n");
}
std::string GCTonemapTrigger::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTonemapTrigger::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTonemapTrigger::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTonemapTrigger::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTonemapTrigger(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTonemapTrigger>("CTonemapTrigger")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TonemapControllerName", &GCTonemapTrigger::GetTonemapControllerName, &GCTonemapTrigger::SetTonemapControllerName)
        .addProperty("TonemapController", &GCTonemapTrigger::GetTonemapController, &GCTonemapTrigger::SetTonemapController)
        .addProperty("Parent", &GCTonemapTrigger::GetParent, &GCTonemapTrigger::SetParent)
        .addFunction("ToPtr", &GCTonemapTrigger::ToPtr)
        .addFunction("IsValid", &GCTonemapTrigger::IsValid)
        .endClass();
}