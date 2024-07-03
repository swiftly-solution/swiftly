#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerMultiple::GCTriggerMultiple(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerMultiple::GCTriggerMultiple(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCTriggerMultiple::GetOnTrigger() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTriggerMultiple", "m_OnTrigger"));
    return value;
}
void GCTriggerMultiple::SetOnTrigger(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTriggerMultiple", "m_OnTrigger", false, value);
}
std::string GCTriggerMultiple::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerMultiple::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerMultiple::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerMultiple::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerMultiple(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerMultiple>("CTriggerMultiple")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnTrigger", &GCTriggerMultiple::GetOnTrigger, &GCTriggerMultiple::SetOnTrigger)
        .addProperty("Parent", &GCTriggerMultiple::GetParent, &GCTriggerMultiple::SetParent)
        .addFunction("ToPtr", &GCTriggerMultiple::ToPtr)
        .addFunction("IsValid", &GCTriggerMultiple::IsValid)
        .endClass();
}