#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerRemove::GCTriggerRemove(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerRemove::GCTriggerRemove(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCTriggerRemove::GetOnRemove() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTriggerRemove", "m_OnRemove"));
    return value;
}
void GCTriggerRemove::SetOnRemove(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTriggerRemove", "m_OnRemove", false, value);
}
std::string GCTriggerRemove::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerRemove::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerRemove::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerRemove::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerRemove(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerRemove>("CTriggerRemove")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnRemove", &GCTriggerRemove::GetOnRemove, &GCTriggerRemove::SetOnRemove)
        .addProperty("Parent", &GCTriggerRemove::GetParent, &GCTriggerRemove::SetParent)
        .addFunction("ToPtr", &GCTriggerRemove::ToPtr)
        .addFunction("IsValid", &GCTriggerRemove::IsValid)
        .endClass();
}