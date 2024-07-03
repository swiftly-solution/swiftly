#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmFootEvent::GCNmFootEvent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmFootEvent::GCNmFootEvent(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCNmFootEvent::GetPhase() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CNmFootEvent", "m_phase");
}
void GCNmFootEvent::SetPhase(uint64_t value) {
    SetSchemaValue(m_ptr, "CNmFootEvent", "m_phase", false, value);
}
std::string GCNmFootEvent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmFootEvent::IsValid() {
    return (m_ptr != nullptr);
}
GCNmEvent GCNmFootEvent::GetParent() const {
    GCNmEvent value(m_ptr);
    return value;
}
void GCNmFootEvent::SetParent(GCNmEvent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmFootEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmFootEvent>("CNmFootEvent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Phase", &GCNmFootEvent::GetPhase, &GCNmFootEvent::SetPhase)
        .addProperty("Parent", &GCNmFootEvent::GetParent, &GCNmFootEvent::SetParent)
        .addFunction("ToPtr", &GCNmFootEvent::ToPtr)
        .addFunction("IsValid", &GCNmFootEvent::IsValid)
        .endClass();
}