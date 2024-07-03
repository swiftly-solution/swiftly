#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmTransitionEvent::GCNmTransitionEvent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmTransitionEvent::GCNmTransitionEvent(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCNmTransitionEvent::GetRule() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CNmTransitionEvent", "m_rule");
}
void GCNmTransitionEvent::SetRule(uint64_t value) {
    SetSchemaValue(m_ptr, "CNmTransitionEvent", "m_rule", false, value);
}
std::string GCNmTransitionEvent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmTransitionEvent::IsValid() {
    return (m_ptr != nullptr);
}
GCNmEvent GCNmTransitionEvent::GetParent() const {
    GCNmEvent value(m_ptr);
    return value;
}
void GCNmTransitionEvent::SetParent(GCNmEvent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmTransitionEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmTransitionEvent>("CNmTransitionEvent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Rule", &GCNmTransitionEvent::GetRule, &GCNmTransitionEvent::SetRule)
        .addProperty("Parent", &GCNmTransitionEvent::GetParent, &GCNmTransitionEvent::SetParent)
        .addFunction("ToPtr", &GCNmTransitionEvent::ToPtr)
        .addFunction("IsValid", &GCNmTransitionEvent::IsValid)
        .endClass();
}